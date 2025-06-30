<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function builtinPopcount(int $bit): int
{
    $ans = 0;
    while ($bit > 0) {
        if ($bit & 1) {
            ++$ans;
        }
        $bit >>= 1;
    }
    return $ans;
}

function splitList(int $start, int $end, array $a): array
{
    $n = $end - $start;
    $list = array_fill(0, $n, []);
    for ($bit = 0; $bit < (1 << $n); ++$bit) {
        $sum = 0;
        for ($i = 0; $i < $n; ++$i) {
            if ($bit & (1 << $i)) {
                $sum += $a[$i + $start];
            }
        }
        $list[builtinPopcount($bit)][] = $sum;
    }
    for ($i = 0; $i < $n; ++$i) {
        sort($list[$i]);
    }
    return $list;
}

function lowerBound(array $a, int $x): int
{
    $ok = count($a);
    $ng = -1;
    while ($ok - $ng !== 1) {
        $mid = intdiv($ok + $ng, 2);
        if ($x <= $a[$mid]) {
            $ok = $mid;
        } else {
            $ng = $mid;
        }
    }
    return $ok;
}

function upperBound(array $a, int $x): int
{
    return lowerBound($a, $x + 1);
}

function main()
{
    // 入力
    [$n, $k, $l, $r] = ints();
    $a = ints();

    // メイン処理
    $h = intdiv($n, 2);
    $listX = splitList(0, $h, $a);
    $listY = splitList($h, $n, $a);
    $ans = 0;
    foreach ($listX as $cntX => $sumListX) {
        $cntY = $k - $cntX;
        if ($cntY < 0 || $cntY >= count($listY)) {
            continue;
        }
        foreach ($sumListX as $sumX) {
            $ans += upperBound($listY[$cntY], $r - $sumX) - lowerBound($listY[$cntY], $l - $sumX);
        }
    }

    // 出力
    output($ans);
}

main();
