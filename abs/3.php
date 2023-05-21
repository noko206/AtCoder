<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($n) = ints();
	$a = ints();

	// 操作の回数
	$ans = 0;

	// 可能な限り操作を繰り返す
	while (true) {

		// 奇数が存在するか確認
		for ($i = 0; $i < $n; ++$i) {
			if ($a[$i] % 2 === 1) {
				break 2;
			}
		}

		// 2で割ったものに置き換える
		for ($i = 0; $i < $n; ++$i) {
			$a[$i] = intdiv($a[$i], 2);
		}

		// 操作の回数を+1する
		++$ans;
	}

	// 出力
	o($ans);
}

main();