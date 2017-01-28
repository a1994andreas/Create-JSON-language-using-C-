#include "JSONLang.h"




PROGRAM_BEGIN
JSON(table) = ARRAY[
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




JSON(obj) = OBJECT{
			KEY(student1) : OBJECT{
			KEY(name) :STRING("Giwrgos"),
			KEY(AM) :STRING("csd3055"),
			KEY(average) :NUMBER(8.2),
			KEY(courses) : OBJECT{
			KEY(hy100) :NUMBER(10),
			KEY(hy150) : NUMBER(6.5),
			KEY(hy255) : NUMBER(7.6)
		}
		},
		KEY(student2) : OBJECT{
			KEY(name) :STRING("Labros"),
			KEY(AM) :STRING("csd2144"),
			KEY(average) :NUMBER(6.4),
			KEY(courses) : OBJECT{
			KEY(hy100) :NUMBER(5.5),
			KEY(hy150) : NUMBER(8),
			KEY(hy255) : NUMBER(6.5)
		}
		},
		KEY(student3) : OBJECT{
			KEY(name) :STRING("Eulampia"),
			KEY(AM) :STRING("csd3322"),
			KEY(average) :NUMBER(7.4),
			KEY(courses) : OBJECT{
			KEY(hy100) :NUMBER(7),
			KEY(hy150) : NUMBER(6.5),
			KEY(hy255) : NUMBER(10)
		}
		}
		}






			PRINT table
			PRINT "---------------------------------------------------\n"
			PRINT obj
			PRINT "---------------------------------------------------\n"

			PROGRAM_END