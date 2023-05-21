<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function main() {

	// 入力
	list($s) = strings();

	// Sを逆順にする
	$s = strrev($s);

	// Tに追加できる文字列
	$add_str_list = [
		strrev('dream'),
		strrev('dreamer'),
		strrev('erase'),
		strrev('eraser'),
	];

	$t = '';       // Tの文字列
	$sub_str = ''; // Sの部分文字列

	for ($i = 0; $i < strlen($s); ++$i) {

		// Sの部分文字列に現在の文字を追加
		$sub_str .= $s[$i];

		foreach ($add_str_list as $add_str) {

			// Sの部分文字列とTに追加できる文字列が一致していれば
			if ($sub_str === $add_str) {
				$t .= $add_str; // Tに文字列を追加
				$sub_str = '';  // 次の部分文字列を見に行くため空にする
			}
		}
	}

	// 出力
	if ($s === $t) {
		o('YES');
	}
	else {
		o('NO');
	}
}

main();