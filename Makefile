axpy-rvv-q15.elf:
	riscv64-elf-gcc -march=rv32imcbv -mabi=ilp32 -O2 axpy-rvv-q15.c -o axpy-rvv-q15.elf

all: axpy-rvv-q15.elf
