
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>
#include <map>
#include <iterator>
#include <initializer_list>
#include <assert.h>
#include <cmath>

class JSON_element {
	std::vector <JSON_element *> array_val;
	std::map<std::string, JSON_element*> obj_map;

	int int_val;
	bool boolean;
	double double_val;
	std::string string_val;
	int type = 0;  
	JSON_element* owner;
	std::string key = "";
	int index = -1;
public:

	JSON_element(JSON_element *elem);
	JSON_element(std::initializer_list<JSON_element> list);
	JSON_element();
	JSON_element(double arg, int _type);
	JSON_element(int  arg, int _type);
	JSON_element(std::string arg);
	JSON_element(double val);
	JSON_element(int _type);
	JSON_element(std::string arg, int _type);

	~JSON_element();

	void set_int_val(int arg);
	void set_double_val(double arg);
	void set_string_val(std::string arg);
	
	int get_int_val();
	double  get_double_val();
	std::string get_string_val();
	int get_type();
	std::vector <JSON_element *>  get_array_val();

	JSON_element  operator+(JSON_element arg);
	JSON_element  operator-(JSON_element arg);
	JSON_element  operator*(JSON_element arg);
	JSON_element  operator/(JSON_element arg);
	JSON_element  operator%(JSON_element arg);


	JSON_element operator&&(JSON_element arg);
	JSON_element operator||(JSON_element arg);
	JSON_element  operator!();

	JSON_element operator<(JSON_element arg);
	JSON_element operator<=(JSON_element arg);
	JSON_element operator>(JSON_element arg);
	JSON_element  operator>=(JSON_element arg);

	JSON_element& operator,(JSON_element arg);
	JSON_element  operator[](JSON_element arg);
	JSON_element & operator[](unsigned int index);
	JSON_element& operator[](const std::string key);

	JSON_element& operator^(JSON_element arg);
	void  operator ~ ();

	std::vector<JSON_element* > push_front(JSON_element *elem, JSON_element *first);
	void insert_into_map(std::pair<std::string, JSON_element* > new_item);
	
	bool is_integer(double k);

	static unsigned int size_of(JSON_element arg);
	static bool is_empty(JSON_element arg);
	static bool has_key(JSON_element arg, std::string key);
	std::string type_of(JSON_element arg);

	friend JSON_element operator==(JSON_element arg, JSON_element arg2) {
		bool ret_val = false;
		JSON_element *temp;
		if ((arg.get_type() == 1 || arg.get_type() == 3) && (arg2.get_type() == 1 || arg2.get_type() == 3)) {
			double var1, var2;
			if (arg.get_type() == 1)
				var1 = arg.get_int_val();
			else
				var1 = arg.get_double_val();
			if (arg2.get_type() == 1)
				var2 = arg2.get_int_val();
			else
				var2 = arg2.get_double_val();
			if (var1 == var2)
				ret_val = true;

		}

		else if (arg.get_type() == 2 && arg2.type == 2) {
			if (!arg.get_string_val().compare(arg2.get_string_val()))
				ret_val = true;
		}
		else if (arg.get_type() == 6 && arg2.type == 6) {
			ret_val = (arg.boolean == arg2.boolean);
		}
		else if (arg.get_type() == 7 || arg2.get_type() == 7) {
			assert(0);
		}
		else if (arg.get_type() == 0 || arg2.get_type() == 0) {
			assert(0);
			//std::cout <<"NOT INITIALIZED";
		}
		else if (arg.get_type() == 4 && arg2.get_type() == 4) {

			if (arg2.get_array_val().size() != arg.get_array_val().size())
				return  new JSON_element("FALSE");
			for (unsigned int i = 0; i < arg2.get_array_val().size(); i++) {
				JSON_element check = (operator==(arg.get_array_val()[i], arg2.get_array_val()[i]));
				if (check.boolean == false)
					return new JSON_element("FALSE");
				//	if ((operator==(arg.get_array_val()[i], arg2.get_array_val()[i])) == false) {
				//		return false;
				//	}
				ret_val = true;
			}

		}
		else if (arg.get_type() == 5 && arg2.get_type() == 5) {
			if (arg.obj_map.size() != arg2.obj_map.size())
				return false;

			for (auto & x : arg.obj_map)
			{

				std::map<std::string, JSON_element*>::iterator it;
				it = arg2.obj_map.find(x.first);

				if (it == arg2.obj_map.end())
					return new JSON_element("FALSE");
				JSON_element check2 = operator==(it->second, x.second);
				if (check2.boolean == false)
					return new JSON_element("FALSE");
			}
			ret_val = true;
		}
		if (ret_val)
			temp = new JSON_element("TRUE");
		else
			temp = new JSON_element("FALSE");
		return temp;
	}
	friend JSON_element operator!=(JSON_element arg, JSON_element arg2) {
		JSON_element temp = (operator==(arg, arg2));
		if (temp.boolean == true)
			return new JSON_element("FALSE");
		else
			return new JSON_element("TRUE");

	}

	friend std::ostream& operator<<(std::ostream& out, JSON_element& elem)
	{
		out << to_string(elem);// for example
		return out;
	}
	friend std::ostream& operator,(std::ostream& out, JSON_element& elem)
	{
		out << to_string(elem); // for example
		return out;
	}
	static std::string to_string(JSON_element arg);



};
