#ifndef HEADER_H
#define HEADER_H
#include <time.h>
typedef struct PasienNode {
    long long nik;
    char nama[50];
    char alamat[100];
    int urgensi;           // 1: Darurat, 2: Mendesak, 3: Biasa
    time_t waktu_periksa;
    char diagnosa[500];
    int height;            // Tambahan untuk fitur AVL Tree
    struct PasienNode *left, *right;
} PasienNode;

typedef struct QueueNode {
    PasienNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct StackNode {
    char teks_diagnosa[500];
    struct StackNode *next;
} StackNode;

typedef struct {
    char riwayat[10][200];
    int head;
    int count;
} CircularLog;

// Pointer Global
extern PasienNode *rootAVL;
extern QueueNode *headQueue;
extern CircularLog logSistem;
extern int totalPasien;

void menuResepsionis();
void menuDokter();
int login(int role); // 1: Resepsionis, 2: Dokter

// Fungsi Basis Data (AVL Tree)