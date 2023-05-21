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
    private $par = []; // 親ノード
    private $siz = []; // 集合のサイズ

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

// 逆置換
function inverse_replace($arr){
    $ans = [];
    $n = count($arr);
    for($i = 0; $i < $n; ++$i){
        $ans[$v] = $i;
    }
    return $ans;
}

// $v以上のうち最小のインデックスを返す
function lower_bound($arr, $v){
    $ok = count($arr);
    $ng = -1;
    while(abs($ok - $ng) > 1){
        $mid = intdiv($ok + $ng, 2);
        if($arr[$mid] >= $v){
            $ok = $mid;
        }
        else{
            $ng = $mid;
        }
    }
    return $ok;
}

function search(){
    
}

function main(){
    $sc = new Scanner;

    $l = $sc->nextInt();
    $q = $sc->nextInt();

    $query = $cut = [];
    for($i = 0; $i < $q; ++$i){
        $c = $sc->nextInt();
        $x = $sc->nextInt();
        $query[] = [$c, $x];
        if($c === 1){
            $cut[] = $x;
        }
    }

    $cut[] = 0;
    $cut[] = $l;
    sort($cut);

    $uf = new UnionFind(count($cut));

    for($i = $q - 1; $i >= 0; --$i){
        list($c, $x) = $query[$i];
        if($c === 1){
            $j = lower_bound($cut, $x);
            $uf->unite($x, $cut[$j - 1]);
        }
        else{
            $j = lower_bound($cut, $x) - 1;
            $v = $cut[$j];

            
        }
    }
}

main();