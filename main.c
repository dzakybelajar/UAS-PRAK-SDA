#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    // Membaca database eksternal saat aplikasi dijalankan
    loadDatabase(); 
    menuUtama();
    return 0;
} 