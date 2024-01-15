<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function o(...$args) { echo implode(' ', $args), "\n"; }

function swap (&$a, &$b): void {
	list($a, $b) = [$b, $a];
}

function main() {

	list($n, $p, $q, $r, $s) = ints();
	$a = ints();

	--$p; --$r;

	for ($i = 0; $i < $q - $p; ++$i) {
		swap($a[$p + $i], $a[$r + $i]);
	}

	echo 1, ' ', 2, ' ', 3, "\n";
	o(1, 2, 3);

	echo 1, "\n";
	o(1);

	echo "1 2 3", "\n";
	
	o(implode("\n", $a));

	foreach ($a as $v) {
		o($v);
	}


	$a = 123;
	$b = "123";
	$c = [1, 2, 3];

	echo $a;
	echo $b;
	for ($i = 0; $i < 3; ++$i) echo $c;
}

main();