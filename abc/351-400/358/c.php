<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	[$n, $m] = ints();
	$s = [];
	for ($i = 0; $i < $n; ++$i) {
		[$s[]] = strings();
	}
	$ans = $n;
	for ($bit = 0; $bit < (1 << $n); ++$bit) {
		$aji = array_fill(0, $m, false);
		$cnt = 0;
		for ($i = 0; $i < $n; ++$i) {
			if ($bit & (1 << $i)) {
				for ($j = 0; $j < $m; ++$j) {
					if ($s[$i][$j] === 'o') {
						$aji[$j] = true;
					}
				}
				++$cnt;
			}
		}
		$is_ok = true;
		for ($i = 0; $i < $m; ++$i) {
			if (!$aji[$i]) {
				$is_ok = false;
			}
		}
		if ($is_ok) {
			$ans = min($ans, $cnt);
		}
	}
	output($ans);
}

main();
