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

function main(){
    $sc = new Scanner;
    $n = $sc->nextInt();
    $m = $sc->nextInt();
    
    $a = $b = [];
    for($i = 0; $i < $n; ++$i){
        $a[] = $sc->nextInt();
    }
    for($i = 0; $i < $m; ++$i){
        $b[] = $sc->nextInt();
    }

    sort($a);
    sort($b);

    $ans = INF;
    $i = $j = 0;
    while($i < $n && $j < $m){
        $ans = min($ans, abs($a[$i] - $b[$j]));
        if($a[$i] < $b[$j]){
            ++$i;   // $aの次を見る
        }
        else{
            ++$j;   // $bの次を見る
        }
    }

    printf("%d\n", $ans);
}

main();