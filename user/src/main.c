
int main(void) {
    register long a7 asm("a7") = 0;
    asm volatile("ecall" : :"r"(a7):"memory");
    while (1) {
    }
    return 0;
}