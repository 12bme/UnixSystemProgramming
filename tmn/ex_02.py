Switched ATTRIBUTE          -- switch의 ID를 나타내는 Attribute
    WITH ATTRIBTUE SYNTAX Switch-ASN1Module.SwitchIdl
    MATCHES FOR EQUALITY, ORDERING;
REGISTERED AS {switchAttribute 1};

NoPorts ATTRIBUTE           -- switch의 포트 개수를 나타내는 Attributes
    WITH ATTRIBUTES SYNTAX Switch-ASN1Module.NoPorts;
    MATCHES FOR EQUALITY, ORDERING;
REGISTERED AS {switchAttribute 2};

SwitchName ATTRIBUTE        -- switch의 이름을 나타내는 Attribute
    WITH ATTRIBUTE SYNTAX Switch-ASN1Module.SwitchName;
    MATCHES FOR EQUALITY;
REGISTERED AS {switchAttribute 3};

ProtNo ATTRIBUTE            -- 접속 실패의 포트숫자를 나타내는 Attribute
    WITH ATTRIBUTE SYNTAX Switch-ASN!Module.ProtNo;
    MATCHES FOR EQUALITY;
REGISTERED AS {switchAttribute 4};
