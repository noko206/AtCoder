<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	list($q) = ints();
	$par = [-1];
	$val = [-1];
	$note = [];
	$now = 0;
	$ans = [];
	for ($i = 0; $i < $q; ++$i) {
		$query = strings();
		if ($query[0] === 'ADD') {
			$next = count($par);
			$par[] = $now;
			$val[] = $query[1];
			$now = $next;
		} elseif ($query[0] === 'DELETE') {
			if ($now !== 0) {
				$now = $par[$now];
			}
		} elseif ($query[0] === 'SAVE') {
			$note[$query[1]] = $now;
		} else {
			if (!isset($note[$query[1]])) {
				$now = 0;
			} else {
				$now = $note[$query[1]];
			}
		}
		output($val[$now]);
	}
}

main();
