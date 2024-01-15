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

$graph = [];    // key:頂点,value:隣接頂点
$depth = [];    // 根からの深さ

// $d:根からの深さ,$v:頂点,$p:親
function dfs($d, $v, $p){
    global $graph, $depth;
    $depth[$v] = $d;
    ++$d;
    foreach($graph[$v] as $next){
        if($next === $p) continue;
        dfs($d, $next, $v);
    }
}

function main(){
    global $graph, $depth;
    $sc = new Scanner;
    $n = $sc->nextInt();
    $q = $sc->nextInt();
    for($i = 0; $i < $n; ++$i){
        $graph[$i] = [];
    }
    for($i = 0; $i < $n - 1; ++$i){
        $a = $sc->nextInt() - 1;
        $b = $sc->nextInt() - 1;
        $graph[$a][] = $b;  // $aから$bに辺を張る
        $graph[$b][] = $a;  // $bから$aに辺を張る
    }
    $c = $d = [];
    for($i = 0; $i < $q; ++$i){
        $c[$i] = $sc->nextInt() - 1;
        $d[$i] = $sc->nextInt() - 1;
    }

    dfs(0, 0, 0);

    for($i = 0; $i < $q; ++$i){
        if(($depth[$c[$i]] + $depth[$d[$i]]) % 2 === 0){
            printf("Town\n");
        }
        else{
            printf("Road\n");
        }
    }
}

main();