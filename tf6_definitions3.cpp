#include "JSONLang.h"

/*
* object inside array definition
* array inside object definition
*/
PROGRAM_BEGIN

JSON(table) = ARRAY[NUMBER(12), OBJECT{ KEY(id) :NUMBER(22) }, STRING("Value")]

JSON(obj) = OBJECT{
	KEY(name) :STRING("Giwrgos"),
	KEY(AM) :STRING("csd3055"),
	KEY(arr) : ARRAY[NUMBER(11),STRING("obejct_array")]
}

JSON(example) = ARRAY[
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

PRINT table
PRINT "---------------------------------------------------\n"
PRINT obj
PRINT "---------------------------------------------------\n"
PRINT example

PROGRAM_END