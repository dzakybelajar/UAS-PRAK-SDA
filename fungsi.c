#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Alokasi memori aktual untuk pointer global
PasienNode *rootAVL = NULL;
QueueNode *headQueue = NULL;
CircularLog logSistem = { .head = 0, .count = 0 };
int totalPasien = 0;