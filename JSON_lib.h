#include "JSON_element.h"


 unsigned int JSON_element::size_of(JSON_element arg) {

	if (arg.type == 1 || arg.type == 2 || arg.type == 3) {
		return 1;
	}
	else {
		if (arg.type == 4) {
			return arg.array_val.size();
		}
		else if (arg.type == 5) {
			return arg.obj_map.size();
		}
	}

}

bool JSON_element::is_empty(JSON_element arg) {
	if (arg.type == 1 || arg.type == 2 || arg.type == 3) {

		return false;
	}
	else {
		if (JSON_element::size_of(arg) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool JSON_element::has_key(JSON_element arg, std::string key) {

	if (arg.type == 1 || arg.type == 2 || arg.type == 3 || arg.type == 4) {
		return false;
	}

	if (arg.type == 5) {
		std::map<std::string, JSON_element *>::iterator it;

		it = arg.obj_map.find(key);
		if (it != arg.obj_map.end())
			return true;	//--------- an exei to key to obj_map tou arg
		else return false;
	}
	return false;
}

std::string JSON_element::type_of(JSON_element arg) {
	std::string res;
	if (arg.type == 1) {
		res = "integer";
	}
	else if (arg.type == 2) {
		res = "string";
	}
	else if (arg.type == 3) {
		res = "double";
	}
	else if (arg.type == 4) {
		res = "array";
	}
	else if (arg.type == 5) {
		res = "Object";
	}
	else if (arg.type == 6) {
		res = arg.boolean;
	}
	else if (arg.type == 7) {
		res = "null";
	}



	else {
		res = "object";
	}
	return res;

}