<?php
[$n, $k] = array_map('intval', explode(' ', trim(fgets(STDIN))));
$ans = [];
$tmp = array_fill(0, $n, 0);

for ($a1 = 0; $a1 <= $k; $a1++) {
    $s1 = $k - $a1;
    if ($n >= 2 || $s1 < 0) break;
    $tmp[0] = $a1;
    if ($n === 1 && $s1 === 0) {
        $ans[] = $tmp;
        break;
    }

    for ($a2 = 0; $a2 <= $k; $a2++) {
        $s2 = $s1 - 2 * $a2;
        if ($n >= 3 || $s2 < 0) break;
        if ($n === 2 && $s2 === 0) {
            $ans[] = [$a1, $a2];
            break;
        }

        for ($a3 = 0; $a3 <= $k; $a3++) {
            $s3 = $s2 - 3 * $a3;
            if ($n >= 4 || $s3 < 0) break;
            if ($n === 3 && $s3 === 0) {
                $ans[] = [$a1, $a2, $a3];
                break;
            }

            for ($a4 = 0; $a4 <= $k; $a4++) {
                $s4 = $s3 - 4 * $a4;
                if ($n >= 5 || $s4 < 0) break;
                if ($n === 4 && $s4 === 0) {
                    $ans[] = [$a1, $a2, $a3, $a4];
                    break;
                }

                for ($a5 = 0; $a5 <= $k; $a5++) {
                    $s5 = $s4 - 5 * $a5;
                    if ($n >= 6 || $s5 < 0) break;
                    if ($n === 5 && $s5 === 0) {
                        $ans[] = [$a1, $a2, $a3, $a4, $a5];
                        break;
                    }

                    for ($a6 = 0; $a6 <= $k; $a6++) {
                        $s6 = $s5 - 6 * $a6;
                        if ($n >= 7 || $s6 < 0) break;
                        if ($n === 6 && $s6 === 0) {
                            $ans[] = [$a1, $a2, $a3, $a4, $a5, $a6];
                            break;
                        }

                        for ($a7 = 0; $a7 <= $k; $a7++) {
                            $s7 = $s6 - 7 * $a7;
                            if ($n >= 8 || $s7 < 0) break;
                            if ($n === 7 && $s7 === 0) {
                                $ans[] = [$a1, $a2, $a3, $a4, $a5, $a6, $a7];
                                break;
                            }

                            for ($a8 = 0; $a8 <= $k; $a8++) {
                                $s8 = $s7 - 8 * $a8;
                                if ($n >= 9 || $s8 < 0) break;
                                if ($n === 8 && $s8 === 0) {
                                    $ans[] = [$a1, $a2, $a3, $a4, $a5, $a6, $a7, $a8];
                                    break;
                                }

                                for ($a9 = 0; $a9 <= $k; $a9++) {
                                    $s9 = $s8 - 9 * $a9;
                                    if ($n >= 10 || $s9 < 0) break;
                                    if ($n === 9 && $s9 === 0) {
                                        $ans[] = [$a1, $a2, $a3, $a4, $a5, $a6, $a7, $a8, $a9];
                                        break;
                                    }

                                    for ($a10 = 0; $a10 <= $k; $a10++) {
                                        $s10 = $s9 - 10 * $a10;
                                        if ($s10 < 0) break;
                                        if ($n === 10 && $s10 === 0) {
                                            $ans[] = [$a1, $a2, $a3, $a4, $a5, $a6, $a7, $a8, $a9, $a10];
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

foreach ($ans as $v) {
    echo implode(' ', $v), PHP_EOL;
}
