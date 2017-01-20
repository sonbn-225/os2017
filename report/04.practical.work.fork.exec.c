#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("Main before fork()\n");
  int pid = fork();
  if (pid == 0) {
    char *freeh[]= { "/bin/free", "-h" , NULL};
    execvp("/bin/free", freeh);
  }
  else {
    char *ps[]= { "/bin/ps", "-ef" , NULL};
    execvp("/bin/ps", ps);
  }
  return 0;
}
