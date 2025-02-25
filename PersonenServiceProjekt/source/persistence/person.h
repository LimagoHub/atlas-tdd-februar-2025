//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once


#include <string>
#include <ostream>

class person {
    std::string id;
    std::string vorname;
    std::string nachname;

public:
    person(const std::string &vorname="John", const std::string &nachname="Doe") : vorname(vorname), nachname(nachname) {}

    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &id) {
        person::id = id;
    }

    const std::string &getVorname() const {
        return vorname;
    }

    void setVorname(const std::string &vorname) {
        person::vorname = vorname;
    }

    const std::string &getNachname() const {
        return nachname;
    }

    void setNachname(const std::string &nachname) {
        person::nachname = nachname;
    }

    bool operator==(const person &rhs) const {
        return id == rhs.id &&
               vorname == rhs.vorname &&
               nachname == rhs.nachname;
    }

    bool operator!=(const person &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const person &person) {
        os << "id: " << person.id << " vorname: " << person.vorname << " nachname: " << person.nachname;
        return os;
    }
};
