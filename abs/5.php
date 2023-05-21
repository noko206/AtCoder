<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($n, $a, $b) = ints();

	// 条件を満たす整数の総和
	$ans = 0;

	// 1以上N以下の整数
	for ($num = 1; $num <= $n; ++$num) {

		$x = $num; // $numは更新できないので$xを更新していく
		$sum = 0;  // 各桁の和

		// $xを10で割っていき0になるまで
		while ($x > 0) {
			$sum += $x % 10;     // ある桁の数を足す
			$x = intdiv($x, 10); // $xを10で割って小数部を切り捨て
		}

		// 各桁の和がA以上B以下なら
		if ($a <= $sum && $sum <= $b) {
			$ans += $num; // 条件を満たした整数を加算
		}
	}

	// 出力
	o($ans);
}

main();