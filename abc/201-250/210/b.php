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
    $s = $sc->next();

    $ans = -1;
    for($i = 0; $i < $n; ++$i){
        // 0の場合は何もしない
        if($s[$i] === '0') continue;

        if($i % 2 === 0){
            // 偶数番目が1なら高橋君
            $ans = 'Takahashi';
        }
        else{
            // 奇数番目が1なら青木君
            $ans = 'Aoki';
        }
        break;
    }

    printf("%s\n", $ans);
}

main();