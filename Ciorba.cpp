//
// Created by Bianca on 16/03/2021.
//

#include "Ciorba.h"

bool Ciorba::isArdei() const {
    return ardei;
}

void Ciorba::setArdei(bool ardei) {
    Ciorba::ardei = ardei;
}

bool Ciorba::isSmantana() const {
    return smantana;
}

void Ciorba::setSmantana(bool smantana) {
    Ciorba::smantana = smantana;
}

type Ciorba::getTip() const {
    return tip;
}

void Ciorba::setTip(type tip) {
    Ciorba::tip = tip;
}

Ciorba::Ciorba(type tip, bool ardei, bool smantana) {
    this->tip = tip;
    this->ardei = ardei;
    this->smantana = smantana;
}

