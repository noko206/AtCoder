<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

function main()
{
	[$s, $t] = strings();
	if ($s === 'AtCoder' && $t === 'Land') {
		output('Yes');
	} else {
		output('No');
	}
}

main();
