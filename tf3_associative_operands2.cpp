#include "JSONLang.h"


PROGRAM_BEGIN
JSON(example1) = ARRAY[
	OBJECT{
		KEY(key1) : NUMBER(11),
		KEY(key2) : ARRAY[
			NUMBER(22) , OBJECT{
				KEY(key3) : NUMBER(33),
				KEY(key4) : ARRAY[
					NUMBER(20) , OBJECT{
						KEY(key5) : NUMBER(44)
					}
				]
			}
		]
	}
]
JSON(example2) = ARRAY[
	OBJECT{
		KEY(key1) : NUMBER(11),
		KEY(key2) : ARRAY[
			NUMBER(22) , OBJECT{
				KEY(key3) : NUMBER(33),
				KEY(key4) : ARRAY[
					NUMBER(20) , OBJECT{
						KEY(key5) : NUMBER(44)
					}
				]
			}
		]
	}
]
JSON(res) = example1 == example2 && !FALSE
JSON(res2) = example1 != example2 || !TRUE

PRINT res, res2
PROGRAM_END

















