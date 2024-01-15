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

class UnionFind{
    private $par = [];
    private $siz = [];

    public function __construct($n){
        for($i = 0; $i < $n; ++$i){
            $this->par[$i] = $i;
        }
        $this->siz = array_fill(0, $n, 1);
    }

    public function root($x){
        if($this->par[$x] === $x){
            return $x;
        }
        return $this->par[$x] = $this->root($this->par[$x]);
    }

    public function unite($x, $y){
        $rx = $this->root($x);
        $ry = $this->root($y);
        if($rx == $ry){
            return false;
        }
        if($this->siz[$rx] < $this->siz[$ry]){
            $rx ^= $ry ^= $rx ^= $ry;
        }
        $this->siz[$rx] += $this->siz[$ry];
        $this->par[$ry] = $rx;
        return true;
    }

    public function size($x){
        return $this->siz[$this->root($x)];
    }
}

const n = 1 << 20;

function main(){
    $sc = new Scanner;

    $q = $sc->nextInt();

    $a = array_fill(0, n, -1);
    $to = range(0, n - 1);
    $uf = new UnionFind(n);

    $ans = [];

    for($i = 0; $i < $q; ++$i){
        $t = $sc->nextInt();
        $x = $sc->nextInt();

        $h = $x % n;

        if($t === 1){
            // hを要素に持つ集合の末尾を更新
            $root_now = $uf->root($h);
            $tail_now = $to[$root_now];
            $a[$tail_now] = $x;

            // hを要素に持つ集合とその次の集合を結合
            $root_next = $uf->root(($tail_now + 1) % n);
            $uf->unite($h, $root_next);

            // 結合した集合の末尾を更新
            $root_unite = $uf->root($h);
            $to[$root_unite] = $to[$root_next];
        }
        else{
            $ans[] = $a[$h];
        }
    }

    foreach($ans as $v){
        printf("%d\n", $v);
    }
}

main();