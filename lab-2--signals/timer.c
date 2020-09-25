
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int time=0;
void ALRM_handler(int signum)
{ //signal handler
  time++;
}
void SIGINT_sighandler(int signum) {
   printf("\nTime Elapsed: %d seconds\n", time);
   exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,ALRM_handler); //register handler to handle SIGALRM
   signal(SIGINT,SIGINT_sighandler);
  
  while(1){
     alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
    printf("Time elapsing...\n");
  } //busy wait for signal to be delivered
  
  return 0; //never reached
}