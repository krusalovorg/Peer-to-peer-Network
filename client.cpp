#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "client.h"
#include <xlocinfo>
#include <winsock.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

int client(int ip, int port)
{
    std::cout << "Run Client" << std::endl;
    int wsaStatus, connectStatus; //check errors
    WSADATA WSAData;
    wsaStatus = WSAStartup(MAKEWORD(2, 0), &WSAData);
    if (wsaStatus != NO_ERROR) {
        std::cout << "WSA Startup failed with error : " << wsaStatus;
    }
    SOCKET sock; //defines the sockets TO SEND
    SOCKADDR_IN sin;//information about the socket

    sin.sin_addr.s_addr = inet_addr("127.0.0.1");//ip of the server you want to connect to
    sin.sin_family = AF_INET;//family of the socket, for internet it's AF_INET
    sin.sin_port = htons(3345);// 23 for telnet etc, it's the port
    sock = socket(AF_INET, SOCK_STREAM, 0);//second parameter is the type of the socket, SOCK_STREAM opens a connection ( use for TCD ), SOCK_DGRAM doesn't connect() or accept() it's used for UDP
    if (sock == INVALID_SOCKET) {
        std::cout << "INVALID SOCKET " << WSAGetLastError();
        WSACleanup();
    }

    bind(sock, (SOCKADDR*)&sin, sizeof(sin)); //binds the socket to the port and the adress above

    char buffer[255]; //creates a buffer to receive messages

    connectStatus = connect(sock, (SOCKADDR*)&sin, sizeof(sin)); //function to connect to the server
    if (connectStatus == SOCKET_ERROR) { //it returns 0 if no error occurs
        std::cout << "Connection failed with error : " << WSAGetLastError();
        closesocket(sock);
        WSACleanup();
    }

    int iResult = send(sock, "Hello world!\r\n", 14, 0);
    if (iResult == SOCKET_ERROR) {
        std::cout << "Send failed with error : " << WSAGetLastError() << std::endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
