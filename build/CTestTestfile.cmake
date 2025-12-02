# CMake generated Testfile for 
# Source directory: /workspaces/Lab3
# Build directory: /workspaces/Lab3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/Lab3/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/Lab3/CMakeLists.txt;36;add_test;/workspaces/Lab3/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
