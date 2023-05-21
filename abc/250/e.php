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
function lower_bound($a, $x) { $ng = -1; $ok = count($a); while($ok - $ng !== 1) { $mid = intdiv($ok + $ng, 2); if($a[$mid] >= $x) $ok = $mid; else $ng = $mid; } return $ok; }
function upper_bound($a, $x) { $ng = -1; $ok = count($a); while($ok - $ng !== 1) { $mid = intdiv($ok + $ng, 2); if($a[$mid] > $x) $ok = $mid; else $ng = $mid; } return $ok; }

const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

function main() {

	// 入力
	list($n) = ints();
	$a = ints();
	$b = ints();
	list($q) = ints();
	$x = [];
	$y = [];
	for ($i = 0; $i < $q; ++$i) {
		list($x[$i], $y[$i]) = ints();
		--$x[$i]; --$y[$i]; // 0-indexed
	}

	// 1. 前処理①
	$mapA = [];
	$mapB = [];
	$cntA = [];
	$cntB = [];
	for ($i = 0; $i < $n; ++$i) {
		$mapA[$a[$i]] = true;
		$mapB[$b[$i]] = true;
		$cntA[] = count($mapA);
		$cntB[] = count($mapB);
	}

	// 2. 前処理②
	$numA = array_keys($mapA); // 並び順が維持されるので
	$numB = array_keys($mapB); // 同上
	$m = min(count($numA), count($numB));
	$st = [];
	$check = array_fill(0, $n, false);
	for ($i = 0; $i < $m; ++$i) {
		foreach ([$numA[$i], $numB[$i]] as $v) {
			if (isset($st[$v])) {
				unset($st[$v]);
			}
			else {
				$st[$v] = true;
			}
		}
		if (count($st) === 0) {
			$check[$i] = true;
		}
	}

	// 3. クエリの処理
	$ans = [];
	for ($i = 0; $i < $q; ++$i) {
		if ($cntA[$x[$i]] === $cntB[$y[$i]] && $check[$cntA[$x[$i]] - 1]) {
			$ans[$i] = true;
		}
		else {
			$ans[$i] = false;
		}
	}

	// 出力
	foreach ($ans as $is_ok) {
		printf("%s\n", $is_ok ? 'Yes' : 'No');
	}
}

main();