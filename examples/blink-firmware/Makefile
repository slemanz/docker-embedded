CC=arm-none-eabi-gcc
TARGET=blink

MACH= -mcpu=cortex-m4
FLOAT=-mfloat-abi=soft

BUILD_DIR= Build

LINKER= -T linkers/STM32F411.ld
MAP_FILE= -Wl,-Map=$(BUILD_DIR)/$(TARGET).map


CFLAGS= -c $(MACH) -mthumb $(FLOAT) -std=gnu99 -Wall -O0 -g \
		--specs=nano.specs -ffunction-sections -fdata-sections

LDFLAGS= $(MACH) -mthumb $(FLOAT) --specs=nosys.specs $(LINKER) $(MAP_FILE) -g \
		-Wl,--gc-sections -static -nostartfiles --specs=nano.specs \
		-Wl,--print-memory-usage

OBJCOPY=arm-none-eabi-objcopy
SIZE=arm-none-eabi-size

JLINK=jlink

###########################################
#				 INCLUDES
###########################################

INCLUDES+= -I Inc/


############################################
# 				SOURCE FILES
############################################

OBJS		+= $(BUILD_DIR)/main.o
OBJS		+= $(BUILD_DIR)/gpio_bits.o
OBJS		+= $(BUILD_DIR)/startup.o


PREREQ = $(BUILD_DIR)/

all: $(PREREQ) $(BUILD_DIR)/$(TARGET).elf

$(PREREQ):
	mkdir $(PREREQ)

$(BUILD_DIR)/%.o: Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o Src/$(*).c

$(BUILD_DIR)/%.o: linkers/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o linkers/$(*).c

$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin
	$(SIZE) $(BUILD_DIR)/$(TARGET).elf

load:
	$(JLINK) -CommanderScript flash.jlink

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all load clean