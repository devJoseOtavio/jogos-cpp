#include <stdio.h>
#include <iostream>

using namespace std;
const int SECRET_NUMBER = 42;

int main() {
    cout << "***************************************" << endl;
    cout << "*  Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "***************************************" << endl;

    cout << "Escolha o seu nível de dificuldade" << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    char difficulty;
    cin >> difficulty;
    
    int trys;
    int trys_number;

    if (difficulty == 'F') {
        trys_number = 7;
    } else if (difficulty = 'M') {
        trys_number = 5;
    } else if (difficulty = 'D') {
        trys_number = 3;
    } else {
        cout << "Tecla invalida" << endl;
    }

    double point = 1000.0;
    bool win = false;
    
    for (trys = 1; trys <= trys_number; trys++) {
        int randomNumber;

        cout << "Tentativa " << trys << endl;
        cout << "qual o seu chute?";
        cin >> randomNumber;

        double lostPoints = abs(randomNumber - SECRET_NUMBER)/2.0;
        point = point - lostPoints;

        cout << "o valor do seu chute é" << randomNumber << endl;
        bool right = randomNumber == SECRET_NUMBER;
        bool bigger = randomNumber > SECRET_NUMBER;
        bool smaller = randomNumber < SECRET_NUMBER;

        if (right) {
            cout << "Você acertou o numero secreto em " << trys << " tentativas" << endl;
            win = true;
            break;
        }

        if (bigger) cout << "Chute foi maior" << endl;
        if (smaller) cout << "Chute foi menor" << endl;
    }

    cout << "Fim de jogo!" << endl;

    if (win == false) {
        cout << "Você excedeu o limite de tentativas e perdeu" << endl;
    } else {
        cout << "Você venceu!" << endl;
        cout.precision(2);
        cout.fixed;
        cout << "Sua pontuação foi de " << point << " pontos." << endl;
    }

    return 0;
}