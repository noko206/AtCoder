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

class Deque {
    private $queue = array();

    // 末尾に要素を追加する
    public function push_back($value) {
        return array_push($this->queue, $value);
    }

    // 末尾の要素を取得・削除する
    public function pop_back() {
        return array_pop($this->queue);
    }

    // 先頭に要素を追加する
    public function push_front($value) {
        return array_unshift($this->queue, $value);
    }

    // 先頭の要素を取得・削除する
    public function pop_front() {
        return array_shift($this->queue);
    }

    // 要素数を取得する
    public function count() {
        return count($this->queue);
    }
}

const _INF = 2e9;
const dy = [1, 0, -1, 0];
const dx = [0, 1, 0, -1];

function main(){
    $sc = new Scanner;
    
    $h = $sc->nextInt();
    $w = $sc->nextInt();

    $s = [];
    for($i = 0; $i < $h; ++$i){
        $s[$i] = $sc->next();
    }

    $dist = array_fill(0, $h, array_fill(0, $w, _INF)); // スタートからの距離
    $dist[0][0] = 0;
    $seen = array_fill(0, $h, array_fill(0, $w, false)); // 探索した区画か判定

    $dq = new Deque();
    $dq->push_front([0, 0]);

    while($dq->count() > 0){
        $p = $dq->pop_front();
        $x = $p[0];
        $y = $p[1];
        $seen[$y][$x] = true;
        for($i = 0; $i < 4; ++$i){
            $nx = $x + dx[$i];
            $ny = $y + dy[$i];
            if($nx < 0 || $ny < 0 || $nx >= $w || $ny >= $h) continue;
            if($seen[$ny][$nx]) continue;
            if($s[$ny][$nx] === '#') continue;
            $dist[$ny][$nx] = $dist[$y][$x];
            $dq->push_front([$nx, $ny]);
        }
        for($i = -2; $i <= 2; ++$i){
            for($j = -2; $j <= 2; ++$j){
                $nx = $x + $i;
                $ny = $y + $j;
                if($nx < 0 || $ny < 0 || $nx >= $w || $ny >= $h) continue;
                if($seen[$ny][$nx]) continue;
                if(abs($i) + abs($j) > 3) continue;
                if($dist[$ny][$nx] <= $dist[$y][$x] + 1) continue;
                $dist[$ny][$nx] = $dist[$y][$x] + 1;
                $dq->push_back([$nx, $ny]);
            }
        }
        if($seen[$h - 1][$w - 1]) break;
    }

    printf("%d\n", $dist[$h - 1][$w - 1]);
}

main();