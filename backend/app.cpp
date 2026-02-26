#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Backend is running..." << std::endl;

    while(true) {
        sleep(10);
    }

    return 0;
}
