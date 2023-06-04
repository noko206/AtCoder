<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

const INF64 = 1001001001001001001;

function chmin(&$a, $b) {
	if ($a > $b) {
		$a = $b;
		return true;
	}
	return false;
}

function main()
{
	// 入力
	list($n) = ints();
	$h = ints();

	// DP
	$dp = array_fill(0, $n, INF64); // 足場iに辿り着くまでに支払うコストの総和の最小値
	$dp[0] = 0;
	for ($i = 0; $i < $n; ++$i) {
		if ($i + 1 < $n) chmin($dp[$i + 1], $dp[$i] + abs($h[$i + 1] - $h[$i])); // 足場i->i+1にジャンプ
		if ($i + 2 < $n) chmin($dp[$i + 2], $dp[$i] + abs($h[$i + 2] - $h[$i])); // 足場i->i+2にジャンプ
	}

	// 出力
	output($dp[$n - 1]);
}

main();
