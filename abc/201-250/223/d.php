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

function topological_sort($G){
    $ans = [];
    $n = count($G);
    $indeg = array_fill(0, $n, 0);
    for($i = 0; $i < $n; ++$i){
        foreach($G[$i] as $v){
            ++$indeg[$v];
        }
    }
    $pq = new SplPriorityQueue;
    $pq->setExtractFlags(SplPriorityQueue::EXTR_DATA);
    for($i = 0; $i < $n; ++$i){
        if($indeg[$i] === 0){
            $pq->insert($i, -$i);
        }
    }
    while($pq->count() > 0){
        $now = $pq->extract();
        $ans[] = $now;
        foreach($G[$now] as $v){
            --$indeg[$v];
            if($indeg[$v] === 0){
                $pq->insert($v, -$v);
            }
        }
    }
    return $ans;
}

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();
    $m = $sc->nextInt();

    $G = array_fill(0, $n, []);
    for($i = 0; $i < $m; ++$i){
        $a = $sc->nextInt();
        $b = $sc->nextInt();
        --$a;
        --$b;
        $G[$a][] = $b;
    }

    $res = topological_sort($G);

    if(count($res) !== $n){
        printf("-1\n");
    }
    else{
        foreach($res as $v){
            printf("%d ", $v + 1);
        }
        printf("\n");
    }
}

main();