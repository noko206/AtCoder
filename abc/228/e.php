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

function mod_pow($a, $n, $p){
    if($n === 0) return 1;
    if($n === 1) return $a % $p;
    if($n % 2 === 1) return (($a % $p) * mod_pow($a, $n - 1, $p)) % $p;
    $t = mod_pow($a, intdiv($n, 2), $p);
    return ($t * $t) % $p;
}

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();
    $k = $sc->nextInt();
    $m = $sc->nextInt();

    if($m % MOD === 0){
        printf("0\n");
        return;
    }

    $r = mod_pow($k, $n, MOD - 1);
    $ans = mod_pow($m, $r, MOD);

    printf("%d\n", $ans);
}

main();