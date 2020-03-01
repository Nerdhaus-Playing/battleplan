cd ..
mkdir build 
cd build
conan install .. --build=missing -s build_type=Debug -o with_tests=True -o with_demo=True
conan build ..
