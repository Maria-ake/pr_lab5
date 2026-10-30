#include <iostream>
#include <string>
#include "callchain.h"

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "int") {
        setThrowInt(true);
    }

    std::cout << "Начало цепи\n";
    f1();
    std::cout << "Конец цепи\n";
    return 0;
}
