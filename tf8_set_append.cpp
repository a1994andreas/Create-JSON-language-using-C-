#include "JSONLang.h"


PROGRAM_BEGIN

JSON(table) = ARRAY[NUMBER(1), NUMBER(2)]

/*simple append*/
SET table APPEND NUMBER(3), NUMBER(4), STRING("example text")

JSON(students) = ARRAY[
	OBJECT{
		KEY(name) : STRING("Nikos Nikolaou"),
		KEY(id) : NUMBER(4444),
		KEY(grades) : ARRAY[
			OBJECT{ KEY(hy100) : NUMBER(7.5) },
				OBJECT{ KEY(hy150) : NUMBER(8) }

		]
	}
]
/*paradeigma apo ekfwnhsh(append se eswteriko pinaka)*/
SET students[0]["grades"] APPEND OBJECT{ KEY(hy255) : NUMBER(9) }
SET students[0]["grades"] APPEND OBJECT{ KEY(hy460) : NUMBER(9.5) }
SET students[0]["grades"] APPEND OBJECT{ KEY(hy352) : NUMBER(10) }


JSON(table2) = ARRAY[
	NUMBER(11), ARRAY[
		NUMBER(22), STRING("second"), ARRAY[
			NUMBER(33), STRING("third"), ARRAY[
				NUMBER(33), STRING("fourth"), ARRAY, STRING("deepest")
			]
		]
	], ARRAY[
		NUMBER(88), NUMBER(99), STRING("finish")
	]
]

/*append se adeio pinaka se pio periplokh domh*/
SET table2[1][2][2][2] APPEND NUMBER(222), NUMBER(333), NUMBER(444), NUMBER(555)

/*an kanoume append se element pou den einai pinakes 8a to piasoume me assert*/
PRINT table
PRINT "---------------------------------------------------\n"
PRINT students
PRINT "---------------------------------------------------\n"
PRINT table2


PROGRAM_END