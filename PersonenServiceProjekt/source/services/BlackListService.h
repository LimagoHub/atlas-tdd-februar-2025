//
// Created by JoachimWagner on 25.02.2025.
//

#pragma once
#include "../persistence/person.h"

class BlackListService {
public:
    BlackListService() = default;
    virtual ~BlackListService() = default;

    virtual bool isBlacklisted(const person &possibleBlacklistedPerson) const = 0;
};
