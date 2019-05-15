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


echo 24c256 54 > /sys/bus/i2c/devices/i2c-1/new_device