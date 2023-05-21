<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($r, $c) = ints();
	$a = [];
	for ($i = 0; $i < 2; ++$i) {
		$a[$i] = ints();
	}

	// A_{R,C}を取得
	$ans = $a[$r - 1][$c - 1];

	// 出力
	output($ans);
}

main();
