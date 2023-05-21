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

// xをk進数から10進数に変換
// xはint型
function baseK_to_base10($k, $x){
    $ans = 0;
    $keta = 1;

    while($x > 0){
        $ans += ($x % 10) * $keta;
        $x = intdiv($x, 10);
        $keta *= $k;
    }

    return $ans;
}

function main(){
    $sc = new Scanner;

    $k = $sc->nextInt();
    $a = $sc->nextInt();
    $b = $sc->nextInt();

    $a = baseK_to_base10($k, $a);
    $b = baseK_to_base10($k, $b);

    printf("%d\n", $a * $b);
}

main();