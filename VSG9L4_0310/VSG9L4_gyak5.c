#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pid;
    int status;
	
	if ((pid = fork()) < 0) {
        perror("fork hiba");
	else if(pid == 0) /* gyermek */
	exit(7); /* befejeződik */
	if(wait(&status) != pid)
		perror("wait hiba"); /* szülő */
	if(WIFEXITED(status))
		printf("sikeresen lefordult")

    return 0;
}