//
// Created by JoachimWagner on 21.02.2024.
//

#pragma once
#include "../persistence/personen_repository.h"
#include "personen_service.h"
#include "personen_service_exception.h"

class personen_service_impl :public personen_service{


public:


    personen_service_impl(personen_repository &repo) :repo(repo) {}

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
        try {
            if (person_.getVorname().length() < 2)
                throw personen_service_exception{"Vorname zu kurz!"};
            if (person_.getNachname().length() < 2)
                throw personen_service_exception{"Nachname zu kurz!"};
            if (person_.getVorname() == "Attila")
                throw personen_service_exception{"Antipath"};

            repo.save_or_update(person_);
        } catch (const personen_service_exception &ex) {
            throw ex;
        }
        catch (const std::exception &ex) {
            throw personen_service_exception("Datenbank nicht erreichbar");
        }
    }




private:

    personen_repository &repo;



};
