<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	// 入力
	list($n, $m) = ints();
	$to = [];
	for ($i = 0; $i < $m; ++$i) {
		list($a, $b) = ints();
		--$a;
		--$b;
		$to[$a][] = $b;
		$to[$b][] = $a;
	}

	// dfs
	$visited = array_fill(0, $n, false);
	$ans = 0;
	$dfs = function(int $v = 0, int $cnt = 1) use(&$dfs, &$ans, &$visited, $to, $n): void {
		if ($cnt === $n) ++$ans;
		$visited[$v] = true;
		foreach ($to[$v] ?? [] as $u) {
			if ($visited[$u]) continue;
			$dfs($u, $cnt + 1);
		}
		$visited[$v] = false;
	};
	$dfs();

	// 出力
	output($ans);
}

main();
