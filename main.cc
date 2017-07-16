#include <string>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char* argv[])
{
    std::string line;
    while(line != "exit"){
        line = readline("repl> ");
        add_history(line.c_str());
    }
}
