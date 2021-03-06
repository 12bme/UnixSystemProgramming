#include <stdio.h>

#define MAXNUM 10

void setString(char* string)
{
    int loop;
    char *cPtr, cVal;
    cPtr = string;

    for(loop = 0; loop < MAXNUM; loop++)
    {
        *cPtr = '1';
        cPtr++;
    }
    *cPtr = '\0';
}

int main(void)
{
    char string[MAXNUM];        // string이라는 이름의 배열 생성
    string[MAXNUM] = '\0';     // '\0'은 문자열의 끝에 null 문자를 추가하여 배열이 하나의 문자열로 사용되는데 문제 없도록
    printf("string : %s\n", string);
    setString(string);          // setString 함수를 호출하면서 인수로 string 배열을 넘겨줌.
    printf("string : %s\n", string);
}
