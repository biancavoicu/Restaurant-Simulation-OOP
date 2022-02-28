//
// Created by Bianca on 17/03/2021.
//

#ifndef RESTAURANT_AUTOINCREMENT_H
#define RESTAURANT_AUTOINCREMENT_H

#include <iostream>

using namespace std;

class AutoIncrement {
private:
    int m_id;
public:
    static int lastId;

    AutoIncrement();

    AutoIncrement(int id);

    int getMId() const;

    friend ostream &operator<<(ostream &os, const AutoIncrement &increment);

};



#endif //RESTAURANT_AUTOINCREMENT_H
