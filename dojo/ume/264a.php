<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($l, $r) = ints();

	// 'atcoder'のL文字目からR文字目までを取得
	--$l;
	$ans = substr('atcoder', $l, $r - $l);

	// 出力
	output($ans);
}

main();
