<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }

class Queue
{
    private $arr = [];

    public function enqueue($x)
    {
        $this->arr[$x] = $x;
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
    list($N, $Q) = ints();
    
    // 隣接リスト
    $G = array_fill(0, $N, []);

    for($i = 0; $i < $N - 1; ++$i)
    {
        list($a, $b) = ints();
        --$a; --$b; // 0-indexedにする

        $G[$a][] = $b; // a->bに辺を張る
        $G[$b][] = $a; // b->aに辺を張る
    }

    // 各頂点のカウンターの値
    $cnt = array_fill(0, $N, 0);

    for($i = 0; $i < $Q; ++$i)
    {
        list($p, $x) = ints();
        --$p; // 0-indexedにする

        $cnt[$p] += $x; // pのカウンターにxを足す
    }

    // キュー
    $q = new SplQueue;
    $q->enqueue(0); // 初期値として根(0-indexedだと0)を入れる

    // 各頂点を探索したかどうかのフラグ
    $seen = array_fill(0, $N, false);

    // キューが空になるまで
    while(!$q->isEmpty())
    {
        // キューから先頭の頂点を取り出す
        $v = $q->dequeue();

        // 探索済みフラグをtrueにする
        $seen[$v] = true;

        // 隣接している頂点を全て探索
        foreach($G[$v] as $u)
        {
            // 探索済みなら何もしない
            if($seen[$u]) continue;

            // カウンターの値を伝播させる
            $cnt[$u] += $cnt[$v];

            // キューに頂点を入れる
            $q->enqueue($u);
        }
    }

    printf("%s\n", implode(' ', $cnt));
}

main();