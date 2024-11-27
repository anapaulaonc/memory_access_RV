
Simulation of memory access in C inspired by the RISC-V RV32I ISA, including functions for reading and writing bytes and words with bounds checking and alignment verification.

# RISC-V Memory Access Simulation in C

This project provides a simulation of memory access functions inspired by the RISC-V RV32I ISA. It includes functions for reading and writing bytes and words to a simulated memory space. The code also includes bounds checking and alignment verification for safer memory operations.

## Features

- **Byte read with sign extension (`lb`)**: Reads a signed byte from memory.
- **Byte read without sign extension (`lbu`)**: Reads an unsigned byte from memory.
- **Word read (`lw`)**: Reads a 32-bit word, ensuring alignment.
- **Byte write (`sb`)**: Writes a byte to memory.
- **Word write (`sw`)**: Writes a 32-bit word, ensuring alignment.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC, Clang)  
- Make sure your development environment supports ANSI C.

### Building and Running

1. Clone this repository:
   ```bash 
   git clone https://github.com/your-username/riscv-memory-simulation.git
   cd riscv-memory-simulation
    ```
   


2. Compile the code:
    ```bash
    gcc -o risc_simulation simulation.c
    ```
    Run the program:
    ```bash
    ./risc_simulation
    ```
## Sample Output

The program writes and reads from memory to test the implemented functions. Example output:

``` bash
lw(0, 0): 0xabacadef
lb(0, 0): 0xffffffef
lb(0, 1): 0xffffffad
lb(0, 2): 0xffffffac
lb(0, 3): 0xffffffab
lbu(0, 0): 0xef
lbu(0, 1): 0xad
lbu(0, 2): 0xac
lbu(0, 3): 0xab
```

## Code Explanation

The simulated memory has a size of 16 KB (MEM_SIZE = 16384). Functions use a base register and an offset to calculate the memory address. The code performs:

- Bounds checking to prevent accessing invalid memory addresses.
- Alignment verification for word operations.



