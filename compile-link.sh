#!/bin/bash
clear
echo "--- Compiling in Progress ---"

# 1. Bersihkan file lama (PENTING biar gak ada Zombie)
rm -f error.txt 
rm -f link 

# 2. Compile dengan menunjuk file satu per satu (Lebih Aman)
# Kita TIDAK memasukkan src/runtime.cpp di sini karena dia sudah di-include di main.cpp
g++ -O3 src/*.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -I include -o link 2> error.txt

# 3. Cek Error
if [ -s error.txt ]; then
    echo " !!! There is an Error Dude! Showing error.txt:"
    echo "-----------------------------------"
    cat error.txt
else
    echo "Compiled Success!!!"
    echo "Try running: ./link <file.link>"
fi
