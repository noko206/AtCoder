<?php

ini_set('memory_limit', '-1');

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function output(...$args) { echo implode(' ', $args), "\n"; }

class Mo
{
	private $n;
	private $lr;
	public $property;

	public function __construct(int $n)
	{
		$this->n = $n;
	}

	public function add(int $l, int $r): void
	{
		$this->lr[] = [$l, $r];
	}

	private function sub_build(callable $add_left, callable $add_right, callable $erase_left, callable $erase_right, callable $out): void
	{
		$q = count($this->lr);
		$bs = intdiv($this->n, min($this->n, (int)sqrt($q)));
		$ord = range(0, $q - 1);
		usort($ord, function(int $a, int $b) use($bs): bool {
			list($la, $ra) = $this->lr[$a];
			list($lb, $rb) = $this->lr[$b];
			$ablock = intdiv($la, $bs);
			$bblock = intdiv($lb, $bs);
			if ($ablock !== $bblock) return $ablock < $bblock;
			return ($ablock & 1) ? $ra > $rb : $ra < $rb;
		});
		$l = 0;
		$r = 0;
		foreach ($ord as $idx) {
			list($left, $right) = $this->lr[$idx];
			while ($l > $left) $add_left(--$l);
			while ($r < $right) $add_right($r++);
			while ($l < $left) $erase_left($l++);
			while ($r > $right) $erase_right(--$r);
			$out($idx);
		}
	}

	public function build(callable $add, callable $erase, callable $out): void
	{
		$this->sub_build($add, $add, $erase, $erase, $out);
	}
}

function main()
{
	// 入力
	list($n, $q) = ints();
	$a = ints();
	$l = [];
	$r = [];
	for ($i = 0; $i < $q; ++$i) {
		list($l[], $r[]) = ints();
	}

	// Moの前処理
	$mo = new Mo($n);
	for ($i = 0; $i < $q; ++$i) {
		$mo->add($l[$i] - 1, $r[$i]);
	}
	$mo->property['a'] = $a;
	$mo->property['cnt'] = array_fill(0, 200005, 0);
	$mo->property['ans'] = array_fill(0, $q, -1);
	$mo->property['sum'] = 0;
	$add = function(int $i) use($mo): void {
		++$mo->property['cnt'][$mo->property['a'][$i]];
		if ($mo->property['cnt'][$mo->property['a'][$i]] >= 3) {
			$mo->property['sum'] += intdiv(($mo->property['cnt'][$mo->property['a'][$i]] - 1) * ($mo->property['cnt'][$mo->property['a'][$i]] - 2), 2);
		}
	};
	$erase = function(int $i) use($mo): void {
		if ($mo->property['cnt'][$mo->property['a'][$i]] >= 3) {
			$mo->property['sum'] -= intdiv(($mo->property['cnt'][$mo->property['a'][$i]] - 1) * ($mo->property['cnt'][$mo->property['a'][$i]] - 2), 2);
		}
		--$mo->property['cnt'][$mo->property['a'][$i]];
	};
	$out = function(int $q) use($mo): void {
		$mo->property['ans'][$q] = $mo->property['sum'];
	};

	// ビルド
	$mo->build($add, $erase, $out);

	// 出力
	output(...$mo->property['ans']);
}

main();
