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
    $x = $sc->next();

    $y = [];
    for($i = 0; $i < 4; ++$i){
        $y[] = (int)$x[$i]; // int型にキャスト
    }

    $is_same = true;    // 4桁とも同じ数字
    $is_step = true;    // 1234のような数字
    for($i = 0; $i < 3; ++$i){
        if($y[$i] !== $y[$i + 1]){
            $is_same = false;
        }
        if(($y[$i] + 1) % 10 !== $y[$i + 1]){
            $is_step = false;
        }
    }

    if($is_same || $is_step){
        printf("Weak\n");
    }
    else{
        printf("Strong\n");
    }
}

main();