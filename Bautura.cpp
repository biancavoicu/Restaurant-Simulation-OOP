//
// Created by Bianca on 16/03/2021.
//

#include "Bautura.h"

Bautura::Bautura(Drink tipBautura) {
    this->tip_bautura = tipBautura;
}

Drink Bautura::getTipBautura() const {
    return tip_bautura;
}

void Bautura::setTipBautura(Drink tipBautura) {
    tip_bautura = tipBautura;
}
