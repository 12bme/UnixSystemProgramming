#include <stdio.h>

int main(void) {
    int *intPtr;
    int intVal = 10;
    intPtr = &intVal;
    printf("intPtr lvaue : %p, rvalue: %x\n", &intPtr, intPtr);
    printf("intVal lvaue : %p, rvalue: %d\n", &intVal, intVal);
    *intPtr = 30;
    printf("intVal lvaue : %p, rvalue: %d\n", &intVal, intVal);
}
