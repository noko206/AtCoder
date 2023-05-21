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

const _INF = 2e9;
const MOD = 1e9 + 7;

function main(){
    $sc = new Scanner;
    $n = $sc->nextInt();
    $m = $sc->nextInt();
    $graph = [];
    for($i = 0; $i < $n; ++$i){
        $graph[$i] = [];
    }
    for($i = 0; $i < $m; ++$i){
        $a = $sc->nextInt() - 1;
        $b = $sc->nextInt() - 1;
        $graph[$a][] = $b; // $aから$bに辺を張る
        $graph[$b][] = $a; // $bから$aに辺を張る
    }

    // BFSで最短経路を求める
    $vs = []; // 1に近い順に頂点を格納
    $dist = array_fill(0, $n, _INF); // key:頂点,value:頂点0からの最短距離
    $dist[0] = 0;
    $q = new SplQueue();
    $q->enqueue(0);
    while($q->count() > 0){
        $v = $q->dequeue();
        $vs[] = $v;
        foreach($graph[$v] as $u){
            if($dist[$u] != _INF) continue;
            $dist[$u] = $dist[$v] + 1;
            $q->enqueue($u);
        }
    }

    // DPで最短経路の個数を求める
    $dp = array_fill(0, $n, 0); // key:頂点,value:最短経路の個数
    $dp[0] = 1;
    foreach($vs as $v){
        foreach($graph[$v] as $u){
            if($dist[$v] + 1 === $dist[$u]){
                $dp[$u] += $dp[$v];
                $dp[$u] %= MOD;
            }
        }
    }

    printf("%d\n", $dp[$n - 1]);
}

main();