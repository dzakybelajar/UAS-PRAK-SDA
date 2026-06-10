#include <stdio.h>
#include <string.h>
#include "header.h"

int login(int role) {
    char username[20];
    char password[20];

    printf("\n--- LOGIN SYSTEM ---\n");
    printf("Username: "); scanf("%s", username);
    printf("Password: "); scanf("%s", password);

if (role == 1) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0) return 1;
}else if (role == 2) {
    if (strcmp(username, "dokter") == 0 && strcmp(password, "dok123") == 0) return 1;
}
printf("[!] Username atau Password Salah!\n");
    return 0;
}

void menuResepsionis() {
    int pilihan, urg;
    long long n;
    char nm[50], alm[100];
    
    while (1) {
        pilihan = 0;
        printf("\n=== PORTAL RESEPSIONIS ===\n");
        printf("1. Registrasi Pasien Baru (Auto-Queue)\n");
        printf("2. Cari Detail Pasien (via NIK)\n");
        printf("3. Update Status Urgensi Antrean\n");
        printf("4. Logout\n");
        printf("Pilih: "); 
        scanf("%d", &pilihan);
        while(getchar()!='\n');

        switch (pilihan) {
            case 1:
                do {
do {
    n = 0;
    printf("NIK: "); 
    scanf("%lld", &n);
    while(getchar()!='\n');

    if (n == 0) {
        printf("NIK tidak valid!\n");
    }
} while(n == 0);
if(searchAVL(rootAVL, n) != NULL) {
    printf("[!] NIK sudah terdaftar di sistem!\n");
    break;
}
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
                simpanDatabase(); // Pastikan data terselamatkan sebelum keluar
                bersihkanQueue();
                bersihkanAVL(rootAVL);
                rootAVL = NULL; // Reset pointer untuk keamanan
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