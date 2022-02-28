//
// Created by Bianca on 16/03/2021.
//

#ifndef RESTAURANT_BAUTURA_H
#define RESTAURANT_BAUTURA_H

enum Drink {
    vin_rosu = 10, vin_alb = 10, sticla_bordeaux = 80, sticla_castel = 60, bere = 8, bere_fara_alcool = 8, apa = 5
};

class Bautura {
    Drink tip_bautura;
public:
    Drink getTipBautura() const;

    void setTipBautura(Drink tipBautura);

    Bautura(Drink tipBautura);
};


#endif //RESTAURANT_BAUTURA_H
