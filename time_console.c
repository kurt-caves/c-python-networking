#include <stdio.h>
#include <time.h>

int main() {

    // datatype that represents time passed since Unix
    time_t timer;
    // get current time an store in timer
    time(&timer);

    printf("Local time is: %s", ctime(&timer));

    return 0;
}