#include <iostream>
#include"Masa.h"
#include"Ciorba.h"
#include"Client.h"
#include"Principal.h"
#include "Bautura.h"
#include "Desert.h"

using namespace std;

vector<Client> clienti;
int AutoIncrement::lastId = 0;
vector<Masa> mese;

void Generare_mese(vector<Masa> &mese, int nrMese) {
    for (int i = 0; i < nrMese; i++) {
        Masa m(8 + i % 15, 0, 0, i + 1, true);
        mese.push_back(m);
    }
}


void Generare_clienti(vector<Client> &clienti, int nr_pers, int id) {
    for (int i = 0; i < nr_pers; i++)
        clienti.push_back(Client(0, id));

}

void alegeMasa(vector<Masa> mese, int nrPersoane) {
    bool bec = false;
    for (int i = 0; i < mese.size(); i++) {
        if (mese[i].isFree() && mese[i].getMCapacitate() >= nrPersoane) {
            bec = true;
            mese[i].setMOcupare(nrPersoane);
            mese[i].setIsFree(false);
            cout << "Exista masa disponibila pentru grupul de " << nrPersoane << " persoane." << endl;
            Generare_clienti(clienti, nrPersoane, mese[i].getMId());
            break;
        }

        if (!bec) {
            cout << "Nu exista o masa libera suficient de mare pentru numarul de persoane." << endl;
        }
    }
}

void cheamaChelner(Client c, int &deplata, vector<Masa> mese) {
    int optiune, idmasa;
    cout << "Doriti nota dumneavoastra (optiunea 1) sau nota totala a mesei (optiunea 2)?" << endl;
    cin >> optiune;
    if (optiune == 1) {
        deplata = c.getMNota();
        cout << deplata << endl;
    } else if (optiune == 2) {
        idmasa = c.getIdMasa();
        for (int i = 0; i < mese.size(); i++)
            if (mese[i].getMId() == idmasa) {
                deplata = mese[i].getMPlata();
                cout << deplata << endl;
                break;
            }
    } else cout << "Optiune imposibila" << endl;
}

void ia_comanda(Masa &table) {
    int op;
    Bautura b(vin_alb);
    Ciorba c(burta, true, true);
    Principal f(orez_sarbesc, frigarui);
    Desert d(tort_kranz);

    for (int k = 0; k < clienti.size(); k++)

        // Luam comanda de la fiecare masa si actualizam nota de plata per client si per masa

        if (clienti[k].getIdMasa() == table.getMId()) {

            //Bauturile
            cout << "[Chelner] Buna ziua! Doriti ceva de baut?" << endl;
            op = rand() % 2;
            if (op == 1) {
                cout << "[Client] Da." << endl;
                cout << "[Chelner] Vin, bere sau apa?" << endl;
                int opb = rand() % 3;
                switch (opb) {
                    case 0: {
                        cout << "[Client] Vin." << endl;
                        cout << "[Chelner] Alb sau rosu?" << endl;
                        int opv = rand() % 2;
                        if (opv == 0) {
                            cout << "[Client] Alb." << endl;
                            cout << "[Chelner] La pahar sau la sticla?" << endl;
                            int opv2 = rand() % 2;
                            if (opv2 == 0) {
                                cout << "[Client] La pahar." << endl;
                                cout << "[Chelner] Cati mililitri? 100 sau 200?" << endl;
                                int opv3 = rand() % 2;
                                if (opv3 == 0) {
                                    cout << "[Client] 100." << endl;
                                    b.setTipBautura(vin_alb);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + p);
                                } else {
                                    cout << "[Client] 200." << endl;
                                    b.setTipBautura(vin_alb);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + 2 * p);
                                }
                            } else {
                                cout << "[Client] La sticla." << endl;
                                cout << "[Chelner] Bordeux din 1996 sau Castel Bolovanu 2004?" << endl;
                                int opv4 = rand() % 2;
                                if (opv4 == 0) {
                                    cout << "[Client] Bordeux din 1996." << endl;
                                    b.setTipBautura(sticla_bordeaux);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + p);
                                } else {
                                    cout << "[Client] Castel Bolovanu 2004." << endl;
                                    b.setTipBautura(sticla_castel);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + p);
                                }
                            }
                        } else {
                            cout << "[Client] Rosu." << endl;
                            int opv2 = rand() % 2;
                            if (opv2 == 0) {
                                cout << "[Chelner] Cati mililitri? 100 sau 200?" << endl;
                                int opv3 = rand() % 2;
                                if (opv3 == 0) {
                                    cout << "[Client] 100." << endl;
                                    b.setTipBautura(vin_rosu);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + p);
                                } else {
                                    cout << "[Client] 200." << endl;
                                    b.setTipBautura(vin_rosu);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + 2 * p);
                                }
                            } else {
                                cout << "[Client] Sticla." << endl;
                                cout << "[Chelner] Bordeux din 1996 sau Castel Bolovanu 2004" << endl;
                                int opv4 = rand() % 2;
                                if (opv4 == 0) {
                                    cout << "[Client] Bordeux din 1996." << endl;
                                    b.setTipBautura(sticla_bordeaux);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + p);
                                } else {
                                    cout << "[Client] Castel Bolovanu 2004." << endl;
                                    b.setTipBautura(sticla_castel);
                                    int p = b.getTipBautura();
                                    clienti[k].setMNota(clienti[k].getMNota() + p);
                                }
                            }
                        }
                    }
                        break;
                    case 1: {
                        cout << "[Client] Bere.";
                        cout << "[Chelner] Cu alcool sau fara?" << endl;
                        int opbb = rand() % 2;
                        if (opbb == 0) {
                            cout << "[Client] Cu alcool." << endl;
                            b.setTipBautura(bere);
                            int p = b.getTipBautura();
                            clienti[k].setMNota(clienti[k].getMNota() + p);
                        } else {
                            cout << "[Client] Fara alcool." << endl;
                            b.setTipBautura(bere_fara_alcool);
                            int p = b.getTipBautura();
                            clienti[k].setMNota(clienti[k].getMNota() + p);
                        }
                    }
                        break;
                    case 2: {
                        cout << "[Client] Apa." << endl;
                        b.setTipBautura(apa);
                        int p = b.getTipBautura();
                        clienti[k].setMNota(clienti[k].getMNota() + p);
                    }
                        break;
                }

            } else cout << "[Client] Nu." << endl;

            // Ciorba
            cout << "[Chelner] Doriti ciorba?" << endl;
            op = rand() % 2;
            if (op == 1) {
                cout << "[Client] Da." << endl;
                cout << "[Chelner] De care? De burta, de legume sau de ciuperci?" << endl;
                int opc = rand() % 3;
                switch (opc) {
                    case 0: {
                        cout << "[Client] De burta." << endl;
                        c.setTip(burta);
                        int p = c.getTip();
                        clienti[k].setMNota(clienti[k].getMNota() + p);
                        cout << "[Chelner] Cu sau fara ardei?" << endl;
                        int opa = rand() % 2;
                        if (opa == 1) {
                            cout << "[Client] Cu ardei." << endl;
                            c.setArdei(true);
                            clienti[k].setMNota(clienti[k].getMNota() + 2);
                        } else cout << "[Client] Fara ardei." << endl;
                        cout << "Cu sau fara smantana?" << endl;
                        int ops = rand() % 2;
                        if (ops == 1) {
                            cout << "[Client] Cu smantana." << endl;
                            c.setSmantana(true);
                            clienti[k].setMNota(clienti[k].getMNota() + 2);
                        } else cout << "[Client] Fara smantana." << endl;
                    }
                        break;
                    case 1: {
                        cout << "[Client] De legume." << endl;
                        c.setTip(legume);
                        int p = c.getTip();
                        clienti[k].setMNota(clienti[k].getMNota() + p);
                        cout << "[Chelner] Cu sau fara ardei?" << endl;
                        int opa = rand() % 2;
                        if (opa == 1) {
                            cout << "[Client] Cu ardei." << endl;
                            c.setArdei(true);
                            clienti[k].setMNota(clienti[k].getMNota() + 2);
                        } else cout << "[Client] Fara ardei." << endl;
                        cout << "[Chelner] Cu sau fara smantana?" << endl;
                        int ops = rand() % 2;
                        if (ops == 1) {
                            cout << "[Client] Cu smantana." << endl;
                            c.setSmantana(true);
                            clienti[k].setMNota(clienti[k].getMNota() + 2);
                        } else cout << "[Client] Fara smantana." << endl;
                    }
                        break;
                    case 2: {
                        cout << "[Client] De ciuperci." << endl;
                        c.setTip(ciuperci);
                        int p = c.getTip();
                        clienti[k].setMNota(clienti[k].getMNota() + p);
                    }
                        break;

                }
            } else cout << "[Client] Nu." << endl;

            // Felul principal
            cout << "[Chelner] Fel principal doriti?" << endl;
            op = rand() % 2;
            if (op == 1) {
                cout << "[Client] Da." << endl;
                cout << "[Chelner] Frigarui de pui, tocana de pui sau Chateaubriand?" << endl;
                int opf = rand() % 3;
                switch (opf) {
                    case 0: {
                        cout << "[Client] Frigarui de pui." << endl;
                        f.setTipPrincipal(frigarui);
                        int p = f.getTipPrincipal();
                        clienti[k].setMNota(clienti[k].getMNota() + p);

                        cout << "[Chelner] Ce garnitura doriti? Cartofi prajiti, piure sau orez sarbesc?" << endl;
                        int opg = rand() % 3;
                        switch (opg) {
                            case 0: {
                                cout << "[Client] Cartofi prajiti." << endl;
                                f.setTipGarnitura(cartofi_prajiti);
                                int g = f.getTipGarnitura();
                                clienti[k].setMNota(clienti[k].getMNota() + g);
                            }
                                break;
                            case 1: {
                                cout << "[Client] Piure." << endl;
                                f.setTipGarnitura(piure);
                                int g = f.getTipGarnitura();
                                clienti[k].setMNota(clienti[k].getMNota() + g);
                            }
                                break;
                            case 2: {
                                cout << "[Client] Orez sarbesc." << endl;
                                f.setTipGarnitura(orez_sarbesc);
                                int g = f.getTipGarnitura();
                                clienti[k].setMNota(clienti[k].getMNota() + g);
                            }
                                break;
                        }
                    }
                        break;
                    case 1: {
                        cout << "[Client] Tocana de pui." << endl;
                        f.setTipPrincipal(tocana);
                        int p = f.getTipPrincipal();
                        clienti[k].setMNota(clienti[k].getMNota() + p);

                        cout << "[Chelner] Ce garnitura doriti? Cartofi prajiti, piure sau orez sarbesc?" << endl;
                        int opg = rand() % 3;
                        switch (opg) {
                            case 0: {
                                cout << "[Client] Cartofi prajiti." << endl;
                                f.setTipGarnitura(cartofi_prajiti);
                                int g = f.getTipGarnitura();
                                clienti[k].setMNota(clienti[k].getMNota() + g);
                            }
                                break;
                            case 1: {
                                cout << "[Client] Piure." << endl;
                                f.setTipGarnitura(piure);
                                int g = f.getTipGarnitura();
                                clienti[k].setMNota(clienti[k].getMNota() + g);
                            }
                                break;
                            case 2: {
                                cout << "[Client] Orez sarbesc." << endl;
                                f.setTipGarnitura(orez_sarbesc);
                                int g = f.getTipGarnitura();
                                clienti[k].setMNota(clienti[k].getMNota() + g);
                            }
                                break;
                        }
                    }
                        break;
                    case 2: {
                        cout << "[Client] Chateaubriand." << endl;
                        cout << "[Chelner] Stroganoff sau file? " << endl;
                        int opch = rand() % 2;
                        if (opch == 0) {
                            cout << "[Client] Stroganoff." << endl;
                            f.setTipPrincipal(chateaubriand_stroganoff);
                            int p = f.getTipPrincipal();
                            clienti[k].setMNota(clienti[k].getMNota() + p);

                            cout << "[Chelner] Ce garnitura doriti? Cartofi prajiti, piure sau orez sarbesc?" << endl;
                            int opg = rand() % 3;
                            switch (opg) {
                                case 0: {
                                    cout << "[Client] Cartofi prajiti." << endl;
                                    f.setTipGarnitura(cartofi_prajiti);
                                    int g = f.getTipGarnitura();
                                    clienti[k].setMNota(clienti[k].getMNota() + g);
                                }
                                    break;
                                case 1: {
                                    cout << "[Client] Piure." << endl;
                                    f.setTipGarnitura(piure);
                                    int g = f.getTipGarnitura();
                                    clienti[k].setMNota(clienti[k].getMNota() + g);
                                }
                                    break;
                                case 2: {
                                    cout << "[Client] Orez sarbesc." << endl;
                                    f.setTipGarnitura(orez_sarbesc);
                                    int g = f.getTipGarnitura();
                                    clienti[k].setMNota(clienti[k].getMNota() + g);
                                }
                                    break;
                            }
                        } else {
                            cout << "[Client] File." << endl;
                            f.setTipPrincipal(chateaubriand_file);
                            int p = f.getTipPrincipal();
                            clienti[k].setMNota(clienti[k].getMNota() + p);

                            cout << "[Chelner] Ce garnitura doriti? Cartofi prajiti, piure sau orez sarbesc?" << endl;
                            int opg = rand() % 3;
                            switch (opg) {
                                case 0: {
                                    cout << "[Client] Cartofi prajiti." << endl;
                                    f.setTipGarnitura(cartofi_prajiti);
                                    int g = f.getTipGarnitura();
                                    clienti[k].setMNota(clienti[k].getMNota() + g);
                                }
                                    break;
                                case 1: {
                                    cout << "[Client] Piure." << endl;
                                    f.setTipGarnitura(piure);
                                    int g = f.getTipGarnitura();
                                    clienti[k].setMNota(clienti[k].getMNota() + g);
                                }
                                    break;
                                case 2: {
                                    cout << "[Client] Orez sarbesc." << endl;
                                    f.setTipGarnitura(orez_sarbesc);
                                    int g = f.getTipGarnitura();
                                    clienti[k].setMNota(clienti[k].getMNota() + g);
                                }
                                    break;
                            }

                        }

                    }
                        break;

                }
            }
            cout << "[Client] Nu." << endl;

            // Desertul
            cout << "[Chelner] Desert doriti?" << endl;
            op = rand() % 2;
            if (op == 1) {
                cout << "[Client] Da." << endl;
                cout << "[Chelner] Inghetata sau tort kranz?" << endl;
                int opd = rand() % 2;
                if (opd == 0) {
                    cout << "[Client] Inghetata." << endl;
                    cout << "[Chelner] Cu 3, 4 sau 5 cupe?" << endl;
                    int opi = rand() % 3;
                    switch (opi) {
                        case 0: {
                            cout << "[Client] Cu 3 cupe." << endl;
                            d.setTipDesert(inghetata3);
                            int p = d.getTipDesert();
                            clienti[k].setMNota(clienti[k].getMNota() + p);
                        }
                            break;
                        case 1: {
                            cout << "[Client] Cu 4 cupe." << endl;
                            d.setTipDesert(inghetata4);
                            int p = d.getTipDesert();
                            clienti[k].setMNota(clienti[k].getMNota() + p);
                        }
                            break;
                        case 2: {
                            cout << "[Client] Cu 5 cupe." << endl;
                            d.setTipDesert(inghetata5);
                            int p = d.getTipDesert();
                            clienti[k].setMNota(clienti[k].getMNota() + p);
                        }
                            break;
                    }

                } else {
                    cout << "[Client] Tort kranz." << endl;
                    d.setTipDesert(tort_kranz);
                    int p = d.getTipDesert();
                    clienti[k].setMNota(clienti[k].getMNota() + p);
                }
            } else cout << "[Client] Nu." << endl;

            // Calculam nota totala a mesei

            mese[table.getMId() - 1].setMPlata(table.getMPlata() + clienti[k].getMNota());
        }

}

///Metoda supraincarcata
void print(Masa a) {
    cout << a;
}

void print(Client c) {
    cout << c;
}


int main() {

    int nr_grupuri = 1 + rand() % 15;
    int nr_mese = 1 + rand() % 15;
    int i, j;


    Generare_mese(mese, nr_mese);

//    for (i = 0; i < mese.size(); i++) {
//        cout << mese[i].getMCapacitate() << " " << mese[i].getMId() << endl;
//    }

    for (i = 0; i < nr_grupuri; i++) {
        int nr_persoane = 1 + rand() % 10;
        alegeMasa(mese, nr_persoane); // in functia aceasta generez si clientii
    }

    for (i = 0; i < mese.size(); i++) {
        ia_comanda(mese[i]);
    }


    int plata = 0;
    int idc;
    bool bec = false;
    cout << "Alegeti id-ul clientului care doreste sa cheme chelnerul la masa." << endl;
    cin >> idc;
    for (i = 0; i < clienti.size(); i++) {
        if (idc == clienti[i].getMId()) {
            bec = true;
            cheamaChelner(clienti[i], plata, mese);
        }
    }
    if (!bec) cout << "Id-ul introdus nu corespunde niciunui client." << endl;

    bool bec2 = false;
    plata = 0;
    cout << "Alegeti id-ul clientului care doreste sa plece de la masa." << endl;
    cin >> idc;
    for (i = 0; i < clienti.size(); i++) {
        if (idc == clienti[i].getMId()) {
            bec2 = true;
            for (j = 0; j < mese.size(); j++)
                if (clienti[i].getIdMasa() == mese[j].getMId()) {
                    mese[j].ClientPleaca(clienti[i].getMNota());
                    cout << "Nota de plata a clientului este: " << clienti[i].getMNota() << endl;
                    cout << "Nota de plata a clientilor ramasi la masa este: " << mese[j].getMPlata() << endl;
                }

        }
    }
    if (!bec2) cout << "Id-ul introdus nu corespunde niciunui client." << endl;
    return 0;
}

