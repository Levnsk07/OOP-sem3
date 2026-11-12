#include "module2.h"

namespace Module2
{
    std::string getMyName()
    {
        std::string name = "James";
        return name;
    }
}


namespace MyModule {
    std::string getMyName() {
        int some_new_line;
        return "Peter";
    }
}