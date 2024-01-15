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

const MOD = 1e9 + 7;

function main(){
    $sc = new Scanner;
    $n = $sc->nextInt();
    $c = [];
    for($i = 0; $i < $n; ++$i){
        $c[$i] = $sc->nextInt();
    }

    sort($c);

    $ans = 1;
    for($i = 0; $i < $n; ++$i){
        $ans *= ($c[$i] - $i);
        $ans %= MOD;
    }

    printf("%d\n", $ans);
}

main();