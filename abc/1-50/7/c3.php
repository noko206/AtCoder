<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }

const _INF = 1001001001001001001; // 10^18より少し大きい値
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]]; // 隣り合う座標の差

class Queue
{
    private $arr = [];

    public function enqueue($x)
    {
        array_push($this->arr, $x);
    }

    public function dequeue()
    {
        return array_shift($this->arr);
    }

    public function isEmpty()
    {
        return empty($this->arr);
    }
}

function main()
{
    list($R, $C) = ints();
    list($sy, $sx) = ints();
    list($gy, $gx) = ints();

    // 0-indexedにする
    --$sy; --$sx; --$gy; --$gx;

    $c = [];

    for($i = 0; $i < $R; ++$i)
    {
        list($c[]) = strings();
    }

    // キュー
    $q = new Queue;
    $q->enqueue([$sy, $sx]); // 初期値としてスタートの座標を入れる

    // スタートの座標からの最短距離
    $dist = array_fill(0, $R, array_fill(0, $C, _INF));
    $dist[$sy][$sx] = 0; // スタートの最短距離は0としておく

    // キューが空になるまで
    while(!$q->isEmpty())
    {
        // キューから先頭の座標を取り出す
        list($y, $x) = $q->dequeue();

        // 隣り合うマスを全て探索
        foreach(_DIF as list($dy, $dx))
        {
            $ny = $y + $dy; // 隣り合うマスのy座標
            $nx = $x + $dx; // 隣り合うマスのx座標

            // 範囲外なら何もしない
            if($ny < 0 || $nx < 0 || $ny >= $R || $nx >= $C) continue;

            // 既に探索済みなら何もしない
            if($dist[$ny][$nx] !== _INF) continue;

            // 壁なら何もしない
            if($c[$ny][$nx] === '#') continue;

            // 最短距離を更新
            $dist[$ny][$nx] = $dist[$y][$x] + 1;

            // キューに座標を入れる
            $q->enqueue([$ny, $nx]);
        }
    }

    printf("%d\n", $dist[$gy][$gx]);
}

main();