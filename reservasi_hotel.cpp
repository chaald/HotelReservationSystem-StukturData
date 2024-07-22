#include "reservasi_hotel.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void menu(listUser &LU, listHotel &LH) {
    int pilihan1, pilihan2, i;
    string namaHotel, namaUser;
    bool found1, found2;
    adrUser U;
    adrHotel H;
    adrBooking B;
    infotypeUser user;
    infotypeHotel hotel;
    infotypeBooking booking;

    cout << "=================== MENU ===================" << endl;
    cout << "1. Booking hotel" << endl;
    cout << "2. Tambah data" << endl;
    cout << "3. Menampilkan data" << endl;
    cout << "4. Menghapus data" << endl;
    cout << "5. Mencari data" << endl;
    cout << "6. Keluar" << endl;
    cout << "Masukan Pilihan: ";
    cin >> pilihan1;
    cout << endl;

    while (pilihan1 != 6) {
        if (pilihan1 == 1) {
            found1 = false;
            cout << "#BOOKING" << endl;
            cout << "Masukkan nama booking: ";
            cin >> booking.namaBooking;
            U = firstUser(LU);

            if (U != NULL) {
                do {
                    if (infoUser(U).namaUser == booking.namaBooking) {
                        found1 = true;
                    } else {
                        U = nextUser(U);
                    }
                } while (U != firstUser(LU) && !found1);
            }

            if (found1 == false) {
                cout << "User tidak ditemukan, mohon untuk daftar terlebih dahulu" << endl;
                cout << endl;
            } else {
                found2 = false;
                i = 1;
                cout << "===================" << endl;
                cout << "Hotel yang tersedia: " << endl;
                H = firstHotel(LH);
                while (H != NULL) {
                    cout << i << ". " << infoHotel(H).namaHotel << endl;
                    H = nextHotel(H);
                    i = i + 1;
                }
                cout << "===================" << endl;
                cout << "Pilih 1 hotel diatas, masukkan nama hotel: ";
                cin >> booking.namaHotel;
                H = firstHotel(LH);
                while (H != NULL) {
                    if (infoHotel(H).namaHotel == booking.namaHotel) {
                        found2 = true;
                    }
                    H = nextHotel(H);
                }
                if (found2 == false) {
                    cout << "Hotel tidak ditemukan, tolong masukan nama hotel dengan benar." << endl;
                    cout << endl;
                } else {
                    cout << "Masukkan durasi booking dalam hari: ";
                    cin >> booking.durasiBooking;
                    cout << "Masukkan ID booking: ";
                    cin >> booking.idBooking;
                    booking.statusBooking = "Booking successful.";
                    B = createElemenBooking(booking);
                    insertLastBooking(LU, LH, U, B);
                    cout << "Booking berhasil ditambahkan" << endl;
                    cout << endl;
                }
            }
            cout << "=================== MENU ===================" << endl;
            cout << "1. Booking hotel" << endl;
            cout << "2. Tambah data" << endl;
            cout << "3. Menampilkan data" << endl;
            cout << "4. Menghapus data" << endl;
            cout << "5. Mencari data" << endl;
            cout << "6. Keluar" << endl;
            cout << "Masukan Pilihan: ";
            cin >> pilihan1;
            cout << endl;
        } else if (pilihan1 == 2) {
            cout << "=================== MENU TAMBAH DATA ===================" << endl;
            cout << "1. Tambah data user" << endl;
            cout << "2. Tambah data hotel" << endl;
            cout << "3. Kembali ke menu" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan2;
            cout << endl;
            while (pilihan2 != 3) {
                if (pilihan2 == 1) {
                    cout << "#TAMBAH USER" << endl;
                    cout << "Masukkan nama: ";
                    cin >> user.namaUser;
                    cout << "Masukkan jenis kelamin (L/P): ";
                    cin >> user.sexUser;
                    cout << "Masukkan ID: ";
                    cin >> user.idUser;
                    U = createElemenUser(user);
                    insertLastUser(LU, U);
                    cout << "Data baru user telah ditambahkan" << endl;
                    cout << endl;
                } else if (pilihan2 == 2) {
                    cout << "#TAMBAH HOTEL" << endl;
                    cout << "Masukkan nama hotel: ";
                    cin >> hotel.namaHotel;
                    cout << "Masukkan tarif hotel per hari: ";
                    cin >> hotel.tarifHotel;
                    cout << "Masukkan jumlah kamar hotel: ";
                    cin >> hotel.jumlahKamar;
                    cout << "Masukkan rating hotel: ";
                    cin >> hotel.ratingHotel;
                    H = createElemenHotel(hotel);
                    insertLastHotel(LH, H);
                    cout << "Data baru hotel telah ditambahkan" << endl;
                    cout << endl;
                }
                cout << "=================== MENU TAMBAH DATA ===================" << endl;
                cout << "1. Tambah data user" << endl;
                cout << "2. Tambah data hotel" << endl;
                cout << "3. Kembali ke menu" << endl;
                cout << "Masukkan pilihan: ";
                cin >> pilihan2;
                cout << endl;
            }
            if (pilihan2 == 3) {
                cout << "=================== MENU ===================" << endl;
                cout << "1. Booking hotel" << endl;
                cout << "2. Tambah data" << endl;
                cout << "3. Menampilkan data" << endl;
                cout << "4. Menghapus data" << endl;
                cout << "5. Mencari data" << endl;
                cout << "6. Keluar" << endl;
                cout << "Masukan Pilihan: ";
                cin >> pilihan1;
                cout << endl;
            }
        } else if (pilihan1 == 3) {
            cout << "=================== MENU MENAMPILKAN DATA ===================" << endl;
            cout << "1. Tampilkan data user" << endl;
            cout << "2. Tampilkan data hotel" << endl;
            cout << "3. Tampilkan data hotel okupansi Ascending" << endl;
            cout << "4. Tampilkan data hotel okupansi Descending" << endl;
            cout << "5. Tampilkan jumlah booking dari suatu user" << endl;
            cout << "6. Tampilkan semua booking" << endl;
            cout << "7. Tampilkan seluruh data User beserta Booking" << endl;
            cout << "8. Kembali ke menu" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan2;
            cout << endl;
            while (pilihan2 != 8) {
                if (pilihan2 == 1) {
                    showUserList(LU);
                } else if (pilihan2 == 2) {
                    showHotelList(LH);
                } else if (pilihan2 == 3) {
                    showHotelAscending(LH);
                } else if (pilihan2 == 4) {
                    showHotelDescending(LH);
                } else if (pilihan2 == 5) {
                    cout << "Masukkan nama user yang ingin diketahui jumlah booking: ";
                    cin >> namaUser;
                    countBooking(LU, namaUser);
                } else if (pilihan2 == 6) {
                    showAllBooking(LU);
                } else if (pilihan2 == 7) {
                    showAllData(LU, LH);
                }
                cout << "=================== MENU MENAMPILKAN DATA ===================" << endl;
                cout << "1. Tampilkan data user" << endl;
                cout << "2. Tampilkan data hotel" << endl;
                cout << "3. Tampilkan data hotel okupansi Ascending" << endl;
                cout << "4. Tampilkan data hotel okupansi Descending" << endl;
                cout << "5. Tampilkan jumlah booking dari suatu user" << endl;
                cout << "6. Tampilkan semua booking" << endl;
                cout << "7. Tampilkan seluruh data User beserta Booking" << endl;
                cout << "8. Kembali ke menu" << endl;
                cout << "Masukkan pilihan: ";
                cin >> pilihan2;
                cout << endl;
            }
            if (pilihan2 == 8) {
                cout << "=================== MENU ===================" << endl;
                cout << "1. Booking hotel" << endl;
                cout << "2. Tambah data" << endl;
                cout << "3. Menampilkan data" << endl;
                cout << "4. Menghapus data" << endl;
                cout << "5. Mencari data" << endl;
                cout << "6. Keluar" << endl;
                cout << "Masukan Pilihan: ";
                cin >> pilihan1;
                cout << endl;
            }
        } else if (pilihan1 == 4) {
                cout << "=================== MENU MENGHAPUS DATA ===================" << endl;
                cout << "1. Hapus user beserta data booking" << endl;
                cout << "2. Hapus data hotel beserta data booking yang terhubung" << endl;
                cout << "3. Kembali ke menu" << endl;
                cout << "Masukan Pilihan: ";
                cin >> pilihan2;
                cout << endl;
                while (pilihan2 != 3){
                    if (pilihan2 == 1){
                        cout << "Masukkan nama user yang akan dihapus bookingnya: ";
                        cin >> namaUser;
                        deleteUserRelasi(LU, namaUser);
                    } else if (pilihan2 == 2){
                        cout << "Masukan nama hotel yang akan dihapus: ";
                        cin >> namaHotel;
                        deleteHotel(LU, LH, namaHotel);
                    }
                    cout << "=================== MENU MENGHAPUS DATA ===================" << endl;
                    cout << "1. Hapus user beserta data booking" << endl;
                    cout << "2. Hapus data hotel beserta data booking yang terhubung" << endl;
                    cout << "3. Kembali ke menu" << endl;
                    cout << "Masukan Pilihan: ";
                    cin >> pilihan2;
                    cout << endl;
                }
                if (pilihan2 == 3){
                    cout << "=================== MENU ===================" << endl;
                    cout << "1. Booking hotel" << endl;
                    cout << "2. Tambah data" << endl;
                    cout << "3. Menampilkan data" << endl;
                    cout << "4. Menghapus data" << endl;
                    cout << "5. Mencari data" << endl;
                    cout << "6. Keluar" << endl;
                    cout << "Masukan Pilihan: ";
                    cin >> pilihan1;
                    cout << endl;
                }
        } else if (pilihan1 == 5) {
            cout << "=================== MENU MENCARI DATA ===================" << endl;
            cout << "1. Mencari data user"  << endl;
            cout << "2. Mencari data hotel" << endl;
            cout << "3. Mencari data booking" << endl;
            cout << "4. Mencari data berdasarkan ID Booking" << endl;
            cout << "5. Kembali ke menu" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan2;
            cout << endl;
            while (pilihan2 != 5) {
                if (pilihan2 == 1) {
                    cout << "Masukkan nama user: ";
                    cin >> user.namaUser;
                    U = seacrhUser(LU, user.namaUser);
                    if (U == NULL) {
                        cout << "User tidak ditemukan" << endl;
                        cout << endl;
                    } else {
                        cout << "Nama: " << infoUser(U).namaUser << endl;
                        cout << "Jenis Kelamin (L/P): " << infoUser(U).sexUser << endl;
                        cout << "ID :" << infoUser(U).idUser << endl;
                        cout << endl;
                    }
                } else if (pilihan2 == 2) {
                    cout << "Masukkan nama hotel: ";
                    cin >> hotel.namaHotel;
                    H = searchHotel(LH, hotel.namaHotel);
                    if (H == NULL) {
                        cout << "Hotel tidak ditemukan" << endl;
                        cout << endl;
                    } else {
                        cout << "Nama hotel: " << infoHotel(H).namaHotel << endl;
                        cout << "Tarif per hari: " << infoHotel(H).tarifHotel << endl;
                        cout << "Jumlah kamar: " << infoHotel(H).jumlahKamar << endl;
                        cout << "Okupansi: " << infoHotel(H).kamarTerpakai << endl;
                        cout << "Rating hotel: " << infoHotel(H).ratingHotel << endl;
                        cout << endl;
                    }
                } else if (pilihan2 == 3) {
                    cout << "Masukkan nama user: ";
                    cin >> user.namaUser;
                    cout << "Masukkan nama hotel: ";
                    cin >> hotel.namaHotel;
                    cout << endl;
                    searchBooking(LU, user.namaUser, hotel.namaHotel);
                } else if (pilihan2 == 4){
                    int idBook;
                    cout << "Masukan ID Booking: ";
                    cin >> idBook;
                    trackBookingNumber(LU, idBook);
                }
                cout << "=================== MENU MENCARI DATA ===================" << endl;
                cout << "1. Mencari data user"  << endl;
                cout << "2. Mencari data hotel" << endl;
                cout << "3. Mencari data booking" << endl;
                cout << "4. Mencari data berdasarkan ID Booking" << endl;
                cout << "5. Kembali ke menu" << endl;
                cout << "Masukkan pilihan: ";
                cin >> pilihan2;
                cout << endl;

            }
            if (pilihan2 == 5) {
                cout << "=================== MENU ===================" << endl;
                cout << "1. Booking hotel" << endl;
                cout << "2. Tambah data" << endl;
                cout << "3. Menampilkan data" << endl;
                cout << "4. Menghapus data" << endl;
                cout << "5. Mencari data" << endl;
                cout << "6. Keluar" << endl;
                cout << "Masukan Pilihan: ";
                cin >> pilihan1;
                cout << endl;
            }
        }
        if (pilihan1 == 6) {
            cout << "Thank You <3" << endl;
        }
    }
};

// ============================================================================ \\

void setHotel(listHotel &LH) {
    infotypeHotel hotel;
    adrHotel H;

    hotel.namaHotel = "A";
    hotel.tarifHotel = 150000;
    hotel.ratingHotel = 4.5;
    hotel.jumlahKamar = 50;
    H = createElemenHotel(hotel);
    insertLastHotel(LH, H);

    hotel.namaHotel = "B";
    hotel.tarifHotel = 400000;
    hotel.ratingHotel = 5;
    hotel.jumlahKamar = 70;
    H = createElemenHotel(hotel);
    insertLastHotel(LH, H);

    hotel.namaHotel = "C";
    hotel.tarifHotel = 70000;
    hotel.ratingHotel = 3.5;
    hotel.jumlahKamar = 50;
    H = createElemenHotel(hotel);
    insertLastHotel(LH, H);
};

// ============================================================================ \\

void createListUser(listUser &LU) {
    firstUser(LU) = NULL;
};

void createListHotel(listHotel &LH) {
    firstHotel(LH) = NULL;
};

// ============================================================================ \\

adrUser createElemenUser(infotypeUser user) {
    adrUser U;

    U = new elemenUser;
    infoUser(U).namaUser = user.namaUser;
    infoUser(U).sexUser = user.sexUser;
    infoUser(U).idUser = user.idUser;
    nextBooking(U) = NULL;
    nextUser(U) = NULL;
    prevUser(U) = NULL;
    return U;
};

adrHotel createElemenHotel(infotypeHotel hotel) {
    adrHotel H;

    H = new elemenHotel;
    infoHotel(H).namaHotel = hotel.namaHotel;
    infoHotel(H).tarifHotel = hotel.tarifHotel;
    infoHotel(H).jumlahKamar = hotel.jumlahKamar;
    infoHotel(H).kamarTerpakai = 0;
    infoHotel(H).ratingHotel = hotel.ratingHotel;
    nextHotel(H) = NULL;
    return H;
};

adrBooking createElemenBooking(infotypeBooking booking) {
    adrBooking B;

    B = new elemenBooking;
    infoBooking(B).namaBooking = booking.namaBooking;
    infoBooking(B).namaHotel = booking.namaHotel;
    infoBooking(B).durasiBooking = booking.durasiBooking;
    infoBooking(B).idBooking = booking.idBooking;
    infoBooking(B).statusBooking = booking.statusBooking;
    nextHotel(B) = NULL;
    nextBooking(B) = NULL;
    return B;
};

// ============================================================================ \\

void insertLastUser(listUser &LU, adrUser U) {
    adrUser P;

    if (firstUser(LU) == NULL) {
        firstUser(LU) = U;
        nextUser(U) = U;
        prevUser(U) = U;
    } else {
        P = firstUser(LU);
        nextUser(U) = P;
        nextUser(prevUser(P)) = U;
        prevUser(U) = prevUser(P);
        prevUser(P) = U;
    }
};

void insertLastHotel(listHotel &LH, adrHotel H) {
    adrHotel P;

    if (firstHotel(LH) == NULL) {
        firstHotel(LH) = H;
    } else {
        P = firstHotel(LH);
        while (nextHotel(P) != NULL) {
            P = nextHotel(P);
        }
        nextHotel(P) = H;
    }
};

void insertLastBooking(listUser &LU, listHotel &LH, adrUser U, adrBooking B){
    adrBooking P;
    adrHotel  Q;

    Q = firstHotel(LH);
    while (Q != NULL && infoHotel(Q).namaHotel != infoBooking(B).namaHotel) {
        Q = nextHotel(Q);
    }
    if (nextBooking(U) == NULL) {
        nextBooking(U) = B;
        nextHotel(B) = Q;
    } else {
        P = nextBooking(U);
        while (nextBooking(P) != NULL) {
            P = nextBooking(P);
        }
        nextBooking(P) = B;
        nextHotel(B) = Q;
    }
    infoHotel(Q).kamarTerpakai = infoHotel(Q).kamarTerpakai + 1;
};

// ============================================================================ \\

void deleteUserRelasi(listUser &LU, string namaUser) {
    adrUser Prec = NULL;
    adrUser U;

    U = seacrhUser(LU, namaUser);
    if (U != NULL){
        adrBooking B = nextBooking(U);
        adrBooking P = NULL;
        while (B != NULL){
            if (nextBooking(B) != NULL){
                P = B;
                B = nextBooking(B);
                nextBooking(U) = B;
                nextBooking(P) = NULL;
            } else {
                nextBooking(U) = NULL;
                B = NULL;
            }
        }
        Prec = prevUser(U);
        if (prevUser(U) == U && nextUser(U) == U){
            firstUser(LU) = NULL;
        } else if (U == firstUser(LU)){
            nextUser(Prec) = nextUser(U);
            prevUser(nextUser(U)) = Prec;
            firstUser(LU) = nextUser(U);
            prevUser(U) = NULL;
            nextUser(U) = NULL;
        } else {
            nextUser(Prec) = nextUser(U);
            prevUser(nextUser(U)) = Prec;
            prevUser(U) = NULL;
            nextUser(U) = NULL;
        }
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "User dengan nama " << namaUser << " tidak ditemukan." << endl;
    }
};

void deleteHotel(listUser &LU, listHotel &LH, string namaHotel){
    adrUser U;
    adrHotel H, PrevH;
    adrBooking B, Prev;
    bool found = false;

    U = firstUser(LU);

    do {
        B = nextBooking(U);
        Prev = NULL;
        while (B != NULL){
            if (infoBooking(B).namaHotel == namaHotel){
                if (Prev == NULL){
                    nextBooking(U) = nextBooking(B);
                    nextBooking(B) = NULL;
                } else {
                    nextBooking(Prev) = nextBooking(B);
                    nextBooking(B) = NULL;
                }
            }
            Prev = B;
            B = nextBooking(B);
        }
        U = nextUser(U);
    }while (U != firstUser(LU));

    H = firstHotel(LH);
    PrevH = NULL;
    while (H != NULL && !found){
        if (infoHotel(H).namaHotel == namaHotel){
            found = true;
        } else {
            PrevH = H;
            H = nextHotel(H);
        }
    }

    if (PrevH == NULL){
        firstHotel(LH) = nextHotel(H);
        nextHotel(H) = NULL;
    } else {
        nextHotel(PrevH) = nextHotel(H);
        nextHotel(H) = NULL;
    }

    cout << "Data Hotel berhasil dihapus." << endl;

}

// ============================================================================ \\

void showUserList(listUser LU) {
    adrUser P;

    if (firstUser(LU) == NULL) {
        cout << "List Kosong" << endl;
        cout << endl;
    } else {
        P = firstUser(LU);
        while (nextUser(P) != firstUser(LU)) {
            cout << "Nama: " << infoUser(P).namaUser << endl;
            cout << "Jenis Kelamin (L/P): " << infoUser(P).sexUser << endl;
            cout << "ID :" << infoUser(P).idUser << endl;
            cout << endl;
            P = nextUser(P);
        }
        cout << "Nama: " << infoUser(P).namaUser << endl;
        cout << "Jenis Kelamin (L/P): " << infoUser(P).sexUser << endl;
        cout << "ID :" << infoUser(P).idUser << endl;
        cout << endl;
    }
};

void showHotelList(listHotel LH) {
    adrHotel P;

    if (firstHotel(LH) == NULL) {
        cout << "List Kosong" << endl;
        cout << endl;
    } else {
        P = firstHotel(LH);
        while (P != NULL) {
            cout << "Nama hotel: " << infoHotel(P).namaHotel << endl;
            cout << "Tarif per hari: " << infoHotel(P).tarifHotel << endl;
            cout << "Jumlah kamar: " << infoHotel(P).jumlahKamar << endl;
            cout << "Okupansi: " << infoHotel(P).kamarTerpakai << endl;
            cout << "Rating hotel: " << infoHotel(P).ratingHotel << endl;
            cout << endl;
            P = nextHotel(P);
        }
    }
};

void showHotelAscending(listHotel LH) {
    adrHotel P, Q, R;
    infotypeHotel tempHotel;

    P = firstHotel(LH);
    while (P != NULL) {
        Q = nextHotel(P);
        while (Q != NULL) {
            if (infoHotel(Q).kamarTerpakai < infoHotel(P).kamarTerpakai) {
                tempHotel.namaHotel = infoHotel(Q).namaHotel;
                tempHotel.tarifHotel = infoHotel(Q).tarifHotel;
                tempHotel.jumlahKamar = infoHotel(Q).jumlahKamar;
                tempHotel.kamarTerpakai = infoHotel(Q).kamarTerpakai;
                tempHotel.ratingHotel = infoHotel(Q).ratingHotel;

                infoHotel(Q).namaHotel = infoHotel(P).namaHotel;
                infoHotel(Q).tarifHotel = infoHotel(P).tarifHotel;
                infoHotel(Q).jumlahKamar = infoHotel(P).jumlahKamar;
                infoHotel(Q).kamarTerpakai = infoHotel(P).kamarTerpakai;
                infoHotel(Q).ratingHotel = infoHotel(P).ratingHotel;

                infoHotel(P).namaHotel = tempHotel.namaHotel;
                infoHotel(P).tarifHotel = tempHotel.tarifHotel;
                infoHotel(P).jumlahKamar = tempHotel.jumlahKamar;
                infoHotel(P).kamarTerpakai = tempHotel.kamarTerpakai;
                infoHotel(P).ratingHotel = tempHotel.ratingHotel;
            }
            Q = nextHotel(Q);
        }
        P = nextHotel(P);
    }

    R = firstHotel(LH);
    while (R != NULL) {
        cout << "Nama hotel: " << infoHotel(R).namaHotel << endl;
        cout << "Tarif per hari: " << infoHotel(R).tarifHotel << endl;
        cout << "Jumlah kamar: " << infoHotel(R).jumlahKamar << endl;
        cout << "Okupansi: " << infoHotel(R).kamarTerpakai << endl;
        cout << "Rating hotel: " << infoHotel(R).ratingHotel << endl;
        cout << endl;
        R = nextHotel(R);
    }
};

void showHotelDescending(listHotel LH) {
    adrHotel P, Q, R;
    infotypeHotel tempHotel;

    P = firstHotel(LH);
    while (P != NULL) {
        Q = nextHotel(P);
        while (Q != NULL) {
            if (infoHotel(Q).kamarTerpakai > infoHotel(P).kamarTerpakai) {
                tempHotel.namaHotel = infoHotel(Q).namaHotel;
                tempHotel.tarifHotel = infoHotel(Q).tarifHotel;
                tempHotel.jumlahKamar = infoHotel(Q).jumlahKamar;
                tempHotel.kamarTerpakai = infoHotel(Q).kamarTerpakai;
                tempHotel.ratingHotel = infoHotel(Q).ratingHotel;

                infoHotel(Q).namaHotel = infoHotel(P).namaHotel;
                infoHotel(Q).tarifHotel = infoHotel(P).tarifHotel;
                infoHotel(Q).jumlahKamar = infoHotel(P).jumlahKamar;
                infoHotel(Q).kamarTerpakai = infoHotel(P).kamarTerpakai;
                infoHotel(Q).ratingHotel = infoHotel(P).ratingHotel;

                infoHotel(P).namaHotel = tempHotel.namaHotel;
                infoHotel(P).tarifHotel = tempHotel.tarifHotel;
                infoHotel(P).jumlahKamar = tempHotel.jumlahKamar;
                infoHotel(P).kamarTerpakai = tempHotel.kamarTerpakai;
                infoHotel(P).ratingHotel = tempHotel.ratingHotel;
            }
            Q = nextHotel(Q);
        }
        P = nextHotel(P);
    }

    R = firstHotel(LH);
    while (R != NULL) {
        cout << "Nama hotel: " << infoHotel(R).namaHotel << endl;
        cout << "Tarif per hari: " << infoHotel(R).tarifHotel << endl;
        cout << "Jumlah kamar: " << infoHotel(R).jumlahKamar << endl;
        cout << "Okupansi: " << infoHotel(R).kamarTerpakai << endl;
        cout << "Rating hotel: " << infoHotel(R).ratingHotel << endl;
        cout << endl;
        R = nextHotel(R);
    }
};

void showAllBooking(listUser LU) {
    adrUser P;
    adrBooking Q;

    if (firstUser(LU) == NULL) {
        cout << "List Kosong" << endl;
        cout << endl;
    } else {
        P = firstUser(LU);
        while (nextUser(P) != firstUser(LU)){
            Q = nextBooking(P);
            while (Q != NULL) {
                cout << "Nama booking: " << infoBooking(Q).namaBooking << endl;
                cout << "Nama hotel: " << infoBooking(Q).namaHotel << endl;
                cout << "Durasi: " << infoBooking(Q).durasiBooking << " hari" << endl;
                cout << "ID booking: " << infoBooking(Q).idBooking << endl;
                cout << "Status booking: " << infoBooking(Q).statusBooking << endl;
                cout << endl;
                Q = nextBooking(Q);
            }
            P = nextUser(P);
        }
        Q = nextBooking(P);
        while (Q != NULL) {
        cout << "Nama booking: " << infoBooking(Q).namaBooking << endl;
        cout << "Nama hotel: " << infoBooking(Q).namaHotel << endl;
        cout << "Durasi: " << infoBooking(Q).durasiBooking << " hari" << endl;
        cout << "ID booking: " << infoBooking(Q).idBooking << endl;
        cout << "Status booking: " << infoBooking(Q).statusBooking << endl;
        cout << endl;
        Q = nextBooking(Q);
        }
    }
};

void showAllData(listUser LU, listHotel LH){
    adrUser U = firstUser(LU);
    adrBooking B;
    adrHotel H;

    if (U != NULL){
        do{
            cout << "ID User: " << infoUser(U).idUser << endl;
            cout << "Nama: " << infoUser(U).namaUser << endl;
            cout << "Gender: " << infoUser(U).sexUser << endl;

            B = nextBooking(U);
            int i = 1;
            while (B != NULL){
                cout << i << "-Booking" << endl;
                cout << "ID Booking: " << infoBooking(B).idBooking << endl;

                H = searchHotel(LH, infoBooking(B).namaHotel);

                cout << "Nama Hotel: " << infoHotel(H).namaHotel << endl;
                cout << "Rating: " << infoHotel(H).ratingHotel << endl;

                B = nextBooking(B);
                i++;
            }

            cout << " " << endl;

            U = nextUser(U);
        }while (U != firstUser(LU));
    } else {
        cout << "List Kosong" << endl;
    }
}

// ============================================================================ \\

adrUser seacrhUser(listUser LU, string namaUser) {
    adrUser P;

    P = firstUser(LU);
    do {
        if (firstUser(LU) == NULL) {
            return NULL;
        } else {
            if (infoUser(P).namaUser == namaUser) {
                return P;
            }
        }
        P = nextUser(P);
    } while (P != firstUser(LU));
    return NULL;
};

adrHotel searchHotel(listHotel LH, string namaHotel) {
    adrHotel P;

    P = firstHotel(LH);
    if (P == NULL) {
        return NULL;
    } else {
        while (P != NULL) {
            if (infoHotel(P).namaHotel == namaHotel) {
                return P;
            }
            P = nextHotel(P);
        }
    }
    return NULL;
};

void searchBooking(listUser LU, string namaUser, string namaHotel) {
    adrUser P;
    adrBooking Q;

    P = seacrhUser(LU, namaUser);
    Q = nextBooking(P);
    while (Q != NULL) {
        if (infoBooking(Q).namaHotel == namaHotel) {
            cout << "Nama booking: " << infoBooking(Q).namaBooking << endl;
            cout << "Nama hotel: " << infoBooking(Q).namaHotel << endl;
            cout << "Durasi: " << infoBooking(Q).durasiBooking << " hari" << endl;
            cout << "ID booking: " << infoBooking(Q).idBooking << endl;
            cout << "Status: " << infoBooking(Q).statusBooking << endl;
            cout << endl;
        }
        Q = nextBooking(Q);
    }
};

// ============================================================================ \\

void countBooking(listUser LU, string namaUser) {
    adrUser P;
    adrBooking Q;
    int jumlahBooking = 0;

    P = seacrhUser(LU, namaUser);

    if (P == NULL) {
        cout << "User tidak ditemukan, pastikan user sudah terdaftar" << endl;
        cout << endl;
    } else {
        Q = nextBooking(P);
        while (Q != NULL) {
            jumlahBooking = jumlahBooking + 1;
            Q = nextBooking(Q);
        }
        cout << "User memiliki " << jumlahBooking << " booking" << endl;
        cout << endl;
    }
};

// ============================================================================ \\

void trackBookingNumber(listUser LU, int searchID) {
    adrUser P;
    adrBooking Q;
    int choice;
    bool found = false;

    P = firstUser(LU);
    do {
        Q = nextBooking(P);
        while (Q != NULL && searchID != infoBooking(Q).idBooking) {
            Q = nextBooking(Q);
        }

        if ( Q != NULL && searchID == infoBooking(Q).idBooking){
            found = true;
        } else {
            P = nextUser(P);
        }
    } while (P != firstUser(LU) && !found);

    if (!found){
        cout << "ID Booking tidak ditemukan." << endl;
    } else {
        cout << "Pilih yang ingin ditampilkan" << endl;
        cout << "1. Tampilkan data user" << endl;
        cout << "2. Tampilkan data booking" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Nama: " << infoUser(P).namaUser << endl;
            cout << "Jenis Kelamin: " << infoUser(P).sexUser << endl;
            cout << "ID: " << infoUser(P).idUser << endl;
        } else {
            cout << "ID Booking: " << infoBooking(Q).idBooking << endl;
            cout << "Nama Booking: " << infoBooking(Q).namaBooking << endl;
            cout << "Nama Hotel: " << infoBooking(Q).namaHotel << endl;
            cout << "Durasi Booking: " << infoBooking(Q).durasiBooking << endl;
        }
    }
};
