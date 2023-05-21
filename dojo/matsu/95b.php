<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $x) = ints();
	$m = [];
	for ($i = 0; $i < $n; ++$i) {
		list($m[]) = ints();
	}

	// 全てのドーナツを1つずつ作り、お菓子の素が何グラム残るか計算
	$ans = $n; // n個作れることは確定
	foreach ($m as $v) {
		$x -= $v;
	}

	// お菓子の素の消費グラムが最小のドーナツを作れるだけ作る
	$min_m = min($m);
	$ans += intdiv($x, $min_m); // 残りのお菓子の素/消費グラム分だけドーナツが作れる

	// 出力
	output($ans);
}

main();
