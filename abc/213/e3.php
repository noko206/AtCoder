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

    $dq = new SplDoublyLinkedList;  // 両端キュー
    $dq->unshift([0, 0]);   // スタート位置を入れる

    while($dq->count() > 0){
        $p = $dq->shift();  // 先頭から値を取得・削除
        $x = $p[0];
        $y = $p[1];
        $seen[$y][$x] = true;   // 探索済みにする
        $d = $dist[$y][$x]; // 現在の距離を取得

        // 縦・横・斜めの4方向にコスト0で移動できる場合
        for($i = 0; $i < 4; ++$i){
            $nx = $x + dx[$i];
            $ny = $y + dy[$i];

            // 範囲外ならスルー
            if($nx < 0 || $ny < 0 || $nx >= $w || $ny >= $h) continue;
            // 探索済みならスルー
            if($seen[$ny][$nx]) continue;
            // コスト0で移動できないならスルー
            if($s[$ny][$nx] === '#') continue;

            $dist[$ny][$nx] = $d;   // コスト0で距離を更新
            $dq->unshift([$nx, $ny]);   // キューの先頭に詰める
        }

        // 自身を中心に5x5の四隅を除いた区画にコスト1で移動できる場合
        for($i = -2; $i <= 2; ++$i){
            for($j = -2; $j <= 2; ++$j){
                $nx = $x + $i;
                $ny = $y + $j;

                // 範囲外ならスルー
                if($nx < 0 || $ny < 0 || $nx >= $w || $ny >= $h) continue;
                // 探索済みならスルー
                if($seen[$ny][$nx]) continue;
                // マンハッタン距離が3より大きければスルー
                if(abs($i) + abs($j) > 3) continue;
                // このルートがコスト的に最適でなければスルー
                if($dist[$ny][$nx] <= $d + 1) continue;

                $dist[$ny][$nx] = $d + 1;   // コスト1で距離を更新
                $dq->push([$nx, $ny]);  // キューの末尾に詰める
            }
        }
    }

    printf("%d\n", $dist[$h - 1][$w - 1]);
}

main();