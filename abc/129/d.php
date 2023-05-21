<?php

// 設定
ini_set('memory_limit', '512M');

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

// 定数
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

function main() {

	// 入力
	list($h, $w) = ints();
	$s = [];
	for ($i = 0; $i < $h; ++$i) {
		list($s[]) = strings();
	}

	// 1. 整形
	for ($i = 0; $i < $h; ++$i) {
		$s[$i] .= '#'; // 例外を作りたくないので、右側に障害物を置く
	}
	$s[] = str_repeat('#', $w + 1); // 例外を作りたくないので、下側に障害物を置く
	$cnt = array_fill(0, $h, array_fill(0, $w, -1)); // 重複分を先に引いておく

	// 2. 横方向
	for ($i = 0; $i < $h; ++$i) {
		$tot = 0;
		for ($j = 0; $j <= $w; ++$j) {
			// 障害物なし
			if ($s[$i][$j] === '.') {
				++$tot;
			}
			// 障害物あり
			else {
				// 障害物と障害物の間にあるマスの数を加算
				for ($k = 1; $k <= $tot; ++$k) {
					$cnt[$i][$j - $k] += $tot;
				}
				$tot = 0;
			}
		}
	}

	// 3. 縦方向
	for ($j = 0; $j < $w; ++$j) {
		$tot = 0;
		for ($i = 0; $i <= $h; ++$i) {
			// 障害物なし
			if ($s[$i][$j] === '.') {
				++$tot;
			}
			// 障害物あり
			else {
				// 障害物と障害物の間にあるマスの数を加算
				for ($k = 1; $k <= $tot; ++$k) {
					$cnt[$i - $k][$j] += $tot;
				}
				$tot = 0;
			}
		}
	}

	// 4. 最大値を求める
	$ans = 0;
	for ($i = 0; $i < $h; ++$i) {
		for ($j = 0; $j < $w; ++$j) {
			// 明かりを置けるのは障害物のないマスだけ
			if ($s[$i][$j] === '.') {
				chmax($ans, $cnt[$i][$j]);
			}
		}
	}

	// 出力
	printf("%d\n", $ans);
}

main();