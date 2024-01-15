<?php

function ints() { return array_map('intval', explode(' ', trim(fgets(STDIN)))); }
function rep($n, $f) { for($i = 0; $i < $n; ++$i) { if($f($i)) break; } }

const _break = true;
const _continue = false;

function main()
{
    $n = ints()[0];
    $cnt = array_fill(0, $n, 0);

    // $n-1回のfor文に展開
    rep($n - 1, function($i) use(&$cnt)
    {
        list($a, $b) = ints();
        ++$cnt[$a - 1];
        ++$cnt[$b - 1];
    });

    $is_ok = false;

    // $n回のfor文に展開
    rep($n, function($i) use(&$is_ok, $cnt, $n)
    {
        if($cnt[$i] === $n - 1)
        {
            $is_ok = true;
            return _break;
        }
    });

    printf("%s\n", $is_ok ? 'Yes' : 'No');
}

main();