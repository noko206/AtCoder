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
// const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _DIF = [[0, 1], [1, 0]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    list($h, $w) = ints();

    $c = [];
    for($i = 0; $i < $h; ++$i)
    {
        list($c[]) = strings();
    }

    $q = new SplQueue;
    $q->enqueue([0, 0]); // 0-indexedのスタート地点のマス

    $cnt = array_fill(0, $h, array_fill(0, $w, 0)); // 通ることのできるマスの数
    $cnt[0][0] = 1;
    
    $ans = 1;

    while(!$q->isEmpty())
    {
        list($y, $x) = $q->dequeue();

        foreach(_DIF as list($dy, $dx))
        {
            $ny = $y + $dy;
            $nx = $x + $dx;

            if($ny >= $h || $nx >= $w) continue;
            if($c[$ny][$nx] === '#') continue;
            if($cnt[$ny][$nx] !== 0) continue;

            $cnt[$ny][$nx] = $cnt[$y][$x] + 1;
            chmax($ans, $cnt[$ny][$nx]);

            $q->enqueue([$ny, $nx]);
        }
    }

    printf("%d\n", $ans);
}

main();