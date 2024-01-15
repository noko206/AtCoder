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
    $k = $sc->nextInt();
    $c = [];
    $count_candy = [];  // key：色, value：キャンディの数
    for($i = 0; $i < $n; ++$i){
        $c[$i] = $sc->nextInt();
        $count_candy[$c[$i]] = 0;
    }

    $count_type = 0;    // キャンディの種類数
    // 1～k-1番目のキャンディの種類数を求める
    for($i = 0; $i < $k; ++$i){
        if($count_candy[$c[$i]] === 0){
            // c_iが初めて現れた色なら種類数を+1
            ++$count_type;
        }
        ++$count_candy[$c[$i]];
    }

    $ans = $count_type;
    // i-K+1～i番目のキャンディの種類数を求める
    for($i = $k; $i < $n; ++$i){
        --$count_candy[$c[$i - $k]];
        if($count_candy[$c[$i - $k]] === 0){
            // c_iのキャンディが0個になったら種類数を-1
            --$count_type;
        }

        if($count_candy[$c[$i]] === 0){
            // c_iが初めて現れた色なら種類数を+1
            ++$count_type;
        }
        ++$count_candy[$c[$i]];

        $ans = max($ans, $count_type);
    }

    printf("%d\n", $ans);
}

main();