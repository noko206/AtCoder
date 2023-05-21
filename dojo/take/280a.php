<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($h, $w) = ints();
	$s = [];
	for ($i = 0; $i < $h; ++$i) {
		list($s[]) = strings();
	}

	// コマが置かれているマスの個数をカウント
	$ans = 0;
	for ($i = 0; $i < $h; ++$i) {
		for ($j = 0; $j < $w; ++$j) {
			if ($s[$i][$j] === '#') {
				++$ans;
			}
		}
	}

	// 出力
	output($ans);
}

main();
