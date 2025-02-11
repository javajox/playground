#include "../unit_test_helper.h"
#include <string.h>

#include "../unity.h"
#include "fs.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_create_txt_file(void) {
   const char *file_name_parts[] = {"/tmp/", generate_random_string(10), "test_fs.txt"};
   char *path_to_file = concatenate(file_name_parts, 3);

   create_txt_file(path_to_file, "test");
   TEST_ASSERT_TRUE(file_exists(path_to_file));

   TEST_ASSERT_EQUAL_STRING("test", read_txt_file(path_to_file));
   remove(path_to_file);

   TEST_ASSERT_FALSE(file_exists(path_to_file));
}

int main(void) {
   UNITY_BEGIN();

   RUN_TEST(test_create_txt_file);

   return UNITY_END();
}