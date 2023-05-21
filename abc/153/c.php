<?php

// 設定
ini_set('memory_limit', '-1');

// 自作関数
function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o($a) { if(is_array($a)) { foreach ($a ?? [] as $v) { echo $v, "\n"; }} else { echo $a, "\n"; }}
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
function lower_bound($a, $x) { $ng = -1; $ok = count($a); while($ok - $ng !== 1) { $mid = intdiv($ok + $ng, 2); if($a[$mid] >= $x) $ok = $mid; else $ng = $mid; } return $ok; }
function upper_bound($a, $x) { $ng = -1; $ok = count($a); while($ok - $ng !== 1) { $mid = intdiv($ok + $ng, 2); if($a[$mid] > $x) $ok = $mid; else $ng = $mid; } return $ok; }
function compress($a) { $a = array_flip($a); ksort($a); $i = 0; foreach ($a as $k => $_) { $a[$k] = $i++; } return $a; }
function eratosthenes($n) { $a = array_fill(0, $n + 1, true); $a[0] = false; $a[1] = false; for($i = 2; $i <= $n; ++$i) { if(!$a[$i]) continue; for($j = $i * 2; $j <= $n; $j += $i) { $a[$j] = false; }} return $a; }
function divisor($n) { $a = []; for($i = 1; $i * $i <= $n; ++$i) { if($n % $i === 0) { $a[] = $i; $j = intdiv($n, $i); if($j !== $i) $a[] = $j; }} sort($a); return $a; }
function is_prime($n) { if($n === 1 || $n === 0) return false; for($i = 2; $i * $i <= $n; ++$i) { if($n % $i === 0) return false; } return true; }
function prime_factorize($n) { $a = []; for($i = 2; $i * $i <= $n; ++$i) { if($n % $i !== 0) continue; $ex = 0; while($n % $i === 0) { ++$ex; $n = intdiv($n, $i); } $a[] = [$i, $ex]; } if($n !== 1) $a[] = [$n, 1]; return $a; }

// 定数
const DIF4 = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const DIF8 = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]];
const INF32 = 1001001001;
const INF64 = 1001001001001001001;
const MOD1000000007 = 1000000007;
const MOD998244353 = 998244353;

function main() {

	// 入力
	list($n, $k) = ints();
	$h = ints();

	// メイン処理
	rsort($h);
	$ans = 0;
	for ($i = 0; $i < $n; ++$i) {
		if ($k > 0) {
			--$k;
			continue;
		}
		$ans += $h[$i];
	}

	// 出力
	o($ans);
}

main();