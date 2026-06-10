# Medical Track : Sistem Manajemen Antrean dan Rekam Medis

Medical Track  adalah program berbasis CLI yang mensimulasikan sistem manajemen
antrean pasien dan rekam medis yang menggunakan konsep struktur data Stack, Queue, dan
AVL tree dalam bahasa C. Program ini dirancang untuk menyelesaikan masalah
pengelolaan antrean pasien yang tidak menerapkan tingkatan urgensi dengan menerapkan algoritma
selction sort dan juga merge sort untuk laporan real-time. 

Proyek ini dikembangkan sebagai bagian dari Ujian Akhir Semester Praktikum
Struktur Data dan Algoritma.

## Cara Menjalankan Program

### Prasyarat

- GCC versi 9.0 atau lebih baru
- Sistem operasi Linux / macOS / Windows (dengan MinGW)

### Kompilasi
- Kompilasi standar : 
gcc  fungsi.c main.c -o program_sementara  
- Jika compile pakai makefile : 
    * Jika OS Windows : 
        mingw32-make run
    * Jika OS Linux :
        make run

### Jalankan 

./program_sementara   <--- disarankan pakai ini saja karena di makefilenya kami tulis ini.


## Tampilan Menu Program

### Tampilan Menu Utama
=== MEDTRACK PRO ===
1. Masuk Sebagai Resepsionis
2. Masuk Sebagai Dokter
3. Keluar Aplikasi
Pilih Akses:

### Tampilan Menu Resepsionis
=== PORTAL RESEPSIONIS ===
1. Registrasi Pasien Baru (Auto-Queue)
2. Cari Detail Pasien (via NIK)
3. Update Status Urgensi Antrean
4. Logout
Pilih:

### Tampilan Menu Dokter
=== PORTAL DOKTER ===
1. Periksa Pasien Terdepan (Undo Stack)
2. Riwayat Aktivitas Log (Circular Log)
3. Cetak Seluruh Laporan Rekam Medis (Merge Sort)
4. Logout
Pilih: 

## Tim Pengembang

-------------------------------------------------------------------------------------------------------------------------
|         Nama         |                                   Kontribusi Utama                                             |
|----------------------|------------------------------------------------------------------------------------------------|
| M. Dzaky Syraj       | Implementasi AVL Tree, manajemen File I/O (Database), menu utama, dan dokumentasi README       |
| Hanif Maulana        | Implementasi Queue, modul updateStatusPasien, dan pengujian program                            |
| Muhammad Rayyan      | Implementasi fungsi stablePrioritySort, analisis kompleksitas algoritma antrean, dan laporan   |
| Putri Rahmatul Ulya  | Implementasi Stack (Undo Diagnosa), modul CircularLog, dan laporan                             |
| Keisya Zahira        | Implementasi fungsi kumpulData, Merge Sort untuk visualisasi laporan terpaginasi, dan laporan  |
-------------------------------------------------------------------------------------------------------------------------

## Lisensi

Proyek ini dibuat untuk keperluan akademik dalam rangka Ujian Akhir Semester
Praktikum Struktur Data dan Algoritma. Bebas digunakan sebagai referensi
pembelajaran dengan menyebutkan sumber.

username resepsionis : admin
password : 123

username dokter : dokter
password : dok123