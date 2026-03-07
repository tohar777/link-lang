#include "help.h"
#include <iostream>

<<<<<<< HEAD
void printVersion() {
	std::cout << "Link-Lang Version 0.4a (Alpha Release) \n" << std::endl;
} 

=======
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c
void printHelp() {
    std::cout << R"(

========================================================
<<<<<<< HEAD
           NEBULA OS LINK-LANG v0.4a (Alpha) HELP
=======
           NEBULA OS LINK-LANG v0.2.2a (Alpha) HELP
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c
========================================================
History:
Created by   : Pilot0253
Developed by : logoro17 // LoRoGo17 

USAGE:
  ./link                  : Enter Interactive Mode (REPL).
  ./link <file.link>      : Execute a Link-Lang script file.
<<<<<<< HEAD
  ./link --help           : Show this manual.
=======
  ./compile-link.sh       : Recompile source code.
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c

DATA TYPES:
  Integer  : 10, 25, -5
  Float    : 3.14, 2.5
  String   : "Hello", 'World'
  Char     : 'A', 'x'
  Boolean  : true, false
<<<<<<< HEAD
  List     : [1, 2, "Text"]
  Dict     : {"key": "value", "ver": 1.0}
  Object   : <Instance Robot> (New!)
=======
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c

BASIC COMMANDS:
  set x = 10              : Variable declaration.
  print(x)                : Output to screen.
  input("Message: ")      : Get user input.
<<<<<<< HEAD
  import "file.link"      : Import other script files.
  sh "ls -la"             : Quick shell command execution.

OBJECT ORIENTED PROGRAMMING (New!):
  class Robot {           : Define a class.
      init(name) {        : Constructor.
          set this.n = name
      }
      func walk() {       : Method definition.
          print(this.n)
      }
  }
  set r = new Robot("X")  : Create new instance.
  r.walk()                : Call method.

CONTROL FLOW (HYBRID STYLE):
  * Supports both Indentation (Python) and Block {} (C/Java)
  
  1. CONDITIONAL
     if x > 10 { print("Big") }
     else      { print("Small") }

  2. LOOPING
     while x < 5 {
         print(x)
         set x = x + 1
     }
     for i in range(5) {
         print(i)
     }

  3. ERROR HANDLING
     try {
         io.read("missing.txt")
     } catch (e) {
         print("Error: " + e)
     }

BUILT-IN LIBRARIES:

  [TIME & SYSTEM]
  time.sleep(ms)          : Pause execution (e.g., 1000 = 1 sec).
  os.exec("cmd")          : Execute shell command.
  os.getenv("KEY")        : Get env variable.
  os.setenv("K","V")      : Set env variable.

  [LIST & DATA]
  list.add(lst, item)     : Add item to list.
  len(obj)                : Get length of String or List.
  range(n)                : Generate list [0, 1, ... n-1].

  [FILE I/O]
  io.read("path")         : Read file content.
  io.write("p", "txt")    : Write to file (Overwrite).
  io.append("p", "txt")   : Append to file.
  io.exists("path")       : Check file existence.
  io.remove("path")       : Delete file.

  [STRING]
  str.trim(" txt ")       : Remove whitespace.
  str.replace(s, "a","b") : Replace text.
  str.split("a,b", ",")   : Split string to List.
  str.merge(list, ",")    : Merge List to String.
  str.contains(s, "sub")  : Check substring.

  [MATH]
  math.pi()               : Returns PI.
  math.pow(b, e)          : Power.
  math.sqrt(x)            : Square Root.
  math.sin(r) / cos(r)    : Trigonometry (Radians).
  math.abs(x)             : Absolute value.

========================================================

)" << std::endl;
}   
=======

MATHEMATICAL OPERATORS:
  +  : Addition (or String concatenation).
  -  : Subtraction.
  * : Multiplication.
  /  : Division.

LOGIC & COMPARISON:
  >  : Greater than.
  <  : Less than.
  == : Equal to.

CONTROL FLOW:
  Execute code blocks using indentation (spaces/tabs).

  1. CONDITIONAL (IF-ELIF-ELSE)
     if x > 10
         print("Large")
     elif x > 5
         print("Medium")
     else
         print("Small")

  2. LOOPING (WHILE)
     while x < 5
         print(x)
         set x = x + 1

  3. LOOPING (FOR)
     for i in range(5)
         print(i)

SYSTEM COMMANDS:
  sh "clear"              : Execute Linux terminal commands.
  sh "ls -la"             : Another example.

INTERACTIVE MODE:
  - Press Enter once for standard command lines.
  - When writing blocks (if/while), press Enter twice (empty line)
    to execute the block.
========================================================

)" << std::endl;
}   
>>>>>>> a9e7b5f67ff71ead5b253ae707b9ab78576a0a8c
