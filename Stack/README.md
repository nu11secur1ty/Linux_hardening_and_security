***Stack pointer***

-----------------------------------------------------------------------------------------------------------------------

```c
#include <stdio.h>
#include <stdlib.h>

unsigned long *get_stack_ptr(void) {
  __asm__(
    "mov %rsp, %rax"
  );
}

int main(int argc, char **argv) {
  unsigned long *stack_ptr = get_stack_ptr();

  printf("Size Of Ptr: %d bytes\n", sizeof(unsigned long *));
  printf("Stack Pointer: %llX\n", stack_ptr);

  return 0;
}
```
