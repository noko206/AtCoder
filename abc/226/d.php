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

function gcd($x, $y){
    return ($x % $y) ? gcd($y, $x % $y) : $y;
}

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();

    $x = [];
    $y = [];

    for($i = 0; $i < $n; ++$i){
        $x[$i] = $sc->nextInt();
        $y[$i] = $sc->nextInt();
    }

    $magic = [];
    $ans = 0;

    for($i = 0; $i < $n; ++$i){
        for($j = 0; $j < $n; ++$j){
            if($i === $j) continue;

            $dx = $x[$j] - $x[$i];
            $dy = $y[$j] - $y[$i];

            if($dx === 0){
                $dy = intdiv($dy, abs($dy));
            }
            else if($dy === 0){
                $dx = intdiv($dx, abs($dx));
            }
            else{
                $gcd = gcd(abs($dx), abs($dy));
                $dx = intdiv($dx, $gcd);
                $dy = intdiv($dy, $gcd);
            }
            
            if(!isset($magic[$dy][$dx])){
                ++$ans;
                $magic[$dy][$dx] = true;
            }
        }
    }

    printf("%d\n", $ans);
}

main();