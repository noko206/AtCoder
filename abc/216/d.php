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

    $n = $sc->nextInt();
    $m = $sc->nextInt();

    $index = array_fill(0, $n + 5, -1); // key:ボールの色,value:筒のindex
    $q = []; // M個の筒

    for($i = 0; $i < $m; ++$i){
        $k = $sc->nextInt();
        $q[$i] = new SplQueue();
        for($j = 0; $j < $k; ++$j){
            $q[$i]->enqueue($sc->nextInt());
        }
    }

    $pair = new SplQueue(); // 取り出せるボールのペア(筒のindex)

    // 筒の一番上を走査
    for($i = 0; $i < $m; ++$i){
        $a = $q[$i]->dequeue();
        if($index[$a] === -1){
            // ペアにならないものはindexを保存
            $index[$a] = $i;
        }
        else{
            // ペアになるものは$pairに追加
            $pair->enqueue([$index[$a], $i]);
        }
    }

    $cnt = 0; // 取り出したボールの種類数
    while($pair->count() > 0){
        $s = $pair->dequeue();
        ++$cnt;
        // ボールのペアについて2回分操作を行う
        foreach($s as $i){
            if($q[$i]->count() > 0){
                $a = $q[$i]->dequeue();
                if($index[$a] === -1){
                    // ペアにならないものはindexを保存
                    $index[$a] = $i;
                }
                else{
                    // ペアになるものは$pairに追加
                    $pair->enqueue([$index[$a], $i]);
                }
            }
        }
    }

    // 取り出したボールがN種類あるかチェック
    if($cnt === $n){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}

main();