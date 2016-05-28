/*
 * sshsocket - this provides a subset of the ssh functionality in libssh2
 */
#include "version.h"
#include "sshsocket.h"

#include <cstdlib>
#include <iostream>

#include <boost/python.hpp>

namespace bpy = boost::python;

const char* get_version(){
    return _version; 
}

BOOST_PYTHON_MODULE(sshsocket) {
    bpy::def("version", get_version);
    bpy::class_<sshsocket::SSHSocket>(
        "SSHSocket", bpy::init<>())
    .def("accept", &sshsocket::SSHSocket::accept)
    .def("connect", &sshsocket::SSHSocket::connect)
    .def("close", &sshsocket::SSHSocket::close)
    .def("read", &sshsocket::SSHSocket::read)
    .def("write", &sshsocket::SSHSocket::write)
    .def("bind", &sshsocket::SSHSocket::bind)
    .def("fileno", &sshsocket::SSHSocket::fileno)
    .def("setblocking", &sshsocket::SSHSocket::setblocking) 
    ;
}

int main(int argc, const char **argv) {
    std::cout << "sshsocket " << _version << std::endl;
    std::_Exit(EXIT_SUCCESS);
}
