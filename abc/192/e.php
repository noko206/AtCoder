<?php

function strings() { return explode(' ', trim(fgets(STDIN))); }
function ints() { return array_map('intval', strings()); }

const _LLINF = 1001001001001001001;

function main() {

	// 入力
	list($n, $m, $x, $y) = ints();
	$a = $b = $t = $k = [];
	for ($i = 0; $i < $m; ++$i) {
		list($a[], $b[], $t[], $k[]) = ints();
	}

	// 1. 整形
	--$x; --$y; // 0-indexedに変換
	$G = array_fill(0, $n, []); // 隣接リスト
	for ($i = 0; $i < $m; ++$i) {
		--$a[$i]; --$b[$i]; // 0-indexedに変換
		$G[$a[$i]][] = [$b[$i], $i]; // a->b に辺を張る
		$G[$b[$i]][] = [$a[$i], $i]; // b->a に辺を張る
	}

	// 2. ダイクストラ法
	$pq = new SplPriorityQueue;
	$pq->setExtractFlags(SplPriorityQueue::EXTR_BOTH); // データと優先順位の両方を含む配列を取り出すモードに設定
	$pq->insert($x, 0); // データ：都市｜優先度：都市Xからの最短距離
	$dist = array_fill(0, $n, _LLINF); // 都市Xからの最短距離
	$dist[$x] = 0;

	while (!$pq->isEmpty()) {

		// 距離が最短の都市を取得
		$tmp = $pq->extract();
		$v = $tmp['data'];
		$d = $tmp['priority'] * (-1); // 正に戻す

		// 最短経路でない場合は何もしない
		if ($dist[$v] < $d) continue;

		// 隣接している都市を探索
		foreach ($G[$v] as list($u, $i)) {

			// 発車までの待ち時間
			$wait = ($d % $k[$i] === 0) ? 0 : $k[$i] - ($d % $k[$i]);

			// 最短経路でない場合は何もしない
			if ($dist[$u] < $d + $t[$i] + $wait) continue;

			// 最短距離を更新
			$dist[$u] = $d + $t[$i] + $wait;
			$pq->insert($u, (-1) * $dist[$u]); // 優先度が低い順にソートしたいので、優先度は負にする
		}
	}

	// 出力
	if ($dist[$y] === _LLINF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", $dist[$y]);
	}
}

main();