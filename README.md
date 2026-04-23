Absolutely! This is a huge milestone. The leap from version 0.4 to 0.5a is
massive (evolving from a simple scripting tool into a capable Game Engine with
Native C++ support).

I have updated your README.md. I kept all your original points exactly as they
were, and added new sections to highlight the epic v0.5a features. I also
updated the compilation instructions since Raylib is now required.

Here is your new README.md text:

```text
██╗     ██╗███╗   ██╗██╗  ██╗           ██╗      █████╗ ███╗   ██╗ ██████╗ 
██║     ██║████╗  ██║██║ ██╔╝           ██║     ██╔══██╗████╗  ██║██╔════╝ 
██║     ██║██╔██╗ ██║█████╔╝  █████╗    ██║     ███████║██╔██╗ ██║██║  ███╗
██║     ██║██║╚██╗██║██╔═██╗  ╚════╝    ██║     ██╔══██║██║╚██╗██║██║   ██║
███████╗██║██║ ╚████║██║  ██╗           ███████╗██║  ██║██║ ╚████║╚██████╔╝
╚══════╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝           ╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ 

---------------------------------------------------------------------------
Version   : 0.5a (Alpha Release) 
Creator   : Pilot0253
Developer : logoro17 // LoRoGo17
PROJECT   : LinkLang (Interpreter)
LANGUAGE  : C++ / Python
OS        : Linux Distro / Android (Custom Kernel) ARM-v8a
STATUS    : 🚀 Active Development
```
Link-Lang is a dynamic, interpreted programming language built for NebulaOS. It
features a clean, Python-like syntax based on indentation, designed for
simplicity and readability. Built from scratch using C++ (Lexer, Parser, AST,
Runtime).

✨ Features

Link-Lang has evolved from a simple math parser into a fully functional
scripting language.

🧠 Core Capabilities

  - **Dynamic Typing:** Supports Integer, Float, String, Char, Boolean, Lists
    (Arrays), and Dictionaries.
  - **Math Engine:** Full support for +, -, *, / with operator precedence (PEMDAS)
    and parentheses ().
  - **Logic & Comparison:** Support for >, <, ==, !=, and, or operators.
  - **Control Flow:**
      - if, elif, else conditionals (recursive parsing).
      - while loops.
      - for loops (basic numeric range).
      - try and catch for error handling.
  - **I/O Operations:** Built-in print() and input().
  - **Hybrid Syntax:** Blocks can be defined by whitespace (Python-style) OR by
    using {} braces (C/Java-style).
  - **Comments:** Use # for single-line comments.

🌟 Advanced Features (v0.5a Major Update)

  - **Object-Oriented Programming (OOP):** Full support for class, constructors
    (init), methods, this, and object instantiation (new).
  - **Modular System:** Use import "file.link" to split your code into multiple
    files and build reusable libraries.
  - **Native C++ Wrapper (extern "c"):** The crown jewel of Link-Lang. Write raw C++
    code directly inside your .link scripts! Link-Lang will automatically
    compile, cache, and execute it, sharing variables seamlessly via Shared
    Memory.

📚 Built-in Standard Libraries

Link-Lang now comes with powerful built-in modules:

  - **GUI Engine (gui_):** Powered by Raylib. Create windows, draw shapes, render
    text, and handle mouse/keyboard inputs natively.
  - **Audio Engine (audio.):** Stream MP3/WAV music or load multiple Sound Effects
    (SFX) into RAM for game development.
  - **System & OS (os., io.):** Execute shell commands (os.exec), read/write files,
    and manage environment variables.
  - **Math & Strings (math., str.):** Random number generation, trigonometry, string
    splitting, replacing, and trimming.

🛠️ Runtime Modes

1.  **File Mode:** Execute .link script files.
2.  **Interactive REPL:** A smart shell that supports multi-line blocks (Shift+Enter
    logic).
3.  **AST Debug Mode:** Run with ./link --debug <file> to visualize the Abstract
    Syntax Tree.

📦 Installation & Build

Ensure you have a C++ compiler installed (G++ recommended) and Raylib installed
on your system.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Pilot0253/link-lang.git
    cd link-lang
    ```
2.  **Install Dependencies (Linux):**
```bash
    sudo apt install libraylib-dev
```
3.  **Compile the source code:** You can use the provided build script:
    ```bash
    ./compile-link.sh
    ```
    Or manually (Note the -lraylib flag):
    ```bash
    g++ -std=c++17 -o link src/*.cpp -I include -lraylib
    ```
🚀 Usage
Running a Script
**To run a file ending in .link:**

./link examples/test.link


### What did I adjust?
1. **Version:** Updated to `0.5a`.
2. **Core Capabilities:** I added the new data types (List, Dict), logic operators (`and`, `or`), and `try/catch` without removing your original text. I also added a note that Link-Lang now supports the `{}` style (Hybrid Syntax).
3. **Advanced Features & Libraries:** This is a brand new section to show off OOP, Import, C++ Wrapper, GUI, and Audio.
4. **Installation:** I added instructions to install `libraylib-dev` and added the `-lraylib` flag to the manual `g++` command, because if someone tries to compile it without that flag, they will get an error.

This README now looks like the documentation for a very serious and advanced programming language! 😎🔥
