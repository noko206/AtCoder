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

function dfs($x){
    global $t, $a, $acquired, $ans;

    if($acquired[$x]) return;

    foreach($a[$x] as $v){
        dfs($v);
    }

    $acquired[$x] = true;
    $ans += $t[$x];
}

function main(){
    global $t, $a, $acquired, $ans;
    
    $sc = new Scanner;

    $n = $sc->nextInt();

    $t = [];
    $k = [];
    $a = array_fill(0, $n, []);

    for($i = 0; $i < $n; ++$i){
        $t[$i] = $sc->nextInt();
        $k[$i] = $sc->nextInt();
        for($j = 0; $j < $k[$i]; ++$j){
            $a[$i][$j] = $sc->nextInt();
            --$a[$i][$j];
        }
    }

    $acquired = array_fill(0, $n, false);
    $ans = 0;

    dfs($n - 1);

    printf("%d\n", $ans);
}

main();