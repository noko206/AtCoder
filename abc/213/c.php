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

// 一次元の座標圧縮
function compress($arr){
    $ans = [];
    $i = 1; // 圧縮後の座標
    $pre_v = -1;    // 一つ前の座標

    asort($arr);    // keyを維持したままソート
    foreach($arr as $k => $v){
        if($pre_v !== -1 && $pre_v !== $v){
            ++$i;
        }
        $ans[$k] = $i;  // 圧縮した座標
        $pre_v = $v;    // 一つ前の座標を更新
    }

    return $ans;
}

function main(){
    $sc = new Scanner;
    
    $h = $sc->nextInt();
    $w = $sc->nextInt();
    $n = $sc->nextInt();

    $a = $b = [];
    for($i = 0; $i < $n; ++$i){
        $a[$i] = $sc->nextInt();
        $b[$i] = $sc->nextInt();
    }

    // 座標圧縮
    $ans_a = compress($a);
    $ans_b = compress($b);

    for($i = 0; $i < $n; ++$i){
        printf("%d %d\n", $ans_a[$i], $ans_b[$i]);
    }
}

main();