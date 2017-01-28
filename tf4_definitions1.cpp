#include "JSONLang.h"

PROGRAM_BEGIN

JSON(simple_int) = NUMBER(12)
JSON(simple_double) = NUMBER(1.123)
JSON(simple_string) = STRING("example text")

JSON(simple_empty_array) = ARRAY
JSON(simple_array) = ARRAY[NUMBER(1), NUMBER(2), NUMBER(3), NUMBER(4)]
JSON(simple_array2) = ARRAY[STRING("text 1"), STRING("text 2"), STRING("text 3"), STRING("text 4")]
JSON(simple_array3) = ARRAY[STRING("text 1"), NUMBER(1), STRING("text 3"), NUMBER(2)]

JSON(simple_empty_object) = OBJECT{}

JSON(simple_object) = OBJECT{
	KEY(name1) : STRING("andreas"),
	KEY(name2) : STRING("stelios"),
	KEY(hy100) : NUMBER(9),
	KEY(hy150) : NUMBER(9.1),
	KEY(hy225) : NUMBER(9.2),
	KEY(hy340) : NUMBER(9.3),
	KEY(hy352) : NUMBER(10),
	KEY(AM1) : STRING("csd3031"),
	KEY(AM2) : STRING("csd3101")
}

PRINT simple_int, simple_double, simple_string, simple_empty_array, simple_array, simple_array2,
simple_array3, simple_empty_object, simple_object

PROGRAM_END