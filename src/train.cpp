// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    // Создаем новый вагон
    Cage *newCage = new Cage;
    newCage->light = light;
    newCage->next = newCage;
    newCage->prev = newCage;

    // Если поезд пустой, новый вагон становится первым
    if (!first) {
        first = newCage;
        return;
    }

    // Добавляем новый вагон в конец поезда
    newCage->next = first;
    newCage->prev = first->prev;
    first->prev->next = newCage;
    first->prev = newCage;
}

int Train::getLength() {
    if (!first) {
        return 0;
    }

    Cage *current = first;
    int length = 1;
    while (current->next != first) {
        current = current->next;
        length++;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}

ostream& operator<<(ostream& os, const Train& train) {
    if (!train.first) {
        os << "Поезд пустой";
        return os;
    }

    Cage *current = train.first;
    os << "Поезд:n";
    do {
        os << (current->light ? "свет включен" : "свет выключен") << "n";
        current = current->next;
    } while (current != train.first);

    return os;
}
