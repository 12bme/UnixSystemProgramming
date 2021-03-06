#define REQUEST 1
#define RESPONSE 2

/* request를 담은 스트럭처 */
typedef struct
{
    int reqType;
    char reqData[10];
} RequestType;

/* response를 담은 스트럭처 */
typedef struct
{
    int isDone;
    char resData[30];
} ResponseType;

/**
 * request 또는 response를 담게될
 * message 스트럭쳐
 */
typedef struct
{
    /* messageType에 따라 union속의 타입이 결정 */
    unsigned int messageType;
    // union 타입으로 상황에 따라 RequestType 형의 스트럭처로 활용될 수도 있고
    // ResponseType형의 스트럭처로 활용될 수도 있다.
    union
    {
        /* messageType = REQUEST인 경우 */
        RequestType request;
        /* messageType = RESPONSE인 경우 */
        ResponseType response;
    } uType;
} MessageType;
