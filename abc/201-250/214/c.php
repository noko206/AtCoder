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

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();
    
    $s = [];
    for($i = 0; $i < $n; ++$i){
        $s[$i] = $sc->nextInt();
    }

    $t = [];
    $min_i = 0;
    for($i = 0; $i < $n; ++$i){
        $t[$i] = $sc->nextInt();
        if($t[$min_i] > $t[$i]){
            $min_i = $i;
        }
    }

    $dp[$min_i] = $t[$min_i];
    for($i = 0; $i < $n; ++$i){
        $j = ($i + $min_i) % $n;
        $j_next = ($j + 1) % $n;
        $dp[$j_next] = min($t[$j_next], $s[$j] + $dp[$j]);
    }

    for($i = 0; $i < $n; ++$i){
        printf("%d\n", $dp[$i]);
    }
}

main();