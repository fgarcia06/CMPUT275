#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>
#define _MSG_MAX_LENGTH 100

using namespace std;

struct header {
  unsigned int type;    // Ignoring byte ordering for now
  unsigned int len;     // Ignoring byte ordering for now
};

int main() {

  const char * pipename = "./sharedch";

  mkfifo(pipename, 0666); // all users can read and write 
  int fd = open(pipename, O_RDONLY); // open for read-only access

  char msg[_MSG_MAX_LENGTH];
  char filename[_MSG_MAX_LENGTH];
  struct header h = { 0, 0 };
  int filed;
  void * fb;

  while(true){
    memset(msg, 0, _MSG_MAX_LENGTH);
    // FIXME:  Check return values for read() and others
    read(fd, &h, sizeof(h));   // header
    if( h.type == 0 ) {
      read(fd, msg, h.len);    // payload
      cout << msg << endl;
      if( strcmp(msg, "quit") == 0 ){
        break;
      }
    } else if( h.type == 1 ) {
      memset(filename, 0, _MSG_MAX_LENGTH);
      strcpy(filename, "copy.");
      read(fd, &(filename[5]), h.len);   // payload
// cout << "got: " << filename << endl;
    } else if( h.type == 2 ) {
      fb = calloc(0, h.len);    // Could use new, etc.
      unlink(filename);	// Be careful
      filed = open(filename, ( O_RDWR | O_CREAT ), ( S_IRUSR | S_IWUSR ) );
// cout << errno << endl;
      read(fd, fb, h.len);
      write(filed, fb, h.len);  // payload
// cout << "end " << filename << " " << filed << " " << fb << endl;
      close(filed);
      free(fb);
    }
  }

  // close pipe from the write end 
  close(fd);

  // reclaim the backing file 
  unlink(pipename);

  return 0;
}
