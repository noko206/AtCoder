<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($a, $b) = ints();

	// 生成された金属を判定
	$ans = '';
	if ($b === 0) {
		$ans = 'Gold';
	} elseif ($a === 0) {
		$ans = 'Silver';
	} else {
		$ans = 'Alloy';
	}

	// 出力
	output($ans);
}

main();
