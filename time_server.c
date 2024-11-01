#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>  // addrinfo
#include <unistd.h> //close
#include <errno.h> //errno
#include <stdio.h>
#include <string.h>
#include <time.h>

// macros
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)

int main()
{
    printf("Configuring local address....\n");
    // variable 'hints' of type struct addrinfo
    struct addrinfo hints;
    // takes pointer to address of hints, sets it to 0, specify number of bytes that should be set to zero
    // this is done because addrinfo has a ton of fields that need to be initialized
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // no need to initialize bind_address with memset before hand
    // will hold the return info from getaddrinfo()
    struct addrinfo *bind_address;
    // 
    // 0, means to listen on all network interfaces, 8080 is the port
    getaddrinfo(0, "8080", &hints, &bind_address);
    printf("Creating socket...\n");
    // define socket_listen as a SOCKET type
    SOCKET socket_listen;
    // call socket function to gen socket.socket()
    // takes 3 params: family, socket type and protocol
    socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
    if(!ISVALIDSOCKET(socket_listen)) {
        fprintf(stderr, "socket() failed. (%d\n)", GETSOCKETERRNO());
        return 1;
    }
    printf("Binding socket to locall address...\n");
    if(bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address);

    return 0;
}
