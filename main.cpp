#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Search { // создадим класс для поиска расстояния между словами

private:
        string str, oneWord, twoWord;
        int position;
        int getWayBetweenWord();
public:
        Search();
        ~Search();
};

Search::Search() { // конструктор, используется для ввода данных в поля класса
        cout << "Введите строку: ";
        getline(cin, str);
        cout << "Введите первое слово: ";
        cin >> oneWord;
        cout << "Введите второе слово: ";
        cin >> twoWord;
        int count = getWayBetweenWord();
        if (count)
                cout << "Кол-во слов: " << count;
        else
                cout << "Нет слов между словами" << endl;
}
int Search::getWayBetweenWord() { // метод для поиска минимального расстояния между словами
        int positionOneWord = str.find(oneWord) + 1; // по первому вхождению в строку
        int positionTwoWord = str.find(twoWord) - 1; // по первому вхождению в строку

        //cout << positionOneWord << " " << oneWord << endl;
        //cout <<positionTwoWord << " " << twoWord << endl;

        if(positionOneWord < 0 || positionTwoWord < 0)
                return 0;

        if (positionOneWord > positionTwoWord){
                int temp = positionTwoWord;
                positionTwoWord = positionOneWord - 1;
                positionOneWord = temp + 1;
        }

        //cout << positionOneWord << " " << oneWord << endl;
        //cout <<positionTwoWord << " " << twoWord << endl;

        int i = positionOneWord, countWord = 0;

        //cout << i << endl;

        while (i < positionTwoWord) {
                //cout << i << endl;
                if (str[i] == ' ')
                        countWord++;
                i++;
        }

        //cout << countWord << " = countOne" << endl;

        if (countWord == 0)
                return 0;

        int countWordTwo = 0;

        positionOneWord = str.find_last_of(oneWord) + 1; // по последнему вхождению в строку
        positionTwoWord = str.find(twoWord) - 1;  // по первому вхождению в строку
        i = positionOneWord;

        while (i < positionTwoWord) {
                //cout << i << endl;
                if (str[i] == ' ')
                        countWordTwo++;
                i++;
        }
        if (countWord > countWordTwo)
                countWord = countWordTwo;

        //cout << countWord << " = countOne" << endl;
        //cout << countWordTwo << " = countTwo" << endl;

        if (countWord == 0 || countWordTwo == 0)
                return 0;

        countWordTwo = 0;

        positionOneWord = str.find(oneWord) + 1; // по первому вхождению в строку
        positionTwoWord = str.find_last_of(twoWord) - 1;  // по последнему вхождению в строку
        i = positionOneWord;

        while (i < positionTwoWord) {
                //cout << i << endl;
                if (str[i] == ' ')
                        countWordTwo++;
                i++;
        }
        if (countWord > countWordTwo)
                countWord = countWordTwo;

        //cout << countWord << " = countOne" << endl;
        //cout << countWordTwo << " = countTwo" << endl;

        if (countWord == 0)
                return 0;
        countWordTwo = 0;

        positionOneWord = str.find_last_of(oneWord) + 1; // по последнему вхождению в строку
        positionTwoWord = str.find_last_of(twoWord) - 1;  // по последнему вхождению в строку
        i = positionOneWord;

        while (i < positionTwoWord) {
                //cout << i << endl;
                if (str[i] == ' ')
                        countWordTwo++;
                i++;
        }

        if (countWord > countWordTwo)
                countWord = countWordTwo;

        //cout << countWord << " = countOne" << endl;
        //cout << countWordTwo << " = countTwo" << endl;

        if (countWord == 0 || countWordTwo == 0)
                return 0;
        countWordTwo = 0;

        return countWord;
}

void main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        Search *varClass = new Search();
        system("pause");
}
