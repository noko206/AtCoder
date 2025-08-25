<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
    [$d] = ints();
    [$n] = ints();

    // いもす法による区間加算
    $ans = array_fill(0, $d, 0);
    for ($i = 0; $i < $n; ++$i) {
        [$l, $r] = ints();
        --$l;
        --$r; // 配列が0スタートなので、それに合わせる
        ++$ans[$l];
        if ($r + 1 < $d) {
            --$ans[$r + 1];
        }
    }

    // 累積和
    for ($i = 0; $i < $d - 1; ++$i) {
        $ans[$i + 1] += $ans[$i];
    }

    output(...$ans);
}

main();
