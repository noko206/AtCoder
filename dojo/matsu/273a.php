<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function f(int $x): int
{
	if ($x === 0) return 1; // 終了条件
	return $x * f($x - 1); // 再帰呼び出し
}

function main()
{
	// 入力
	list($n) = ints();

	// 出力
	output(f($n));
}

main();
