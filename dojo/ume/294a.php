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
	$a = ints();

	// Aから偶数だけ取り出す
	$ans = [];
	foreach ($a as $v) {
		if ($v % 2 === 0) {
			$ans[] = $v;
		}
	}

	// 出力
	output(...$ans);
}

main();