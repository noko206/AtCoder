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

$seen = array_fill(0, 2e5, false);  // 頂点が探索されたか判定する配列

function dfs($graph, $v){
    global $seen;

    $seen[$v] = true;
    printf("%d ", $v + 1);

    foreach($graph[$v] as $next){
        if($seen[$next]) continue;
        dfs($graph, $next);
        printf("%d ", $v + 1);
    }

    if($v == 0) return;
}

function main(){
    $sc = new Scanner;

    $n = $sc->nextInt();

    $graph = [];
    for($i = 0; $i < $n - 1; ++$i){
        $a = $sc->nextInt() - 1;
        $b = $sc->nextInt() - 1;
        $graph[$a][] = $b;  // AからBに辺を張る
        $graph[$b][] = $a;  // BからAに辺を張る
    }

    for($i = 0; $i < $n; ++$i){
        if(empty($graph[$i])) continue;
        sort($graph[$i]);
    }

    dfs($graph, 0);
    
    printf("\n");
}

main();