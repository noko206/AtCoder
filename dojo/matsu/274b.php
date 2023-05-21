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
	$c = [];
	for ($i = 0; $i < $h; ++$i) {
		list($c[]) = strings();
	}

	// ans[j]:=c_{i,j}が'#'であるような整数iの個数としてカウント
	$ans = array_fill(0, $w, 0); // 要素数w,初期値0の配列を作成
	for ($i = 0; $i < $h; ++$i) {
		for ($j = 0; $j < $w; ++$j) {
			if ($c[$i][$j] === '#') {
				++$ans[$j];
			}
		}
	}

	// 出力
	output(...$ans);
}

main();
