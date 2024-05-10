// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    // Создаем поезд
    Train train;

    // Добавляем вагоны
    train.addCage(true);
    train.addCage(false);
    train.addCage(true);
    train.addCage(false);

    // Выводим информацию о поезде
    cout << train << endl;

    // Вычисляем длину поезда
    cout << "Длина поезда: " << train.getLength() << endl;

    // Вычисляем число переходов
    cout << "Число переходов: " << train.getOpCount() << endl;

    return 0;
}
