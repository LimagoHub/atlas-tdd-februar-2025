//
// Created by JoachimWagner on 21.02.2024.
//

#pragma once
#include "../persistence/personen_repository.h"
#include "personen_service.h"


#include "personen_service_exception.h"

class personen_service_impl :public personen_service{


public:


    personen_service_impl(personen_repository &repo) :
        repo(repo) {}

    /*
 *	Vorname < 2 -> PSE
 *	Nachname < 2 -> PSE
 *
 *	Attila -> PSE
 *
 *	Alle technische Exceptions -> PSE
 *
 *	Happy Day -> person an Save_or_update Methode uebergeben
 *
 */
    void speichern(person &person_)   override{


    }

    void speichern(std::string vorname, std::string nachname) override {

    }


private:

    personen_repository &repo;



};
