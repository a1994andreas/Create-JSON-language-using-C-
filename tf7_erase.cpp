#include "JSONLang.h"


PROGRAM_BEGIN

JSON(table) = ARRAY[NUMBER(11), NUMBER(22), NUMBER(33), NUMBER(44), NUMBER(55)]

/*erase element of array*/
ERASE table[2]
PRINT table
PRINT "---------------------------------------------------\n"

/*erase all the elements of the table*/
ERASE table
PRINT table
PRINT "---------------------------------------------------\n"

JSON(obj) = OBJECT{
	KEY(key1) : NUMBER(11),
	KEY(key2) : NUMBER(22),
	KEY(key3) : STRING("text example!"),
	KEY(key4) : NUMBER(33)
}
/*erase element with specific key*/
ERASE obj["key2"]
PRINT obj
PRINT "---------------------------------------------------\n"
/*clear the object*/
ERASE obj
PRINT obj
PRINT "---------------------------------------------------\n"

JSON(example) = ARRAY[
	OBJECT{
		KEY(key1) : NUMBER(11),
		KEY(key2) : ARRAY[
			NUMBER(22222) , OBJECT{
				KEY(key3) : NUMBER(33),
				KEY(key4) : ARRAY[
					NUMBER(99999) , OBJECT{
						KEY(key5) : NUMBER(44)
					}
				]
			}
		]
	}
]

/*erase se pio periplokh  domh*/
ERASE example[0]["key2"][1]["key4"][0]
ERASE example[0]["key2"][1]["key4"]
ERASE example[0]["key2"]
PRINT example
PRINT "---------------------------------------------------\n"

PROGRAM_END





























