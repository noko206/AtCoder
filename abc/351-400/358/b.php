<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	[$n, $a] = ints();
	$t = ints();
	$now = 0;
	$ans = [];
	for ($i = 0; $i < $n; ++$i) {
		if ($now <= $t[$i]) {
			$now = $t[$i] + $a;
		} else {
			$now += $a;
		}
		$ans[] = $now;
	}
	output(...$ans);
}

main();
