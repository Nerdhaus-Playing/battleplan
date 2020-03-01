cd ..
mkdir build 
cd build
conan install .. --build=missing -s build_type=Debug -s compiler.libcxx=libstdc++11 -o with_tests=True -o with_demo=True
conan build ..
