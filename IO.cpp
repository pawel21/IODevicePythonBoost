#include <boost/python.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <errno.h>
#include <typeinfo>
#include <stdlib.h>

using namespace std;

class IODevice
{
public:
		void hello() {
			cout<<"hello"<<endl;
		}
		void connect(const char* port);
		void send_command(const char* command);
		void read_buffor();

private:
	int file_descriptor=0;
};


void IODevice::connect(const char * port) {
	this->file_descriptor = open(port, O_RDWR | O_NOCTTY);
	if (this->file_descriptor<0)
	{
		std::cout<<"No find port"<< std::endl;
	}
}

//TODO change size to write
void IODevice::send_command(const char* command)
{
	write(this->file_descriptor, (char*)command, 128);
}

//TODO add size of buffor to create it dynamic
void IODevice::read_buffor()
{
	char buffor[128];
	read(this->file_descriptor, buffor, 128);
	std::cout<<buffor<<std::endl;
}

BOOST_PYTHON_MODULE(IO) {

	using namespace boost::python;

	class_<IODevice>("IODevice")
		.def("hello", &IODevice::hello)
		.def("connect", &IODevice::connect)
		.def("send_command", &IODevice::send_command)
		.def("read_buffor", &IODevice::read_buffor);

}
