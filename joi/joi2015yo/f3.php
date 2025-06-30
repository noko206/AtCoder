<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
    // 入力
    [$n, $d] = ints();
    $xy = [];
    for ($i = 0; $i < $n; ++$i) {
        $xy[] = ints();
    }
    usort($xy, function (array $a, array $b): bool {
        if (abs($a[0]) === abs($b[0])) {
            return 0;
        }
        return abs($a[0]) < abs($b[0]) ? 1 : -1;
    });
    $x = [];
    $y = [];
    foreach ($xy as [$x_, $y_]) {
        $x[] = $x_;
        $y[] = $y_;
    }
    unset($xy); // メモリ節約

    // メイン処理
    $h = intdiv($n, 2);
    $enumInit = new SplFixedArray(2);
    $enumInit[0] = 0;
    $enumInit[1] = 0;

    $nl = pow(3, $h);
    $enumL = new SplFixedArray($nl);
    for ($i = 0; $i < $nl; ++$i) {
        $enumL[$i] = clone $enumInit;
    }
    $len = 1;
    for ($i = 0; $i < $h; ++$i) {
        $x_ = $x[$i];
        $y_ = $y[$i];
        $j = 0;
        while ($j < $nl) {
            if ($x_ >= 0) {
                $enumL[$j][0] -= $x_;
                $enumL[$j][1] -= $y_;
                $j += $len;
                $enumL[$j][0] += $x_;
                $enumL[$j][1] += $y_;
                $j += $len;
                $enumL[$j][0] += $x_;
                $enumL[$j][1] += $y_;
                $j += $len;
            } else {
                $enumL[$j][0] += $x_;
                $enumL[$j][1] += $y_;
                $j += $len;
                $enumL[$j][0] -= $x_ * 2;
                $enumL[$j][1] -= $y_ * 2;
                $j += $len;
                $enumL[$j][0] += $x_;
                $enumL[$j][1] += $y_;
                $j += $len;
            }
        }
        $len *= 3;
    }
    for ($i = 0; $i < $nl - 1; ++$i) {
        $enumL[$i + 1][0] += $enumL[$i][0];
        $enumL[$i + 1][1] += $enumL[$i][1];
    }
    array_pop($enumL);

    $nr = pow(3, $n - $h);
    $enumR = array_fill(0, $nr, [0, 0]);
    $len = 1;
    for ($i = 0; $i < $n - $h; ++$i) {
        $x_ = $x[$i + $h];
        $y_ = $y[$i + $h];
        $j = 0;
        while ($j < $nr) {
            $enumR[$j][0] += $x_;
            $enumR[$j][1] += $y_;
            $j += $len;
            $enumR[$j][0] -= $x_ * 2;
            $enumR[$j][1] -= $y_ * 2;
            $j += $len;
            $enumR[$j][0] += $x_;
            $enumR[$j][1] += $y_;
            $j += $len;
        }
        $len *= 3;
    }
    for ($i = 0; $i < $nr - 1; ++$i) {
        $enumR[$i + 1][0] += $enumR[$i][0];
        $enumR[$i + 1][1] += $enumR[$i][1];
    }

    $q = [];
    $posL = 0;

    $ans = 0;
    $pos = 0;
    foreach ($enumL as [$xl, $yl]) {
        while ($pos < $nr && $xl + $enumR[$pos][0] >= -$d) {
            while ($posL !== count($q) && $enumR[end($q)][1] <= $enumR[$pos][1]) {
                array_pop($q);
            }
            $q[] = $pos;
            ++$pos;
        }
        while ($posL !== count($q) && $xl + $enumR[$q[$posL]][0] > $d) {
            ++$posL;
        }
        if ($posL !== count($q)) {
            $ans = max($ans, $yl + $enumR[$q[$posL]][1]);
        }
    }

    // 出力
    output($ans);
}

main();
