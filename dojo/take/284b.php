<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// tを受け取る
	list($t) = ints();

	// t個のテストケースを処理
	$ans = [];
	for ($i = 0; $i < $t; ++$i) {
		// テストケースの入力
		list($n) = ints();
		$a = ints();

		// Aの奇数の個数をカウント
		$cnt = 0;
		foreach ($a as $v) {
			if ($v % 2 === 1) {
				++$cnt;
			}
		}

		// 答えをansに追加
		$ans[] = $cnt;
	}

	// 出力
	output(...$ans);
}

main();
