# CMake generated Testfile for 
# Source directory: /home/ain/projects/khias/lib/cJSON-master
# Build directory: /home/ain/projects/khias/lib/cJSON-master
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "/home/ain/projects/khias/lib/cJSON-master/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "/home/ain/projects/khias/lib/cJSON-master/CMakeLists.txt;252;add_test;/home/ain/projects/khias/lib/cJSON-master/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
