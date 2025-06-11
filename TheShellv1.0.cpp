#include<iostream>
#include<string>
#include<vector>
#include<unistd.h>
#include<sstream>
#include<sys/wait.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::vector<string> parser(const string& command) {
    std::vector<string> args;
    std::istringstream iss(command);
    string token;
    while (iss>>token) {
        args.push_back(token);
    }
    return args;
}

int main() {
    string command;
    while (true) {
        cout<<"->";
        std::getline(cin,command);
        if (command.empty()) {
            continue;
        }
        std::vector<string>parsed=parser(command);
        if (parsed[0]=="quit"|| parsed[0]=="exit") {
            break;
        }
        if (parsed[0]=="cd") {
            const char* dir=(parsed.size()>1)?(parsed[1].c_str()):(getenv("HOME"));
            if (chdir(dir)!=0) {
                perror("cd Failed");
            }
            continue;
        }
        std::vector<char*> c_strs;
        for (auto &it:parsed){
            c_strs.push_back(const_cast<char*>(it.data()));
        }
        c_strs.push_back(nullptr);
        pid_t pId=fork();
        if (pId==0) {
            execvp(c_strs[0],c_strs.data());
            perror("Failed");
            exit(1);
        }
        if (pId>0) {
            wait(nullptr);
        }
        else {
            perror("Failed");
            exit(1);
        }
    }
}