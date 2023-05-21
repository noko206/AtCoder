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

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();

    $a = [];
    for($i = 0; $i < $n; ++$i){
        $a[$i] = $sc->nextInt();
    }

    $x = $sc->nextInt();

    $a_sum = array_sum($a); // Aの総和
    $ans = intdiv($x, $a_sum) * $n; // 繰り返し分で使われたAの個数
    $x %= $a_sum; // Xを超えるのにあといくつ必要か

    for($i = 0; $i < $n; ++$i){
        $x -= $a[$i];
        ++$ans;
        if($x < 0){
            break;
        }
    }

    printf("%d\n", $ans);
}

main();