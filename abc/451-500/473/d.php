<?php
[$n, $k] = array_map('intval', explode(' ', trim(fgets(STDIN))));

$ans = [];
$tmp = array_fill(0, $n, 0);

$dfs = function (int $pos, int $sum) use (&$dfs, &$ans, &$tmp, $k, $n): void {
    if ($pos === $n - 1) {
        if ($sum % $n === 0) {
            $tmp[$pos] = intdiv($sum, $n);
            $ans[] = $tmp;
        }
        return;
    }

    for ($i = 0; $i <= $k; $i++) {
        if ($sum - (($pos + 1) * $i) < 0) {
            break;
        }
        $tmp[$pos] = $i;
        $dfs($pos + 1, $sum - (($pos + 1) * $i));
    }
};

$dfs(0, $k);
sort($ans);

foreach ($ans as $values) {
    echo implode(' ', $values) . PHP_EOL;
}