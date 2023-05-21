<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $x) = ints();
	$a = ints();

	// N個の商品の合計金額を計算
	$sum = 0;
	for ($i = 0; $i < $n; ++$i) {
		if ($i % 2 === 1) {
			$sum += $a[$i] - 1; // 1円引き
		} else {
			$sum += $a[$i];
		}
	}

	// X≧sumならN個の商品を全て買うことができる
	if ($x >= $sum) {
		output('Yes');
	} else {
		output('No');
	}
}

main();
