//
// Created by roman on 20.04.19.
//
#include <iostream>
#include <sys/mman.h>
#include <errno.h>
#include <cstring>

using std::cout;
using std::cin;

const int length = 53;

unsigned char binary_codes[] = {0x55, 0x48, 0x89, 0xe5, 0xc7, 0x45, 0xf8,
                                0xdf, 0xcf, 0xbf, 0xaf, // <------ here is a number 7, 8, 9,  10
                                0xc7, 0x45, 0xfc,
                                0x00, 0x00, 0x00, 0x00, 0x83, 0x7d, 0xf8, 0x00, 0x74, 0x18, 0x8b, 0x45, 0xf8, 0x83,
                                0xe0, 0x01, 0x85, 0xc0, 0x74, 0x04, 0x83, 0x45, 0xfc, 0x01, 0x8b, 0x45, 0xf8, 0xd1,
                                0xe8, 0x89, 0x45, 0xf8, 0xeb, 0xe2, 0x8b, 0x45, 0xfc, 0x5d, 0xc3};

int main() {
    unsigned int inp;
    cout << "Enter the number: ";
    cin >> inp;
    std::memcpy(binary_codes + 7, &inp, 4);

    void *mem = mmap(nullptr, length, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem == MAP_FAILED) {
        cout << strerror(errno) << std::endl;
        return errno;
    }
    if (mprotect(mem, length, PROT_EXEC | PROT_WRITE) != 0) {
        cout << strerror(errno) << std::endl;
        return errno;
    }

    std::memcpy(mem, binary_codes, length);
    cout << "There are "  << ((int (*)()) mem)() << " ones in binary form of " << inp <<  std::endl;
    if (munmap(mem, length) == -1) {
        cout << strerror(errno) << std::endl;
        return errno;
    }
    return 0;
}