<?php

list($n,$x,$y) = explode(" ",trim(fgets(STDIN)));
$map = [];

while($stdin = trim(fgets(STDIN))){
	list($s,$t) = explode(" ",$stdin);
	$map[$s][] = $t;
	$map[$t][] = $s;
}

$memo = [];

$queue = [[$x,""]];
while(true){
	$v = current($queue);
	$target = $v[0];
	// $ans = $v[1];

	//ゴール
	if($target === $y){
		// echo $ans;
		// echo $target;
		// exit;
		break; // 追加！
	}

	$memo[$target] = 1;
	// $ans .= "{$target} ";

	foreach ($map[$target] as $v){
		if(isset($memo[$v])){
			continue;
		}
		// $queue[] = [$v,$ans];
		$queue[] = [$v,$target]; // 追加！($targetは$vの親)
	}
	next($queue);
}

// 以降追加！
$to = []; // key:頂点｜val:親
foreach ($queue as list($v, $p)) {
	$to[$v] = $p;
}

// y→xに親ノードを辿っていく
$ans = [];
$v = $y;
while ($to[$v] !== '') {
	$ans[] = $v;
	$v = $to[$v];
}
$ans[] = $v;

// x→yの順に変換
$ans = array_reverse($ans);
echo implode(' ', $ans), PHP_EOL;