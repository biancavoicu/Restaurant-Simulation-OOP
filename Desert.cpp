//
// Created by Bianca on 16/03/2021.
//

#include "Desert.h"

Dessert Desert::getTipDesert() const {
    return tip_desert;
}

void Desert::setTipDesert(Dessert tipDesert) {
    tip_desert = tipDesert;
}

Desert::Desert(Dessert tipDesert) {
    this->tip_desert = tipDesert;
}

Desert operator+(Desert obj, Desert obj2) {
    Desert res(nimic);
    res.tip_desert = static_cast<Dessert>(obj.tip_desert + obj2.tip_desert);
    return res;
}

Desert operator+=(Desert d, Desert dd) {
    d.tip_desert = static_cast<Dessert>(d.tip_desert + dd.tip_desert);
}
