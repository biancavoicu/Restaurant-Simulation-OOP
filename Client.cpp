//
// Created by Bianca on 17/03/2021.
//

#include "Client.h"
#include "AutoIncrement.h"

using namespace std;

int Client::getMId() const {
    return m_Id;
}

void Client::setMId() {
    AutoIncrement ai;
    m_Id = ai.getMId();
}

int Client::getMNota() const {
    return m_nota;
}

void Client::setMNota(int mNota) {
    m_nota = mNota;
}

int Client::getIdMasa() const {
    return id_masa;
}

void Client::setIdMasa(int idMasa) {
    id_masa = idMasa;
}

Client::Client(int mNota, int idMasa) {
    AutoIncrement ai;
    m_Id = ai.getMId();
    m_nota = mNota;
    id_masa = idMasa;
}

ostream &operator<<(ostream &os, const Client &client) {
    os << "Id: " << client.m_Id << " nota: " << client.m_nota << " id_masa: " << client.id_masa;
    return os;
}
