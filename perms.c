#include <stdlib.h>
#include "perms.h"

#include <string.h>

// Forventet output: "-rwx------"
char *fmt_perms(struct perms_t perms) {
    // char out[11]; // NO GO: Jeg må ikke allokere på stakken

    // Fordi jeg returnerer en pointer som skal opstå i funktionen
    // og skal leve længere end funktionen, så er heap-allokering
    // helt oplagt.
    char *out = malloc(11 * sizeof(char));
    out[0] = '-';
    out[1] = perms.user.read ? 'r' : '-';
    out[2] = perms.user.write ? 'w' : '-';
    out[3] = perms.user.execute ? 'x' : '-';

    out[4] = perms.group.read ? 'r' : '-';
    out[5] = perms.group.write ? 'w' : '-';
    out[6] = perms.group.execute ? 'x' : '-';

    out[7] = perms.others.read?  'r' : '-';
    out[8] = perms.others.write ? 'w' : '-';
    out[9] = perms.others.execute?  'x' : '-';
    out[10] = '\0';

    return out;
}

char *ny_fmt_perms(struct ny_perms_t perms) {
    char *out = malloc(11 * sizeof(char));

    out[0] = '-';
    out[1] = (perms.bits & USER_READ) ? 'r' : '-';
    out[2] = (perms.bits & USER_WRITE) ? 'w' : '-';
    out[3] = (perms.bits & USER_EXECUTE) ? 'x' : '-';

    out[4] = (perms.bits & GROUP_READ) ? 'r' : '-';
    out[5] = (perms.bits & GROUP_WRITE) ? 'w' : '-';
    out[6] = (perms.bits & GROUP_EXECUTE) ? 'x' : '-';

    out[7] = (perms.bits & OTHERS_READ) ?  'r' : '-';
    out[8] = (perms.bits & OTHERS_WRITE) ? 'w' : '-';
    out[9] = (perms.bits & OTHERS_EXECUTE)?  'x' : '-';
    out[10] = '\0';

    return out;
}
