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

        while(getchar()!='\n');

        switch (pilihan) {
            case 1:
                if (login(1)) menuResepsionis();
                break;
            case 2:
                if (login(2)) menuDokter();
                break;
            case 3:
                printf("Terima kasih telah menggunakan MedTrack Pro.\n");
                return;
            default:
                printf("Pilihan tidak valid!\n");
        }

    }
}

int main() {
    // Membaca database eksternal saat aplikasi dijalankan
    loadDatabase(); 
    menuUtama();
    return 0;
} 