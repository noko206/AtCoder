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
	$s = [];
	for ($i = 0; $i < $n; ++$i) {
		list($s[]) = strings();
	}

	// S_N,S_N-1,...,S_1の順番に並び替え
	$ans = array_reverse($s);

	// 出力
	output(...$ans);
}

main();