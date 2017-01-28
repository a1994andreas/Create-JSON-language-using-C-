#include "JSONLang.h"


PROGRAM_BEGIN
JSON(array1) = ARRAY[NUMBER(12), NUMBER(13), ARRAY[NUMBER(44), NUMBER(55)]]
JSON(array2) = ARRAY[NUMBER(66), NUMBER(77), ARRAY[NUMBER(88), NUMBER(99)]]
/*pros8esh duo array pou exoun eswterika array*/
JSON(array_res) = array1 + array2

JSON(obj1) = OBJECT{
	KEY(key1) : NUMBER(11) ,
	KEY(key2) : STRING("VALUE") ,
	KEY(key3) : NUMBER(22) ,
	KEY(key4) : OBJECT{
	KEY(key5) : NUMBER(12)
}
}
JSON(obj2) = OBJECT{
	KEY(key6) : NUMBER(11) ,
	KEY(key7) : STRING("VALUE") ,
	KEY(key8) : NUMBER(22) ,
	KEY(key9) : OBJECT{
	KEY(key10) : NUMBER(12)
}
}
/*pros8esh duo object pou periexoun object*/
JSON(object_res) = obj1 + obj2

/*pra3eis mesa se dhlwsh metablhths*/
JSON(example) = ARRAY[
	OBJECT{
		KEY(key1) : NUMBER(11) + NUMBER(22)*NUMBER(2),
		KEY(key2) : ARRAY[
			NUMBER(22) - NUMBER(10) / NUMBER(2) , OBJECT{
				KEY(key3) : NUMBER(20) % NUMBER(2),
				KEY(key4) : ARRAY[
					NUMBER(20) , OBJECT{
						KEY(key5) : STRING("text1 ") + STRING(" text2") + STRING(" more text")
					}
				]
			}
		]
	}
]



PRINT array_res
PRINT "---------------------------------------------------\n"
PRINT object_res
PRINT "---------------------------------------------------\n"
PRINT example
PROGRAM_END

















