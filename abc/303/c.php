<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

const dx = ['R' => 1, 'L' => -1, 'U' => 0, 'D' => 0];
const dy = ['R' => 0, 'L' => 0, 'U' => 1, 'D' => -1];

function main()
{
	// 入力
	list($n, $m, $h, $k) = ints();
	list($s) = strings();
	$x = [];
	$y = [];
	for ($i = 0; $i < $m; ++$i) {
		list($x[], $y[]) = ints();
	}

	// アイテムを連想配列で管理
	$items = [];
	for ($i = 0; $i < $m; ++$i) {
		$items[$x[$i]][$y[$i]] = true; // 使用可能ならtrue
	}

	// 移動を繰り返す
	$cx = 0;
	$cy = 0;
	$is_ok = true;
	for ($i = 0; $i < $n; ++$i) {
		// 移動
		$cx += dx[$s[$i]];
		$cy += dy[$s[$i]];
		// 体力を1消費
		--$h;
		// 体力が負になったか判定
		if ($h < 0) {
			$is_ok = false;
			break;
		}
		// 体力がk未満でアイテムがあれば回復
		if ($h < $k && !empty($items[$cx][$cy])) {
			$h = $k;
			$items[$cx][$cy] = false; // 使用済にする
		}
	}

	// 出力
	output($is_ok ? 'Yes' : 'No');
}

main();
