
# SimpleUnixShell

A lightweight Unix shell built from scratch in C++ with native process management, command parsing, and a modular architecture, built to understand how real shells work under the hood.
It supports commands execution, changing directories (cd) , management of system processes using fork() and execvp(), and error handling. 
Built for and runs only on the linux operating system.

## Demo Video
![DemoVideo](https://github.com/Halonixthefirst/Simple-Unix-Shell/blob/main/DemoVideo.gif)

## Features:

* Execute built-in commands (e.g., `echo`, `ls`, `mkdir`)
* Built-in `cd` support
* Command parsing using `std::stringstream`
* Proper error handling for system calls

## How it works:

1. The main loop runs and the symbol (=>) shows up when the shell is ready to take an input.
2. The shell accepts a line input with white spaces , which is then parsed using a parser function that uses the StringStream to remove the white spaces and store each parsed word as a separate word in a vector. 
3. If the first element is quit or exit. The program terminates.
4. If the first element of parsed is cd, a char stores the address for cd as the second element or HOME if the second element is empty.
5. Change the directory using chdir(). 
6. A vector of C-style strings is created from the parsed vector and a null pointer is pushed to the end of the vector.
7. A child process is created using fork();
8. In the child, execvp() is used to process the C-style array.
9. If the child has not executed, the parent waits for the child using wait().
10. The program loops back.

In case of an error the program exits returning the exit code.

## Learning Outcomes:

* Process creation using fork() and execvp.
* Parsing using string stream.
* Working of C-style strings.
* Handling built in commands like cd.

## Roadmap
- [ ] Add support for piping and redirection
- [ ] Built-in command history (up/down arrows)
- [ ] AI-suggestions via OpenAI API
- [ ] Tab auto-completion

## Contribution:

Feel free to contribute any improvements to the project. As its a learning project, feel free to fork and experiment.
