// void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[]){
    void *addr = (void *) 0x400000;  // Example address
    int length = 4096;               // 4 KB
    int prot = 1;                    // Example: PROT_READ
    int flags = 2;                    // Example: MAP_PRIVATE
    int fd = -1;                      // No file (anonymous mapping)
    int offset = 0;                   // Offset in file

    void *result = mmap(addr, length, prot, flags, fd, offset);
    if (result == (void *) -1) {
        printf(1,"mmap failed\n");
    } else {
        printf(1,"mmap returned: %p\n", result);
    }
    munmap();
    exit();
}