CC=gcc
CFLAGS=-W -Wall
TARGET=exl_3_calc_exe
OBJECTS=exl_3_addnum.o exl_3_main.o
# 매크로를 참조할 때는 소괄호나 중괄호 둘러싸고 앞에 '$'를 붙입니다.
# 탭으로 시작해서는 안되고 ,:,=,#,"" 등은 매크로 이름에 사용할 수 없습니다.
# 매크로는 반드시 치환될 위치보다 먼저 정의되어야 합니다.
# 여기서 -W -WALL는 컴파일 시 컴파일이 되지 않을 정도의 오류라도 모두 출력되게 하는 옵션입니다.
exl_3_calc_exe : exl_3_addnum.o exl_3_main.o
	gcc -o exl_3_calc_exe exl_3_addnum.o exl_3_main.o
exl_3_addnum.o : ex1_3_addnum.c
	gcc -c -o exl_3_addnum.o ex1_3_addnum.c
exl_3_main.o : ex1_3_main.c
	gcc -c -o exl_3_main.o ex1_3_main.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o exl_3_calc_exe

