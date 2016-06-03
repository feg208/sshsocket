#ifndef _SSHSOCKET_H
#define _SSHSOCKET_H

#include <boost/python.hpp>

extern "C" {
#include<libssh2.h>
}

namespace sshsocket {

    namespace bpy = boost::python;

class SSHSocket {
    public:
        SSHSocket();
        void accept();
        void connect(const bpy::tuple);
        void close();
        bpy::str read(const bpy::long_&);
        bpy::long_ write(const bpy::str&);
        void bind(const bpy::tuple);
        int fileno();
        void setblocking(const bool block = true) { isblocking = block; }
    private:
        bool isblocking;
};

}
#endif
