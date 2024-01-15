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
    $k = $sc->nextInt();

    $a = [];

    for($i = 0; $i < $n; ++$i){
        $a[$i] = $sc->nextInt();
    }

    $ok = 0;
    $ng = (int)1e18;

    while($ng - $ok !== 1){
        $mid = intdiv($ok + $ng, 2);
        $sum = 0;
        foreach($a as $v){
            $sum += min($v, $mid);
        }
        if($sum >= $mid * $k){
            $ok = $mid;
        }
        else{
            $ng = $mid;
        }
    }

    printf("%d\n", $ok);
}

main();