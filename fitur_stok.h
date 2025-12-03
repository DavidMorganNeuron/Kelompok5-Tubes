void tambahStok() {
    int pilihan, tambahan;
    
    do {
        daftarBarang();
        printf("               UPDATE STOK               \n");
        printf("==========================================\n");
        printf("[1/2/3/4/5/6] Atau [0] Untuk KEMBALI: ");
        scanf("%d", &pilihan);
        
        if (pilihan == 0) {
            return; // kembali ke menu admin
        }

        if (pilihan < 1 || pilihan > 6) {
            printf("Menu tidak valid!\n");
            system("pause");
        } else {
            printf("Masukkan Jumlah Penambahan Stok: ");
            scanf("%d", &tambahan);
            
            stok[pilihan - 1] += tambahan;
            
            system("cls");
            printf("Stok Berhasil Ditambah! Stok Sekarang: %d\n", stok[pilihan - 1]);
            system("pause");
        }
    } while (pilihan != 0);
}