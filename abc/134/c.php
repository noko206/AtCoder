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
	for ($i = 0; $i < $n; ++$i) {
		list($a[]) = ints();
	}

	// 1,2番目に大きい値を取得
	$sorted_a = $a;
	sort($sorted_a);
	$first = $sorted_a[$n - 1];
	$second = $sorted_a[$n - 2];

	// 答えを計算
	$ans = [];
	foreach ($a as $v) {
		if ($v === $first) {
			$ans[] = $second;
		} else {
			$ans[] = $first;
		}
	}

	// 出力
	output(...$ans);
}

main();
