//#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Search{

private:
    string str, oneWord, twoWord;
    int position;
    int getWayBetweenWord();
public:
    Search();
    ~Search();
};

Search::Search(){
    cout << "Введите строку: ";
    getline(cin, str);
    cout << "Введите первое слово: ";
    cin >> oneWord;
    cout << "Введите второе слово: ";
    cin >> twoWord;
    cout << "Кол-во слов: " << getWayBetweenWord();
}
int Search::getWayBetweenWord(){
    int positionOneWord = str.find_last_of(oneWord)+1;
    int positionTwoWord = str.find(twoWord)-1;
    int i = positionOneWord, countWord = 0;
    while(i < positionTwoWord){
        if(str[i] == ' ') {
            countWord++;
        }
        i++;
    }
    return countWord;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //cout << "Введённая строка: " << str << endl;
    Search *varClass = new Search();
    system("pause");
    return 0;
}
