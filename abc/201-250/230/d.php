<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function chmax(&$a, $b) { if($a < $b) { $a = $b; return true; } return false; }
function chmin(&$a, $b) { if($a > $b) { $a = $b; return true; } return false; }
function gcd($a, $b) { return ($a % $b) ? gcd($b, $a % $b) : $b; }
function lcm($a, $b) { return intdiv($a, gcd($a, $b)) * $b; }
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    list($n, $d) = ints();

    $wall = [];

    for($i = 0; $i < $n; ++$i)
    {
        list($l, $r) = ints();
        $wall[] = [$r, $l];
    }

    sort($wall);

    $ans = 0;
    $x = -_INF;

    foreach($wall as list($r, $l))
    {
        if($x + $d - 1 < $l)
        {
            ++$ans;
            $x = $r;
        }
    }

    printf("%d\n", $ans);
}

main();