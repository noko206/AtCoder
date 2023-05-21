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

    $div = array_fill(0, 100100, false);    // Aの約数かを判定
    for($i = 0; $i < $n; ++$i){
        $a = $sc->nextInt();
        // A_iの約数判定
        for($j = 1; $j * $j <= $a; ++$j){
            // 約数でないならスルー
            if($a % $j !== 0) continue;
            $div[$j] = true;                // $jを約数に持つ
            $div[intdiv($a, $j)] = true;    // $a/$jも約数に持つ
        }
    }

    $ans = [1]; // 条件を満たすkを格納
    for($k = 2; $k <= $m; ++$k){
        $is_ok = true;  // gcd(A,k)=1かを判定
        // kの約数判定
        for($i = 1; $i * $i <= $k; ++$i){
            // 約数でないならスルー
            if($k % $i !== 0) continue;
            // Aと同じ約数を持つ場合（1を除く）
            if(($div[$i] && $i > 1) || $div[intdiv($k, $i)]){
                $is_ok = false;
                break;
            }
        }
        if($is_ok){
            $ans[] = $k;
        }
    }

    printf("%d\n", count($ans));
    foreach($ans as $a){
        printf("%d\n", $a);
    }
}

main();