<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	[$n, $m] = ints();
	$a = ints();
	$b = ints();
	sort($a);
	sort($b);
	$j = 0;
	$cnt = 0;
	$ans = 0;
	for ($i = 0; $i < $m; ++$i) {
		if ($j >= $n) {
			break;
		}
		while ($j < $n && $b[$i] > $a[$j]) {
			++$j;
		}
		if ($j >= $n) {
			break;
		}
		$ans += $a[$j];
		++$cnt;
		++$j;
	}
	if ($cnt !== $m) {
		$ans = -1;
	}
	output($ans);
}

main();
