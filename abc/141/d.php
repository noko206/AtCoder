<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }

function main() {

	// 入力
	list($n, $m) = ints();
	$a = ints();

	// 1. priority_queueに品物の金額を詰める
	$pq = new SplPriorityQueue;
	foreach ($a as $v) {
		$pq->insert($v, $v);
	}

	// 2. 割引券を使う
	while ($m--) {
		$v = $pq->extract(); // 最も大きい金額を取得
		$v = intdiv($v, 2); // 割引
		$pq->insert($v, $v); // 再度priority_queueに詰める
	}

	// 3. 割引後の品物の合計金額を求める
	$ans = 0;
	while (!$pq->isEmpty()) {
		$ans += $pq->extract();
	}

	// 出力
	printf("%d\n", $ans);
}

main();