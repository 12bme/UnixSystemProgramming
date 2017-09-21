Switch MANAGED OBJECT CLASS     -- 이름을 Switch로 지정
DERIVED FROM "Rec. X.721 | ISO/IEC 10165-2: 1992 :top;"  -- 상속 관계 지정
CHARACTERIZED BY
    SwitchPkg PACKAGE       -- package 이름 지정

    BEHAVIOR
        SwitchBehavior BEHAVIOR     -- switch에 대한 기술
        DEFINED AS Instantiable class represnting the switch device;;

    ATTRIBUTES                   -- switch가 가지는 attribute
        Switched GET,            -- 식별자로서 Get만 허용
        NoPorts GET-REPLACES     -- 포트의 수로 GET/SET 허용
        SwitchName GET-REPACE,   -- 스위치 이름 GET/SET 혀용

    ACTIONS
        PowerOnOff;              -- 파워를 끄거나 켤 수 있음

    NOTIFICATIONS
        SwitchingAlarm;;;        -- Manager에게 통지해야할 내용

REGISTERED AS {switchMObject 1};
