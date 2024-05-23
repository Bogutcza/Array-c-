#include <iostream>
#include <fstream>
#include <limits>
#include "array.h"

#define SIZE 10

using namespace std;

void displayArray(int array[]) {
    for (int i = 0; i < SIZE; ++i) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
}

int saveArrayToFile(int array[]) {
    ofstream outFile("plik.txt");
    if (!outFile) {
        cerr << "Błąd przy otwieraniu pliku do zapisu." << endl;
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        outFile << "array[" << i << "] = " << array[i] << endl;
    }
    outFile.close();
    return 0;
}

int restoreArrayFromFile(int array[]) {
    ifstream inFile("plik.txt");
    if (!inFile) {
        cerr << "Błąd przy otwieraniu pliku do odczytu." << endl;
        return 1;
    }
    string dummy;
    char ignoreChar;
    int index, value;
    for (int i = 0; i < SIZE; ++i) {
        inFile >> dummy >> ignoreChar >> index >> ignoreChar >> ignoreChar >> value;
        if (inFile.fail() || index != i) {
            cerr << "Błąd przy odczycie danych z pliku." << endl;
            inFile.close();
            return 2;
        }
        array[i] = value;
    }
    inFile.close();
    return 0;
}

void enterDataIntoArray(int array[]) {
    cout << "Wprowadź dane do tablicy" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "array[" << i << "] = ";
        while (!(cin >> array[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // odrzucenie błędnego wejścia
            cout << "Nieprawidłowe dane. Proszę wprowadzić liczbę całkowitą: ";
        }
    }
}

int FindMaximumValue(int array[]) {
    int max = array[0];
    for (int i = 1; i < SIZE; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int FindMinimumValue(int array[]) {
    int min = array[0];
    for (int i = 1; i < SIZE; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

float CalculateAverage(int array[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += array[i];
    }
    return static_cast<float>(sum) / SIZE;
}
