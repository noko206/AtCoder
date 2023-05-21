<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($h, $w) = ints();
	$a = [];
	for ($i = 0; $i < $h; ++$i) {
		$a[$i] = ints();
	}

	// マスに置いてあるブロックの最小値を取得
	$min = 1000000000; // すごいでかい値で初期化
	for ($i = 0; $i < $h; ++$i) {
		for ($j = 0; $j < $w; ++$j) {
			$min = min($min, $a[$i][$j]);
		}
	}

	// すべてのマスのブロックの個数をminにすればよいので、a_{i,j}-minの合計を計算
	$ans = 0;
	for ($i = 0; $i < $h; ++$i) {
		for ($j = 0; $j < $w; ++$j) {
			$ans += $a[$i][$j] - $min;
		}
	}

	// 出力
	output($ans);
}

main();
