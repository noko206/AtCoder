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
            list($rx, $ry) = [$ry, $rx];
        }
        $this->siz[$rx] += $this->siz[$ry];
        $this->par[$ry] = $rx;
        return true;
    }

    public function size($x){
        return $this->siz[$this->root($x)];
    }
}

function main(){
    $sc = new Scanner;

    $l = $sc->nextInt();
    $q = $sc->nextInt();

    $ans = [];
    $cut = [0, $l];
    for($i = 0; $i < $q; ++$i){
        $c = $sc->nextInt();
        $x = $sc->nextInt();

        if($c === 1){
            $index = lower_bound($cut, $x);
            array_splice($cut, $index, 0, $x);
        }
        else{
            $right = lower_bound($cut, $x);
            $left = $right - 1;
            $ans[] = $cut[$right] - $cut[$left];
        }
    }

    foreach($ans as $v){
        printf("%d\n", $v);
    }
}

main();