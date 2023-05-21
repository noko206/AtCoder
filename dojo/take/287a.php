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
	$s = [];
	for ($i = 0; $i < $n; ++$i) {
		list($s[]) = strings();
	}

	// 賛成と反対の人数をカウント
	$for_cnt = 0;
	$against_cnt = 0;
	foreach ($s as $v) {
		if ($v === 'For') {
			++$for_cnt;
		} else {
			++$against_cnt;
		}
	}

	// 賛成の人数 > 反対の人数なら答えはYes/そうでなければNo
	if ($for_cnt > $against_cnt) {
		output('Yes');
	} else {
		output('No');
	}
}

main();
