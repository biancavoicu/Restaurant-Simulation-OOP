//
// Created by Bianca on 15/03/2021.
//

#ifndef RESTAURANT_MASA_H
#define RESTAURANT_MASA_H

#include <vector>
#include <ostream>
#include "Client.h"

using namespace std;

class Masa {
    int m_capacitate, m_ocupare, m_plata = 0, m_id;
    bool is_free;

public:

    Masa(const Masa &m1);

    Masa(int mCapacitate, int mOcupare, int mPlata, int mId, bool isFree);

    int getMCapacitate() const;

    void setMCapacitate(int capacitate);

    int getMOcupare() const;

    void setMOcupare(int ocupare);

    Masa(int capacitate, int ocupare);

    int getMPlata() const;

    void setMPlata(int plata);

    bool isFree() const;

    void setIsFree(bool isFree);

    int getMId() const;

    void setMId(int mId);

    Masa(int mCapacitate, int mId, bool isFree);

    void ClientPleaca(int nota_plata);

    friend ostream &operator<<(ostream &os, const Masa &masa);

    friend istream& operator>>(istream &input,Masa &obj);

    friend Masa operator>(Masa const obj, Masa const obj2);

};


#endif //RESTAURANT_MASA_H
