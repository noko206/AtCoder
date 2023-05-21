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

function main(){
    $sc = new Scanner;

    $q = $sc->nextInt();

    $queue = new SplQueue();
    $p_queue = new SplPriorityQueue();
    $p_queue->setExtractFlags(SplPriorityQueue::EXTR_PRIORITY);  // 優先順位を取り出す
    $ans = [];

    for($i = 0; $i < $q; ++$i){
        $query = $sc->nextInt();
        switch($query){
            case 1:
                $queue->enqueue($sc->nextInt());
                break;
            case 2:
                if($p_queue->count() === 0){
                    $ans[] = $queue->dequeue();
                }
                else{
                    $ans[] = (-1) * $p_queue->extract();
                }
                break;
            case 3:
                while($queue->count() > 0){
                    $p_queue->insert('', (-1) * $queue->dequeue());
                }
                break;
        }
    }

    foreach($ans as $v){
        printf("%d\n", $v);
    }
}

main();