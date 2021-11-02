#include "types.h"
// #include "stat.h"
#include "user.h" 

// make qemu-nox
// ps aux | grep qemu

int
main(int argc, char *argv[]) {   
  // int status = 0;
  // wait(&status);  

  // printf(1, "status: %d \n", status);

  // int pid; 
  // if (!(pid = fork())) { //if child
  //   printf(1, "hello I am the child with pid %d \n", getpid());
  //   exit(99);
  //   return 0;
  // }
  
  // pid = wait(&status);
  // printf(1,"child pid: %d exited with status: %d \n", pid, status);

  // exit(0);

  int pid1 = 0;
  pid1 = fork();
  if (pid1) { //if parent
    set_priority(3);
    sleep(5);
    printf(1, "Im the parent. I should run after my child\n");
  }
  else { //else child
    set_priority(2);
    sleep(5);
    printf(1, "Im the child. I should run before my parent\n");
  }
  sleep(5);

  // if (pid1) {
  //   set_priority(20);
  //   sleep(5);
  //   printf(1, "Now I should print before my child\n");
  // }
  // else {
  //   set_priority(10);
  //   sleep(5);
  //   printf(1, "Im the child\n");
  // }

  // sleep(5);

  exit(0);
  return 0;
}
