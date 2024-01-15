<?php

class Scanner {
    private $arr = [];
    private $count = 0;
    private $pointer = 0;
    // 文字列型で入力を受け取る
    public function next() {
        if($this->pointer >= $this->count) {
            $str = trim(fgets(STDIN));
            $this->arr = explode(' ', $str);
            $this->count = count($this->arr);
            $this->pointer = 0;
        }
        $result = $this->arr[$this->pointer];
        $this->pointer++;
        return $result;
    }
    // 次の入力が存在するかを判定する
    public function hasNext() {
        return $this->pointer < $this->count;
    }
    // 整数型で入力を受け取る
    public function nextInt() {
        return (int)$this->next();
    }
    // 浮動小数点型で入力を受け取る
    public function nextDouble() {
        return (double)$this->next();
    }
}

class BinaryTrie{
    private $nodes;
    private $cnt;
    private $id;
    private $bitlen;
    
    public function __construct($max_query = 2e5, $bitlen = 30){
        $n = $max_query * $bitlen;
        $this->nodes = array_fill(0, 2 * $n, -1);
        $this->cnt = array_fill(0, $n, 0);
        $this->id = 0;
        $this->bitlen = $bitlen;
    }

    // 挿入
    public function insert($x){
        $pt = 0;
        for($i = $this->bitlen - 1; $i >= 0; --$i){
            $y = $x >> $i & 1;
            if($this->nodes[2 * $pt + $y] === -1){
                ++$this->id;
                $this->nodes[2 * $pt + $y] = $this->id;
            }
            ++$this->cnt[$pt];
            $pt = $this->nodes[2 * $pt + $y];
        }
        ++$this->cnt[$pt];
    }

    // 昇順でk番目の値
    public function kth_elm($k){
        $pt = 0;
        $ans = 0;
        for($i = $this->bitlen - 1; $i >= 0; --$i){
            $ans <<= 1;
            if($this->nodes[2 * $pt] !== -1 && $this->cnt[$this->nodes[2 * $pt]] > 0){
                if($this->cnt[$this->nodes[2 * $pt]] >= $k){
                    $pt = $this->nodes[2 * $pt];
                }
                else{
                    $k -= $this->cnt[$this->nodes[2 * $pt]];
                    $pt = $this->nodes[2 * $pt + 1];
                    ++$ans;
                }
            }
            else{
                $pt = $this->nodes[2 * $pt + 1];
                ++$ans;
            }
        }
        return $ans;
    }

    // x以上の最小要素が昇順で何番目か
    public function lower_bound($x){
        $pt = 0;
        $ans = 1;
        for($i = $this->bitlen - 1; $i >= 0; --$i){
            if($pt === -1){
                break;
            }
            if($x >> $i & 1 && $this->nodes[2 * $pt] !== -1){
                $ans += $this->cnt[$this->nodes[2 * $pt]];
            }
            $pt = $this->nodes[2 * $pt + ($x >> $i & 1)];
        }
        return $ans;
    }
}

function main(){
    $sc = new Scanner;

    $l = $sc->nextInt();
    $q = $sc->nextInt();

    // ini_set('memory_limit', '1024M'); // VSCode等で動かす場合は必要
    $bt = new BinaryTrie;
    $bt->insert(0);
    $bt->insert($l);
    $ans = [];

    for($i = 0; $i < $q; ++$i){
        $c = $sc->nextInt();
        $x = $sc->nextInt();
        if($c === 1){
            $bt->insert($x);
        }
        else{
            $p = $bt->lower_bound($x);
            $ans[] = $bt->kth_elm($p) - $bt->kth_elm($p - 1);
        }
    }

    foreach($ans as $a){
        printf("%d\n", $a);
    }
}

main();