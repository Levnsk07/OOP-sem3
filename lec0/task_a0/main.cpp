#include "lib_module1/module1.h"
#include "lib_module2/module2.h"
#include <iostream>


namespace newOne {
    std::string getMyName() {
        return "Peter";
    }
}

int main(int argc, char** argv)
{
    std::cout <<  "Hello world!" << "\n";

    std::cout << Module1::getMyName() << "\n";
    std::cout << Module2::getMyName() << "\n";

    using namespace Module1;
    std::cout << getMyName() << "\n"; // (A) // Использование Функции из модуля 1, не требует аннотации к пространству имён
    std::cout << Module2::getMyName() << "\n";

    //using namespace Module2; // (B)
    //std::cout << getMyName() << "\n"; // COMPILATION ERROR (C) // ошибка так как уже объявлен другое пространство имён
    // Р-Е - использование {..} для выделения части где будет использоваться определённый namespace, использование импорта для каждой необходимой функции по отдельности

    using Module2::getMyName;
    std::cout << getMyName() << "\n"; // (D) // указание использования определённой функции из определённого пространства имён

}

// N5 написать using namespace std или указать точное  using namespace std::cout