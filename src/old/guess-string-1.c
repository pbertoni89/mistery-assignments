/**
 * What is the value of the variable output at the end of this program?
 * 1. 00005
 * 2. 1000116
 * 3. 1000100005
 * 4. 00006
 */

#include <stdio.h>
#include <string.h>

void main() {
    char output [50];
    int x = 100011;
    sprintf(output, "%05d", x);
    int y = strlen(output);
    sprintf(output, "%05d", y);
//    printf(output);
}
