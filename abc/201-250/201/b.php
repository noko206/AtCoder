<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n) = ints();
	$s = [];
	$t = [];
	for ($i = 0; $i < $n; ++$i) {
		list($s[], $t[]) = strings();
		$t[$i] = (int)$t[$i];
	}

	// [t,s]に整形してtでソート
	$ts = [];
	for ($i = 0; $i < $n; ++$i) {
		$ts[] = [$t[$i], $s[$i]];
	}
	rsort($ts);

	// 2番目に高い山の名前を取得
	list($_, $ans) = $ts[1];

	// 出力
	output($ans);
}

main();
