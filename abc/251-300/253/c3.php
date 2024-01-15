<?php

// 設定
ini_set('memory_limit', '-1');

// 自作関数
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
function compress ($a) { $a = array_flip($a); ksort($a); $i = 0; foreach ($a as $k => $_) { $a[$k] = $i++; } return $a; }

// 定数
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

class BinaryIndexedTree {
	private $n;
	private $bit;

	public function __construct($n) {
		$this->n = $n + 1;
		$this->bit = array_fill(0, $n, 0);
	}

	public function add($idx, $x) {
		for ($i = $idx; $i < $this->n; $i += ($i & -$i)) {
			$this->bit[$i] += $x;
		}
	}

	public function sum($idx) {
		$sum = 0;
		for ($i = $idx; $i > 0; $i -= ($i & -$i)) {
			$sum += $this->bit[$i];
		}
		return $sum;
	}

	private function count_lower($x) {
		if ($x <= 0) return 0;
		$k = 0;
		$idx = 1;
		while ($idx < $this->n) $idx <<= 1;
		for ($i = $idx; $i > 0; $i >>= 1) {
			if ($k + $i < $this->n && $this->bit[$k + $i] < $x) {
				$x -= $this->bit[$k + $i];
				$k += $i;
			}
		}
		return $k + 1;
	}

	public function lower_bound($x) {
		return $this->count_lower($x);
	}

	public function upper_bound($x) {
		return $this->count_lower($x + 1);
	}

	public function test($x) {
		$k = 0;
		$idx = 1;
		while ($idx < $this->n) $idx <<= 1;
		for ($i = $idx; $i > 0; $i >>= 1) {
			if ($k + $i < $this->n && $this->bit[$k + $i] > $x) {
				$x -= $this->bit[$k + $i];
				$k += $i;
			}
		}
		return $k + 1;
	}
}

function main() {

	// 入力
	list($q) = ints();
	$query = [];
	while ($q--) {
		$query[] = ints();
	}

	// 1. 座標圧縮
	$a = [];
	foreach ($query as $v) {
		if ($v[0] !== 3) {
			$a[] = $v[1];
		}
	}
	$compress = compress($a);
	$compress = array_map(function ($v) { return ++$v; }, $compress);
	$decompress = array_flip($compress);

	// 2. シミュレーション
	$n = count($compress);
	$bit = new BinaryIndexedTree($n);
	$ans = [];
	foreach ($query as $v) {
		if ($v[0] === 1) {
			list($_, $x) = $v;
			$bit->add($compress[$x], 1);
		}
		if ($v[0] === 2) {
			list($_, $x, $c) = $v;
			chmin($c, $bit->sum($compress[$x]) - $bit->sum($compress[$x] - 1)); // $cを小さい方に更新
			$bit->add($compress[$x], (-1) * $c);
		}
		if ($v[0] === 3) {
			$size = $bit->sum($n);
			$max = $bit->lower_bound($size);
			$min = $bit->lower_bound(1);
			$ans[] = $decompress[$max] - $decompress[$min];
		}
	}

	// 出力
	foreach ($ans as $v) {
		printf("%d\n", $v);
	}
}

main();