<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $m) = ints();
	$a = ints();
	$b = ints();

	// 総得点を計算
	$ans = 0;
	for ($i = 0; $i < $n; ++$i) {
		$ans += $a[$b[$i] - 1];
	}

	// 出力
	output($ans);
}

main();
