/// Author:  Alexander Bazzi
/// Description: Initializes a socket to listen for a tcp connection from a 
/// client on the specified port.

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

    SocketType server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *msg = "Hello handsome";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        PRINTLASTERROR;
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof(opt))) {
        PRINTLASTERROR;
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // or specific IP
    address.sin_port = htons(5000);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        PRINTLASTERROR;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        PRINTLASTERROR;
        exit(EXIT_FAILURE);
    }

    std::cout << "Listening on port 5000...\n";

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        PRINTLASTERROR;
        exit(EXIT_FAILURE);
    }

    ssize_t valread = portable_read(new_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << std::endl;
    send(new_socket, msg, strlen(msg), 0);
    std::cout << "Server reply: " << msg << "\n";

    CLOSESOCKET(new_socket);
    CLOSESOCKET(server_fd);
    cleanup_network();

    return 0;
}
