<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($s, $t) = ints();

	// a,b,cのありうる通りを全て試す(全探索)
	// a+b+c≦Sなので、0≦a,b,c≦S
	$ans = 0;
	for ($a = 0; $a <= $s; ++$a) {
		for ($b = 0; $b <= $s; ++$b) {
			for ($c = 0; $c <= $s; ++$c) {
				// 条件を満たすなら答えを+1
				if ($a + $b + $c <= $s && $a * $b * $c <= $t) {
					++$ans;
				}
			}
		}
	}

	// 出力
	output($ans);
}

main();
