void lihatLaporan() {
    int key;
    do {
        system("cls");
        printf("====================================\n");
        printf("          LAPORAN PENDAPATAN        \n");
        printf("====================================\n"); 
        printf(" Nasi Goreng   |  %d  | Rp.%d \n", totalPembelian[0], hargaSatuan[0]);
        printf(" Ayam Geprek   |  %d  | Rp.%d \n", totalPembelian[1], hargaSatuan[1]);
        printf(" Ifumie Goreng |  %d  | Rp.%d \n", totalPembelian[2], hargaSatuan[2]);
        printf(" Es Teh Manis  |  %d  | Rp.%d \n", totalPembelian[3], hargaSatuan[3]);
        printf(" Kukubima Susu |  %d  | Rp.%d \n", totalPembelian[4], hargaSatuan[4]);
        printf(" Air Mineral   |  %d  | Rp.%d \n", totalPembelian[5], hargaSatuan[5]);
        printf("====================================\n");
        printf(" TOTAL PENJUALAN: Rp. %d       \n", totalPendapatan);
        printf("====================================\n");
        printf(" Enter [0] Untuk KEMBALI: ");
        scanf("%d", &key);

    } while (key != 0);
}