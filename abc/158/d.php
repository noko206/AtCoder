<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($s) = strings();
	list($q) = ints();
	$queries = [];
	for ($i = 0; $i < $q; ++$i) {
		$queries[] = strings();
	}

	// クエリを処理
	$is_reverse = false;
	$head = ''; // 文字列Sの先頭に追加される文字列
	$tail = ''; // 文字列Sの末尾に追加される文字列
	foreach ($queries as list($t, $f, $c)) {
		$t = (int)$t;
		$f = (int)$f;
		if ($t === 1) {
			$is_reverse = !$is_reverse;
		} else {
			if ($f === 1) {
				if ($is_reverse) $tail .= $c;
				else             $head .= $c;
			} else {
				if ($is_reverse) $head .= $c;
				else             $tail .= $c;
			}
		}
	}

	// 答えを整形
	if ($is_reverse) $s = strrev($tail) . strrev($s) . $head;
	else             $s = strrev($head) . $s . $tail;

	// 出力
	output($s);
}

main();
