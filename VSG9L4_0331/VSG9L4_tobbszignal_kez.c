#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void HandleSignals(int signum);

int main(void) {
	void(*sigHandlerInterrupt)(int);
	void(*sigHandlerQuit)(int);
	void(*sigHandlerReturn)(int);
	sigHandlerInterrupt = sigHandlerQuit =HandleSignals;
	sigHandlerReturn = signal(SIGINT, sigHandlerInterrupt);
	if (sigHandlerReturn == SIG_ERR){
		perror("signal error: ");
		return 1;
	}
	sigHandlerReturn = signal(SIQUIT, sigHandlerQuit);
	
	if (sigHandlerReturn == SIG_ERR) {
		perror("signal error ");
		return 1;
	}
	while (1){
		printf("\nA program leallitashoz nyison meg egy masik terminalt utana nyomja meg a ctrl+c ketszer")
		sleep(10);
	}
	return 0;
}

void HandleSignals(int signum){
	switch(signum){
		case SIGINT:
		printf("\n nyomja meg a CTRL + C ez viszaallitja a SIGINT jelet\n");
		signal(SIGINT, SIG_DFL);
		break;
		case SIQUIT:
		printf("\n nyomja meg a CTRL+\n");
		break;
		default;
		printf("\nFogadot jel szama :%d\n", signum);
		break;
	}
	return;
}
