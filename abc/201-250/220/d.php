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

const MOD = 998244353;

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();
    
    $a = [];
    for($i = 0; $i < $n; ++$i){
        $a[$i] = $sc->nextInt();
    }

    $dp = array_fill(0, $n, array_fill(0, 10, 0)); // dp[i][j]:i番目までの数字を使い、一番左がjとなる組み合わせの数
    $dp[0][$a[0]] = 1;

    for($i = 1; $i < $n; ++$i){
        for($j = 0; $j < 10; ++$j){
            // 足した時
            $dp[$i][($j + $a[$i]) % 10] += $dp[$i - 1][$j];
            $dp[$i][($j + $a[$i]) % 10] %= MOD;

            // 掛けた時
            $dp[$i][($j * $a[$i]) % 10] += $dp[$i - 1][$j];
            $dp[$i][($j * $a[$i]) % 10] %= MOD;
        }
    }

    for($i = 0; $i < 10; ++$i){
        printf("%d\n", $dp[$n - 1][$i]);
    }
}

main();