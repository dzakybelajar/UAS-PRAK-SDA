#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Alokasi memori aktual untuk pointer global
PasienNode *rootAVL = NULL;
QueueNode *headQueue = NULL;
CircularLog logSistem = { .head = 0, .count = 0 };
int totalPasien = 0;

int max(int a, int b) { return (a > b) ? a : b; }

int getHeight(PasienNode* n) {
    if (n == NULL) return 0;
    return n->height;
}