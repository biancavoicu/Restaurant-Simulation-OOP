//
// Created by Bianca on 17/03/2021.
//

#include "AutoIncrement.h"

int AutoIncrement::getMId() const {
    return m_id;
}

ostream &operator<<(ostream &os, const AutoIncrement &increment) {
    os << "m_id: " << increment.m_id;
    return os;
}

AutoIncrement::AutoIncrement() {
    lastId++;
    m_id = lastId;
}

AutoIncrement::AutoIncrement(int id) {
    if (id > lastId) {
        m_id = id;
        lastId = id;
    } else {
        lastId++;
        m_id = lastId;
    }

}