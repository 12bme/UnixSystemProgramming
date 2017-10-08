/* DB에서 가져온 프로세서들의 정보를 저장할 struct */
typedef struct {
    char proc_name[8];          /* 프로세서 이름 */
    char proc_desc[64];         /* 프로세서 설명 */
    char proc_alive[2];         /* 프로세서 실행여부 */
    char proc_start_time[32];   /* 프로세서 시작 시간 */   
    char proc_stop_time[32];    /* 프로세서 종료 시간 */
} PROC_LIST_T;

/* DB에서 가져온 에러들의 정보를 저장할 struct */
typedef struct {
    char error_date_time[32];   /* 에러가 발생한 시간과 날짜 */
    char error_cause[32];       /* 에러가 발생한 이유 */
    int  error_level;           /* 에러 등급. Severity 숫자 이용 */
    char error_mis[64];         /* 에러가 발생한 지역을 유추할 정보 */
    char error_process_name[2]; /* 에러 정보를 보낸 프로세스 이름 */
    char error_code[8];         /* 에러의 종류를 식별하는 정보를 제공 */
} ERROR_LIST_T;
