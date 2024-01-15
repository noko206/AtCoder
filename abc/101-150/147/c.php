<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	list($n) = ints();
	$a = [];
	$x = [];
	$y = [];
	for ($i = 0; $i < $n; ++$i) {
		list($a[]) = ints();
		for ($j = 0; $j < $a[$i]; ++$j) {
			list($x[$i][], $y[$i][]) = ints();
			--$x[$i][$j];
		}
	}

	$ans = 0;
	for ($bit = 0; $bit < (1 << $n); ++$bit) {
		$is_honest = [];
		$cnt = 0;
		for ($i = 0; $i < $n; ++$i) {
			if ($bit & (1 << $i)) {
				$is_honest[$i] = true;
				++$cnt;
			} else {
				$is_honest[$i] = false;
			}
		}
		$is_ok = true;
		for ($i = 0; $i < $n; ++$i) {
			if ($bit & (1 << $i)) {
				for ($j = 0; $j < $a[$i]; ++$j) {
					if ($y[$i][$j] === 0 && $is_honest[$x[$i][$j]]) $is_ok = false;
					if ($y[$i][$j] === 1 && !$is_honest[$x[$i][$j]]) $is_ok = false;
				}
			}
		}
		if ($is_ok) $ans = max($ans, $cnt);
	}

	output($ans);
}

main();