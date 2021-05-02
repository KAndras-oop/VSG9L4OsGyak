#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int fd;
    pid_t child;

    if((mkfifo("VSG9L4", S_IRUSR | S_IWUSR)) < 0)
	{
        printf("RENDSZER: Nem sikerult a FIFO letrehozasa!\n");
        exit(1);
	}

    if((child = fork()) < 0){
        printf("RENDSZER: Nem sikerult a child fork processz letrehozasa!\n");
        exit(1);
    }
	else
	{
		printf("RENDSZER: A child processz elindult!\n\n");
	}

    //child processz
    if(!child){
        char *uzenet = "Garamszegi Marton";


        if((fd = open("VSG9L4", O_WRONLY)) < 0){
            printf("child: Nem sikerult a FIFO megnyitasa!\n");
            exit(1);


        } else {

            printf("child: FIFO megnyitva csak irasra, iras folyamatban...\n");
            write(fd, uzenet, strlen(uzenet));

        }
        printf("RENDSZER: A child processz sikeresen befejezete az irast,\na child processz kilep.\n\n");
		printf("RENDSZER: parent processz inditasa\n");
    }

    //parent processz
    if(child){
        char buf[256];
        if((fd = open("VSG9L4", O_RDONLY)) <0 ){

            printf("parent: Nem sikerult a FIFO megnyitasa!\n");
            exit(1);

        } else {

            printf("parent: FIFO megnyitva csak olvasasra, olvasas folyamatban...\n");
            read(fd, buf, sizeof(buf));
            printf("parent: Kiolvasott adat: %s.\n\n", buf);

            printf("RENDSZER: A parent processz sikeresen befejezete az olvasast.\n");

        }
        if((unlink("VSG9L4")) < 0 || (close(fd)) < 0){

            printf("RENDSZER: Nem sikerult a FIFO torlese!");

        } else {

            printf("RENDSZER: FIFO sikeresen torolve, kilepes.\n");
        }
	}


    return 0;

}