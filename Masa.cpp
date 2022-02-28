//
// Created by Bianca on 15/03/2021.
//

#include "Masa.h"

using namespace std;

int Masa::getMCapacitate() const {
    return m_capacitate;
}

void Masa::setMCapacitate(int capacitate) {
    Masa::m_capacitate = capacitate;
}

int Masa::getMOcupare() const {
    return m_ocupare;
}

void Masa::setMOcupare(int ocupare) {
    Masa::m_ocupare = ocupare;
}

Masa::Masa(int capacitate, int ocupare) {
    this->m_capacitate = capacitate;
    this->m_ocupare = ocupare;
}

int Masa::getMPlata() const {
    return m_plata;
}

void Masa::setMPlata(int plata) {
    Masa::m_plata = plata;
}

bool Masa::isFree() const {
    return is_free;
}

void Masa::setIsFree(bool isFree) {
    is_free = isFree;
}

Masa::Masa(int mCapacitate, int mId, bool isFree) {
    this->m_capacitate = mCapacitate;
    this->m_id = mId;
    this->is_free = isFree;
}

int Masa::getMId() const {
    return m_id;
}

void Masa::setMId(int mId) {
    m_id = mId;
}

/// Constructor de copiere

Masa::Masa(const Masa &m1) {
    m_plata = m1.m_plata;
    m_ocupare = m1.m_ocupare;
    m_id = m1.m_id;
    m_capacitate = m1.m_capacitate;
    is_free = m1.is_free;
}

void Masa::ClientPleaca(int nota_plata) {
    this->setMOcupare(m_ocupare - 1);
    if (m_ocupare == 0) setIsFree(true);
    this->setMPlata(m_plata - nota_plata);
}

Masa::Masa(int mCapacitate, int mOcupare, int mPlata, int mId, bool isFree) {
    m_capacitate = mCapacitate;
    m_ocupare = mOcupare;
    m_plata = mPlata;
    m_id = mId;
    is_free = isFree;
}

ostream &operator<<(ostream &os, const Masa &masa) {
    os << "capacitate: " << masa.m_capacitate << " ocupare: " << masa.m_ocupare << " plata: " << masa.m_plata
       << " id: " << masa.m_id << " is_free: " << masa.is_free;
    return os;
}

Masa operator>(Masa const obj, Masa const obj2) {
    if (obj.m_capacitate > obj2.m_capacitate)
        return obj;
}

istream &operator>>(istream &input, Masa &obj) {
    input >> obj.m_capacitate >> obj.m_ocupare >> obj.m_plata;
    return input;
}




