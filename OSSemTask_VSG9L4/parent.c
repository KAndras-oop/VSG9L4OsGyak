#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    char* myfifo = "myfifo";
    mkfifo(myfifo, 0666);
    int number = 0;
    unsigned char line[80];
    pid_t pid=fork();
    if(pid==0){
    execv("./child",NULL);
    }
    else{
    while (number == 0) {
        fd = open(myfifo, O_RDONLY);
        read(fd, line, sizeof(line));

        memcpy(&number, line, sizeof(number));

       
        
    }
    close(fd);
    fd = open(myfifo, O_WRONLY);
    printf("A kapott szam: %d\n", number);
    number = number * 2;
    memcpy(line, &number, sizeof(number));
    write(fd, line, strlen(line) + 1);
    close(fd);
    
    return 0;
    }
}