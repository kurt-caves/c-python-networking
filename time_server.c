#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>  // addrinfo
#include <unistd.h> //close
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
    hints.ai_family =
}
