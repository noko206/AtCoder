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
    $a = $sc->nextInt();
    $x = $sc->nextInt();
    $y = $sc->nextInt();

    $ans = -1;
    if($n <= $a){
        // 購入するキャベツがA個以下
        $ans = $n * $x;
    }
    else{
        // 購入するキャベツがA+1個以上
        $ans = $a * $x + ($n - $a) * $y;
    }

    printf("%d\n", $ans);
}

main();