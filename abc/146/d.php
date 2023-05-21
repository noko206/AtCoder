<?php

class Scanner {
    private $queue;
    private function all_enqueue() { foreach(explode(' ', trim(fgets(STDIN))) as $v) $this->queue->enqueue($v); }
    private function all_dequeue() { while(!$this->queue->isEmpty()) $a[] = $this->queue->dequeue(); return $a; }
    public function __construct() { $this->queue = new SplQueue; }
    public function string() { if($this->queue->isEmpty()) self::all_enqueue(); return $this->queue->dequeue(); }
    public function int() { return (int)$this->string(); }
    public function double() { return (double)$this->string(); }
    public function strings() { if($this->queue->isEmpty()) self::all_enqueue(); return self::all_dequeue(); }
    public function ints() { return array_map('intval', $this->strings()); }
    public function doubles() { return array_map('doubleval', $this->strings()); }
}
function chmax(&$a, $b) { if($a < $b) { $a = $b; return true; } return false; }
function chmin(&$a, $b) { if($a > $b) { $a = $b; return true; } return false; }
function gcd(int $a, int $b): int { return ($a % $b) ? gcd($b, $a % $b) : $b; }
function lcm(int $a, int $b): int { return intdiv($a, gcd($a, $b)) * $b; }
const _DIF = [[-1, 0], [0, 1], [1, 0], [0, -1]];
const _INF = 1001001001001001001;
const _MOD = 1000000007;

function main()
{
    $sc = new Scanner;

    $n = $sc->int();

    $G = array_fill(0, $n, []);
    $edge = [];

    for($i = 0; $i < $n - 1; ++$i)
    {
        list($a, $b) = $sc->ints();
        
        --$a;
        --$b;

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

            chmax($k, $num);
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