#include "JSON_element.h"



JSON_element JSON_element:: operator+(JSON_element arg) {
	JSON_element *temp;
	double num1, num2;
	assert(this->type == 1 || this->type == 3 || this->type == 2 || this->type == 4 || this->type == 5);
	assert(arg.type == 1 || arg.type == 3 || arg.type == 2 || arg.type == 4 || arg.type == 5);

	if (this->type == 1)
		num1 = this->get_int_val();
	else if (this->type == 3)
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else if (arg.type == 3)
		num2 = arg.get_double_val();
	if ((this->type == 1 || this->type == 3) && (arg.type == 1 || arg.type == 3)) {
		auto result = num1 + num2;
		if (is_integer(result)) {
			temp = new JSON_element((int)result, 1);
			//temp->set_int_val((int)result);
		}
		else {
			temp = new JSON_element(result, 3);
			//	temp->set_double_val(result);
		}
	}
	else if (arg.type == 2) {
		temp = new JSON_element(this->get_string_val() + arg.get_string_val(), 2);
		//	temp->set_string_val(this->get_string_val() + arg.get_string_val());
	}
	else if (arg.type == 4 && this->type == 4) {
		temp = new JSON_element(4);
		temp->array_val = this->array_val;
		temp->array_val.insert(temp->array_val.end(), arg.array_val.begin(), arg.array_val.end());
		for (unsigned int i = 0; i < temp->array_val.size(); ++i) {
			temp->array_val[i]->owner = temp;
		}
	}
	else if (arg.type == 5 && this->type == 5) {
		temp = new JSON_element;
		temp->type = 5;
		temp->obj_map.insert(arg.obj_map.begin(), arg.obj_map.end());
		temp->obj_map.insert(this->obj_map.begin(), this->obj_map.end());
		for (auto & x : temp->obj_map)
		{
			x.second->owner = temp;
		}

	}
	else {
		temp = NULL;
	}
	return temp;
}
JSON_element JSON_element:: operator-(JSON_element arg) {
	JSON_element *temp;
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	auto result = num1 - num2;
	if (is_integer(result)) {
		temp = new JSON_element((int)result, 1);
		//		temp->set_int_val((int)result);
	}
	else {
		temp = new JSON_element(result, 3);
		//		temp->set_double_val(result);
	}

	return temp;
}
JSON_element JSON_element:: operator*(JSON_element arg) {
	JSON_element *temp;
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	auto result = num1 * num2;
	if (is_integer(result)) {
		temp = new JSON_element((int)result, 1);
		//	temp->set_int_val((int)result);
	}
	else {
		temp = new JSON_element(result, 3);
		//	temp->set_double_val(result);
	}

	return temp;
}
JSON_element JSON_element:: operator/(JSON_element arg) {
	JSON_element *temp;
	double num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = arg.get_double_val();

	auto result = num1 / num2;
	if (is_integer(result)) {
		temp = new JSON_element((int)result, 1);
		//		temp->set_int_val((int)result);
	}
	else {
		temp = new JSON_element(result, 3);
		//		temp->set_double_val(result);
	}

	return temp;
}
JSON_element JSON_element:: operator%(JSON_element arg) {
	JSON_element *temp;
	int num1, num2;
	assert(this->type == 1 || this->type == 3);
	assert(arg.type == 1 || arg.type == 3);

	if (this->type == 1)
		num1 = this->get_int_val();
	else
		num1 = (int) this->get_double_val();
	if (arg.type == 1)
		num2 = arg.get_int_val();
	else
		num2 = (int)arg.get_double_val();

	auto result = num1 % num2;
	if (is_integer(result)) {
		temp = new JSON_element(result, 1);
		//		temp->set_int_val(result);
	}
	else {
		temp = new JSON_element(result, 3);
		//	temp->set_double_val(result);
	}

	return temp;
}