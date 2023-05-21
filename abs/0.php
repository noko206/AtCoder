<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	list($a)     = ints();    // 1行目を取得
	list($b, $c) = ints();    // 2行目を取得
	list($s)     = strings(); // 3行目を取得

	o($a + $b + $c, $s); // 出力
}

main();