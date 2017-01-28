#include "JSONLang.h"


PROGRAM_BEGIN

JSON(table) = ARRAY[NUMBER(11), NUMBER(22), NUMBER(33), NUMBER(44), STRING("Value")]

/*allagh timhs se ena pedio sto array*/
SET table[0] ASSIGN NUMBER(99);

/*allagh typou enos member tou array*/
SET table[1] ASSIGN STRING("new value");

/*allagh enos stoixeiou me array*/
SET table[2] ASSIGN ARRAY[NUMBER(1.2), NUMBER(1.2), STRING("eeeee")]

/*allagh enos stoixeiou me object*/
SET table[3] ASSIGN OBJECT{ KEY(example1) : STRING("Some text"),KEY(example2) : STRING("Some text2") }

/*prosvash se stoixeio pou den uparxei ston pinaka pianetai apo assert*/
//SET table[100] ASSIGN STRING("new value");

JSON(obj) = OBJECT{
	KEY(key1) : NUMBER(11) ,
	KEY(key2) : STRING("VALUE") ,
	KEY(key3) : NUMBER(22) ,
	KEY(key4) : NUMBER(33) ,
}

/*allagh timhs se pedio sto object*/
SET obj["key1"] ASSIGN NUMBER(88)

/*allagh typou enos member tou object*/
SET obj["key2"] ASSIGN NUMBER(99)

/*allagh enos member me array*/
SET obj["key3"] ASSIGN ARRAY[NUMBER(1.2), NUMBER(1.2), STRING("eeeee")]

/*allagh enos member me object*/
SET obj["key4"] ASSIGN OBJECT{ KEY(example1) : STRING("Some text"),KEY(example2) : STRING("Some text2") }




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
/*allagh timhs se poio periplokh domh*/
SET example[0]["key2"][0] ASSIGN STRING("new value assigned number1!!")
SET example[0]["key2"][1]["key4"][1]["key5"] ASSIGN STRING("new value assigned number 2!!")



PRINT table
PRINT "---------------------------------------------------\n"
PRINT obj
PRINT "---------------------------------------------------\n"
PRINT example


PROGRAM_END