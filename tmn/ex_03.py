PowerOnOff ACTION
    BEHAVIOR
    PowerOnOffBehavior BEHAVIOUR    -- 장비를 끄고 켬을 소개
        DEFINED AS "Turn the switching equipment on or off";;
    MODE CONFIRMED;                 -- ASN.1 파일 속에 아래의 2개를 지정
    WITH INFORMATION SYNTAX Switch-ASN1Module.PowerRequest;
    WITH REPLAY SYNTAX Switch-ASN.1Module.PowerReponse;
REGISTERED AS {switchAction 1};
