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
    $m = $sc->nextInt();

    $b = [];
    for($i = 0; $i < $n; ++$i){
        for($j = 0; $j < $m; ++$j){
            $b[$i][$j] = $sc->nextInt();
            --$b[$i][$j];
        }
    }

    $is_ok = true;

    // 縦方向のチェック
    for($i = 0; $i < $n - 1; ++$i){
        if($b[$i][0] + 7 !== $b[$i + 1][0]){
            $is_ok = false;
        }
    }

    // 横方向のチェック
    for($i = 0; $i < $n; ++$i){
        for($j = 0; $j < $m - 1; ++$j){
            if(($b[$i][$j] % 7) + 1 !== ($b[$i][$j + 1] % 7)){
                $is_ok = false;
            }
        }
    }

    if($is_ok){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}

main();