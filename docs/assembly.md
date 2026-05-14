# ASSEMBLY: Basic Concepts

<details>
<summary><h2>Registers</h2></summary>

A **register** is a small, ultra-fast, volatile, named storage location built into the processor. It is used to hold data, instructions or memory addresses temporarily during processing. Registers are the fastest memory in a computer, allowing immediate access to data for calculations, unlike slower RAM.

In x86-64 architecture there are mainly 16 main general-purpose registers:
```
rax  rbx  rcx  rdx
rai  rdi  rbp  rsp
r8-r15
```
But cpu's also have _instruction pointers_ (`rip`), _flags registers_, _SIMD registers_ (`xmm`, `ymm`, etc.). So actually there are many more. Also architectures (ARM, RISC-v) differ. But Intel and AMD both implement x86-64 architecture, so they shere the same programmer-visible registers.

## Register names
Register names come from older CPU designs, and their names reflect their _original purpose_. However, these names no longer define strict behaviour, since registers have become more flexible and general-purpose.

- `rax`: _**A**ccumulator Register_
   * Historically used for arithmetic operations
   * Today used to **return values from functions**
- `rdi`: _**D**estination **I**ndex_
   * Originally used in memory copy instructions
   * Today (System V ABI): **first function argument**
- `rsi`: _**S**ource **I**ndex_
   * Originally paired with `rdi`
   * Today (System V ABI): **second function argument**
- `rdx`: _**D**ata Register_
   * In the past, used in various operations (multiplication, I/O...)
   * Today (System V ABI): **third function argument**
- `rcx`: _**C**ounter register_ 
   * Historically used as a loop counter
   * Today (System V ABI): **fourth function argument** 
- ...


</details>

<details>
<summary><h2>Structure of an assembly file</h2></summary>

## Directives

## Sections
A **_section_** is a region of the object file used for a specific purpose. Typical sections are:
- `.text`:    executable code
- `.data`:    initialized writable data
- `.bss`:     uninitialized data
- `.rodata`:  read-only constants
Sections organize memory by purposes.

## Labels
Labels live inside sections. A **label** is a type of symbol used to mark a specific location in the code (an instruction address) or a location in data memory.Each label corresponds to some address in the generated machine code. The assembler creates a _symbol table_ that roughly says:

| Symbol     | Address  |
|------------|----------|
| ft_strlen: | 0x1000   |
| .loop:     | 0x1003   |
| .end:      | 0x1015   |

When a program is split into multiple files, the linker needs a way to connect them together. This is a simple step-through process's description:
1. The C compiler generates an object file that needs a symbol named *ft_strlen*
2. NASM generates another object file providing a symbol *ft_strlen* at address XYZ
3. The linker matches both symbols together

Two types of labels:

### * Global labels
Global labels usually represent functions ald global variables. They can be exported with global.

### * Local labels
Local labels are used for internal jumps. 
```
ft_strlen:
.loop:
```
actually behaves conceptually as `ft_strlen.loop`

</details>

<details>
<summary><h2>Common operations</h2></summary>

### Zeroing a register
` xor rax, rax` always resulst in zero because every bit cancels itself. 
It is a usual operation in assembly to set a register to zero