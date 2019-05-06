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

echo am33xx_pwm > /sys/devices/bone_capemgr.9/slots
echo bone_pwm_P9_14 > /sys/devices/bone_capemgr.9/slots
echo 1800 > /sys/devices/ocp.3/pwm_test_P9_14.15/period
echo 1 > /sys/devices/ocp.3/pwm_test_P9_14.15/polarity
echo 0 > /sys/devices/ocp.3/pwm_test_P9_14.15/polarity
clear
setOutput 1 18
setOutput 0 3
setOutput 1 28
echo 0 > /sys/class/gpio/gpio3/value
echo 0 > /sys/class/gpio/gpio60/value

