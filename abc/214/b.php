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

    $s = $sc->nextInt();
    $t = $sc->nextInt();

    $ans = 0;
    for($a = 0; $a <= 100; ++$a){
        for($b = 0; $b <= 100; ++$b){
            for($c = 0; $c <= 100; ++$c){
                if($a + $b + $c > $s) continue;
                if($a * $b * $c > $t) continue;
                ++$ans;
            }
        }
    }

    printf("%d\n", $ans);
}

main();