<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($x, $y, $n) = ints();

	// 3*X≦YならX円のりんごだけでN個手に入れた方がお得
	// 3*X＞YならY円のりんごを買えるだけ買って、残りをX円のりんごで補うのがお得
	$ans = -1;
	if (3 * $x <= $y) {
		$ans = $n * $x;
	} else {
		$y_cnt = intdiv($n, 3); // Y円のりんごはn/3の小数切り捨ての個数だけ買う
		$x_cnt = $n % 3; // X円のりんごはn/3の余りの個数だけ買う
		$ans =  $y_cnt * $y + $x_cnt * $x;
	}

	// 出力
	output($ans);
}

main();
