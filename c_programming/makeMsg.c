#include <stdio.h>
#include "msgType.h"

/*
 * 포인터로 들어온 message의 messageType부터 확인을 한다.
 *
 * 메시지 타입이 REQUEST이면 message 속의 union 데이터 중 requestType 형의
 * 스트럭처에 데이터를 세팅한 후 포인터를 리턴한다.
 *
 * 마찬가지로 RESPONSE 타입인 경우에는 responseType형의 스트럭처를 이용한다.
 *
 * 만일 둘중 아무 타입도 아니면 0을 리턴한다.
 * */
MessageType* setMsg(MessageType *message)
{
    if(message->messageType == REQUEST)
    {
        message->uType.request.reqType = 1;
        strcpy(message->uType.request.reqData, "Request.\0");
        return message;
    }
    else if(message->messageType == RESPONSE)
    {
        message->uType.response.isDone = 1;
        strcpy(message->uType.response.resData, "Result 1.Data:3, 2.Number:10...\0");
        return message;
    }
    return 0;
}

/*
 * showMsg()는 message 포인터를 인수로 받은 후,
 * 내부의 데이터를 화면에 출력한다. 이때도 messageType을 확인한 후
 * union 속의 어떤 스트럭처를 활용할지 결정한다.
 *
 * 확인이 끝나면 해당 스트럭처 속의 데이터를 화면에 출력한다.
 * */
void showMsg(MessageType *message)
{
    if(message->messageType == REQUEST)
    {
        printf("Request Type: %d\n", message->uType.request.reqType);
        printf("Request Data: %s\n", message->uType.request.reqData);
    }
    else if(message->messageType == RESPONSE)
    {
        printf("Response is done: %d\n",  message->uType.response.isDone);
        printf("Response Data: %s\n", message->uType.response.resData);
    }
}
