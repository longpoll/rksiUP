#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Search { // создадим класс для поиска расстояния между словами

private:
    string str, oneWord, twoWord;
    int position, countWord, countWordTwo;
    int getWayBetweenWord();
    int getWayFindFind();
    int getWayFindLast();
    int getWayLastFind();
    int getWayLastLast();
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

int Search::getWayFindFind(){
    int positionOneWord = str.find(oneWord) + 1; // по первому вхождению в строку
    int positionTwoWord = str.find(twoWord) - 1; // по первому вхождению в строку

    /* if (positionOneWord > positionTwoWord){
        int temp = positionTwoWord;
        positionTwoWord = positionOneWord - 1;
        positionOneWord = temp + 1;
    }*/

    int i = positionOneWord, countWord = 0;
    if (positionOneWord != positionTwoWord) { // ищем только в случае, если позиции не совпадают
        while (i < positionTwoWord) {
            if (str[i] == ' ')
                countWord++;
            i++;
        }
    } else
        countWord = -1; //

    return countWord;
}

int Search::getWayLastFind(){
    int positionOneWord = str.find_last_of(oneWord) + 1; // по последнему вхождению в строку
    int positionTwoWord = str.find(twoWord) - 1;  // по первому вхождению в строку
    int i = positionOneWord;

    while (i < positionTwoWord) {
        //cout << i << endl;
        if (str[i] == ' ')
            countWordTwo++;
        i++;
    }

    return countWord;
}
int Search::getWayFindLast(){
    int positionOneWord = str.find(oneWord) + 1; // по первому вхождению в строку
    int positionTwoWord = str.find_last_of(twoWord) - 1;  // по последнему вхождению в строку
    int i = positionOneWord;

    while (i < positionTwoWord) {
        if (str[i] == ' ')
            countWordTwo++;
        i++;
    }

    return countWord;
}
int Search::getWayLastLast(){
    int positionOneWord = str.find_last_of(oneWord) + 1; // по последнему вхождению в строку
    int positionTwoWord = str.find_last_of(twoWord) - 1;  // по последнему вхождению в строку

    int i = positionOneWord;

    if(positionOneWord != positionTwoWord) {
        while (i < positionTwoWord) {
            //cout << i << endl;
            if (str[i] == ' ')
                countWordTwo++;
            i++;
        }
    }

    return countWord;
}
int Search::getWayBetweenWord() { // метод для поиска минимального расстояния между словами
    int positionOneWord = str.find(oneWord) + 1; // по первому вхождению в строку
    int positionTwoWord = str.find(twoWord) - 1; // по первому вхождению в строку

    if(positionOneWord < 0 || positionTwoWord < 0) // если таких слов нет в строке, то просто прекратить выполнение метода
        return 0;

    int countWord = getWayFindFind(); // ищем расстояние по первому вхождению

    int countWordTwo = countWord;
    countWord = getWayLastFind(); // ищем расстояние по последнему и первому вхождениям
    if(countWord < countWordTwo)
        countWord = countWordTwo;
    countWordTwo = 0;
    countWord = getWayFindLast(); // по последнему и первому вхождениям
    if(countWord < countWordTwo)
        countWord = countWordTwo;
    countWordTwo = 0;
    countWord = getWayLastLast(); // по последним вхождениям
    if(countWord < countWordTwo)
        countWord = countWordTwo;

    return countWord;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Search *varClass = new Search();
    system("pause");
    return 0;
}
