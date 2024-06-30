<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

/**
 * 逆元を拡張ユークリッドの互除法で計算
 *
 * @param int $val
 * @param int $mod
 * @return int
 */
function invMod(int $val, int $mod): int
{
	$val %= $mod;
	if ($val < 0) {
		$val += $mod;
	}
	$a = $val;
	$b = $mod;
	$u = 1;
	$v = 0;
	while ($b) {
		$t = intdiv($a, $b);
		$a -= $t * $b;
		list($a, $b) = [$b, $a];
		$u -= $t * $v;
		list($u, $v) = [$v, $u];
	}
	return (($u % $mod) + $mod) % $mod;
}

function f(int $j, int $l): int
{
	static $fact, $ifact;
	if (!isset($fact, $ifact)) {
		$fact[0] = 1;
		for ($i = 0; $i < 1000; ++$i) {
			$fact[$i + 1] = $fact[$i] * ($i + 1);
			$fact[$i + 1] %= 998244353;
		}
		for ($i = 0; $i <= 1000; ++$i) {
			$ifact[$i] = invMod($fact[$i], 998244353);
		}
	}
	assert($j + $l <= 1000);
	$ans = $fact[$j + $l];
	$ans *= $ifact[$j];
	$ans %= 998244353;
	$ans *= $ifact[$l];
	$ans %= 998244353;
	return $ans;
}

function main()
{
	[$k] = ints();
	$c = ints();
	$dp = array_fill(0, 27, array_fill(0, $k + 1, 0));
	$dp[0][0] = 1;
	for ($i = 0; $i < 26; ++$i) {
		for ($j = 0; $j <= $c[$i]; ++$j) {
			for ($l = 0; $l <= $k; ++$l) {
				if ($j + $l > $k) {
					break;
				}
				$tmp = f($j, $l) * $dp[$i][$l];
				$tmp %= 998244353;
				$dp[$i + 1][$j + $l] += $tmp;
				$dp[$i + 1][$j + $l] %= 998244353;
			}
		}
	}
	$ans = 0;
	for ($i = 1; $i <= $k; ++$i) {
		$ans += $dp[26][$i];
		$ans %= 998244353;
	}
	output($ans);
}

main();
