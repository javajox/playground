#ifndef FS_H
#define FS_H

#include <stdbool.h>

int create_txt_file(const char *file_path, const char *file_content);
bool file_exists(const char *file_path);
int remove(const char *file_path);

#endif //FS_H
