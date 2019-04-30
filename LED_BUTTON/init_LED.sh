#!/bin/bash

# GPIO X_Y : setInput X Y
setInput(){
    local gpio='32*$1+$2'
    echo $gpio > /sys/class/gpio/export
    echo in > /sys/class/gpio/gpio+$gpio+/direction
}

# GPIO X_Y : setOutput X Y
setOutput(){
    local gpio='32*$1+$2'
    echo $gpio > /sys/class/gpio/export
    echo out > /sys/class/gpio/gpio+$gpio+/direction
}

echo 50 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio50/direction

echo 48 > /sys/class/gpio/export
echo in > /sys/class/gpio/gpio48/direction

