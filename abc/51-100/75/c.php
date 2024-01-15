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

	$ans = 0;

	// 辺iが橋かどうかをチェック
	for($i = 0; $i < $m; ++$i)
	{
		$uf = new UnionFind($n);

		for($j = 0; $j < $m; ++$j)
		{
			// 辺iだけ取り除く
			if($i === $j)
			{
				continue;
			}

			$uf->unite($a[$j], $b[$j]);
		}

		// 任意の頂点のサイズがnでない(グラフが非連結の)場合
		if($uf->size(0) !== $n)
		{
			++$ans;
		}
	}

	printf("%d\n", $ans);
}

main();