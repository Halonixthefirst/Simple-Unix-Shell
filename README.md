# SimpleUnixShell

A simple shell built in C++ as a learning project. It supports commands execution, changing directories (cd) , management of system processes using fork() and execvp(), and error handling. 
Note:Built for the linux operating system.

Features:

Execute built-in commmands (echo,ls,mkdir,etc) .
Execute cd to change directories.
Command Parsing using StringStreams(sstream).
Proper error handling.

How it works:

-1: The main loop runs and the symbol (=>) shows up when the shell is ready to take an input.
-2: The shell accepts a line input with whitespaces , which is then parsed using a parser function that uses the StringStream to remove the whitespaces ans store each parsed word as a separate word in a vector. 
-3: If the first element is quit or exit. The program terminates.
-4: If the first element of parsed is cd, a char stores the address for cd as the second element or HOME if the second element is empty.
-5: Change the directory using chdir(). 
-6: A vector of C-style strings is created from the parsed vector and a null pointer is pushed to the end of the vector.
-7: A child process is created using fork();
-8: In the child, execvp() is used to process the C-style array.
-9: If the child has not executed, the parent waits for the child using wait().
-10: The program loops back.
--- In case of an error the program exits returning the exit code.

Learning Outcomes:

-Process creation using fork() and execvp.
-Parsing using string stream.
-Working of C-style strings.
-Handling built in commands like cd.

Contribution:

Feel free to contribute any improvements to the project. As its a learning project, feel free to fork and experiment.
