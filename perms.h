#ifndef AFL_2_DEMO_PERMS_H
#define AFL_2_DEMO_PERMS_H
#include <stdbool.h>
#include <stdint.h>

struct rwe_t {
    bool read;
    bool write;
    bool execute;
};

struct perms_t {
    struct rwe_t user;
    struct rwe_t group;
    struct rwe_t others;
};


struct ny_perms_t {
    uint32_t bits;
};

#define USER_READ 1
#define USER_WRITE 2
#define USER_EXECUTE 4

#define GROUP_READ 8
#define GROUP_WRITE 16
#define GROUP_EXECUTE 32

#define OTHERS_READ 64
#define OTHERS_WRITE 128
#define OTHERS_EXECUTE 256

// Returner jeg en string, SKAL jeg heap-allokere
char *fmt_perms(struct perms_t);

char *ny_fmt_perms(struct ny_perms_t);

// Tager jeg output-string'en som input, undgår jeg
// at allokere inde i funktionen jeg bygger
// void fmt_perms(struct perms_t, char *);

#endif //AFL_2_DEMO_PERMS_H