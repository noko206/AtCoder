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
    $a = $b = [];
    for($i = 0; $i < $n; ++$i){
        $a[$i] = $sc->nextInt();
    }
    for($i = 0; $i < $n; ++$i){
        $b[$i] = $sc->nextInt();
    }

    // dp[i][j]:=i番目でjを選んだときの組み合わせの数
    $dp = array_fill(0, $n + 1, array_fill(0, 3001, 0));
    for($i = $a[0]; $i <= $b[0]; ++$i){
        $dp[0][$i] = 1;
    }

    // 配るDP
    for($i = 0; $i < $n - 1; ++$i){
        // 組み合わせ数を配る
        for($j = $a[$i]; $j <= $b[$i]; ++$j){
            $dp[$i + 1][max($j, $a[$i + 1])] += $dp[$i][$j];
            $dp[$i + 1][max($j, $a[$i + 1])] %= MOD;
        }
        // 累積和
        for($j = $a[$i + 1]; $j < $b[$i + 1]; ++$j){
            $dp[$i + 1][$j + 1] += $dp[$i + 1][$j];
            $dp[$i + 1][$j + 1] %= MOD;
        }
    }

    $ans = 0;
    foreach($dp[$n - 1] as $v){
        $ans += $v;
        $ans %= MOD;
    }

    printf("%d\n", $ans);
}

main();