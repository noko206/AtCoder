<?php

class Scanner {
    private $arr = [];
    private $count = 0;
    private $pointer = 0;
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
    public function hasNext() {
        return $this->pointer < $this->count;
    }
    public function nextInt() {
        return (int)$this->next();
    }
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

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();

    $edge = [];
    for($i = 0; $i < $n - 1; ++$i){
        $u = $sc->nextInt() - 1;
        $v = $sc->nextInt() - 1;
        $w = $sc->nextInt();
        $edge[$i] = ['w' => $w, 'u' => $u, 'v' => $v];
    }

    sort($edge);

    $uf = new UnionFind($n);
    $ans = 0;
    
    foreach($edge as $e){
        $ans += $e['w'] * $uf->size($e['u']) * $uf->size($e['v']);
        $uf->unite($e['u'], $e['v']);
    }

    printf("%d\n", $ans);
}

main();