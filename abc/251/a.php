<?php

$n = trim(fgets(STDIN));
$c = mb_strlen($n);
if($c ==1){
    echo $n.$n.$n.$n.$n.$n."\n";
}elseif($c == 2){
    echo $n.$n.$n."\n";
}else{
    echo $n.$n."\n";
}

?>