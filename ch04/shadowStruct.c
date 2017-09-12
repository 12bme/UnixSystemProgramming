struct spwd {
    char *sp_namp;  // 로그인명을 저장한다.
    char *sp_pwdp;  // 사용자 계정의 패스워드를 13개 문자로 암호화해 저장
    int sp_lstchg;  // 패스워드를 변경한 날짜 정보. 1970년 1월 1일부터 일 수로 계산해 저장.
    int sp_min;     // 변경된 패스워드를 사용해야 하는 최소 일 수
    int sp_max;     // 현재 패스워드를 사용할 수 있는 최대 일 수
    int sp_warn;    // 패스워드를 변경할 날이 되기 전에 경고를 시작하는 일수
    int sp_inact;   // 사용자 계정으로 로그인할 수 없는 일 수
    int sp_expire;  // 사용자 계정이 만료되는 날짜 정보. 1970년 1월 1일부터 일 수로 표시.
    int sp_flag;    // 현재는 미사용
}
