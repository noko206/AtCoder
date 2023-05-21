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
    list($n, $a, $b) = ints();
    list($p, $q, $r, $s) = ints();

    for($i = $p; $i <= $q; ++$i)
    {
        for($j = $r; $j <= $s; ++$j)
        {
            if($i + $j === $a + $b) echo '#';
            else if($i - $j === $a - $b) echo '#';
            else echo '.';
        }
        echo "\n";
    }
}

main();