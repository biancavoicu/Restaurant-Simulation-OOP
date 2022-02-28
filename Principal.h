//
// Created by Bianca on 16/03/2021.
//

#ifndef RESTAURANT_PRINCIPAL_H
#define RESTAURANT_PRINCIPAL_H

enum Garnitura {
    cartofi_prajiti, piure, orez_sarbesc
};

enum Fel {
    frigarui = 20, tocana = 20, chateaubriand_stroganoff = 26, chateaubriand_file = 25
};

class Principal {
    Garnitura tip_garnitura;
    Fel tip_principal;
public:
    Garnitura getTipGarnitura() const;

    void setTipGarnitura(Garnitura tip);

    Fel getTipPrincipal() const;

    void setTipPrincipal(Fel tipPrincipal);

    Principal(Garnitura tipGarnitura, Fel tipPrincipal);
};


#endif //RESTAURANT_PRINCIPAL_H
