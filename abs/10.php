<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($n) = ints();
	// 時刻0のとき(0,0)にいることを追加すると実装が楽
	$t = [0];
	$x = [0];
	$y = [0];
	for ($i = 0; $i < $n; ++$i) {
		list($t[], $x[], $y[]) = ints();
	}

	$is_ok = true; // 計画が実行可能かどうか

	for ($i = 0; $i < $n; ++$i) {

		$dist = abs($x[$i + 1] - $x[$i]) + abs($y[$i + 1] - $y[$i]); // 距離
		$dt   = $t[$i + 1] - $t[$i];                                 // 時刻の差

		// 時間が足りない場合 または 到達後の残り時間が奇数の場合
		if ($dt < $dist || ($dt - $dist) % 2 === 1) {
			$is_ok = false;
		}
	}

	// 出力
	if ($is_ok) {
		o('Yes');
	}
	else {
		o('No');
	}
}

main();