<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }

class UnionFind
{
    private $par = []; // 親ノードを表す配列
    private $siz = []; // 自身が属する集合の要素数(参照されるのはルートのみ)

    public function __construct($n)
	{
		// 全てのノードを親で初期化
        for($i = 0; $i < $n; ++$i)
		{
            $this->par[$i] = $i;
        }

		// サイズの初期化
        $this->siz = array_fill(0, $n, 1);
    }

	// ルートを取得
    public function root($x)
	{
		// 自分が親のとき、自分を返す
        if($this->par[$x] === $x)
		{
            return $x;
        }

		// 親ノードを更新しつつ、再帰的にルートを探す
        return $this->par[$x] = $this->root($this->par[$x]);
    }

	// 二つのノードが属する集合を結合
    public function unite($x, $y)
	{
		// ルートを取得
        $rx = $this->root($x);
        $ry = $this->root($y);

		// 既に結合している場合は何もしない
		if($rx === $ry)
		{
            return false;
        }

		// サイズが大きい方をrxとする
        if($this->siz[$rx] < $this->siz[$ry])
		{
            list($rx, $ry) = [$ry, $rx];
        }

		// サイズの更新
        $this->siz[$rx] += $this->siz[$ry];

		// 親ノードの更新
        $this->par[$ry] = $rx;

        return true;
    }

	// 二つのノードが同じ集合に属するかを取得
	public function same($x, $y)
	{
		// ルートが同じかどうかで判定
		return $this->root($x) === $this->root($y);
	}

	// サイズを取得
    public function size($x)
	{
		// ルートのサイズを取得
        return $this->siz[$this->root($x)];
    }
}

function main()
{
	list($n, $m) = ints();

	$a = [];
	$b = [];

	for($i = 0; $i < $m; ++$i)
	{
		list($a[$i], $b[$i]) = ints();

		// 0-indexedにする
		--$a[$i];
		--$b[$i];
	}

	// i番目の橋まで崩落したときの不便さ
	$ans = array_fill(0, $m + 1, 0);
	$ans[$m] = intdiv($n * ($n - 1), 2); // 全ての橋が崩落したときの不便さはnC2

	$uf = new UnionFind($n);

	// m,m-1,m-2,...,1番目の橋を順に架けていく
	for($i = $m - 1; $i >= 0; --$i)
	{
		// 橋を架ける前から行き来ができた場合
		if($uf->same($a[$i], $b[$i]))
		{
			// 橋を架けても不便さは変わらない
			$ans[$i] = $ans[$i + 1];
		}
		else
		{
			// 橋を架けることで行き来が可能になった島の組み合わせの数だけ不便さが減る
			$ans[$i] = $ans[$i + 1] - ($uf->size($a[$i]) * $uf->size($b[$i]));
		}

		// i番目の橋を架ける
		$uf->unite($a[$i], $b[$i]);
	}

	for($i = 1; $i <= $m; ++$i)
	{
		printf("%d\n", $ans[$i]);
	}
}

main();