<?php

// 設定
ini_set('memory_limit', '-1');

// 自作関数
function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }
function doubles() { return array_map('doubleval', strings()); }
function chmax(&$a, $b) { if($a < $b) { $a = $b; return true; } return false; }
function chmin(&$a, $b) { if($a > $b) { $a = $b; return true; } return false; }
function gcd($a, $b) { return ($a % $b) ? gcd($b, $a % $b) : $b; }
function lcm($a, $b) { return intdiv($a, gcd($a, $b)) * $b; }
function swap(&$a, &$b) { list($a, $b) = [$b, $a]; }
function sub_sort(&$a, $i, $j) { $b = array_slice($a, $i, $j - $i); sort($b); foreach($b as $k => $v){ $a[$k + $i] = $v; }}
function sub_reverse(&$a, $i, $j) { $b = array_slice($a, $i, $j - $i); foreach(array_reverse($b) as $k => $v){ $a[$k + $i] = $v; }}
function next_permutation(&$a) { $n = count($a); for($i = $n - 2; $i >= 0; --$i) { if($a[$i] < $a[$i + 1]){ for($j = $n - 1;; --$j){ if($a[$i] < $a[$j]){ swap($a[$i], $a[$j]); sub_reverse($a, $i + 1, $n); return true; }}}} return false; }
function __builtin_popcount($i) { if($i){ return ($i & 1) + __builtin_popcount($i >> 1); } return 0; }
function mod_power($a, $n, $m) { if($n === 0) return 1; if($n === 1) return $a % $m; if($n % 2 === 1) return ($a * mod_power($a, $n - 1, $m)) % $m; return pow(mod_power($a, $n >> 1, $m), 2) % $m;}
function mod_inverse($a, $m) { $b = $m; $u = 1; $v = 0; while($b){ $t = intdiv($a, $b); $a -= $t * $b; swap($a, $b); $u -= $t * $v; swap($u, $v); } $u += $m; return $u % $m; }
function run_length_encode($s) { $n = strlen($s); $t = ''; $a = []; $j = -1; for($i = 0; $i < $n; ++$i){ if($t !== $s[$i]) { ++$j; $t = $s[$i]; $a[$j] = [$t, 1]; } else { ++$a[$j][1]; }} return $a; }
function run_length_decode($a) { $s = ''; foreach($a as $v){ for($i = 0; $i < $v[1]; ++$i){ $s .= $v[0]; }} return $s; }
function lower_bound($a, $x) { $ng = -1; $ok = count($a); while($ok - $ng !== 1) { $mid = intdiv($ok + $ng, 2); if($a[$mid] >= $x) $ok = $mid; else $ng = $mid; } return $ok; }
function upper_bound($a, $x) { $ng = -1; $ok = count($a); while($ok - $ng !== 1) { $mid = intdiv($ok + $ng, 2); if($a[$mid] > $x) $ok = $mid; else $ng = $mid; } return $ok; }

// 定数
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001;
const _LLINF = 1001001001001001001;
const _MOD = 1000000007;

class BinaryTrie {

	private $nodes;  // ポインタ
	private $cnt;    // 部分木に含まれる要素の個数
	private $id;     // 最大のポインタID
	private $bitlen; // ビット長

	/**
	 * コンストラクタ｜O(Nlog(A_Max))
	 * @param int $max_query BinaryTrieの最大サイズ
	 * @param int $bitlen ビット長
	 */
	public function __construct($max_query = 200000, $bitlen = 30) {
		$n = $max_query * $bitlen;
		$this->nodes = array_fill(0, 2 * $n, -1);
		$this->cnt = array_fill(0, $n, 0);
		$this->id = 0;
		$this->bitlen = $bitlen;
	}

	/**
	 * 要素を追加｜O(log(A_Max))
	 * @param int $x 追加する要素
	 */
	public function insert($x) {
		$pt = 0;
		for ($i = $this->bitlen - 1; $i >= 0; --$i) {
			$y = $x >> $i & 1;
			if ($this->nodes[2 * $pt + $y] === -1) {
				++$this->id;
				$this->nodes[2 * $pt + $y] = $this->id;
			}
			++$this->cnt[$pt];
			$pt = $this->nodes[2 * $pt + $y];
		}
		++$this->cnt[$pt];
	}

	/**
	 * 要素を削除｜O(log(A_Max))
	 * @param int $x 削除する要素
	 */
	public function erase($x) {
		if ($this->count($x) === 0) return;
		$pt = 0;
		for ($i = $this->bitlen - 1; $i >= 0; --$i) {
			$y = $x >> $i & 1;
			--$this->cnt[$pt];
			$pt = $this->nodes[2 * $pt + $y];
		}
		--$this->cnt[$pt];
	}

	/**
	 * 昇順でk番目の値を取得 (1-indexed)｜O(log(A_Max))
	 * @param int $k 昇順で何番目か
	 * @return int 昇順でk番目の値
	 */
	public function kth_elm($k) {
		$pt = 0;
		$ans = 0;
		for ($i = $this->bitlen - 1; $i >= 0; --$i) {
			$ans <<= 1;
			if ($this->nodes[2 * $pt] !== -1 && $this->cnt[$this->nodes[2 * $pt]] > 0) {
				if ($this->cnt[$this->nodes[2 * $pt]] >= $k) {
					$pt = $this->nodes[2 * $pt];
				}
				else {
					$k -= $this->cnt[$this->nodes[2 * $pt]];
					$pt = $this->nodes[2 * $pt + 1];
					++$ans;
				}
			}
			else {
				$pt = $this->nodes[2 * $pt + 1];
				++$ans;
			}
		}
		return $ans;
	}

	/**
	 * $x以上の値のうち、最小の値は昇順で何番目か (1-indexed)｜O(log(A_Max))
	 * @param int $x 何以上の値か
	 * @return int 昇順で何番目か
	 */
	private function count_lower($x) {
		$pt = 0;
		$ans = 1;
		for($i = $this->bitlen - 1; $i >= 0; --$i) {
			if ($pt === -1) break;
			if ($x >> $i & 1 && $this->nodes[2 * $pt] !== -1) {
				$ans += $this->cnt[$this->nodes[2 * $pt]];
			}
			$pt = $this->nodes[2 * $pt + ($x >> $i & 1)];
		}
		return $ans;
	}

	/**
	 * $x以上の値のうち、最小の値は昇順で何番目か (1-indexed)｜O(log(A_Max))
	 * @param int $x 何以上の値か
	 * @return int 昇順で何番目か
	 */
	public function lower_bound($x) {
		return $this->count_lower($x);
	}

	/**
	 * $xより大きい値のうち、最小の値は昇順で何番目か (1-indexed)｜O(log(A_Max))
	 * @param int $x 何より大きい値か
	 * @return int 昇順で何番目か
	 */
	public function upper_bound($x) {
		return $this->count_lower($x + 1);
	}

	/**
	 * 全要素の数を取得｜O(1)
	 * @return int 全要素の数
	 */
	public function size() {
		return $this->cnt[0];
	}

	/**
	 * ある要素の数を取得｜O(log(A_Max))
	 * @param int $x 個数を取得したい要素の値
	 * @return int ある要素の数
	 */
	public function count($x) {
		$pt = 0;
		for ($i = $this->bitlen - 1; $i >= 0; --$i) {
			$y = $x >> $i & 1;
			if ($this->nodes[2 * $pt + $y] === -1) return 0;
			$pt = $this->nodes[2 * $pt + $y];
		}
		return $this->cnt[$pt];
	}

	/**
	 * 最大値を取得｜O(log(A_Max))
	 * @return int 最大値
	 */
	public function max() {
		return $this->kth_elm($this->cnt[0]);
	}

	/**
	 * 最小値を取得｜O(log(A_Max))
	 * @return int 最小値
	 */
	public function min() {
		return $this->kth_elm(1);
	}
}

function compress ($a) {
	$a = array_flip($a);
	ksort($a);
	$i = 0;
	foreach ($a as $k => $_) {
		$a[$k] = $i++;
	}
	return $a;
}

function main() {

	// 入力
	list($l, $q) = ints();
	$c = [];
	$x = [];
	for ($i = 0; $i < $q; ++$i) {
		list($c[], $x[]) = ints();
	}

	// 1. 座標圧縮
	$x[] = 0;
	$x[] = $l;
	$compress = compress($x);
	$decompress = array_flip($compress);

	// 2. シミュレーション
	$bt = new BinaryTrie(200002, 18); // log_2(200002) < 18
	$bt->insert($compress[0]);
	$bt->insert($compress[$l]);
	$ans = [];
	for ($i = 0; $i < $q; ++$i) {
		if ($c[$i] === 1) {
			$bt->insert($compress[$x[$i]]);
		}
		if ($c[$i] === 2) {
			$k = $bt->lower_bound($compress[$x[$i]]);
			$ans[] = $decompress[$bt->kth_elm($k)] - $decompress[$bt->kth_elm($k - 1)];
		}
	}

	// 出力
	foreach ($ans as $v) {
		printf("%d\n", $v);
	}
}

main();