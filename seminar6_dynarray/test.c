#include <stdio.h>
#include "log.h"

int main(void) {
    LOG("Start");

    printf("Hello\n");

    LOG("Finish");

    return 0;
}