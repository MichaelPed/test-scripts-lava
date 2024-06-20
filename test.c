#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int forkedMethod(int sleepTime) {
  printf("Fork method start, sleep %d seconds\n", sleepTime);
  sleep(15);
  printf("Done sleeping, thread finishes executing\n");
  return 0;
}

int main(void) {
  int ret=0;
  pid_t pid;
  switch (pid = fork()) {
    case -1:
      ret = -1;
      break;
    case 0:
      /* child thread */

      /* the child becomes session leader */
      if(setsid() < 0){
        exit(EXIT_FAILURE);
      }
      ret = forkedMethod(15);
      break;
    default:
      /* parent thread */
      break;
  }
  
  return ret;
}
