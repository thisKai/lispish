#ifndef __Lispish_Header_REPL
#define __Lispish_Header_REPL

#include <string>

enum struct ReplResult
{
    Success,
    Error,
};

ReplResult repl(const char prompt[]);

#endif
