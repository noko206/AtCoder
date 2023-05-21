<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($s) = strings();

	// 1が書かれたマスの個数
	$ans = 0;

	// 全探索
	for ($i = 0; $i < 3; ++$i) {

		// s_iが1なら
		if ($s[$i] === '1') {

			// 1が書かれたマスの個数を+1する
			++$ans;
		}
	}

	// 出力
	o($ans);
}

main();