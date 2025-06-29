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
    $x = [];
    $y = [];
    for ($i = 0; $i < $n; ++$i) {
        [$x[], $y[]] = ints();
    }

    // メイン処理
    $h = intdiv($n, 2);
    $enumL = [];
    $nl = pow(3, $h);
    for ($bit = 0; $bit < $nl; ++$bit) {
        $bit_ = $bit;
        $xl = 0;
        $yl = 0;
        for ($i = 0; $i < $h; ++$i) {
            switch ($bit_ % 3) {
                case 0:
                    $xl -= $x[$i];
                    $yl -= $y[$i];
                    break;
                case 1:
                    $xl += $x[$i];
                    $yl += $y[$i];
                    break;
            }
            $bit_ = intdiv($bit_, 3);
        }
        $enumL[] = [$xl, $yl];
    }

    $enumR = [];
    $nr = pow(3, $n - $h);
    for ($bit = 0; $bit < $nr; ++$bit) {
        $bit_ = $bit;
        $xr = 0;
        $yr = 0;
        for ($i = 0; $i < $n - $h; ++$i) {
            switch ($bit_ % 3) {
                case 0:
                    $xr -= $x[$i + $h];
                    $yr -= $y[$i + $h];
                    break;
                case 1:
                    $xr += $x[$i + $h];
                    $yr += $y[$i + $h];
                    break;
            }
            $bit_ = intdiv($bit_, 3);
        }
        $enumR[] = [$xr, $yr];
    }

    sort($enumL);
    rsort($enumR);

    $q = new SplDoublyLinkedList();
    $ans = 0;
    $pos = 0;
    foreach ($enumL as [$xl, $yl]) {
        while ($pos < $nr && $xl + $enumR[$pos][0] >= -$d) {
            while (!$q->isEmpty() && $enumR[$q->top()][1] <= $enumR[$pos][1]) {
                $q->pop();
            }
            $q->push($pos);
            ++$pos;
        }
        while (!$q->isEmpty() && $xl + $enumR[$q->bottom()][0] > $d) {
            $q->shift();
        }
        if (!$q->isEmpty()) {
            $ans = max($ans, $yl + $enumR[$q->bottom()][1]);
        }
    }

    // 出力
    output($ans);
}

main();
