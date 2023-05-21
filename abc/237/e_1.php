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
function run_length_encode($s) { $n = strlen($s); $t = ''; $a = []; $j = -1; for($i = 0; $i < $n; ++$i){ if($t !== $s[$i]) { ++$j; $t = $s[$i]; $a[$j] = [$t, 1]; } else { ++$a[$j][1]; }} return $a; }
function run_length_decode($a) { $s = ''; foreach($a as $v){ for($i = 0; $i < $v[1]; ++$i){ $s .= $v[0]; }} return $s; }
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    list($n, $m) = ints();
    $h = ints();

    $G = array_fill(0, $n, []);
    for($i = 0; $i < $m; ++$i)
    {
        list($u, $v) = ints();

        --$u;
        --$v;

        $G[$u][] = $v;
        $G[$v][] = $u;
    }

    $pq = new SplPriorityQueue;
    $pq->setExtractFlags(SplPriorityQueue::EXTR_BOTH);
    $pq->insert(0, 0);

    $dist = array_fill(0, $n, _LLINF);
    $dist[0] = 0;

    while($pq->count() > 0)
    {
        $x = $pq->extract();
        $v = $x['data'];
        $d = - $x['priority'];

        if($dist[$v] < $d)
        {
            continue;
        }

        foreach($G[$v] as $u)
        {
            if(chmin($dist[$u], $dist[$v] + max(0, $h[$u] - $h[$v])))
            {
                $pq->insert($u, - $dist[$u]);
            }
        }
    }

    $ans = -_LLINF;

    for($i = 0; $i < $n; ++$i)
    {
        chmax($ans, $h[0] - $h[$i] - $dist[$i]);
    }

    printf("%d\n", $ans);
}

main();