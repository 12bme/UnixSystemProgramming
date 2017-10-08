#include <stdio.h>

/* DB에서 가져온 프로세서들의 정보를 저장할 struct */
typedef struct{
    char proc_name[8];              /* 프로세서 이름 */
    char proc_desc[64];             /* 프로세서 설명 */
    char proc_alive[2];             /* 프로세서 실행여부 */
    char proc_start_time[32];       /* 프로세스 시작 시간 */
    char proc_stop_time[32];        /* 프로세서 종료 시간 */
} PROC_LIST_T;
PROC_LIST_T proc_list;

/* DB에서 가져온 에러들의 정보를 저장할 struct */
typedef struct{
    char error_date_time[32];       /* 에러가 발생한 시간과 날짜 */
    char error_cause[32];           /* 에러가 발생한 이유 */
    int  error_level;               /* 에러 등급. Severity 숫자 이요 */
    char error_mis[64];             /* 에러가 발생한 지역을 유추할 정보 */
    char error_process_name[2];     /* 에러 정보를 보낸 프로세스 이름 */
    char error_code[8];             /* 에러의 종류를 식별하는 정보를 제공 */
} ERROR_LIST_T;
ERROR_LIST_T error_list;

/* 프로세스 테이블의 값을 조회하는 함수 */
int get_process_info()
{
    printf("get_process_info() 함수 실행!\n");
    strcpy(proc_list.proc_name, "proc-name");
    strcpy(proc_list.proc_desc, "proc-desc");
    strcpy(proc_list.proc_alive, "proc-alive");
    strcpy(proc_list.proc_start_time, "proc-start-time");
    strcpy(proc_list.proc_stop_time, "proc-stop-time");

    printf("프로세스 테이블에서 데이터 조회 끝!\n");
    return 1;
}

/* 에러 테이블의 값을 조회하는 함수 */
int get_error_info()
{
    printf("get_error_info() 함수 실행!\n");
    strcpy(error_list.error_date_time, "date-time");
    strcpy(error_list.error_cause, "error-cause");
    error_list.error_level = 1;
    strcpy(error_list.error_mis, "error-mis");
    strcpy(error_list.error_process_name, "ko");
    strcpy(error_list.error_code, "code");

    printf("에러 테이블에서 데이터 조회 끝!\n");
    return 1;
}

#define MAX_FUNC_NUM 2
#define DBFUNC(command, func) dbFuncMember[(command)]=(func)

/* 함수 실행을 대행하게 될 대행 함수 */
int (*dbFuncMember[MAX_FUNC_NUM])();

/* 함수를 가리키는 enum */
enum db_func {
    GET_PROCESS_INFO,       /* 0 */
    GET_ERROR_INFO
};

/* enum 데이터와 실제 함수이름 매핑 */
void dbFuncInit(void)
{
    int i;
    
    for(i=0; i < MAX_FUNC_NUM; i++)
        dbFuncMember[i] = NULL;

    DBFUNC(GET_PROCESS_INFO, get_process_info);
    DBFUNC(GET_ERROR_INFO, get_error_info);
}

int runDBFunc(db_func)
{
    int returnVal;

    /* DB 관련 초기 함수를 실행 */
    printf("\nDB와 연결을 설정합니다.\n");

    /* get_XXX_info() 함수를 할당하고 실행 */
    returnVal = (*dbFuncMember[db_func])();

    /* 작업 수행후 DB disconnect 작업 실행 */
    printf("DB와 연결을 해제합니다.\n\n");

    return returnVal;
}

int main()
{
    dbFuncInit();
    runDBFunc(GET_PROCESS_INFO);    // 또는 runDBFunc(0);
    runDBFunc(GET_ERROR_INFO);      // 또는 runDBFunc(1);
}
