#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mengambil variabel yang dibutuhkan untuk mencetak struk
void cetakStruk(int k_id[], int k_jlh[], int k_total[], int jumlahItem, int totalBelanja, int bayar, int kembali) {
    system("cls");
    FILE *file = fopen("struk.txt", "w");

    if (file != NULL) {
        fprintf(file, "============================================\n");
        fprintf(file, "              STRUK PEMBELIAN              \n");
        fprintf(file, "                WARKOP CKCK                \n");
        fprintf(file, "============================================\n");
        fprintf(file, "%-15s %-5s %-10s %-10s\n", "Menu", "Qty", "Harga", "Subtotal");
        fprintf(file, "--------------------------------------------\n");

        for(int x = 0; x < jumlahItem; x++) {
            int id = k_id[x];
            char *namaBarang;
            if (id == 0) namaBarang = "Nasi Goreng";
            else if (id == 1) namaBarang = "Ayam Geprek";
            else if (id == 2) namaBarang = "Ifumie Goreng";
            else if (id == 3) namaBarang = "Es Teh Manis";
            else if (id == 4) namaBarang = "Kukubima Susu";
            else namaBarang = "Air Mineral";
            fprintf(file, "%-15s %-5d Rp.%-7d Rp.%-9d\n", namaBarang, k_jlh[x], harga[id], k_total[x]);
        }
        
        fprintf(file, "--------------------------------------------\n");
        fprintf(file, "TOTAL     : Rp. %-10d\n", totalBelanja);
        fprintf(file, "BAYAR     : Rp. %-10d\n", bayar);
        fprintf(file, "KEMBALI   : Rp. %-10d\n", kembali);
        fprintf(file, "============================================\n");
        fprintf(file, "      Terima Kasih Telah Berkunjung ke      \n");
        fprintf(file, "                WARKOP CKCK                 \n");
        fprintf(file, "============================================\n");
        fclose(file);

        printf(">>> Struk berhasil dicetak di struk.txt <<<\n");
    } else {
        printf("Error: Gagal membuat file struk.\n");
    }
    system("pause");
}