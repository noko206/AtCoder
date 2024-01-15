<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $k) = ints();
	$a = array_map(fn($x) => $x - 1, ints()); // 0-indexedで受け取る

	// ループに入るまで移動を繰り返す
	$dist = [0];
	$i = 0;
	while (!isset($dist[$a[$i]])) {
		$dist[$a[$i]] = $dist[$i] + 1;
		$i = $a[$i];
	}
	$loop_start = $a[$i];
	$move_cnt_first = $dist[$a[$i]];
	$move_cnt_per_loop = $dist[$i] - $dist[$a[$i]] + 1;

	// ループに入る前に移動が終わる場合
	if ($k <= $move_cnt_first) {
		$i = 0;
		while ($k--) {
			$i = $a[$i];
		}
		output($i + 1);
		return;
	}

	// ループ分を省略する
	$k -= $move_cnt_first;
	$k %= $move_cnt_per_loop;
	$i = $loop_start;
	while ($k--) {
		$i = $a[$i];
	}
	output($i + 1);
}

main();
