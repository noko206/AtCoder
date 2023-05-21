<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n) = ints();
	$a = ints();
	list($q) = ints();
	$queries = [];
	for ($i = 0; $i < $q; ++$i) {
		$queries[] = ints();
	}

	// クエリを処理
	$ans = [];
	foreach ($queries as $query) {
		// クエリの種類を取得
		$t = $query[0];
		// A_kの値をxに変更
		if ($t === 1) {
			list($_, $k, $x) = $query;
			$a[$k - 1] = $x;
		}
		// A_kの値を$ansに追加
		if ($t === 2) {
			list($_, $k) = $query;
			$ans[] = $a[$k - 1];
		}
	}

	// 出力
	output(...$ans);
}

main();
