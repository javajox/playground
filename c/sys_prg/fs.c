#include "fs.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "assert.h"

int create_txt_file(const char *file_path, const char *file_content) {
   assert(file_path != NULL);
   assert(file_content != NULL);
   int fd = open(file_path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
   if (fd == -1) {
     return -1;
   }
   ssize_t bytes_counted = write(fd, file_content, strlen(file_content));
   if (bytes_counted == -1) {
     return -1;
   }
   return 0;
}

bool file_exists(const char *file_path) {
   return access(file_path, F_OK) == 0;
}

int remove(const char *file_path) {
    return unlink(file_path) == 0 ? 0 : -1;
}
