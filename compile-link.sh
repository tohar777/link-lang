#!/bin/bash

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
    echo "❌ There an Error Dude! Showing error.log:"
    echo "-----------------------------------"
    cat error.txt
else
    echo "Compiled Success! Type './link' to Use Link-Lang. Enjoy :)"
fi
