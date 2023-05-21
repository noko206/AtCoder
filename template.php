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

}

main();