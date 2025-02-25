//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once

#include <optional>
#include <vector>
#include "person.h"
class personen_repository {

public:
    virtual void save_or_update(const person& person) const = 0;
    virtual std::optional<person> find_by_id(std::string id) const = 0;
    virtual std::vector<person> find_all() const = 0;
    virtual bool delete_by_id(std::string id) const = 0;
};
