<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

const INF64 = 1001001001001001001;
const BORDER_K = 1500;

function main()
{
	[$h, $w, $k] = ints();
	[$si, $sj] = ints();
	--$si;
	--$sj;
	$a = [];
	for ($i = 0; $i < $h; ++$i) {
		$a[] = ints();
	}
	$dp = array_fill(0, BORDER_K + 1, array_fill(0, $h, array_fill(0, $w, -INF64)));
	$dp[0][$si][$sj] = 0;
	$pq = new SplPriorityQueue();
	$pq->setExtractFlags(SplPriorityQueue::EXTR_BOTH);
	$pq->insert([$si, $sj], 0);
	$pq_sub = new SplPriorityQueue();
	$pq_sub->setExtractFlags(SplPriorityQueue::EXTR_BOTH);
	$dy = [0, -1, 0, 1, 0];
	$dx = [0, 0, 1, 0, -1];
	for ($cnt = 0; $cnt < BORDER_K; ++$cnt) {
		while (!$pq->isEmpty()) {
			['data' => [$cy, $cx], 'priority' => $v] = $pq->extract();
			if ($dp[$cnt][$cy][$cx] > $v) {
				continue;
			}
			for ($i = 0; $i < 5; ++$i) {
				$ny = $cy + $dy[$i];
				$nx = $cx + $dx[$i];
				if ($ny < 0 || $nx < 0 || $ny >= $h || $nx >= $w) {
					continue;
				}
				if ($dp[$cnt + 1][$ny][$nx] < $dp[$cnt][$cy][$cx] + $a[$ny][$nx]) {
					$dp[$cnt + 1][$ny][$nx] = $dp[$cnt][$cy][$cx] + $a[$ny][$nx];
					$pq_sub->insert([$ny, $nx], $dp[$cnt + 1][$ny][$nx]);
				}
			}
		}
		[$pq, $pq_sub] = [$pq_sub, $pq];
	}
	if ($k <= BORDER_K) {
		$ans = 0;
		for ($i = 0; $i < $h; ++$i) {
			for ($j = 0; $j < $w; ++$j) {
				$ans = max($ans, $dp[$k][$i][$j]);
			}
		}
		output($ans);
	} else {
		$ans = 0;
		for ($i = 0; $i < $h; ++$i) {
			for ($j = 0; $j < $w; ++$j) {
				$ans = max($ans, $dp[BORDER_K][$i][$j] + ($k - BORDER_K) * $a[$i][$j]);
			}
		}
		output($ans);
	}
}

main();
