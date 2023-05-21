<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($n) = ints();
	$a = ints();

	// 降順にソート
	rsort($a);

	$alice = 0; // Aliceの得点の合計
	$bob   = 0; // Bobの得点の合計

	// a_iが書かれたカードを取っていく
	for ($i = 0; $i < $n; ++$i) {

		// 偶数番目なら
		if ($i % 2 === 0) {
			$alice += $a[$i]; // Aliceに得点を加算
		}
		// 奇数番目なら
		else {
			$bob += $a[$i]; // Bobに得点を加算
		}
	}

	// AliceとBobの得点の差分が答え
	$ans = $alice - $bob;

	// 出力
	o($ans);
}

main();