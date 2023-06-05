<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }
function chmin(&$a, $b) { if ($a > $b) { $a = $b; return true; } return false; }

const INF32 = 1001001001;

function main()
{
	// 入力
	list($n) = ints();
	$x = [];
	$y = [];
	$z = [];
	for ($i = 0; $i < $n; ++$i) {
		list($x[], $y[], $z[]) = ints();
	}

	// bitDP
	$dp = array_fill(0, 1 << $n, array_fill(0, $n, INF32));
	$dp[1][0] = 0; // 都市1からスタート
	for ($i = 0; $i < (1 << $n); ++$i) {
		for ($j = 0; $j < $n; ++$j) {
			// 都市jに訪れたことがなければ何もしない
			if (!($i & (1 << $j))) continue;
			// 都市jに訪れることができないなら何もしない
			if ($dp[$i][$j] === INF32) continue;
			for ($k = 0; $k < $n; ++$k) {
				// 都市kに訪れたことがあれば何もしない
				if ($k & (1 << $k)) continue;
				$cost = abs($x[$j] - $x[$k]) + abs($y[$j] - $y[$k]) + max(0, $z[$k] - $z[$j]);
				chmin($dp[$i | (1 << $k)][$k], $dp[$i][$j] + $cost);
			}
		}
	}

	// 出力
	output($dp[(1 << $n) - 1][0]);
}

main();
