//
// Created by JoachimWagner on 24.02.2025.
//

#pragma once


class Stapel {
private:
    bool empty{true};

public:
    bool isEmpty() {
        return empty;
    }

    void push(int i) {
        empty = false;
    }
};
