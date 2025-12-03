// fungsi tampilan menu
void daftarBarang() {
    system("cls");
    printf("==========================================\n");
    printf("               DAFTAR MENU               \n");
    printf("==========================================\n");
    printf(" No | Nama Menu       | Harga     | Stok\n");
    printf("====|=================|===========|=======\n");
    printf(" 1. | Nasi Goreng     | Rp.%d  | %d\n", harga[0], stok[0]);
    printf("    |                 |           |          \n");
    printf(" 2. | Ayam Geprek     | Rp.%d  | %d\n", harga[1], stok[1]);
    printf("    |                 |           |          \n");
    printf(" 3. | Ifumie Goreng   | Rp.%d  | %d\n", harga[2], stok[2]);
    printf("    |                 |           |          \n");
    printf(" 4. | Es Teh Manis    | Rp.%d   | %d\n", harga[3], stok[3]);
    printf("    |                 |           |          \n");
    printf(" 5. | Kukubima Susu   | Rp.%d  | %d\n", harga[4], stok[4]);
    printf("    |                 |           |          \n");
    printf(" 6. | Air Mineral     | Rp.%d   | %d\n", harga[5], stok[5]);
    printf("==========================================\n");
}

// fungsi transaksi
void menuTransaksi() {
    // variabel keranjang belanja
    int k_id[50]; // menyimpan id barang
    int k_jlh[50]; // menyimpan jumlah beli
    int k_total[50]; // menyimpan total harga per item
    int jumlahItem = 0; // menghitung berapa item sudah di keranjang
    
    int totalBelanja = 0;
    int pilihan;
    int jumlah;
    int bayar;
    int kembalian;
    int tambahLagi; // beli lagi

    do {
        daftarBarang();
        printf(" Daftar di Keranjang: %d item\n", jumlahItem);
        printf("==========================================\n");
        printf(" 0. Kembali\n");
        printf("==========================================\n");
        printf(" [1/2/3/4/5/6/0]: ");
        scanf("%d", &pilihan);

        if (pilihan == 0) return; // balik ke halaman utama

        if (pilihan < 1 || pilihan > 6) {           
            printf(" Menu Tidak Ditemukan.\n");
            system("pause");
        } else {
            int i = pilihan - 1; // mengubah ke index array
            printf(" Jumlah Porsi: ");
            scanf("%d", &jumlah);

            // cek stok
            if (jumlah > stok[i]) {
                printf(" Stok Tidak Cukup! Sisa Stok: %d\n", stok[i]);
                system("pause");
            } else {
                // masukkan ke keranjang
                k_id[jumlahItem] = i;
                k_jlh[jumlahItem] = jumlah;
                k_total[jumlahItem] = jumlah * harga[i];
                
                totalBelanja = totalBelanja + k_total[jumlahItem];
                
                // kurangi stok sementara (biar kalau beli lagi stoknya update)
                stok[i] = stok[i] - jumlah; 
                
                jumlahItem++; // nambah jumlah item di keranjang
                system ("cls");
                printf("==========================================\n");
                printf(" Berhasil Masuk Ke Keranjang!\n");
            }
        }

        // nambah lagi
    do {
        printf("==========================================\n");
        printf(" Ingin Menambah Pembelian?\n");
        printf(" 1. Iya\n");
        printf(" 2. Tidak (Lanjut Pembayaran)\n");
        printf("==========================================\n");
        printf(" [1/2]: ");
        scanf("%d", &tambahLagi);

        if (tambahLagi != 1 && tambahLagi != 2) {
                printf(" Pilihan Tidak Valid. Coba Lagi.\n");
                system("pause");
                system("cls");
            }
    } while (tambahLagi != 1 && tambahLagi != 2);

    } while (tambahLagi == 1);

    // proses pembayaran
    if (jumlahItem > 0) {
        printf("==========================================\n");
        printf(" Total Belanja: Rp %d\n", totalBelanja);
        printf(" Masukkan Uang Tunai: ");
        scanf("%d", &bayar);
        printf("==========================================\n");

        if (bayar < totalBelanja) {
            printf(" Uang Kurang! Transaksi Dibatalkan.\n");

            // kembalikan stok karena batal
            for (int x = 0; x < jumlahItem; x++) {
                stok[k_id[x]] += k_jlh[x];
            }
            system("pause");
        } else {
            // transaksi berhasil
            kembalian = bayar - totalBelanja;
            totalPendapatan += totalBelanja;

            // update data laporan
            for (int x = 0; x < jumlahItem; x++) {
                int id = k_id[x];
                totalPembelian[id] += k_jlh[x];
                hargaSatuan[id] += k_total[x];
            }

            // Panggil Fungsi Cetak Struk Baru
            cetakStruk(k_id, k_jlh, k_total, jumlahItem, totalBelanja, bayar, kembalian);
        }
    }
}