# Python version
PYTHON = /usr/include/python2.7

# Boost libs
BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

TARGET = hello_cpp_world

$(TARGET).so: $(TARGET).o
	g++ -shared -Wl,--export-dynamic \
	$(TARGET).o -L$(BOOST_LIB) -lboost_python \
	-L/usr/lib/python2.7/config -lpython2.7 \
	-o $(TARGET).so

$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON) -I$(BOOST_INC) -c -fPIC $(TARGET).cpp