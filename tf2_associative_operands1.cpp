#include "JSONLang.h"

JSON(simple_object1) = OBJECT{
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
JSON(simple_object2) = OBJECT{
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

PROGRAM_BEGIN

JSON(var1) = NUMBER(12)>NUMBER(11)
JSON(var2) = NUMBER(12) >= NUMBER(11)
JSON(var3) = NUMBER(12)<NUMBER(11)
JSON(var4) = NUMBER(12) <= NUMBER(11)

JSON(simple_array1) = ARRAY[STRING("text 1"), STRING("text 2"), STRING("text 3"), STRING("text 4")]
JSON(simple_array2) = ARRAY[STRING("text 1"), STRING("text 2"), STRING("text 3"), STRING("text 4")]
JSON(var5) = simple_array1 == simple_array2
JSON(var6) = simple_array1 != simple_array2

	

JSON(var7) = simple_object1 == simple_object2
JSON(var8) = simple_object1 != simple_object2


PRINT var1, var2, var3, var4
PRINT "\narray results:\n"
PRINT var5, var6
PRINT "\nobject results:\n"
PRINT var7, var8


PROGRAM_END

















