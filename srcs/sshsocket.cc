/*
 * sshsocket - this provides a subset of the ssh functionality in libssh2
 */
#include "version.h"

#include <cstdlib>
#include <iostream>

#include <boost/python.hpp>

namespace bpy = boost::python;

const char* get_version(){
    return _version; 
}

BOOST_PYTHON_MODULE(sshsocket) {
    bpy::def("version", get_version);
}

int main(int argc, const char **argv) {
    std::cout << "sshsocket " << _version << std::endl;
    std::_Exit(EXIT_SUCCESS);
}
