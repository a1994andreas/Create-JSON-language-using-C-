#pragma once


#include "JSON_element.h"

#define PROGRAM_BEGIN ; int main(void){ ;


#define PROGRAM_END 	;system("pause"); return 0;}


#define JSON(new_json) ; auto new_json


#define TRUE  JSON_element("TRUE")
#define FALSE  JSON_element("FALSE")
#define NULL  JSON_element("NULL")

#define NUMBER(new_number)  JSON_element(new_number,1)

#define STRING(new_string) JSON_element(new_string,2)

#define ARRAY  JSON_element(4)

#define OBJECT JSON_element
/*
#define KEY(name) std::make_pair(#name,EE

int var = 1;
#define EE (var==0) ? JSON_element(0)
*/
#define SET ;

#define ERASE ; ~

#define ASSIGN =

#define APPEND ^
#define PRINT  ; std::cout <<


#define KEY(name) JSON_element(#name,2 ), EE

int var2 = 1;
#define EE (var2==0) ? JSON_element(0) 
