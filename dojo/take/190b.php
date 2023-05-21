<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $s, $d) = ints();
	$x = [];
	$y = [];
	for ($i = 0; $i < $n; ++$i) {
		list($x[], $y[]) = ints();
	}

	// 詠唱にかかる時間がS秒未満 かつ 威力がDより大きい呪文が存在するか判定
	$is_ok = false;
	for ($i = 0; $i < $n; ++$i) {
		if ($x[$i] < $s && $y[$i] > $d) {
			$is_ok = true;
		}
	}

	// 出力
	if ($is_ok) {
		output('Yes');
	} else {
		output('No');
	}
}

main();
