#include <netdb.h>

struct servent *getservent(void);
// stayopen: 포트 정보 데이터베이스를 열어둘지 여부를 나타내는 값
int setservent(int stayopen);
int endservent(void);
