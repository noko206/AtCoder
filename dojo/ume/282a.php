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

	// 英大文字をAから昇順にK個つなげて得られる文字列を作成
	$alphabets = range('A', 'Z');
	$ans = '';
	for ($i = 0; $i < $k; ++$i) {
		$ans .= $alphabets[$i]; // i番目のアルファベットを結合
	}

	// 出力
	output($ans);
}

main();
