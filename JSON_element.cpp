#include "JSON_element.h"

JSON_element::JSON_element(JSON_element *elem) {
		int_val = elem->int_val;
		double_val = elem->double_val;
		string_val = elem->string_val;
		array_val = elem->array_val;
		obj_map = elem->obj_map;
		type = elem->type;
		owner = elem->owner;
		index = elem->index;
		boolean = elem->boolean;
	}
JSON_element::JSON_element(std::initializer_list<JSON_element> list) {
		this->type = 5;
		for (unsigned int i = 0; i < list.size(); i = i + 2) {
			JSON_element key = *(list.begin() + i);
			JSON_element * elem = new JSON_element(*(list.begin() + i + 1));
			elem->owner = this;
			std::pair<std::string, JSON_element *> pair_elem = std::make_pair(key.get_string_val(), elem);
			pair_elem.second->key = key.get_string_val();
			insert_into_map(pair_elem);
		}
		/*	for each (std::pair<std::string, JSON_element > it in list)
		{
		it.second.owner = this;

		JSON_element *new_js = new JSON_element(it.second);

		std::pair<std::string, JSON_element *> elem = std::make_pair(it.first, new_js);
		elem.second->key = it.first;
		//elem.second->owner = this;
		insert_into_map(elem);
		}
		*/
	}

JSON_element::JSON_element() {
		type = 0;
	}

JSON_element::JSON_element(double arg, int _type) {
		double_val = arg;
		type = 3;
	}
JSON_element::JSON_element(int  arg, int _type) {
		type = 1;
		int_val = arg;
	}
JSON_element::JSON_element(std::string arg) {
		if (!arg.compare("TRUE")) {
			this->boolean = true;

			type = 6;
		}

		else if (!arg.compare("FALSE")) {
			this->boolean = false;
			type = 6;
		}
		else if (!arg.compare("NULL")) {
			std::cout << "null";
			type = 7;
		}

	}
JSON_element::JSON_element(double val) {
		double_val = val;
		type = 3;

	}
JSON_element::JSON_element(int _type) {
		type = 4;

	}


JSON_element::JSON_element(std::string arg, int _type) {
		string_val = arg;
		type = _type;
	}

JSON_element::~JSON_element() {

	}





void JSON_element:: operator ~ ()
	{
		if (this->key.compare("")) {
			std::map<std::string, JSON_element*>::iterator it;
			it = this->owner->obj_map.find(this->key);
			this->owner->obj_map.erase(it);


		}
		else if (this->type == 5) {

			this->obj_map.clear();

		}
		else if (this->type == 4) {

			this->array_val.clear();
		}
		else if (this->index != -1) {

			this->owner->array_val.erase(this->owner->array_val.begin() + this->index);
			for (unsigned int i = 0; i < this->owner->array_val.size(); i++) {
				this->owner->array_val[i]->index = i;
			}
		}
		else {
			assert(0);
		}


	}



void JSON_element::insert_into_map(std::pair<std::string, JSON_element* > new_item)
	{
		obj_map.insert(new_item);

	}


void JSON_element::set_int_val(int arg) {
		int_val = arg;
		return;
	}
void JSON_element::set_double_val(double arg) {
		double_val = arg;
		return;
	}
void JSON_element::set_string_val(std::string arg) {
		string_val = arg;
		return;
	}

int JSON_element::get_int_val() {
		return int_val;
	}
double JSON_element::get_double_val() {
		return double_val;
	}
std::string JSON_element:: get_string_val() {
		return string_val;
	}
int JSON_element::get_type() {
		return type;
	}
std::vector <JSON_element *>  JSON_element::get_array_val() {
		return array_val;
	}

JSON_element& JSON_element::operator,(JSON_element arg) {
		arg.index = this->array_val.size();
		this->array_val.push_back(new JSON_element(&arg));
		return *this;
	}


JSON_element JSON_element::operator[](JSON_element arg) {
		this->array_val = arg.array_val;
		this->array_val = push_front(this, new JSON_element(&arg));
		return *this;
	}
JSON_element & JSON_element::operator[](unsigned int index) {
		assert(this->array_val.size() > index);
		for (unsigned int i = 0; i < this->array_val.size(); i++) {
			this->array_val[i]->owner = this;

		}

		return *this->array_val[index];

	}

JSON_element& JSON_element::operator[](const std::string key) {
		if (this->obj_map.find(key) != this->obj_map.end())
			std::cout << "";
		//	std::cout << "to vriskei\n";
		else {
			auto new_item = std::make_pair(key, new JSON_element());
			this->obj_map.insert(new_item);
			std::cout << "DEN to vriskei(create new pair)\n";
		}
		for (auto & x : this->obj_map)
		{
			x.second->owner = this;
		}
		return *this->obj_map.find(key)->second;

	}





JSON_element& JSON_element::operator^(JSON_element arg) {
		assert(this->type == 4);
		arg.index = this->array_val.size();
		this->array_val.push_back(new JSON_element(arg));
		std::vector <JSON_element *> arr = arg.get_array_val();
		if (arg.type != 4) {
			for (unsigned int i = 0; i < arr.size(); i++) {

				this->array_val.push_back(new JSON_element(arr[i]));
			}
		}
		return *this;

	}



std::vector<JSON_element* > JSON_element::push_front(JSON_element *elem, JSON_element *first) {
		std::vector<JSON_element* > new_list;
		first->index = 0;
		new_list.push_back(first);
		for (unsigned int i = 0; i < array_val.size(); i++) {
			array_val[i]->index = i + 1;
			new_list.push_back(array_val[i]);

		}
		return new_list;
	}

 std::string JSON_element::to_string(JSON_element arg) {
	std::string ret_val = "";
	if (arg.get_type() == 1)
		ret_val += "<INT VAL> : " + std::to_string(arg.get_int_val()) + "\n";
	else if (arg.get_type() == 2)
		ret_val += "<STRING VAL> : " + arg.get_string_val() + "\n";
	else if (arg.get_type() == 3)
		ret_val += "<DOUBLE VAL> : " + std::to_string(arg.get_double_val()) + "\n";
	else if (arg.get_type() == 0)
		ret_val += "not initialized object\n";
	else if (arg.get_type() == 6) {
		if (arg.boolean)
			ret_val += "TRUE\n";
		else
			ret_val += "FALSE\n";
	}
	else if (arg.get_type() == 7) {
		ret_val += "NULL\n";
	}
	else if (arg.get_type() == 4) {

		ret_val += "ARRAY WITH SIZE: " + std::to_string(arg.array_val.size()) + "\n";
		std::vector <JSON_element *> arr = arg.get_array_val();
		for (unsigned int i = 0; i < arr.size(); i++) {
			ret_val += "Array element: " + std::to_string(i) + "\n    ";
			ret_val += to_string(arr[i]);

		}
	}
	else if (arg.get_type() == 5) {
		ret_val += "OBJECT\n";
		for (auto & x : arg.obj_map)
		{
			ret_val += "KEY: " + x.first + "\n";
			ret_val += to_string(x.second);
		}
	}
	return ret_val;

}


bool JSON_element::is_integer(double k)
	{
		return std::floor(k) == k;
	}


