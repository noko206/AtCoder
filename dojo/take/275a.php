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
	$h = ints();

	// 最も高い橋の高さを取得し、ループを回して何本目か確認
	$max = max($h);
	$ans = -1;
	for ($i = 0; $i < $n; ++$i) {
		if ($h[$i] === $max) {
			$ans = $i + 1;
		}
	}

	// 出力
	output($ans);
}

main();
