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
    $q = $sc->nextInt();

    $pq = new SplPriorityQueue;
    $pq->setExtractFlags(SplPriorityQueue::EXTR_PRIORITY);  // 優先順位を取り出す
    $s = 0; // 操作2のXの総和
    $ans = [];
    for($i = 0; $i < $q; ++$i){
        $p = $sc->nextInt();
        $x = 0; // 初期化
        switch($p){
            case 1:
                $x = $sc->nextInt();
                $x -= $s;   // キュー内の数字に合わせる
                $x *= -1;   // 符号を反転させて挿入
                $pq->insert('', $x);
                break;
            case 2:
                $x = $sc->nextInt();
                $s += $x;
                break;
            case 3:
                $x = $pq->extract();
                $x *= -1;   // 符号を反転
                $x += $s;   // 実際の値に戻す
                $ans[] = $x;
                break;
        }
    }

    foreach($ans as $a){
        printf("%d\n", $a);
    }
}

main();