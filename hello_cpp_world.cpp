/*
 * Main.cpp
 *
 *  Created on: Jun 17, 2012
 *      Author: moloch
 */
#include <iostream>
#include <string>
#include <boost/python.hpp>
#include <python2.7/Python.h>

/* Required constructor, does nothing */
void python_init() {
	NULL;
}

char const* greet() {
	return "hello, world";
}

void display_str(std::string word) {
	std::cout << word << std::endl;
}

BOOST_PYTHON_MODULE(hello_cpp_world)
{
	using namespace boost::python;
	def("greet", greet);
	def("display_str", display_str);

	/* It is required to have a function with the same name as the module */
	def("hello_cpp_world", python_init);
}
