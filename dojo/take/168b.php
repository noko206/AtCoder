<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($k) = ints();
	list($s) = strings();

	$ans = '';
	if (strlen($s) <= $k) {
		// Sはそのまま
		$ans = $s;
	} else {
		// Sを先頭K文字+...に変換
		$ans = substr($s, 0, $k) . '...';
	}

	// 出力
	output($ans);
}

main();
