#ifndef RESERVASI_HOTEL_INCLUDED
#define RESERVASI_HOTEL_INCLUDED

#include <iostream>

using namespace std;

// KELOMPOK 11 -  RESERVASI HOTEL :
// Devana Hadnaru Ramadwipa (1305220044)
// Chacha Alisha Dewintasari (1305220036)

// Parent CDLL : User
// Child SLL : Hotel, Booking(relasi)

#define infoUser(P) (P)->infoUser
#define infoHotel(P) (P)->infoHotel
#define infoBooking(P) (P)->infoBooking
#define nextUser(P) (P)->nextUser
#define nextHotel(P) (P)->nextHotel
#define nextBooking(P) (P)->nextBooking
#define firstUser(L) ((L).firstUser)
#define firstHotel(L) ((L).firstHotel)
#define prevUser(P) (P)->prevUser

typedef struct elemenUser *adrUser;
typedef struct elemenHotel *adrHotel;
typedef struct elemenBooking *adrBooking;

struct infotypeUser {
    string namaUser, sexUser;
    int idUser;
};

struct infotypeHotel {
    string namaHotel;
    int tarifHotel, jumlahKamar, kamarTerpakai;
    float ratingHotel;
};

struct infotypeBooking {
    string namaBooking, namaHotel, statusBooking;
    int idBooking, durasiBooking;
};

struct elemenUser {
    infotypeUser infoUser;
    adrBooking nextBooking;
    adrUser nextUser;
    adrUser prevUser;
};

struct elemenHotel {
    infotypeHotel infoHotel;
    adrHotel nextHotel;
};

struct elemenBooking {
    infotypeBooking infoBooking;
    adrHotel nextHotel;
    adrBooking nextBooking;
};

struct listUser {
    adrUser firstUser;
};

struct listHotel {
    adrHotel firstHotel;
};

void menu(listUser &LU, listHotel &LH);

void setHotel(listHotel &LH);

void createListUser(listUser &LU);
void createListHotel(listHotel &LH);

adrUser createElemenUser(infotypeUser user);
adrHotel createElemenHotel(infotypeHotel hotel);
adrBooking createElemenBooking(infotypeBooking booking);

void insertLastUser(listUser &LU, adrUser U);
void insertLastHotel(listHotel &LH, adrHotel H);
void insertLastBooking(listUser &LU, listHotel  &LH, adrUser U, adrBooking B);

void deleteUserRelasi(listUser &LU, string namaUser);
void deleteHotel(listUser &LU, listHotel &LH, string namaHotel);

void showUserList(listUser LU);
void showHotelList(listHotel LH);
void showHotelAscending(listHotel LH);
void showHotelDescending(listHotel LH);
void showAllBooking(listUser LU);
void showAllData(listUser LU, listHotel LH);

adrUser seacrhUser(listUser LU, string namaUser);
adrHotel searchHotel(listHotel LH, string namaHotel);
void searchBooking(listUser LU, string namaUser, string namaHotel);
void trackBookingNumber(listUser LU, int searchID);

void countBooking(listUser LU, string namaUser);

#endif // RESERVASI_HOTEL_INCLUDED
