# sshsocket
This is a python module meant to mimic the sslsocket interface. This uses libssh2 and boost.python
to provide a blocking/nonblocking socket-type interface for ssh connections
```
import sshsocket

with sshsocket.sshsocket(sock, user='foo', password='bar) as ssh_sock:
    ssh_sock.write('ls -lha /tmp')
    try:
        print ssh_socket.read()
    except sshsocket.CommandError, cmd_err:
        raise
    ssh_sock.setblocking(False)
    # Add to polling loop for sshified state machines
```
