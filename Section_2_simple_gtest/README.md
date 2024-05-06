mkdir build
cd build
cmake ..
make 
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage