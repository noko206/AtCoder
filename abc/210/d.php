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

const _INF = 2e18;

function main(){
    $sc = new Scanner;
    $h = $sc->nextInt();
    $w = $sc->nextInt();
    $c = $sc->nextInt();
    $a = [];
    for($i = 0; $i < $h; ++$i){
        $a[$i] = [];
        for($j = 0; $j < $w; ++$j){
            $a[$i][$j] = $sc->nextInt();
        }
    }

    $ans = _INF;
    for($_ = 0; $_ < 2; ++$_){
        $dp = [];   // key：マス(i,j), value：マス(0,0)～(i,j)におけるA_(i',j')-C*(i'+j')の最小値
        for($i = 0; $i < $h; ++$i){
            $dp[$i] = [];
            for($j = 0; $j < $w; ++$j){
                $dp[$i][$j] = _INF; // 初期化

                if($i - 1 >= 0){
                    // 最小値を伝播させる
                    $dp[$i][$j] = min($dp[$i][$j], $dp[$i - 1][$j]);
                }

                if($j - 1 >= 0){
                    // 最小値を伝播させる
                    $dp[$i][$j] = min($dp[$i][$j], $dp[$i][$j - 1]);
                }

                // マス(i,j)とマス(0,0)～(i,j)((i,j)自身は含まない)の組み合わせによる費用
                $ans = min($ans, $a[$i][$j] + $c * ($i + $j) + $dp[$i][$j]);

                // マス(i,j)のdpの値を更新
                $dp[$i][$j] = min($dp[$i][$j], $a[$i][$j] - $c * ($i + $j));
            }
        }
        // i'>iの場合を考慮して配列を逆順にする
        $a = array_reverse($a);
    }

    printf("%d\n", $ans);
}

main();