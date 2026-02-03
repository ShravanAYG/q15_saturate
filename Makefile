q15_saturate:
	riscv32-unknown-elf-gcc -march=rv32imcbv -mabi=ilp32 -O2 src/q15_saturate -o q15_saturate.elf
all: q15_saturate
