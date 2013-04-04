obj-m = flexdrop.o
KVERSION = $(shell uname -r)
EXTRA_CFLAGS += -Os -g -ggdb
#ccflags-y += -O0 -g -ggdb

flexdrop-objs := main.o kresolv.o

KALLSYMS_LOOKUP_NAME=$(shell grep 'T kallsyms_lookup_name$$' /proc/kallsyms | cut -d\  -f1)
CFLAGS_kresolv.o = -DKALLSYMS_LOOKUP_NAME=0x$(KALLSYMS_LOOKUP_NAME)LL

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean

re: clean all
