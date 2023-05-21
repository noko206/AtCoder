<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($x) = strings();

	// 4桁とも同じ数字
	$is_same = true;
	for ($i = 0; $i < 3; ++$i) {
		if ($x[$i] != $x[$i + 1]) {
			$is_same = false;
		}
	}

	// [1234]のような連番である
	$is_step = true;
	for ($i = 0; $i < 3; ++$i) {
		// 9+1=10を0と同じと考えたい場合は10で割った余りを考えればよい
		if (($x[$i] + 1) % 10 != $x[$i + 1]) {
			$is_step = false;
		}
	}

	// どちらかの条件を満たすときはWeak/そうでなければStrong
	if ($is_same || $is_step) {
		output('Weak');
	} else {
		output('Strong');
	}
}

main();
