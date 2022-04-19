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
  int fd = open(pipename, O_RDONLY); // open for read-only access

  char msg[_MSG_MAX_LENGTH];
  char current;
  int idx;

  while(1){
    idx = 0;
    while(1){
      read(fd, &current, 1);
      if( current == '\n' ){
        break;
      }
      msg[idx++] = current;
    }
    msg[idx] = '\0';
    cout << "-----"  << endl;
    cout << msg << endl;
    cout << "-----"  << endl;
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
