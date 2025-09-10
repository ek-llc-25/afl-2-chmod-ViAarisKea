#include <stdlib.h>
#include "perms.h"

// Forventet output: "-rwx------"
char *fmt_perms(struct perms_t perms) {
    // char out[11]; // NO GO: Jeg må ikke allokere på stakken

    // Fordi jeg returnerer en pointer som skal opstå i funktionen
    // og skal leve længere end funktionen, så er heap-allokering
    // helt oplagt.
    char *out = malloc(11 * sizeof(char));

    out[0] = '-';
    // TODO: Find ud af hvad der er inde i 'perms'
    out[10] = '\0';

    return out;
}

char *ny_fmt_perms(struct ny_perms_t perms) {
    char *out = malloc(11 * sizeof(char));

    out[0] = '-';
    // TODO: Find bits'ene inde i 'perms'
    out[10] = '\0';
}
