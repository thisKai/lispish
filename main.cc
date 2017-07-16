#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char* argv[])
{
    char* line;
    while(line != "exit"){
        line = readline("repl> ");
        add_history(line);
    }
}
