<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($a, $b, $c, $d, $e) = ints();

	// 5つの整数を配列に変換
	$set = [$a, $b, $c, $d, $e];
	// array_unique関数で重複している値を削除
	$unique_set = array_unique($set);
	// 配列の要素数をカウント
	$ans = count($unique_set);

	// 出力
	output($ans);
}

main();
