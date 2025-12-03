#include <stdio.h>
#include <stdlib.h>
#define pass 123

// file header
#include "data.h" // variabel global
#include "fitur_struk.h" // struk
#include "fitur_transaksi.h" // transaksi
#include "fitur_stok.h" // stok
#include "fitur_laporan.h" // laporan

// fitur level
void menuAdmin() {
    int menu;
    do {
        system("cls");
        printf("==========================================\n");
        printf("|             HALAMAN ADMIN              |\n");
        printf("==========================================\n");
        printf("|1. Laporan Penjualan                    |\n");
        printf("|2. Tambah Stok Barang                   |\n");
        printf("|3. Keluar (Logout)                      |\n");
        printf("==========================================\n");
        printf("[1/2/3]: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: 
                lihatLaporan(); // pindah ke fitur_laporan.h
                break;
            case 2: 
                tambahStok(); // pindah ke fitur_stok.h
                break;
            case 3: 
                printf("Logout berhasil.\n");
                system("pause");
                break;
            default: 
                printf("Pilihan Tidak Valid. Coba lagi.\n");
                system("pause"); // berfungsi sebagai jeda
        }
    } while (menu != 3);
}

void menuPegawai() {
    int menu;
    do {
        system("cls");
        printf("==========================================\n");
        printf("|            HALAMAN PEGAWAI             |\n");
        printf("==========================================\n");
        printf("|1. Transaksi                            |\n");
        printf("|2. Keluar (Logout)                      |\n");
        printf("==========================================\n");
        printf("[1/2]: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: 
                menuTransaksi(); // pindah ke fitur_transaksi.h
                break;
            case 2: 
                printf("Logout berhasil.\n");
                system("pause");
                break;
            default: 
                printf("Pilihan Tidak Valid. Coba lagi.\n");
                system("pause");
        }
    } while (menu != 2);
}

int main() {
    int level;
    int pw;
    
    do {
        system("cls");
        printf("==========================================\n");
        printf("|              WARKOP CKCK               |\n");
        printf("==========================================\n");
        printf("|Login Sebagai:                          |\n");
        printf("|1. Admin                                |\n");
        printf("|2. Pegawai                              |\n");
        printf("|3. Tutup Program                        |\n");
        printf("==========================================\n");
        printf("[1/2/3]: ");
        scanf("%d", &level);

        if (level == 1) {
            // password
            printf("Masukkan Password Anda: ");
            scanf("%d", &pw);
            
            if (pw == pass) {
                printf("Login Berhasil!\n");
                system("pause");
                menuAdmin();
            } else {
                printf("Password Salah! Akses Ditolak.\n");
                system("pause");
            }
        } else if (level == 2) {
            menuPegawai();
        } else if (level == 3) {
            system("cls");
            printf("================================================\n");
            printf("|\t\tPROGRAM SELESAI\t\t       |\n");
            printf("| Terima Kasih Telah Berkunjung ke WARKOP CKCK |\n");
            printf("================================================\n");
        } else {
            printf("Pilihan tidak valid. Coba Lagi.\n");
            system("pause");
        }
    } while (level != 3);

    return 0;
}