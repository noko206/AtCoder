<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($a, $b) = ints();

	// 積が偶数の場合
	if (($a * $b) % 2 === 0) {
		o('Even');
	}
	// 積が奇数の場合
	else {
		o('Odd');
	}
}

main();