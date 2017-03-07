#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("Main before fork()\n");
  int pid1 = fork();
  int pid2 = fork();
  if (pid1 == 0) {
    char *freeh[]= { "/bin/free", "-h" , NULL};
    execvp("/bin/free", freeh);
  }
  if (pid2 == 0) {
    char *ps[]= { "/bin/ps", "-ef" , NULL};
    execvp("/bin/ps", ps);
  }
  return 0;
}
