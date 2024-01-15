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

    $xy = $sc->nextDouble();
    $x = (int)$xy;
    $y = (int)(($xy - $x) * 10);

    if($y <= 2){
        printf("%d-\n", $xy);
    }
    else if($y <= 6){
        printf("%d\n", $x);
    }
    else{
        printf("%d+", $x);
    }
}

main();