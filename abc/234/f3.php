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

	private $fact	= [];			// a!
	private $ifact	= [];			// (a!)^(-1)
	private $mod	= 1000000007;	// 法とする数

	/**
	 * a!と(a!)^(-1)をmodで割った余りを求めておく
	 * 計算量：O(n+log(mod))
	 * @param int $n n!まで作成
	 * @param int $mod 法とする数
	 */
	public function __construct($n, $mod) {
		$this->mod = $mod;
		$this->fact[0] = 1;
		for ($i = 1; $i <= $n; ++$i) {
			$this->fact[$i] = $this->fact[$i - 1] * $i;
			$this->fact[$i] %= $this->mod;
		}
		$this->ifact[$n] = self::inverse($this->fact[$n], $this->mod);
		for ($i = $n; $i >= 1; --$i) {
			$this->ifact[$i - 1] = $this->ifact[$i] * $i;
			$this->ifact[$i - 1] %= $this->mod;
		}
	}

	/**
	 * nCkをmodで割った余りを取得
	 * 計算量：O(1)
	 * @param int $n n-元
	 * @param int $k k-組み合わせ
	 * @return int nCkをinit時の$modで割った余り
	 */
	public function binom($n, $k) {
		$c = $this->fact[$n] * $this->ifact[$k];
		$c %= $this->mod;
		$c *= $this->ifact[$n - $k];
		$c %= $this->mod;
		return $c;
	}

	/**
	 * n!をmodで割った余りを取得
	 * 計算量：O(1)
	 * @param int $n 階乗
	 * @return int n!をmodで割った余り
	 */
	public function fact($n) {
		return $this->fact[$n];
	}

	/**
	 * (n!)^(-1)をmodで割った余りを取得
	 * 計算量：O(1)
	 * @param int $n 階乗
	 * @return int (n!)^(-1)をmodで割った余り
	 */
	public function ifact($n) {
		return $this->ifact[$n];
	}

	/**
	 * a^nをmodで割った余りを取得
	 * 計算量：O(log(n))
	 * @param int $a 底
	 * @param int $n 指数
	 * @param int $mod 法とする数
	 * @return int a^nをmodで割った余り
	 */
	public static function power($a, $n, $mod) {
		if ($n === 0) return 1;
		if ($n === 1) return $a % $mod;
		if ($n % 2 === 1) return ($a * self::power($a, $n - 1, $mod)) % $mod;
		return pow(self::power($a, $n >> 1, $mod), 2) % $mod;
	}

	/**
	 * modを法とした時のaの逆元を取得
	 * 計算量：O(log(mod))
	 * @param int $a 逆元を求めたい数
	 * @param int $mod 法とする数
	 * @return int modを法とした時のaの逆元
	 */
	public static function inverse($a, $mod) {
		return self::power($a, $mod - 2, $mod);
	}

	/**
	 * c_i=Σ_{j=0}^i(a_j*b_{i-j})である配列cを取得
	 * 計算量：O(n*log(n)+log(mod)) (ただし、n=|a|+|b|)
	 * @param array $a 畳み込みをする配列
	 * @param array $b 畳み込みをする配列
	 * @param int $mod 法とする数
	 * @return array 配列c
	 */
	public static function convolution($a, $b, $mod) {
		$n = count($a);
		$m = count($b);
		if ($n === 0 || $m === 0) {
			return [];
		}

		if (min($n, $m) <= 60) {
			if ($n < $m) {
				[$n, $m] = [$m, $n];
				[$a, $b] = [$b, $a];
			}
			$ans = array_fill(0, $n + $m - 1, 0);
			for ($i = 0; $i < $n; $i++) {
				for ($j = 0; $j < $m; $j++) {
					$ans[$i + $j] += ($a[$i] * $b[$j]) % $mod;
					$ans[$i + $j] %= $mod;
				}
			}
			return $ans;
		}
		$z = 1 << self::ceil_log2($n + $m - 1);
		for ($i = count($a); $i < $z; $i++) {
			$a[$i] = 0;
		}
		for ($i = count($b); $i < $z; $i++) {
			$b[$i] = 0;
		}

		$g = self::primitive_root($mod);
		$es = $ies = $sum_e = array_fill(0, 30, 0);
		$cnt2 = self::NTZ($mod - 1);
		$e = (int)gmp_powm($g, ($mod - 1) >> $cnt2, $mod);
		$ie = (int)gmp_invert($e, $mod);
		for ($i = $cnt2; $i >= 2; $i--) {
			$es[$i - 2] = $e;
			$ies[$i - 2] = $ie;
			$e =  $e * $e % $mod;
			$ie = $ie * $ie % $mod;
		}
		$now = 1;
		for ($i = 0; $i < $cnt2 - 2; $i++) {
			$sum_e[$i] = ($es[$i] * $now) % $mod;
			$now = $now * $ies[$i] % $mod;
		}

		$now = 1;
		for ($i = 0; $i < $cnt2 - 2; $i++) {
			$sum_ie[$i] = ($ies[$i] * $now) % $mod;
			$now = $now * $es[$i] % $mod;
		}

		$a = self::butterfly($a, $sum_e, $mod);

		$b = self::butterfly($b, $sum_e, $mod);
		for ($i = 0; $i < $z; $i++) {
			$a[$i] = $a[$i] * $b[$i] % $mod;
		}
		$a = self::butterfly_inv($a, $sum_ie, $mod);
		$iz = (int)gmp_invert($z, $mod);
		$ans = [];
		for ($i = 0; $i < $n + $m - 1; $i++) {
			$ans[$i] = (($a[$i] + $mod) * $iz) % $mod;

		}
		return $ans;
	}

	private static function butterfly($a, $sum_e, $mod) {
		$n = count($a);
		$h = self::ceil_log2($n);
		$p = 1 << $h;
		$w = 1;
		for ($ph = 1; $ph <= $h; $ph++) {
			$p >>= 1;
			$now = 1;
			$offset = 0;
			$add = 1 << ($h - $ph + 1);
			for ($s = 0; $s < $w; $s++) {
				for ($i = 0; $i < $p; $i++) {

					$a[$i + $offset + $p] =( $a[$i + $offset] - $a[$i + $offset + $p] * $now )% $mod;
					$a[$i + $offset] = ($a[$i + $offset] * 2 - $a[$i + $offset + $p]) % $mod;
				}
				$now = $now * $sum_e[self::NTZ(~($s))] % $mod;
				$offset += $add;
			}
			$w <<= 1;
		}
		return $a;
	}

	private static function butterfly_inv($a, $sum_ie, $mod) {
		$n = count($a);
		$h = self::ceil_log2($n);

		$w = 1 << $h;
		$p = 1;
		for ($ph = $h; $ph >= 1; $ph--) {
			$w >>= 1;
			$inow = 1;
			$offset = 0;
			$add = 1 << ($h - $ph + 1);
			for ($s = 0; $s < $w; $s++) {
				for ($i = 0; $i < $p; $i++) {
					$a[$i + $offset] = ($a[$i + $offset] + $a[$i + $offset + $p])  % $mod;

					$a[$i + $offset + $p] = (($a[$i + $offset] - ($a[$i + $offset + $p]<<1))  * $inow) % $mod;
				}
				$inow = $inow * $sum_ie[self::NTZ(~$s)] % $mod;
				$offset += $add;
			}
			$p <<= 1;
		}
		return $a;
	}

	private static function bit_to_num($bits) {
		$bits = ($bits & 0x55555555) + ($bits >> 1 & 0x55555555);
		$bits = ($bits & 0x33333333) + ($bits >> 2 & 0x33333333);
		$bits = ($bits & 0x0f0f0f0f) + ($bits >> 4 & 0x0f0f0f0f);
		$bits = ($bits & 0x00ff00ff) + ($bits >> 8 & 0x00ff00ff);
		return ($bits & 0x0000ffff) + ($bits >> 16 & 0x0000ffff);
	}

	private static function NTZ($bits) {
		return self::bit_to_num((~$bits) & ($bits - 1));
	}

	public static function primitive_root($m) {
		if ($m === 2) return 1;
		if ($m === 167772161) return 3;
		if ($m === 469762049) return 3;
		if ($m === 754974721) return 11;
		if ($m === 998244353) return 3;
		$divs = array_fill(0, 20, 0);
		$divs[0] = 2;
		$cnt = 1;
		$x = intdiv($m - 1, 2);
		while ($x % 2 === 0) {
			$x >>= 1;
		}
		for ($i = 3; $i * $i <= $x; $i += 2) {
			if ($x % $i === 0) {
				$divs[$cnt++] = $i;
				while ($x % $i === 0) {
					$x /= $i;
				}
			}
		}
		if ($x > 1) {
			$divs[$cnt++] = $x;
		}
		for ($g = 2; ; $g++) {
			$ok = true;
			for ($i = 0; $i < $cnt; $i++) {
				if ((int)gmp_powm($g, intdiv(($m - 1), $divs[$i]), $m) === 1) {
					$ok = false;
					break;
				}
			}
			if ($ok) return $g;
		}
		return 0;
	}

	private function ceil_log2($x) {
		$t = [0xFFFFFFFF00000000,
			0x00000000FFFF0000,
			0x000000000000FF00,
			0x00000000000000F0,
			0x000000000000000C,
			0x0000000000000002];
		$y = ((($x & ($x - 1)) == 0) ? 0 : 1);
		$j = 32;
		foreach ($t as $value) {
			$k = ((($x & $value) == 0) ? 0 : $j);
			$y += $k;
			$x >>= $k;
			$j >>= 1;
		}
		return $y;
	}
}

function main() {

	// 入力
	list($s) = strings();

	// 1. 前処理
	$n = strlen($s);
	$ctoi = array_flip(range('a', 'z'));
	$freq = array_fill(0, 26, 0);
	for ($i = 0; $i < $n; ++$i) {
		++$freq[$ctoi[$s[$i]]];
	}
	$mod_obj = new Mod($n, _MOD);

	// 2. 畳み込み
	$v = [];
	for ($i = 0; $i < 26; ++$i) {
		$c = $freq[$i];
		for ($j = 0; $j <= $c; ++$j) {
			$v[$i][] = $mod_obj->ifact($j);
		}
	}

	$init = [1];
	for ($i = 0; $i < 26; ++$i) {
		$init = Mod::convolution($init, $v[$i], _MOD);
	}

	// 3. 答えを求める
	$ans = 0;
	for ($i = 1; $i <= $n; ++$i) {
		$ans += ($init[$i] * $mod_obj->fact($i)) % _MOD;
		$ans %= _MOD;
	}

	// 出力
	printf("%d\n", $ans);
}
var_dump(Mod::power(2, 4, _MOD));
//main();