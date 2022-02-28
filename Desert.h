//
// Created by Bianca on 16/03/2021.
//

#ifndef RESTAURANT_DESERT_H
#define RESTAURANT_DESERT_H

enum Dessert {
    inghetata3 = 6, inghetata4 = 8, inghetata5 = 10, tort_kranz = 10, nimic = 0
};

class Desert {
    Dessert tip_desert;
public:
    Dessert getTipDesert() const;

    void setTipDesert(Dessert tipDesert);

    Desert(Dessert tipDesert);

    friend Desert operator+(Desert obj, Desert obj2);

    friend Desert operator+=(Desert d, Desert dd);
};


#endif //RESTAURANT_DESERT_H
