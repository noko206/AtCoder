<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $m) = ints();
	$k = [];
	$s = [];
	for ($i = 0; $i < $m; ++$i) {
		$input = ints();
		$k[] = $input[0];
		for ($j = 0; $j < $k[$i]; ++$j) {
			$s[$i][] = $input[$j + 1] - 1; // 0-indexed
		}
	}
	$p = ints();

	// bit全探索
	$ans = 0;
	for ($bit = 0; $bit < (1 << $n); ++$bit) {
		// 全ての電球が点灯しているか判定
		$is_ok = true;
		for ($i = 0; $i < $m; ++$i) {
			$on_cnt = 0; // 電球iにつながっているonのスイッチの個数
			for ($j = 0; $j < $k[$i]; ++$j) {
				// s[i][j]のスイッチがonになっていたら
				if ($bit & (1 << $s[$i][$j])) {
					++$on_cnt;
				}
			}
			if ($on_cnt % 2 !== $p[$i]) {
				$is_ok = false;
				break;
			}
		}
		// 全ての電球が点灯していたら答えを+1
		if ($is_ok) {
			++$ans;
		}
	}

	// 出力
	output($ans);
}

main();
