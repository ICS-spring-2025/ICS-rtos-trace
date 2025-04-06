Чтобы подключить макросы нужно


1. подключить к проекту trace_macros.h
2. выделить NONLOAD область памяти в Nкб
3. Объявить начало области для сохранения
4. configUSE_TRACE_FACILITY = 1


(qemu) pmemsave 0x80100000 0x100000 trace_dump.bin

export PATH=$PATH:/opt/riscv/bin

compile ```make DEBUG=1```
run ```qemu-system-riscv32 -nographic -machine virt -net none   -chardev stdio,id=con,mux=on -serial chardev:con   -mon chardev=con,mode=readline -monitor telnet:127.0.0.1:55555,server,nowait -bios none   -smp 1 -kernel ./build/RTOSDemo.axf```
