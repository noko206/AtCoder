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
function mod_multi_combination($a, $b, $m) { if($a === 0 && $b === 0) return 1; if($a <= 0 || $b < 0) return 0; return mod_combination($a + $b - 1, $b, $m); }
function run_length_encode($s) { $n = strlen($s); $t = ''; $a = []; $j = -1; for($i = 0; $i < $n; ++$i){ if($t !== $s[$i]) { ++$j; $t = $s[$i]; $a[$j] = [$t, 1]; } else { ++$a[$j][1]; }} return $a; }
function run_length_decode($a) { $s = ''; foreach($a as $v){ for($i = 0; $i < $v[1]; ++$i){ $s .= $v[0]; }} return $s; }
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    list($n, $m) = ints();

    $takahashi = array_fill(0, $n, array_fill(0, $n, false)); // ボールの連結情報を格納した行列
    $aoki = array_fill(0, $n, array_fill(0, $n, false)); // ボールの連結情報を格納した行列

    for($i = 0; $i < $m; ++$i)
    {
        list($a, $b) = ints();

        --$a; --$b; // 0-indexedにする

        $takahashi[$a][$b] = true;
        $takahashi[$b][$a] = true;
    }

    for($i = 0; $i < $m; ++$i)
    {
        list($c, $d) = ints();

        --$c; --$d; // 0-indexedにする

        $aoki[$c][$d] = true;
        $aoki[$d][$c] = true;
    }

    $p = range(0, $n - 1);
    $is_ok = false;

    do
    {
        $is_same = true;

        for($i = 0; $i < $n; ++$i)
        {
            for($j = 0; $j < $n; ++$j)
            {
                if($takahashi[$i][$j] !== $aoki[$p[$i]][$p[$j]])
                {
                    $is_same = false;
                }
            }
        }

        if($is_same)
        {
            $is_ok = true;
            break;
        }
    }
    while(next_permutation($p));

    printf("%s\n", $is_ok ? 'Yes' : 'No');
}

main();