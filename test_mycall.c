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
    set_priority(1);
    sleep(5);
    printf(1, "Im the parent. I should run after my child. My priority: %d\n", get_priority());
  }
  else { //else child
    set_priority(2);
    sleep(5);
    printf(1, "Im the child. I should run before my parent. My priority: %d\n", get_priority());
  }
  sleep(5);

  if (pid1) {
    set_priority(20);
    sleep(5);
    printf(1, "Now I should print before my child. My priority: %d\n", get_priority());
  }
  else {
    set_priority(10);
    sleep(5);
    printf(1, "Im the child. Im going to exit. My priority: %d\n", get_priority());
    exit(0);
  }

  sleep(5);

  //------------ avoid starvation  ---------------------------
  printf(1, "\n ----------------------- avoid starvation test ----------------------\n");
  
  pid1 = fork();
  if (pid1) {
    set_priority(30);
    while (!waitpid(pid1, 0, 1)) {
      printf(1, "Im the parent. Im attempting to starve my child. My priority: %d\n", get_priority());
    }
  }
  else {
    sleep(5);
    printf(1, "\n\nIm the child. I ran with priority: %d\n\n", get_priority());
  }

  exit(0);
  return 0;
}
