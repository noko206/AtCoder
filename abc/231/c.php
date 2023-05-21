<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function chmax(&$a, $b) { if($a < $b) { $a = $b; return true; } return false; }
function chmin(&$a, $b) { if($a > $b) { $a = $b; return true; } return false; }
function gcd($a, $b) { return ($a % $b) ? gcd($b, $a % $b) : $b; }
function lcm($a, $b) { return intdiv($a, gcd($a, $b)) * $b; }
function swap(&$a, &$b) { list($a, $b) = [$b, $a]; }
function sub_sort(&$a, $i, $j) { $b = array_slice($a, $i, $j - $i); sort($b); foreach($b as $k => $v){ $a[$k + $i] = $v; }}
function sub_reverse(&$a, $i, $j) { $b = array_slice($a, $i, $j - $i); foreach(array_reverse($b) as $k => $v){ $a[$k + $i] = $v; }}
function next_permutation(&$a) { $n = count($a); for($i = $n - 2; $i >= 0; --$i) { if($a[$i] < $a[$i + 1]){ for($j = $n - 1;; --$j){ if($a[$i] < $a[$j]){ swap($a[$i], $a[$j]); sub_reverse($a, $i + 1, $n); return true; }}}} return false; }
function __builtin_popcount($i) { if($i){ return ($i & 1) + __builtin_popcount($i >> 1); } return 0; }
function mod_power($a, $n, $m) { if($n === 0) return 1; if($n === 1) return $a % $m; if($n % 2 === 1) return ($a * mod_power($a, $n - 1, $m)) % $m; return pow(mod_power($a, $n >> 1, $m), 2) % $m;}
function mod_inverse($a, $m) { $b = $m; $u = 1; $v = 0; while($b){ $t = intdiv($a, $b); $a -= $t * $b; swap($a, $b); $u -= $t * $v; swap($u, $v); } $u += $m; return $u % $m; }
function mod_combination($a, $b, $m) { $t = 1; for($i = 0; $i < $b; ++$i){ $t *= $a - $i; $t %= $m; $t *= mod_inverse($i + 1, $m); $t %= $m; } return $t; }
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    list($n, $q) = ints();
    $a = ints();
    
    sort($a);

    $ans = [];

    for($i = 0; $i < $q; ++$i)
    {
        list($x) = ints();

        $ok = $n;
        $ng = -1;

        while($ok - $ng != 1)
        {
            $mid = intdiv($ok + $ng, 2);

            if($a[$mid] >= $x)
            {
                $ok = $mid;
            }
            else
            {
                $ng = $mid;
            }
        }

        $ans[] = $n - $ok;
    }

    foreach($ans as $v)
    {
        printf("%d\n", $v);
    }
}

main();