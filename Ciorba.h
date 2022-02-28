//
// Created by Bianca on 16/03/2021.
//

#ifndef RESTAURANT_CIORBA_H
#define RESTAURANT_CIORBA_H

enum type {
    burta = 17, legume = 13, ciuperci = 15
};

class Ciorba {
    type tip;
    bool ardei, smantana;
public:
    bool isArdei() const;

    void setArdei(bool ardei);

    bool isSmantana() const;

    void setSmantana(bool smantana);

    type getTip() const;

    void setTip(type tip);

    Ciorba(type tip, bool ardei, bool smantana);

};


#endif //RESTAURANT_CIORBA_H
