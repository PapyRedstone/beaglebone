CFLAGS = -g #-Wall -pedantic -std=c++17 -O3
LDFLAGS = -pthread #-lsfml-network -lsfml-graphics -lsfml-window -lsfml-system
#UNIT = -ftest-coverage -fprofile-arcs
GCC = ~/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc

TARGET = eeprom_i2c

SRC = $(wildcard src/*.c)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

all: $(TARGET)

remake: clean $(TARGET) cleanRemote

$(TARGET) : $(OBJ)
	$(GCC) obj/* $(LDFLAGS) -o $@ 

obj/%.o: src/%.c
	$(GCC) -c -Iinclude $(CFLAGS) -o $@ $<

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f

run:
	scp $(TARGET) init_$(TARGET).sh root@172.17.12.118:/root/
	ssh root@172.17.12.118 'chmod ugo+x /root/$(TARGET) && chmod ugo+x /root/init_$(TARGET).sh && /root/init_$(TARGET).sh'

cleanRemote:
	ssh root@172.17.12.118 'rm /root/$(TARGET)'

install:
	cd ~
	wget -c https://releases.linaro.org/components/toolchain/binaries/6.5-2018.12/arm-linux-gnueabihf/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf.tar.xz
	tar xf gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf.tar.xz
