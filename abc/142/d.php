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

function gcd(int $x, int $y): int
{
	return ($x % $y) ? gcd($y, $x % $y) : $y;
}

function prime_divisors(int $n): array
{
	$ans = [];
	for ($i = 2; $i * $i <= $n; ++$i) {
		if ($n % $i === 0) {
			$ans[] = $i;
			while ($n % $i === 0) {
				$n = intdiv($n, $i);
			}
		}
	}
	if ($n !== 1) {
		$ans[] = $n;
	}
	sort($ans);
	return $ans;
}

function main()
{
	list($a, $b) = ints();
	$g = gcd($a, $b);
	$d = prime_divisors($g);
	output(count($d) + 1)
}

main();