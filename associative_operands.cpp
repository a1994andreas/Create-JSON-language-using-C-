#include "JSON_element.h"

JSON_element JSON_element::operator&&(JSON_element arg) {
	assert(arg.type == 6 && this->type == 6);
	JSON_element *temp;
	bool val = arg.boolean && this->boolean;
	if (val)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;
}
JSON_element JSON_element::operator||(JSON_element arg) {
	assert(arg.type == 6 && this->type == 6);
	JSON_element *temp;
	bool val = arg.boolean || this->boolean;
	if (val)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;
}
JSON_element JSON_element:: operator!() {
	assert(this->type == 6);
	JSON_element *temp;
	bool val = !this->boolean;
	if (val)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;
}

JSON_element JSON_element:: operator<(JSON_element arg) {
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);
	JSON_element *temp;

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	bool result = num1 < num2;
	if (result)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;
}
JSON_element JSON_element:: operator<=(JSON_element arg) {
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);
	JSON_element *temp;

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	bool result = num1 <= num2;
	if (result)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;

}
JSON_element JSON_element:: operator>(JSON_element arg) {
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);
	JSON_element *temp;

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	auto result = num1 > num2;
	if (result)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;

}
JSON_element JSON_element:: operator>=(JSON_element arg) {
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);
	JSON_element *temp;

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	auto result = num1 >= num2;
	if (result)
		temp = new JSON_element("TRUE");
	else
		temp = new JSON_element("FALSE");
	return temp;

}