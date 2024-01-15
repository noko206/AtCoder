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

function main()
{
    $sc = new Scanner;

    $n = $sc->nextInt();

    $G = array_fill(0, $n, []);
    $edge = [];

    for($i = 0; $i < $n - 1; ++$i)
    {
        $a = $sc->nextInt() - 1;
        $b = $sc->nextInt() - 1;

        $G[$a][] = $b;
        $G[$b][] = $a;

        $edge[] = [$a, $b];
    }
    
    $q = new SplQueue;
    $q->enqueue(0);

    $seen = array_fill(0, $n, false);
    $parent = array_fill(0, $n, -1);

    $color = [];
    $k = 1;

    while(!$q->isEmpty())
    {
        $v = $q->dequeue();

        $seen[$v] = true;

        $num = 1;

        foreach($G[$v] as $u)
        {
            if($num === $parent[$v])
            {
                ++$num;
            }

            if($seen[$u]) continue;

            $color[$v][$u] = $num;
            $color[$u][$v] = $num;

            $k = max($k, $num);
            ++$num;

            $parent[$u] = $color[$v][$u];

            $q->enqueue($u);
        }
    }

    printf("%d\n", $k);
    foreach($edge as list($v, $u))
    {
        printf("%d\n", $color[$v][$u]);
    }
}

main();