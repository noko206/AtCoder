<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n) = ints();

	// 出題される問題数を計算
	$ans = 0;
	if ($n <= 125) {
		$ans = 4;
	} elseif ($n <= 211) {
		$ans = 6;
	} else {
		$ans = 8;
	}

	// 出力
	output($ans);
}

main();
