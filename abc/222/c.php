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

function janken($x, $y){
    $to_num = [
        'G' => 0,
        'C' => 1,
        'P' => 2,
    ];
    
    $x = $to_num[$x];
    $y = $to_num[$y];

    if(($x + 1) % 3 === $y){
        return 1;
    }
    else if($x === ($y + 1) % 3){
        return -1;
    }
    else{
        return 0;
    }
}

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();
    $m = $sc->nextInt();

    $a = [];
    $result = []; // value:[勝数, 番号]
    for($i = 0; $i < 2 * $n; ++$i){
        $a[$i] = $sc->next();
        $result[$i] = [0, $i];
    }

    // Mラウンドの試合を行う
    for($i = 0; $i < $m; ++$i){
        // 2*N人の試合を行う
        for($j = 0; $j < $n; ++$j){
            $x = $a[$result[2 * $j][1]][$i]; // 2*j番目の人の手
            $y = $a[$result[2 * $j + 1][1]][$i]; // 2*j+1番目の人の手

            // じゃんけん
            switch(janken($x, $y)){
                case 1:
                    --$result[2 * $j][0]; // 2*j番目の人の勝ち
                    break;
                case -1:
                    --$result[2 * $j + 1][0]; // 2*j+1番目の人の勝ち
                    break;
            }
        }
        // ソート
        sort($result);
    }

    foreach($result as list($_, $id)){
        printf("%d\n", $id + 1);
    }
}

main();