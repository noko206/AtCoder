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
	list($s) = strings();

	// Sを先頭から見ていき最初の1が現れるのが奇数番目or偶数番目を判定
	$lose_takahashi = true;
	for ($i = 0; $i < $n; ++$i) {
		if ($s[$i] === '1') {
			if ($i % 2 === 0) {
				$lose_takahashi = true;
			} else {
				$lose_takahashi = false;
			}
			break; // ループを抜けないと次の1が現れた場合も処理が行われてしまう
		}
	}

	// 出力
	if ($lose_takahashi) {
		output('Takahashi');
	} else {
		output('Aoki');
	}
}

main();
