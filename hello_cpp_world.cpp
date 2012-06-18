/*
 * Main.cpp
 *
 *  Created on: Jun 17, 2012
 *      Author: moloch
 */
#include <string>
#include <vector>
#include <iostream>
#include <boost/python.hpp>
#include <python2.7/Python.h>

/* Required constructor, does nothing */
void python_init() {
	NULL;
}

char const* greet() {
	return "Hello World!";
}

void display_str(std::string word) {
	std::cout << word << std::endl;
}

void display_list(unsigned int len, boost::python::list& ls) {
	std::cout << "Length: " << len << std::endl;
	for (unsigned int index = 0; index < len; ++index) {
		std::string data = boost::python::extract<std::string>(ls[index]);
		std::cout << index << ": " << data << std::endl;
	}
}

boost::python::dict create_dict() {
	boost::python::dict d;
	d["foo"] = "hello";
	d["bar"] = "world";
	return d;
}

void keyword_args(std::string foo, std::string bar) {
	std::cout << "Foo: " << foo << std::endl;
	std::cout << "Bar: " << bar << std::endl;
}

void default_args(std::string foo = "foo", std::string bar = "bar") {
	std::cout << "Foo: " << foo << std::endl;
	std::cout << "Bar: " << bar << std::endl;
}

/* Macro to wrap keyword_args, the '1' and '2' are the min/max number of args */
BOOST_PYTHON_FUNCTION_OVERLOADS(default_args_overloads, default_args, 0, 2);

BOOST_PYTHON_MODULE(hello_cpp_world) {
	using namespace boost::python;
	def("greet", greet);
	def("display_str", display_str);
	def("display_list", display_list);
	def("create_dict", create_dict);
	def("keyword_args", keyword_args, args("foo", "bar"));
	def("default_args", default_args, default_args_overloads(args("foo", "bar"), "doc-string"));

	/* It is required to have a function with the same name as the module */
	def("hello_cpp_world", python_init);
}
