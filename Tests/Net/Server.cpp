/**
 *
 *       @file  Server.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/10/2011 19:24:10
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/TcpServer.h>
#include <Net/TcpSocket.h>
#include <stdio.h>
#include <Net/SocketErrors.h>
int main() {
    TcpServer server;

    if(server.listen(2000) == SocketErrors::SOEBIND) {
        perror("");
        return -1;
    }

    TcpSocket* s = server.accept();

    if(s == NULL) {
        cout << "Error: cannot accept conection" << endl;
        return -1;
    }

    cout << "Connected client" << endl;
    int i = 4;
    i++;
    s->sendInt(10);
    s->sendString("hello");
    s->close();
    delete s;
    server.close();
    return 1;
}
