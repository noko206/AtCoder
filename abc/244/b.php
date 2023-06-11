<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

const dy = [0, -1, 0, 1];
const dx = [1, 0, -1, 0];

function main()
{
	// 入力
	list($n) = ints();
	list($t) = strings();

	// 移動を繰り返す
	$x = 0;
	$y = 0;
	$r = 0; // 回転した回数
	for ($i = 0; $i < $n; ++$i) {
		if ($t[$i] === 'S') {
			$x += dx[$r];
			$y += dy[$r];
		} else {
			$r = ($r + 1) % 4; // 4回転すると0回転に戻る
		}
	}

	// 出力
	output($x, $y);
}

main();
