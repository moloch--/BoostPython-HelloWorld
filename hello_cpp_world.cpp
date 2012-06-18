/*
 * Main.cpp
 *
 *  Created on: Jun 17, 2012
 *      Author: moloch
 */

#include <python2.7/Python.h>
#include <boost/python.hpp>

/* Required constructor, does nothing */
void python_init() {
	NULL;
}

/* Return a string */
char const* greet() {
	return "hello, world";
}

BOOST_PYTHON_MODULE(hello_cpp_world)
{
	using namespace boost::python;
	def("greet", greet);

	/*
	 * It is required to have a function with the same name as the module (maininit)
	 */
	def("hello_cpp_world", python_init);
}
