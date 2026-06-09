#include <stdio.h>
#include <string.h>
#include "header.h"

void menuUtama() {
    int pilihan;
    while (1) {
        pilihan = 0;
        printf("\n=== MEDTRACK PRO ===\n");
        printf("1. Masuk Sebagai Resepsionis\n");
        printf("2. Masuk Sebagai Dokter\n");
        printf("3. Keluar Aplikasi\n");
        printf("Pilih Akses: "); 
        scanf("%d", &pilihan);

    }
}

int main() {
    // Membaca database eksternal saat aplikasi dijalankan
    loadDatabase(); 
    menuUtama();
    return 0;
} 