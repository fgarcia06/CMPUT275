#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>
#include <limits.h>	// For SSIZE_MAX
#define _MSG_MAX_LENGTH 100

using namespace std;

struct header {
  unsigned int type;	// Ignoring byte ordering for now
  unsigned int len;	// Ignoring byte ordering for now
};

int main() {

  const char * pipename = "./sharedch";

  mkfifo(pipename, 0666); // all users can read and write 
  int fd = open(pipename, O_WRONLY); // open for write-only access

  char msg[_MSG_MAX_LENGTH];
  struct header h = { 0, 0 };
  struct stat sb; // NEW
  int filed;
  void * fb;

  while(true){
    memset(msg, 0, _MSG_MAX_LENGTH);
    cin.getline(msg, _MSG_MAX_LENGTH);
    // FIXME:  Check return values for write() and others

    // NEW send command
    if( strncmp(msg, "send", 4) == 0 ) {
      // Send path
      const char * path = &(msg[5]);
      h.type = 1;
      h.len = strlen(path);
      write(fd, &h, sizeof(h));	// header
      write(fd, path, h.len);	// payload

      // Send file itself
      h.type = 2;
      filed = open(path, O_RDONLY);
      fstat(filed, &sb);
      h.len = sb.st_size;

      fb = calloc(0, h.len);	// Could use new, etc.
      read(filed, fb, h.len);
      write(fd, &h, sizeof(h));	// header
      write(fd, fb, h.len);	// payload
      free(fb);
// cout << "done send\n";
    }
    // Regular text
    else {
      h.type = 0;
      h.len = strlen(msg);
      write(fd, &h, sizeof(h));	// header
      write(fd, msg, h.len);	// payload
      if( strcmp(msg, "quit") == 0 ) {
        break;
      }
    }
  }  

  // close pipe from the write end 
  close(fd);
  // reclaim the backing file 
  unlink(pipename);

  return 0;
}
