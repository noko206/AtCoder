<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

class SCC
{
	private $n;
	private $edges;

	public function __construct(int $n)
	{
		$this->n = $n;
		$this->edges = [];
	}

	public function add_edge(int $from, int $to): void
	{
		assert(0 <= $from && $from < $this->n);
		assert(0 <= $to && $to < $this->n);
		$this->edges[] = [$from, $to];
	}

	private function csr(): array
	{
		$start = array_fill(0, $this->n + 1, 0);
		$elist = array_fill(0, count($this->edges), 0);
		foreach ($this->edges as list($from, $to)) {
			++$start[$from + 1];
		}
		for ($i = 1; $i <= $this->n; ++$i) {
			$start[$i] += $start[$i - 1];
		}
		$counter = $start;
		foreach ($this->edges as list($from, $to)) {
			$elist[$counter[$from]++] = $to;
		}
		return [$start, $elist];
	}

	private function scc_ids(): array
	{
		list($start, $elist) = $this->csr();
		$now_ord = 0;
		$group_num = 0;
		$visited = [];
		$low = array_fill(0, $this->n, 0);
		$ord = array_fill(0, $this->n, -1);
		$ids = array_fill(0, $this->n, 0);
		$dfs = function (int $v) use (&$dfs, $start, $elist, &$now_ord, &$group_num, &$visited, &$low, &$ord, &$ids): void
		{
			$low[$v] = $now_ord;
			$ord[$v] = $now_ord;
			++$now_ord;
			$visited[] = $v;
			for ($i = $start[$v]; $i < $start[$v + 1]; ++$i) {
				$to = $elist[$i];
				if ($ord[$to] === -1) {
					$dfs($to);
					$low[$v] = min($low[$v], $low[$to]);
				} else {
					$low[$v] = min($low[$v], $ord[$to]);
				}
			}
			if ($low[$v] === $ord[$v]) {
				while (true) {
					$u = array_pop($visited);
					$ord[$u] = $this->n;
					$ids[$u] = $group_num;
					if ($u === $v) break;
				}
				++$group_num;
			}
		};
		for ($i = 0; $i < $this->n; ++$i) {
			if ($ord[$i] === -1) $dfs($i);
		}
		foreach ($ids as &$x) {
			$x = $group_num - 1 - $x;
		}
		return [$group_num, $ids];
	}

	public function scc(): array
	{
		list($group_num, $ids) = $this->scc_ids();
		$counts = array_fill(0, $group_num, 0);
		foreach ($ids as $x) {
			++$counts[$x];
		}
		$groups = array_fill(0, $group_num, []);
		for ($i = 0; $i < $this->n; ++$i) {
			$groups[$ids[$i]][] = $i;
		}
		return $groups;
	}
}

function main() {

	// 入力
	list($n) = ints();
	$s = [];
	$t = [];
	for ($i = 0; $i < $n; ++$i) {
		list($s[], $t[]) = strings();
	}

	// ユーザ名にユニークなIDを割り振る
	$st = [];
	for ($i = 0; $i < $n; ++$i) {
		$st[] = $s[$i];
		$st[] = $t[$i];
	}
	$st = array_merge(array_unique($st));
	$mp = array_flip($st);

	// グラフを作成
	$g = new SCC(count($mp));
	for ($i = 0; $i < $n; ++$i) {
		$g->add_edge($mp[$s[$i]], $mp[$t[$i]]);
	}

	// サイクルが存在するかチェック
	$is_ok = true;
	foreach ($g->scc() as $v) {
		if (count($v) >= 2) {
			$is_ok = false;
		}
	}

	// 出力
	output($is_ok ? 'Yes' : 'No');
}

main();