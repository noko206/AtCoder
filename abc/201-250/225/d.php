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

class Train {
    private $prev;
    private $next;

    public function __construct($n){
        $this->prev = array_fill(0, $n + 1, -1);
        $this->next = array_fill(0, $n + 1, -1);
    }

    public function unite($x, $y){
        $this->next[$x] = $y;
        $this->prev[$y] = $x;
    }

    public function separate($x, $y){
        $this->next[$x] = -1;
        $this->prev[$y] = -1;
    }

    public function print($x){
        $now = $x;
        while($this->prev[$now] !== -1){
            $now = $this->prev[$now];
        }

        $ans = [$now];
        while($this->next[$now] !== -1){
            $ans[] = $this->next[$now];
            $now = $this->next[$now];
        }

        printf("%d %s\n", count($ans), implode(' ', $ans));
    }
}

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();
    $q = $sc->nextInt();

    $t = new Train($n);
    for($i = 0; $i < $q; ++$i){
        $k = $sc->nextInt();
        switch($k){
            case 1:
                $x = $sc->nextInt();
                $y = $sc->nextInt();
                $t->unite($x, $y);
                break;
            case 2:
                $x = $sc->nextInt();
                $y = $sc->nextInt();
                $t->separate($x, $y);
                break;
            case 3:
                $x = $sc->nextInt();
                $t->print($x);
                break;
        }
    }
}

main();