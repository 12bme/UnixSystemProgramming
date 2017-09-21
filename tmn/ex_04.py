SwitchAlarm NOTIFICATION
    BEHAVIOUR
    AlarmBehaviour BEHAVIOUR
        DEFINED AS "Alarm emitted when a port on the switch fails";;
    WITH INFORMATION SYNTAX Switch-ASN1Module.SwitchingAlarm
        AND ATTRIBUTE IDS
        Switched switched,
        PortNo       portNo;
REGISTERED AS {switchNotification 1};
