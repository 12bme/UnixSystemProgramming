#include <stdio.h>

// 함수의 이름을 대체할 매크로 선언
#define FUNC1 func1
#define FUNC2 func2

// func1(), func2() 함수 작성
int func1(int intVal1){ return --intVal1; }
int func2(int intVal2){ return --intVal2; }

// 인수로 들어오는 함수 이름을 실행시키는 함수
int runFunc(char* string, int inVal)
{
    int retVal;
    // 함수를 이용할 포인터 선언
    int (*funcPtr)(int retVal);
    // 포인터에 함수이름을 할당
    funcPtr = string;
    // 함수를 실행하고 그 결과 값을 리턴
    return (*funcPtr)(inVal);
}

int main(void)
{
    int intVal = 3;
    intVal = runFunc(FUNC2, intVal);
    printf("After running func2 intVal: %d\n", intVal);
    intVal = runFunc(FUNC1, intVal);
    printf("After running func1 intVal: %d\n", intVal);
}
