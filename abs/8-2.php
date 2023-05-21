<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($n, $y) = ints();

	// お年玉の組み合わせを全列挙
	for($a = 0; $a <= $n; ++$a) {
		for ($b = 0; $a + $b <= $n; ++$b) {

			$c   = $n - $a - $b;                       // 1000円札の枚数
			$sum = $a * 10000 + $b * 5000 + $c * 1000; // 金額

			// 金額が同じなら
			if ($sum === $y) {
				o($a, $b, $c); // 出力
				return;        // 処理終了
			}
		}
	}

	// 条件を満たすお年玉の組み合わせがなかった場合の出力
	o(-1, -1, -1);
}

main();