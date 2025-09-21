#include <stdio.h>
#include "perms.h"

int main(void) {
    struct perms_t hello_txt;
    hello_txt.user.read = true;
    hello_txt.group.read = true;
    hello_txt.others.read = true;

    hello_txt.user.write= false;
    hello_txt.group.write= false;
    hello_txt.others.write= false;

    hello_txt.user.execute= false;
    hello_txt.group.execute= false;
    hello_txt.others.execute= false;

    char *perms = fmt_perms(hello_txt);
    printf("hello.txt har rettighederne %s\n", perms);


    struct ny_perms_t foo;
    foo.bits = 0b001001001;

    char *ny_perms = ny_fmt_perms(foo);
    printf("expected: -r--r--r--, actual: %s\n", ny_perms);

    foo.bits = USER_READ | USER_WRITE | USER_EXECUTE | GROUP_READ | OTHERS_READ;
    char *ny_perms2 = ny_fmt_perms(foo);
    printf("expected: -rwxr--r--, actual: %s\n", ny_perms2);

    foo.bits = USER_EXECUTE | GROUP_WRITE | GROUP_EXECUTE | OTHERS_READ;
    char *ny_perms3 = ny_fmt_perms(foo);
    printf("expected: ---x-wxr--, actual: %s\n", ny_perms3);

    foo.bits = USER_READ | USER_EXECUTE | GROUP_READ | GROUP_EXECUTE | OTHERS_WRITE | OTHERS_READ;
    char *ny_perms4 = ny_fmt_perms(foo);
    printf("expected: -r-xr-xrw-, actual: %s\n", ny_perms4);

    foo.bits = USER_READ | USER_WRITE | USER_EXECUTE | GROUP_READ | GROUP_WRITE |
        GROUP_EXECUTE | OTHERS_READ | OTHERS_WRITE | OTHERS_EXECUTE;
    char *ny_perms5 = ny_fmt_perms(foo);
    printf("expected: -rwxrwxrw, actual: %s\n", ny_perms5);
    return 0;
}