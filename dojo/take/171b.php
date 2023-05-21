<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $k) = ints();
	$p = ints();

	// ソートして価格が小さい果物K種類の合計金額を計算
	sort($p);
	$ans = 0;
	for ($i = 0; $i < $k; ++$i) {
		$ans += $p[$i];
	}

	// 出力
	output($ans);
}

main();
