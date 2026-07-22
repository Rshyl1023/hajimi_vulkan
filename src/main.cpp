#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

#include "first_app.h"

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    lve::FirstApp app{};

    try {
        app.run();
    }catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}