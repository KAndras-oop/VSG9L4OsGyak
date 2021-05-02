#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int fd;
    int number = rand() % 99 + 1;
    unsigned char line[80];
    memcpy(line, &number, sizeof(number));
    char* myfifo = "myfifo";
    fd = open(myfifo, O_WRONLY);
    write(fd, line, sizeof(int));
    int readnumber = number;
    close(fd);
    fd = open(myfifo, O_RDONLY);
    while (number == readnumber) {
        
        read(fd, line, sizeof(line));
        memcpy(&readnumber, line, sizeof(readnumber));
    }
    printf("A kiolvasott szam: %d\n", readnumber);
    close(fd);

    return 0;
}