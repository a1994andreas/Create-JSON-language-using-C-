testfile1:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf1_arithmetical_operands.cpp
	./a.out
testfile2:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf2_associative_operands1.cpp
	./a.out

testfile3:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf3_associative_operands2.cpp
	./a.out

testfile4:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf4_definitions1.cpp
	./a.out

testfile5:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf5_definitions2.cpp
	./a.out

testfile6:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf6_definitions3.cpp
	./a.out
testfile7:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf7_erase.cpp
	./a.out

testfile8:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf8_set_append.cpp
	./a.out

testfile9:
	g++ -std=c++11 arithmetical_operants.cpp associative_operands.cpp JSON_element.cpp tf9_set_assign.cpp
	./a.out



