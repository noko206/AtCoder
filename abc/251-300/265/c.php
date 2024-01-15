<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

const di = ['U' => -1, 'D' => 1, 'L' => 0, 'R' => 0];
const dj = ['U' => 0, 'D' => 0, 'L' => -1, 'R' => 1];

function main()
{
	// 入力
	list($h, $w) = ints();
	$g = [];
	for ($i = 0; $i < $h; ++$i) {
		list($g[]) = strings();
	}

	// 可能な限りマスを移動する
	$visited = array_fill(0, $h, array_fill(0, $w, false));
	$i = 0;
	$j = 0;
	while (true) {
		// 訪れたことを記録
		$visited[$i][$j] = true;
		// マスの移動
		$ni = $i + di[$g[$i][$j]];
		$nj = $j + dj[$g[$i][$j]];
		// 範囲外に出るようならそこで移動終了
		if ($ni < 0 || $nj < 0 || $ni >= $h || $nj >= $w) break;
		// 既に訪れたことがあるなら-1を出力
		if ($visited[$ni][$nj]) {
			output(-1);
			return;
		}
		// i,jを更新
		$i = $ni;
		$j = $nj;
	}

	// 出力
	output($i + 1, $j + 1);
}

main();
