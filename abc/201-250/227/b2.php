<?php

function ints() { return array_map('intval', explode(' ', trim(fgets(STDIN)))); }
function rep($n, $f) { for($i = 0; $i < $n; ++$i) { if($f($i)) break; } }

const _break = true;
const _continue = false;

function main()
{
    $n = ints()[0];
    $s = ints();

    $ans = 0;

    // $n回のfor文に展開
    rep($n, function($i) use(&$ans, $s)
    {
        $is_ok = false;
        // $s[$i]回のfor文に展開
        rep($s[$i], function($a) use(&$is_ok, $s, $i)
        {
            // $s[$i]回のfor文に展開
            rep($s[$i], function($b) use(&$is_ok, $s, $i, $a)
            {
                if($a === 0 || $b === 0) return _continue;

                if(4 * $a * $b + 3 * $a + 3 * $b === $s[$i])
                {
                    $is_ok = true;
                }
            });
        });
        if(!$is_ok)
        {
            ++$ans;
        }
    });

    printf("%d\n", $ans);
}

main();