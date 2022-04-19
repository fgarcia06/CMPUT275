#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>
#define _MSG_MAX_LENGTH 100

using namespace std;

int main() {

  const char * pipename = "./sharedch";

  mkfifo(pipename, 0666); // all users can read and write 
  int fd = open(pipename, O_WRONLY); // open for write-only access

  char msg[_MSG_MAX_LENGTH];
  char delimiter = '\n';

  while(true){
    memset(msg, 0, _MSG_MAX_LENGTH);
    cin.getline(msg, _MSG_MAX_LENGTH);
    write(fd, msg, strlen(msg));
    write(fd, &delimiter, 1);
    if( strcmp(msg, "quit") == 0 ){
      break;
    }
  }  

  // close pipe from the write end 
  close(fd);
  // reclaim the backing file 
  unlink(pipename);

  return 0;
}
