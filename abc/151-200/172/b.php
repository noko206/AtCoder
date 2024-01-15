<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($s) = strings();
	list($t) = strings();

	// 操作回数を求める
	$ans = 0;
	$n = strlen($s);
	for ($i = 0; $i < $n; ++$i) {
		if ($s[$i] !== $t[$i]) {
			++$ans;
		}
	}

	// 出力
	output($ans);
}

main();
