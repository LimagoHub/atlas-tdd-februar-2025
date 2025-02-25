//
// Created by JoachimWagner on 25.02.2025.
//

#pragma once
#include "gmock/gmock.h"

#include "../source/services/BlackListService.h"

class MockBlackListService :public BlackListService{
public:
    MOCK_METHOD(bool, isBlacklisted, (const person &p), (const, override));
};
