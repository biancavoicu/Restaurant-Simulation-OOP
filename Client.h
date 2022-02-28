//
// Created by Bianca on 17/03/2021.
//

#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H

#include "Masa.h"
#include <vector>
#include <ostream>
#include "AutoIncrement.h"
using namespace std;

class Client {
private:
    int m_Id, m_nota = 0, id_masa;

public:
    int getIdMasa() const;

    void setIdMasa(int idMasa);

    int getMId() const;

    void setMId();

    int getMNota() const;

    Client(int mNota, int idMasa);

    void setMNota(int mNota);

    friend ostream &operator<<(ostream &os, const Client &client);
};


#endif //RESTAURANT_CLIENT_H
