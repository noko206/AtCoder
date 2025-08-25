<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
    [$n, $q] = ints();
    $a = ints();

    // 累積和を計算
    $tot = [];
    $tot[0] = 0; // 最初は0を入れること！
    for ($i = 0; $i < $n; ++$i) {
        $tot[$i + 1] = $tot[$i] + $a[$i];
    }

    // クエリを処理
    $ans = [];
    for ($i = 0; $i < $q; ++$i) {
        [$l, $r] = ints();
        --$l;
        --$r; // 配列の添字が0スタートなので合わせる
        $ans[] = $tot[$r + 1] - $tot[$l];
    }

    output(...$ans);
}

main();
