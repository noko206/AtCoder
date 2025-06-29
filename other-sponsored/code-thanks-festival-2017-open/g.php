<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
    // 入力
    [$n, $m] = ints();
    $a = [];
    $b = [];
    for ($i = 0; $i < $m; ++$i) {
        [$a[], $b[]] = ints();
        --$a[$i];
        --$b[$i];
    }

    // メイン処理
    $matrix = array_fill(0, $n, array_fill(0, $n, false));
    for ($i = 0; $i < $m; ++$i) {
        $matrix[$a[$i]][$b[$i]] = true;
        $matrix[$b[$i]][$a[$i]] = true;
    }

    $h = intdiv($n, 2);

    $filterA = array_fill(0, $h, 0);
    for ($i = 0; $i < $h; ++$i) {
        for ($j = 0; $j < $h; ++$j) {
            if ($matrix[$i][$j]) {
                $filterA[$i] |= 1 << $j;
            }
        }
    }

    $filterB = array_fill(0, $n - $h, 0);
    for ($i = 0; $i < $n - $h; ++$i) {
        for ($j = 0; $j < $n - $h; ++$j) {
            if ($matrix[$i + $h][$j + $h]) {
                $filterB[$i] |= 1 << $j;
            }
        }
    }

    $filterAtoB = array_fill(0, $h, 0);
    for ($i = 0; $i < $h; ++$i) {
        for ($j = 0; $j < $n - $h; ++$j) {
            if ($matrix[$i][$j + $h]) {
                $filterAtoB[$i] |= 1 << $j;
            }
        }
    }

    $enumA = [];
    for ($bitA = 0; $bitA < (1 << $h); ++$bitA) {
        $ok = true;
        for ($i = 0; $i < $h; ++$i) {
            if (($bitA & (1 << $i)) && ($bitA & $filterA[$i])) {
                $ok = false;
            }
        }
        if ($ok) {
            $enumA[] = $bitA;
        }
    }

    $enumAtoB = [];
    foreach ($enumA as $bitA) {
        $mask = 0;
        for ($i = 0; $i < $h; ++$i) {
            if ($bitA & (1 << $i)) {
                $mask |= $filterAtoB[$i];
            }
        }
        $bitB = 0;
        for ($i = 0; $i < $n - $h; ++$i) {
            if (!($mask & (1 << $i))) {
                $bitB |= 1 << $i;
            }
        }
        $enumAtoB[$bitA] = $bitB;
    }

    $dp = array_fill(0, 1 << ($n - $h), 0);
    for ($bitB = 0; $bitB < (1 << ($n - $h)); ++$bitB) {
        for ($i = 0; $i < $n - $h; ++$i) {
            if ($bitB & (1 << $i)) {
                continue;
            }
            if ($bitB & $filterB[$i]) {
                $dp[$bitB | (1 << $i)] = max($dp[$bitB | (1 << $i)], $dp[$bitB]);
            } else {
                $dp[$bitB | (1 << $i)] = max($dp[$bitB | (1 << $i)], $dp[$bitB] + 1);
            }
        }
    }

    $ans = 0;
    foreach ($enumA as $bitA) {
        $cnt = 0;
        for ($i = 0; $i < $h; ++$i) {
            if ($bitA & (1 << $i)) {
                ++$cnt;
            }
        }
        $bitB = $enumAtoB[$bitA];
        $cnt += $dp[$bitB];
        $ans = max($ans, $cnt);
    }

    // 出力
    output($ans);
}

main();
