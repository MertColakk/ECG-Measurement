#!/bin/bash

read -p "Which C++ version you want to use? (Ex: c++11, c++14, c++17): " user_cpp_version

case $user_cpp_version in
    "c++11")
        cpp_version="--std=c++11"
        ;;
    "c++14")
        cpp_version="--std=c++14"
        ;;
    "c++17")
        cpp_version="--std=c++17"
        ;;
    *)
        echo "Invalid C++ version. You will use C++17 defaultly."
        cpp_version="--std=c++17"
        ;;
esac

g++ $cpp_version ECG.cpp main.cpp Utility.cpp -o "executable" && ./executable

#This shell script written by Mustafa Mert Çolak(22298506)
