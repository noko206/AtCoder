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
	$a = [];
	$b = [];
	for ($i = 0; $i < $n; ++$i) {
		list($a[], $b[]) = ints();
	}

	// A_i+B_iを計算
	$ans = [];
	for ($i = 0; $i < $n; ++$i) {
		$ans[] = $a[$i] + $b[$i];
	}

	// 出力
	output(...$ans);
}

main();