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
const _MOD = 998244353;

class Mod {

	private $fact	= [];	// a!
	private $ifact	= [];	// (a!)^(-1)

	/**
	 * a!と(a!)^(-1)をmodで割った余りを求めておく
	 * @param int $n n!まで作成
	 * @param int $mod 法とする数
	 */
	public function init($n, $mod) {
		$this->fact[0] = 1;
		for ($i = 1; $i <= $n; ++$i) {
			$this->fact[$i] = $this->fact[$i - 1] * $i;
			$this->fact[$i] %= $mod;
		}
		$this->ifact[$n] = $this->mod_inverse($this->fact[$n], $mod);
		for ($i = $n; $i >= 1; --$i) {
			$this->ifact[$i - 1] = $this->ifact[$i] * $i;
			$this->ifact[$i - 1] %= $mod;
		}
	}

	/**
	 * nCkをmodで割った余りを取得（事前にinitを呼ぶ必要あり）
	 * @param int $n n-元
	 * @param int $k k-組み合わせ
	 * @param int $mod 法とする数（init時と同じ値にする）
	 * @return int nCkをinit時の$modで割った余り
	 */
	public function binom($n, $k, $mod) {
		if ($k < 0 || $k > $n) return 0;
		$c = $this->fact[$n] * $this->ifact[$k];
		$c %= $mod;
		$c *= $this->ifact[$n - $k];
		$c %= $mod;
		return $c;
	}

	/**
	 * a^nをmodで割った余りを取得
	 * @param int $a 底
	 * @param int $n 指数
	 * @param int $mod 法とする数
	 * @return int a^nをmodで割った余り
	 */
	public function mod_power($a, $n, $mod) {
		if ($n === 0) return 1;
		if ($n === 1) return $a % $mod;
		if ($n % 2 === 1) return ($a * $this->mod_power($a, $n - 1, $mod)) % $mod;
		return pow($this->mod_power($a, $n >> 1, $mod), 2) % $mod;
	}

	/**
	 * modを法とした時のaの逆元を取得
	 * @param int $a 逆元を求めたい数
	 * @param int $mod 法とする数
	 * @return int modを法とした時のaの逆元
	 */
	public function mod_inverse($a, $mod) {
		$b = $mod;
		$u = 1;
		$v = 0;
		while ($b > 0) {
			$t = intdiv($a, $b);
			$a -= $t * $b;
			$u -= $t * $v;
			list($a, $b) = [$b, $a];
			list($u, $v) = [$v, $u];
		}
		return ($u + $mod) % $mod;
	}
}

function main() {

	// 入力
	list($s) = strings();

	// 1. 文字種別に数を求める
	$n = strlen($s);
	$ctoi = array_flip(range('a', 'z'));
	$freq = array_fill(0, 26, 0);
	for ($i = 0; $i < $n; ++$i) {
		++$freq[$ctoi[$s[$i]]];
	}

	// 2. 初期化
	$dp = array_fill(0, 27, array_fill(0, $n + 1, 0));
	$dp[0][0] = 1;
	$mod_obj = new Mod;
	$mod_obj->init($n, _MOD);

	// 3. DP
	for ($i = 0; $i < 26; ++$i) {
		for ($j = 0; $j <= $n; ++$j) {
			for ($k = 0; $k <= min($j, $freq[$i]); ++$k) {
				$dp[$i + 1][$j] += $dp[$i][$j - $k] * $mod_obj->binom($j, $k, _MOD);
				$dp[$i + 1][$j] %= _MOD;
			}
		}
	}

	// 4. 答えを求める
	$ans = 0;
	for ($i = 1; $i <= $n; ++$i) {
		$ans += $dp[26][$i];
		$ans %= _MOD;
	}

	// 出力
	printf("%d\n", $ans);
}

main();