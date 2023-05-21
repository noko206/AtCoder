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

const chokudai = 'chokudai';
const len_chokudai = 8;
const MOD = 1e9 + 7;

function main(){
    $sc = new Scanner;
    $s = $sc->next();

    $len = strlen($s);
    $dp = []; // $sのj文字目までを使ってchokudaiのi文字目までの文字列を作る場合の数
    $dp[0] = array_fill(0, $len, 0);

    // $sの$j-1文字目までを使って'c'を作る場合の数を求める
    for($j = 0; $j < $len; ++$j){
        if($j > 0){
            $dp[0][$j] = $dp[0][$j - 1];
        }

        if($s[$j] === chokudai[0]){
            ++$dp[0][$j];
        }
    }

    // 全ての$dpを求める
    for($i = 1; $i < len_chokudai; ++$i){
        $dp[$i] = array_fill(0, $len, 0);
        for($j = $i; $j < $len; ++$j){
            if($s[$j] === chokudai[$i]){
                $dp[$i][$j] = $dp[$i][$j - 1] + $dp[$i - 1][$j];
            }
            else{
                $dp[$i][$j] = $dp[$i][$j - 1];
            }
            $dp[$i][$j] %= MOD;
        }
    }

    printf("%d", $dp[len_chokudai - 1][$len - 1]);
}

main();