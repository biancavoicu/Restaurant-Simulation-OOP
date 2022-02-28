//
// Created by Bianca on 16/03/2021.
//

#include "Principal.h"

Garnitura Principal::getTipGarnitura() const {
    return tip_garnitura;
}

void Principal::setTipGarnitura(Garnitura tip) {
    Principal::tip_garnitura = tip;
}

Fel Principal::getTipPrincipal() const {
    return tip_principal;
}

void Principal::setTipPrincipal(Fel tipPrincipal) {
    tip_principal = tipPrincipal;
}

Principal::Principal(Garnitura tipGarnitura, Fel tipPrincipal) {
    this->tip_garnitura=tipGarnitura;
    this->tip_principal=tipPrincipal;
}
