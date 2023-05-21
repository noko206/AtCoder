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
    $is_ok = true; // true:文字列の重複なし,false:文字列の重複あり
    $check = []; // 文字列の重複チェック用
    for($i = 0; $i < 4; ++$i){
        $s = $sc->next();
        if(array_key_exists($s, $check)){
            $is_ok = false;
        }
        else{
            $check[$s] = 0;
        }
    }

    if($is_ok){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}

main();