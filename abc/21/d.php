<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

class Modint
{
	public const MOD998244353  = 998244353;
	public const MOD1000000007 = 1000000007;

	private const MOD_MIN = 1;
	private const MOD_MAX = 2000001000;

	/** @var int mod */
	private $mod;

	/**
	 * プロパティの初期化｜計算量:O(1)
	 * @param int $mod mod
	 */
	public function __construct(int $mod)
	{
		assert(self::MOD_MIN <= $mod && $mod <= self::MOD_MAX);
		$this->mod = $mod;
	}

	/**
	 * modを取得｜計算量:O(1)
	 * @return int mod
	 */
	public function get_mod(): int
	{
		return $this->mod;
	}

	/**
	 * 加算｜計算量:O(|vals|)
	 * @param int $vals 加算する値
	 * @return int 計算結果
	 */
	public function add(int ...$vals): int
	{
		$ans = 0;
		foreach ($vals as $val) {
			$val = (($val % $this->mod) + $this->mod) % $this->mod; // valが負,mod以上のときを考慮
			$ans = ($ans + $val) % $this->mod;
		}
		return $ans;
	}

	/**
	 * 減算｜計算量:O(|vals|)
	 * @param int $target 減算される値
	 * @param int $vals 減算する値
	 * @return int 計算結果
	 */
	public function sub(int $target, int ...$vals): int
	{
		$ans = (($target % $this->mod) + $this->mod) % $this->mod; // targetが負,mod以上のときを考慮
		foreach ($vals as $val) {
			$val %= $this->mod;
			$ans = ((($ans - $val) % $this->mod) + $this->mod) % $this->mod;
		}
		return $ans;
	}

	/**
	 * 乗算｜計算量:O(|$vals|)
	 * @param int $vals 乗算する値
	 * @return int 計算結果
	 */
	public function mul(int ...$vals): int
	{
		$ans = 1;
		foreach ($vals as $val) {
			$val = (($val % $this->mod) + $this->mod) % $this->mod; // valが負,mod以上のときを考慮
			$ans = ($ans * $val) % $this->mod;
		}
		return $ans;
	}

	/**
	 * 除算｜計算量:O(|$vals|log mod)
	 * @param int $target 除算される値
	 * @param int $vals 除算する値
	 * @return int 計算結果
	 */
	public function div(int $target, int ...$vals): int
	{
		$ans = (($target % $this->mod) + $this->mod) % $this->mod; // targetが負,mod以上のときを考慮
		foreach ($vals as $val) {
			$ans = ($ans * self::inv($val)) % $this->mod;
		}
		return $ans;
	}

	/**
	 * 累乗を繰り返し二乗法で計算｜計算量:O(log $exp)
	 * @param int $val 底
	 * @param int $exp 指数
	 * @return int 計算結果
	 */
	public function pow(int $val, int $exp): int
	{
		assert($exp >= 0);
		$val = (($val % $this->mod) + $this->mod) % $this->mod; // valが負,mod以上のときを考慮
		$pow = function ($val, $exp) use (&$pow) {
			if ($exp === 0) return 1;
			if ($exp === 1) return $val % $this->mod;
			if ($exp % 2 === 1) return ($val * $pow($val, $exp - 1, $this->mod)) % $this->mod;
			return pow($pow($val, $exp >> 1, $this->mod), 2) % $this->mod;
		};
		return $pow($val, $exp);
	}

	/**
	 * 逆元を拡張ユークリッドの互除法で計算｜計算量:O(log mod)
	 * @param int $val 逆元を求めたい値
	 * @return int 計算結果
	 */
	public function inv(int $val): int
	{
		$val = (($val % $this->mod) + $this->mod) % $this->mod; // valが負,mod以上のときを考慮
		list($a, $b, $u, $v) = [$val, $this->mod, 1, 0];
		while ($b) {
			$t = intdiv($a, $b);
			$a -= $t * $b;
			list($a, $b) = [$b, $a];
			$u -= $t * $v;
			list($u, $v) = [$v, $u];
		}
		return (($u % $this->mod) + $this->mod) % $this->mod;
	}

	/**
	 * 加算(参照渡しver)｜計算量:O(|vals|)
	 * @param int &$target 加算される値
	 * @param int $vals 加算する値
	 * @return int 計算結果
	 */
	public function chadd(int &$target, int ...$vals): int
	{
		return $target = $this->add($target, ...$vals);
	}

	/**
	 * 減算(参照渡しver)｜計算量:O(|vals|)
	 * @param int &$target 減算される値
	 * @param int $vals 減算する値
	 * @return int 計算結果
	 */
	public function chsub(int &$target, int ...$vals): int
	{
		return $target = $this->sub($target, ...$vals);
	}

	/**
	 * 乗算(参照渡しver)｜計算量:O(|$vals|)
	 * @param int &$target 乗算される値
	 * @param int $vals 乗算する値
	 * @return int 計算結果
	 */
	public function chmul(int &$target, int ...$vals): int
	{
		return $target = $this->mul($target, ...$vals);
	}

	/**
	 * 除算(参照渡しver)｜計算量:O(|$vals|log mod)
	 * @param int &$target 割られる値
	 * @param int $vals 割る値
	 * @return int 計算結果
	 */
	public function chdiv(int &$target, int ...$vals): int
	{
		return $target = $this->div($target, ...$vals);
	}

	/**
	 * 累乗を繰り返し二乗法で計算(参照渡しver)｜計算量:O(log $exp)
	 * @param int &$val 底
	 * @param int $exp 指数
	 * @return int 計算結果
	 */
	public function chpow(int &$val, int $exp): int
	{
		return $val = $this->pow($val, $exp);
	}

	/**
	 * 逆元を拡張ユークリッドの互除法で計算(参照渡しver)｜計算量:O(log mod)
	 * @param int &$val 逆元を求めたい値
	 * @return int 計算結果
	 */
	public function chinv(int &$val): int
	{
		return $val = $this->inv($val);
	}
}

function main()
{
	// 入力
	list($n) = ints();
	list($k) = ints();

	// modint
	$modint = new Modint(Modint::MOD1000000007);

	// dp
	$dp = array_fill(0, $k + 1, array_fill(0, $n, 0));
	$dp[0][0] = 1;
	for ($i = 0; $i < $k; ++$i) {
		for ($j = 0; $j < $n; ++$j) {
			$dp[$i + 1][$j] = $dp[$i][$j];
		}
		// 累積和
		for ($j = 0; $j < $n - 1; ++$j) {
			$modint->chadd($dp[$i + 1][$j + 1], $dp[$i + 1][$j]);
		}
	}

	// ansを計算
	$ans = $modint->add(...$dp[$k]);

	// 出力
	output($ans);
}

main();