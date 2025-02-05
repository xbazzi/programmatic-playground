/// Author:  Alexander Bazzi
/// Description: Connects to a tcp server and sends a message over a socket

#include <iostream>
#include <cstring> // For memset on POSIX

// Platform-specific includes and initialization
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "Ws2_32.lib")

    typedef SOCKET SocketType;
    #define CLOSESOCKET closesocket
    #define PRINTLASTERROR std::cerr << "WSAGetLastError: " << WSAGetLastError() << std::endl;

    void init_network() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "WSAStartup failed.\n";
            exit(1);
        }
    }

    void cleanup_network() {
        WSACleanup();
    }
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    typedef int SocketType;
    #define CLOSESOCKET close
    #define PRINTLASTERROR perror("Error")

    void init_network() {
        // No initialization needed for POSIX
    }

    void cleanup_network() {
        // No cleanup needed for POSIX
    }
#endif

// Define a portable read function
ssize_t portable_read(SocketType socket, char *buffer, size_t length) {
    #ifdef _WIN32
    return recv(socket, buffer, length, 0);
    #else
    return read(socket, buffer, length);
    #endif
}

int main() {
    init_network();

    SocketType sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        PRINTLASTERROR;
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr)); // Ensure struct is empty
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "\nConnection Failed \n";
        return -1;
    }

    const char* msg = "Hello from client";
    send(sock, msg, strlen(msg), 0);
    std::cout << "Message: " << msg << "\n";

    char buffer[1024] = {0};
    portable_read(sock, buffer, 1024);
    std::cout << "Server reply: " << buffer << std::endl;

    CLOSESOCKET(sock);
    cleanup_network();

    return 0;
}