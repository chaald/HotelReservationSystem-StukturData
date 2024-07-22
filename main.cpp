#include <iostream>
#include "reservasi_hotel.h"

using namespace std;

int main() {
    listUser LU;
    listHotel LH;

    createListUser(LU);
    createListHotel(LH);

    setHotel(LH);
    menu(LU, LH);

    return 0;
}
