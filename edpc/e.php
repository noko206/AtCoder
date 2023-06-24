<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

const INF64 = 1001001001001001001;
const VALUE_MAX = 100000;

function main()
{
	// 入力
	list($n, $w) = ints();
	$weight = [];
	$value = [];
	for ($i = 0; $i < $n; ++$i) {
		list($weight[], $value[]) = ints();
	}

	// dp[i][j]:=i番目までの品物のうち、価値の総和がjとなる重さの総和の最小値
	$dp = array_fill(0, $n + 1, array_fill(0, VALUE_MAX + 1, INF64));
	$dp[0][0] = 0;
	for ($i = 0; $i < $n; ++$i) {
		for ($j = 0; $j <= VALUE_MAX; ++$j) {
			if ($j - $value[$i] >= 0) {
				// 品物iを選んで価値の総和をjにできる場合
				$dp[$i + 1][$j] = min($dp[$i][$j], $dp[$i][$j - $value[$i]] + $weight[$i]);
			} else {
				$dp[$i + 1][$j] = $dp[$i][$j];
			}
		}
	}

	// 答えを計算
	$ans = 0;
	for ($i = 0; $i <= VALUE_MAX; ++$i) {
		if ($dp[$n][$i] <= $w) {
			$ans = max($ans, $i);
		}
	}

	// 出力
	output($ans);

	for ($i = 0; $i <= $n; ++$i) {
		for ($j = 0; $j <= 6; ++$j) echo $dp[$i][$j], ' ';
		echo PHP_EOL;
	}
}

main();
