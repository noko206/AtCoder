<?php

function ints() { return array_map('intval', explode(' ', trim(fgets(STDIN)))); }
function doubles() { return array_map('doubleval', explode(' ', trim(fgets(STDIN)))); }
function strings() { return explode(' ', trim(fgets(STDIN))); }
function chmax(&$a, $b) { if($a < $b) { $a = $b; return true; } return false; }
function chmin(&$a, $b) { if($a > $b) { $a = $b; return true; } return false; }
function gcd(int $a, int $b): int { return ($a % $b) ? gcd($b, $a % $b) : $b; }
function lcm(int $a, int $b): int { return intdiv($a, gcd($a, $b)) * $b; }
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    list($R, $C) = ints();
    list($sy, $sx) = ints();
    list($gy, $gx) = ints();

    --$sy; --$sx; --$gy; --$gx;

    $c = [];

    for($i = 0; $i < $R; ++$i)
    {
        $c[] = strings()[0];
    }

    $q = new SplQueue;
    $q->enqueue([$sy, $sx]);

    $dist = array_fill(0, $R, array_fill(0, $C, _INF));
    $dist[$sy][$sx] = 0;

    while(!$q->isEmpty())
    {
        list($y, $x) = $q->dequeue();

        foreach(_DIF as list($dy, $dx))
        {
            $ny = $y + $dy;
            $nx = $x + $dx;

            if($ny < 0 || $nx < 0 || $ny >= $R || $nx >= $C) continue;
            if($dist[$ny][$nx] !== _INF) continue;
            if($c[$ny][$nx] === '#') continue;

            $dist[$ny][$nx] = $dist[$y][$x] + 1;

            $q->enqueue([$ny, $nx]);
        }
    }

    printf("%d\n", $dist[$gy][$gx]);
}

main();