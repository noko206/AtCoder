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
    $a = $sc->nextInt();
    $b = $sc->nextInt();

    if(0 < $a && $b === 0){
        printf("Gold\n");
    }
    if($a === 0 && 0 < $b){
        printf("Silver\n");
    }
    if(0 < $a && 0 < $b){
        printf("Alloy\n");
    }
}

main();