<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($a) = ints();
	list($b) = ints();
	list($c) = ints();
	list($x) = ints();

	// 条件を満たす組み合わせの数
	$ans = 0;

	// 500円玉の枚数
	for ($i = 0; $i <= $a; ++$i) {
		// 100円玉の枚数
		for ($j = 0; $j <= $b; ++$j) {
			// 50円玉の枚数
			for ($k = 0; $k <= $c; ++$k) {
				// 合計金額がちょうどX円なら
				if (500 * $i + 100 * $j + 50 * $k === $x) {
					// 組み合わせの数を+1する
					++$ans;
				}
			}
		}
	}

	// 出力
	o($ans);
}

main();