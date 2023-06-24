<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $w) = ints();
	$weight = [];
	$value = [];
	for ($i = 0; $i < $n; ++$i) {
		list($weight[], $value[]) = ints();
	}

	// dp[i][j]:=i番目までの品物のうち、重さの総和がjとなる価値の総和の最大値
	$dp = array_fill(0, $n + 1, array_fill(0, $w + 1, 0));
	for ($i = 0; $i < $n; ++$i) {
		for ($j = 0; $j <= $w; ++$j) {
			if ($j - $weight[$i] >= 0) {
				// 品物iを選んで重さの総和をj以下にできる場合
				$dp[$i + 1][$j] = max($dp[$i][$j], $dp[$i][$j - $weight[$i]] + $value[$i]);
			} else {
				$dp[$i + 1][$j] = $dp[$i][$j];
			}
		}
	}

	// 出力
	output($dp[$n][$w]);
}

main();
