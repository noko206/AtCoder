<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
    // 入力
    [$N, $W] = ints();
    $v = [];
    $w = [];
    for ($i = 0; $i < $N; ++$i) {
        [$v[], $w[]] = ints();
    }

    // メイン処理
    $partL = [];
    $partR = [];
    for ($i = 0; $i < $N; ++$i) {
        if ($i % 2 === 0) {
            $partL[] = [$w[$i], $v[$i]];
        } else {
            $partR[] = [$w[$i], $v[$i]];
        }
    }

    $enumL = [];
    for ($bit = 0; $bit < (1 << count($partL)); ++$bit) {
        $sumW = 0;
        $sumV = 0;
        for ($i = 0; $i < count($partL); ++$i) {
            if ($bit & (1 << $i)) {
                [$wL, $vL] = $partL[$i];
                $sumW += $wL;
                $sumV += $vL;
            }
        }
        $enumL[] = [$sumW, $sumV];
    }

    $enumR = [];
    for ($bit = 0; $bit < (1 << count($partR)); ++$bit) {
        $sumW = 0;
        $sumV = 0;
        for ($i = 0; $i < count($partR); ++$i) {
            if ($bit & (1 << $i)) {
                [$wR, $vR] = $partR[$i];
                $sumW += $wR;
                $sumV += $vR;
            }
        }
        $enumR[] = [$sumW, $sumV];
    }

    sort($enumR);
    $maxV = 0;
    foreach ($enumR as $i => [$wR, $vR]) {
        $maxV = max($maxV, $vR);
        $enumR[$i][1] = $maxV;
    }

    $ans = 0;
    foreach ($enumL as [$wL, $vL]) {
        $ok = -1;
        $ng = count($enumR);
        while ($ng - $ok !== 1) {
            $mid = intdiv($ok + $ng, 2);
            [$wR, $vR] = $enumR[$mid];
            if ($wL + $wR <= $W) {
                $ok = $mid;
            } else {
                $ng = $mid;
            }
        }
        if ($ok !== -1) {
            [$wR, $vR] = $enumR[$ok];
            $ans = max($ans, $vL + $vR);
        }
    }

    // 出力
    output($ans);
}

main();
