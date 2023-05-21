<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($n) = ints();
	$d = [];
	for ($i = 0; $i < $n; ++$i) {
		list($d[]) = ints();
	}

	// 重複分を取り除いた配列
	$d_unique = array_unique($d);

	// 最大の鏡餅の段数
	$ans = count($d_unique);

	// 出力
	o($ans);
}

main();