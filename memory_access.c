
#include <stdint.h>
#include <stdio.h>

#define MEM_SIZE 16384
int8_t mem[MEM_SIZE]; 

// signed byte read
int32_t lb(int32_t reg, int32_t kte) {
    int32_t address = reg + kte;  // calculates the address by adding the register value and the offset
    if (address < 0 || address >= MEM_SIZE) { // checks if the address is within bounds
        printf("error: address out of memory bounds\n");
        return -1;
    }
    int8_t byte = mem[address];  // reads the byte from memory at the calculated address
    return (int32_t) byte;  // converts the read byte to int32_t, sign-extending it
}

// unsigned byte read
int32_t lbu(int32_t reg, int32_t kte) {
    int32_t address = reg + kte;  // calculates the address by adding the register value and the offset
    if (address < 0 || address >= MEM_SIZE) { // checks if the address is within bounds
        printf("error: address out of memory bounds\n");
        return -1;
    }
    uint8_t byte = (uint8_t)mem[address];  // reads the byte from memory and interprets it as unsigned
    return (int32_t) byte;  // converts the read byte to int32_t without sign extension
}

// word (32-bit) read
int32_t lw(int32_t reg, int32_t kte) {
    int32_t address = reg + kte;
    if (address % 4 != 0) { // checks if the address is aligned to 4 bytes
        printf("error: address is not a multiple of 4\n");
        return -1;
    }
    int32_t word = ((uint8_t)mem[address + 3] << 24) |
                   ((uint8_t)mem[address + 2] << 16) |
                   ((uint8_t)mem[address + 1] << 8) |
                   ((uint8_t)mem[address]);
    return word;
}

// byte write to memory
void sb(int32_t reg, int32_t kte, int8_t byte) {
    int32_t address = reg + kte;  // calculates the address by adding the register value and the offset
    if (address < 0 || address >= MEM_SIZE) { // checks if the address is within bounds
        printf("error: address out of memory bounds\n");
        return;
    }
    mem[address] = byte;  // stores the byte at the calculated address
}

// word (32-bit) write to memory
void sw(int32_t reg, int32_t kte, int32_t word) {
    int32_t address = reg + kte;
    if (address % 4 != 0) { // checks if the address is aligned to 4 bytes
        printf("error: address is not a multiple of 4\n");
        return;
    }
    mem[address] = word & 0xFF; // LSB
    mem[address + 1] = (word >> 8) & 0xFF;
    mem[address + 2] = (word >> 16) & 0xFF;
    mem[address + 3] = (word >> 24) & 0xFF; // MSB
}

int main() {
    // tests for writing to memory
    sw(0, 0, 0xABACADEF);
    sb(4, 0, 1);
    sb(4, 1, 2);
    sb(4, 2, 3);
    sb(4, 3, 4);

    // expected values
    printf("lw(0, 0): 0x%x\n", lw(0, 0));
    printf("lb(0, 0): 0x%x\n", lb(0, 0));
    printf("lb(0, 1): 0x%x\n", lb(0, 1));
    printf("lb(0, 2): 0x%x\n", lb(0, 2));
    printf("lb(0, 3): 0x%x\n", lb(0, 3));
    printf("lbu(0, 0): 0x%x\n", lbu(0, 0));
    printf("lbu(0, 1): 0x%x\n", lbu(0, 1));
    printf("lbu(0, 2): 0x%x\n", lbu(0, 2));
    printf("lbu(0, 3): 0x%x\n", lbu(0, 3));

    return 0;
}
