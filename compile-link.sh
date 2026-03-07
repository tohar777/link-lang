#!/bin/bash
clear
echo "--- Compiling in Progress ---"

rm -f error.txt 
rm -f link 

g++ -std=c++17 src/*.cpp -I./include -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o link 2> error.txt

# 3. Cek Error
if [ -s error.txt ]; then
    echo " !!! There is an Error Dude! Showing error.txt:"
    echo "-----------------------------------"
    cat error.txt
else
    echo "Compiled Success!!!"
    echo "Try running: ./link <file.link>"
=======

echo "--- Compiling in Progress ---"

# 1. Error Handling 
rm -f error.log  
rm -f error.txt 
rm -f link 

# 2. Compile the source code
g++ -O3 src/*.cpp -I include -o link 2> error.txt 

# 3. System Wait
sleep 1

# 4. Check for errors and display results
if [ -s error.txt ]; then
    echo "There an Error Dude! Showing error.log:"
    echo "-----------------------------------"
    cat error.txt
else
    echo "Compiled Success! Type './link' to Use Link-Lang. Enjoy :)"
fi
