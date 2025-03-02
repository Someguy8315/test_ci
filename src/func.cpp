#include "func.h"
#include <re2/re2.h>

int getValue()
{
    RE2 pattern("^[0-9]+$");
    std::string input("12345");

    return RE2::FullMatch(input, pattern);
}
