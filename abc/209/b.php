<?php namespace Track;

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
    $x = $sc->nextInt();
    $a = [];
    for($i = 0; $i < $n; ++$i){
        $a[$i] = $sc->nextInt();
    }
    
    $sum = 0;
    for($i = 0; $i < $n; ++$i){
        if($i % 2 === 1){
            --$a[$i];
        }
        $sum += $a[$i];
    }

    if($sum <= $x){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}

main();