#include <stdio.h>
#include <stdint.h>

void print_hex_bytes(int len, const unsigned char *data) {

	for (int i=0; i<len; i++) {
		printf("%02x ", data[i]);
	}
	printf("   ");

}


void disassemble(const unsigned char *raw_instr) {

	const char reg[8][5] = {"%rax", "%rcx", "%rdx", "%rbx", "%rsp", "%rbp", "%rsi", "%rdi"};
	unsigned char opcode = raw_instr[0];
	int len;

	if (opcode == 0x68) {
		len = 5;
		print_hex_bytes(len, raw_instr);
		uint32_t *immediate = (uint32_t *)(raw_instr + 1);
		printf("pushq $%#x\n",  *immediate);

	}
	else if ((opcode & 0x78) == 0x50) {
		len = 1;
		print_hex_bytes(len, raw_instr);
		printf("pushq %s\n", reg[opcode & 0x7]);

	}
	else if (opcode == 0xff) {
		unsigned char var = raw_instr[1];
		if (var == 0x32) {
			len = 2;
			print_hex_bytes(len, raw_instr);
			printf("pushq (%s)\n", reg[var & 0x7]);

		}
		else if (var == 0x70) {
			len = 3;
			print_hex_bytes(len, raw_instr);
			printf("pushq %#x(%s)\n", raw_instr[2], reg[var & 0x7]);

		}
		else if (var == 0x74) {
			len = 4;
			int scale = 1 << (raw_instr[2] >> 6);
			print_hex_bytes(len, raw_instr);
			printf("pushq %#x(%s,%s,%d)\n", raw_instr[3], reg[raw_instr[2] & 0x7], reg[(raw_instr[2] >> 3) & 0x7], scale);

		}
	}
}

int main()
{
    // pushq $0x3f10
    unsigned char inst1[5] = {0x68,0x10,0x3f,0x00,0x00};
    // pushq %rbx
    unsigned char inst2[1] = {0x53};
    // pushq (%rdx)
    unsigned char inst3[2] = {0xff, 0x32};
    // pushq 0x8(%rax)
    unsigned char inst4[3] = {0xff, 0x70, 0x08};
    // pushq 0xff(%rbp,%rcx,4)
    unsigned char inst5[4] = {0xff, 0x74, 0x8d, 0xff};
    disassemble(inst1);
    disassemble(inst2);
    disassemble(inst3);
    disassemble(inst4);
    disassemble(inst5);
    return 0;
}

