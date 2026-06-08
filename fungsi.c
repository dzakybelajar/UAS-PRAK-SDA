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

int getBalance(PasienNode* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

PasienNode* rightRotate(PasienNode* y) {
    PasienNode* x = y->left;
    PasienNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

PasienNode* leftRotate(PasienNode* x) {
    PasienNode* y = x->right;
    PasienNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
