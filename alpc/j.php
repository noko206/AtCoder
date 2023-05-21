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

class Segment_Tree
{
	private const MIN_N = 1;
	private const MAX_N = 100000000;

	/** @var int */
	private $n;
	/** @var callable function(int $a, int $b): int { // a,bに対する二項演算 } */
	private $op;
	/** @var callable function(): int { // opの単位元 } */
	private $e;
	/** @var int */
	private $log;
	/** @var int */
	private $size;
	/** @var int[] */
	private $data;

	public function __construct(int $n, callable $op, callable $e, array $a = [])
	{
		assert(self::MIN_N <= $n && $n <= self::MAX_N);
		$this->n = $n;
		$this->op = $op;
		$this->e = $e;
		$this->log = $this->bit_length($n - 1);
		$this->size = 1 << $this->log;
		$this->data = array_fill(0, 2 * $this->size, $e());
		if (!empty($a)) {
			for ($i = 0; $i < $n; ++$i) {
				$this->data[$this->size + $i] = $a[$i];
			}
			for ($i = $this->size - 1; $i >= 1; --$i) {
				$this->update($i);
			}
		}
	}

	private function bit_length(int $n): int
	{
		$len = 0;
		while ($n > 0) {
			$n >>= 1;
			++$len;
		}
		return $len;
	}

	private function update(int $k): void
	{
		$this->data[$k] = ($this->op)($this->data[2 * $k], $this->data[2 * $k + 1]);
	}

	public function set(int $p, int $x): void
	{
		assert(0 <= $p && $p < $this->n);
		$p += $this->size;
		$this->data[$p] = $x;
		for ($i = 1; $i <= $this->log; ++$i) {
			$this->update($p >> $i);
		}
	}

	public function get(int $p): int
	{
		assert(0 <= $p && $p < $this->n);
		return $this->data[$p + $this->size];
	}

	public function prod(int $l, int $r): int
	{
		assert(0 <= $l && $l <= $r && $r <= $this->n);
		$sml = ($this->e)();
		$smr = ($this->e)();
		$l += $this->size;
		$r += $this->size;
		while ($l < $r) {
			if ($l & 1) {
				$sml = ($this->op)($sml, $this->data[$l]);
				++$l;
			}
			if ($r & 1) {
				--$r;
				$smr = ($this->op)($this->data[$r], $smr);
			}
			$l >>= 1;
			$r >>= 1;
		}
		return ($this->op)($sml, $smr);
	}

	public function all_prod(): int
	{
		return $this->data[1];
	}

	public function max_right(int $l, callable $f): int
	{
		assert(0 <= $l && $l <= $this->n);
		if ($l === $this->n) return $this->n;
		$l += $this->size;
		$sm = ($this->e)();
		do {
			while ($l % 2 === 0) {
				$l >>= 1;
			}
			if (!$f(($this->op)($sm, $this->data[$l]))) {
				while ($l < $this->size) {
					$l <<= 1;
					if ($f(($this->op)($sm, $this->data[$l]))) {
						$sm = ($this->op)($sm, $this->data[$l]);
						++$l;
					}
				}
				return $l - $this->size;
			}
			$sm = ($this->op)($sm, $this->data[$l]);
			$l += 1;
		} while(($l & -$l) !== $l);
		return $this->n;
	}

	public function min_left(int $r, callable $f): int
	{
		assert(0 <= $r && $r <= $this->n);
		if ($r === 0) return 0;
		$r += $this->size;
		$sm = ($this->e)();
		do {
			$r -= 1;
			while ($r > 1 && $r % 2 === 0) {
				$r >>= 1;
			}
			if (!$f(($this->op)($this->data[$r], $sm))) {
				while ($r < $this->size) {
					$r = 2 * $r + 1;
					if ($f(($this->op)($this->data[$r], $sm))) {
						$sm = ($this->op)($this->data[$r], $sm);
						$r -= 1;
					}
				}
				return $r + 1 - $this->size;
			}
			$sm = ($this->op)($this->data[$r], $sm);
		} while(($r & -$r) !== $r);
		return 0;
	}
}

function main()
{
	list($n, $q) = ints();
	$a = ints();
	$op = fn(int $a, int $b): int => max($a, $b);
	$e = fn(): int => -1;
	$seg = new Segment_Tree($n, $op, $e, $a);
	$ans = [];
	while ($q--) {
		$query = ints();
		list($t) = $query;
		if ($t === 1) {
			list($_, $x, $v) = $query;
			--$x;
			$seg->set($x, $v);
		}
		if ($t === 2) {
			list($_, $l, $r) = $query;
			--$l;
			$ans[] = $seg->prod($l, $r);
		}
		if ($t === 3) {
			list($_, $x, $v) = $query;
			--$x;
			$f = fn(int $u): bool => $u < $v;
			$ans[] = $seg->max_right($x, $f) + 1;
		}
	}
	output(...$ans);
}

main();