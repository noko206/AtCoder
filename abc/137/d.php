<?php

ini_set('memory_limit', '-1');

use function explode as ex;
use function implode as im;
use function array_fill as af;

const INF32 = 1001001001;
const INF64 = 1001001001001001001;

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }
function chmax(&$a, $b) { if ($a < $b) { $a = $b; return true; } return false; }
function chmin(&$a, $b) { if ($a > $b) { $a = $b; return true; } return false; }

function main()
{
	list($n, $m) = ints();
	$a = [];
	$b = [];
	$a_to_b = [];
	for ($i = 0; $i < $n; ++$i) {
		list($a[], $b[]) = ints();
		$a_to_b[$a[$i]][] = $b[$i];
	}
	$hp = new SplMaxHeap;
	$ans = 0;
	for ($i = 1; $i <= $m; ++$i) {
		foreach ($a_to_b[$i] ?? [] as $tmp_b) {
			$hp->insert($tmp_b);
		}
		if ($hp->isEmpty()) continue;
		$tmp_b = $hp->extract();
		$ans += $tmp_b;
	}
	output($ans);
}

main();