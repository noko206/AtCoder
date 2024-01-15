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

// 辞書順によるその次の順列を生成する
function next_permutation(&$arr){
	// 要素数の取得
	$n = count($arr);

	// N-2番目から走査
	$i = $n - 2;
	while($i >= 0){
		// 昇順の箇所があればbreak
		if($arr[$i] < $arr[$i + 1]) break;
		--$i;
	}

	// 辞書順で次の順列が存在しなければfalse
	if($i === -1) return false;

	// N-1番目から走査
	$j = $n - 1;
	while($j > 0){
		// i番目より大きい値があればbreak
		if($arr[$i] < $arr[$j]) break;
		--$j;
	}

	// i番目とj番目の値を交換
	list($arr[$i], $arr[$j]) = [$arr[$j], $arr[$i]];

	// i,i+1番目を境に配列を分割
	$arr_sort = array_slice($arr, $i + 1);
	$arr = array_slice($arr, 0, $i + 1);

	// i+1番目以降をソート
	sort($arr_sort);

	// indexに気をつけながら結合
	foreach($arr_sort as $v){
		$arr[] = $v;
	}

	// 辞書順で次の順列が存在したのでtrue
	return true;
}

function main(){
	$sc = new Scanner;

	$s = $sc->next();
	$k = $sc->nextInt();

	$s = str_split($s);	// 配列に変換する
	sort($s);			// ソートする

	for($i = 0; $i < $k - 1; ++$i){
		next_permutation($s);
	}

	$s = implode($s);	// 文字列に変換する

	printf("%s\n", $s);
}

main();