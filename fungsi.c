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

PasienNode* createPasien(long long nik, char nama[], char alamat[], int urgensi, time_t waktu, char diagnosa[]) {
    PasienNode *newNode = (PasienNode*)malloc(sizeof(PasienNode));
    newNode->nik = nik;
    strcpy(newNode->nama, nama);
    strcpy(newNode->alamat, alamat);
    newNode->urgensi = urgensi;

    if(diagnosa == NULL) strcpy(newNode->diagnosa, "Belum Diperiksa");
    else strcpy(newNode->diagnosa, diagnosa);
    
    newNode->left = newNode->right = NULL;
    newNode->waktu_periksa = (waktu == 0) ? time(NULL) : waktu;
    newNode->height = 1;

    totalPasien++;
    return newNode;
}

PasienNode* insertAVL(PasienNode* node, PasienNode* newNode) {
    if (node == NULL) return newNode;

    if (newNode->nik < node->nik) 
        node->left = insertAVL(node->left, newNode);
    else if (newNode->nik > node->nik) 
        node->right = insertAVL(node->right, newNode);
    else 
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

            if (balance > 1 && newNode->nik < node->left->nik) return rightRotate(node);
    
    if (balance < -1 && newNode->nik > node->right->nik) return leftRotate(node);
    
        if (balance > 1 && newNode->nik > node->left->nik) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && newNode->nik < node->right->nik) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

PasienNode* searchAVL(PasienNode* root, long long nik) {
    if (root == NULL || root->nik == nik) return root;
    if (nik < root->nik) return searchAVL(root->left, nik);
    return searchAVL(root->right, nik);
}

void cariDanTampilkanPasien(long long nik) {
    PasienNode* p = searchAVL(rootAVL, nik);
    if (p == NULL) {
        printf("\n[!] Pasien dengan NIK %lld tidak ditemukan.\n", nik);
    } else {
        struct tm *t = localtime(&p->waktu_periksa);
        printf("\n=== DATA DETAIL PASIEN ===\n");
        printf("NIK      : %lld\n", p->nik);
        printf("Nama     : %s\n", p->nama);
        printf("Alamat   : %s\n", p->alamat);
        printf("Urgensi  : %s\n", (p->urgensi == 1) ? "Darurat" : (p->urgensi == 2) ? "Mendesak" : "Biasa");
        printf("Tanggal  : %02d/%02d/%d\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);
        printf("Diagnosa : %s\n", p->diagnosa);
        printf("==========================\n");
    }
}

void enqueue(PasienNode* pasien) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = pasien;
    newNode->next = NULL;

     if (headQueue == NULL) headQueue = newNode;
    else {
        QueueNode* temp = headQueue;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void stablePrioritySort() {
    if (!headQueue || !headQueue->next) return;
    
    for (QueueNode* i = headQueue; i != NULL; i = i->next) {
        QueueNode* minNode = i;
        
        for (QueueNode* j = i->next; j != NULL; j = j->next) {
            if (j->data->urgensi < minNode->data->urgensi) {
                minNode = j;
            }
            else if (j->data->urgensi == minNode->data->urgensi) {
                if (j->data->waktu_periksa < minNode->data->waktu_periksa) {
                    minNode = j;
                }
            }
        }
        if (minNode != i) { 
            PasienNode* minData = minNode->data; 
            QueueNode* curr = i;
            PasienNode* prevData = curr->data;
            
        while (curr != minNode) {
    QueueNode* nextNode = curr->next;
    PasienNode* temp = nextNode->data;
    nextNode->data = prevData;
    prevData = temp;
    curr = nextNode;
}
i->data = minData;    