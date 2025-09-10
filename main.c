#include <stdio.h>
#include "perms.h"

int main(void) {
    struct perms_t hello_txt;
    hello_txt.user.read = true;
    hello_txt.group.read = true;
    hello_txt.others.read = true;

    char *perms = fmt_perms(hello_txt);
    printf("hello.txt har rettighederne %s\n", perms);
    return 0;

    // TODO: Lav en masse tests
}