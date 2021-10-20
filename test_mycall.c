#include "types.h"
// #include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {   
  int status = 0;
  wait(&status);  

  printf(1, "status: %d \n", status);

  int pid; 
  if (!(pid = fork())) { //if child
    printf(1, "hello I am the child with pid %d \n", getpid());
    exit(99);
    return 0;
  }
  
  pid = wait(&status);
  printf(1,"child pid: %d exited with status: %d \n", pid, status);

  exit(0);

  return 0;
    
}
