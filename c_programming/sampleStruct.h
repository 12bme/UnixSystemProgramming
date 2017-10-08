/*
 * 헤더부분에 들어갈 데이터의 종류를 정의한다.
 * 이렇게 정의를 하고 나면 숫자대신 문자열을 활용할 수 있기 때문에
 * 가독성이 높아지고 실수로 인한 버그를 줄일 수 있다.
 * */
#define RequestConnectionOpen   1
#define ResponseOpenResult      2
#define RequestConnectionClose  3
#define ResponseCloseResult     4
#define RequestCommandRun       5
#define ResponseRunResult       6

/*
 * typedef 키워드를 이용하여 struct를 만들고 있다.
 * typedef을 이용하고 나면 이후에 스트럭처 변수를 만들 때
 * "struct DeataHeaderType DataHeader" 대신
 * "DataHeaderType DataHeader" 문장을 이용하여
 * 데이터 타입을 선언할 수 있다.
 * */
typedef struct
{
    /* 해당 메시지의 식별자의 의미한다. 4 bytes */
    unsigned int messageType;
    /* date: YYYYMMDD 8 bytes의 Char 배열 */
    TransactionID TID;
} DataHeaderType;

/*
 * DataBodyType의 스트럭처를 선언하고 있다.
 * 여기서 특이한 내용은 union을 이용하여 스트럭처를 만들고 있다는 점이다.
 * 샘플코드에는 빠져있지만 union 속에 들어있는 각각의 데이터들은 다른곳에서
 * 스트럭처로 이미 선언되어진 타입들이다.
 * */
typedef struct
{
    /*
     * union으로 선언된 내용으로, 이 속에 포함된 스트럭처는 조건에 따라
     * 하나만 사용이 된다. 만일 헤더속의 messageType이 1번이면 union 속의
     * ConnectionOpenType 스트럭처가 메모리에 할당되어 사용이 될 것이고,
     * 2번이면 OpenResultType 스트럭처가 메모리에 할당될 것이다.
     * union 속의 스트럭처를 참조하는 방법도 일반 struct 데이터를 참조하는 것과
     * 마찬가지로 도트(.) 연산자를 활용하면 된다.
     * */
    union
    {
        ConnectionOpenType  connectionOpen;
        OpenResultType      openResult;
        ConnectionCloseType connectionClose;
        CloseResultType     closeResult;
        RunResultType       runResult;
    } uData;
} DataBodyType;

/*
 * 헤더(Header)와 내용(Body)의 스트럭처를 합친 DataType형의 스트럭처를
 * 선언하고 있다. 이제 스트럭처의 정의가 끝났기 때문에 각각의 시스템을 만드는
 * 사람은 이러한 스트럭처를 송신했을때와 수신했을 때에 해야할 일을 함수를 이용하여
 * 만들면 시스템은 성공적으로 구축이 될 것이다.
 * */
typedef struct
{
    DataHeaderType dataHeader;
    DataBodyType   dataBody;
} DataType;
