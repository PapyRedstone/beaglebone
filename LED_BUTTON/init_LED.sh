#!/bin/bash

#clear gpio
clear(){
    for i in {0..320}
    do
	echo $i > /sys/class/gpio/unexport
    done
}

# GPIO X_Y : setInput X Y
setInput(){
    local gpio=$(( 32*$1 + $2 ))
    echo $gpio > /sys/class/gpio/export
    echo in > /sys/class/gpio/gpio$gpio/direction
}

# GPIO X_Y : setOutput X Y
setOutput(){
    local gpio=$(( 32*$1 + $2 ))
    echo $gpio > /sys/class/gpio/export
    echo out > /sys/class/gpio/gpio$gpio/direction
}

clear
setInput 1 16
setOutput 1 18

setOutput 0 3
setOutput 1 28
echo 0 > /sys/class/gpio/gpio3/value
echo 0 > /sys/class/gpio/gpio60/value
