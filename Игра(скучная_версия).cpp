// Игра(скучная_версия).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int convert2(string str) {

    int i = 0;
    string a = "123456";

    str.erase(remove_if(str.begin(), str.end(), isspace), str.end()); // убираем пробелы из строки если они вдруг есть

    for (char const& c : str) {

        if (a.find(c) != string::npos) {

            stringstream s; // читаем и записываем строку в поток
            s << c;

            int y; // закидываем в инт
            s >> y;

            i = i * 10 + y;
        }
        else {

            cout << "Сначала научись вводить и возвращайся" << endl;
            return 0;
        }
    }
    if (i / 10000 == 0 && i % 10000 >= 1111) return i;
    else if (i / 10000 != 0) {
        cout << "Сначала научись вводить и возвращайся" << endl;
        return 0;
    }
    else if (i < 1111) {
        cout << "Сначала научись вводить и возвращайся" << endl;
        return 0;
    }
}

int convert1(string str) {

    int i = 0;
    string a = "12";

    str.erase(remove_if(str.begin(), str.end(), isspace), str.end()); // убираем пробелы из строки если они вдруг есть

    for (char const& c : str) {

        if (a.find(c) != string::npos) {

            stringstream s; // читаем и записываем строку в поток
            s << c;

            int y; // закидываем в инт
            s >> y;

            i = i * 10 + y;
        }
        else {

            cout << "Там белым по чёрному написано << 1 >> или << 2 >>, а ты что печатаешь?" << endl;
            break;
        }
    }
    return i;
}

//        (Исходник со всеми вариантами чисел / загаданное число / число дурачка / индекс числа в массиве вариантов)
bool prov2(vector <vector <int>>& varianty, vector <int> zag, vector <int> dur, int& flag) {

    int popal = 0;
    int est = 0;
    int c = 0;
    for (int i = 0; i < 4; i++) {

        if (dur[i] == zag[i]) { // цифра на месте
            popal++;
        }
        else {

            if (find(zag.begin(), zag.end(), dur[i]) != zag.end()) { // цифра не на месте

                est += 1;
                if (count(dur.begin(), dur.end(), dur[i]) > 1) c += 1;
            }
            else { // цифры нет

                for (int j = 0; j < varianty.size(); j++) { // удаляем все строки где есть ненужная цифра

                    if (dur[i] == varianty[j][0] || dur[i] == varianty[j][1] || dur[i] == varianty[j][2] || dur[i] == varianty[j][3]) {

                        varianty.erase(varianty.begin() + j);
                        j--;
                    }
                }

            }
        }
    }

    cout << "Попал: " << popal << endl;
    cout << "В наличии: " << (est - c) << endl;
    if (popal > 0 || est > 0) flag++;
    if (popal == 4) return true;
    else return false;
}

void game2(vector <int> vec) {

    int mass[6] = { 1, 2, 3, 4, 5, 6 }; // массив возможных чисел
    vector <vector <int> > var;

    for (int i = 0; i < 6; i++) // вектор всех вариантов
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                for (int l = 0; l < 6; l++) {
                    vector <int> var1;
                    var1.push_back(mass[i]);
                    var1.push_back(mass[j]);
                    var1.push_back(mass[k]);
                    var1.push_back(mass[l]);
                    var.push_back(var1);
                }

    int i = 0;

    while (i < var.size()) { // цикл проверки и перебора

        vector <int> chislo;

        cout << "Компьютер придумал число: ";
        for (int j = 0; j < 4; j++) chislo.push_back(var[i][j]); // берем число из набора вариантов чисел
        for (int b : chislo) cout << b << " "; // выводим его
        cout << endl;

        bool flag = prov2(var, vec, chislo, i);

        if (flag) { // попали в число

            break;
        }
    }

    cout << "Победа! Загаданное число действительно ";

    for (int a : vec) cout << a << " ";
}

void prov1(vector <int> chislo_igroka, vector <int> zag) { // ( число игрока / загаданное число )

    int popal = 0;
    int est = 0;
    int c = 0;
    for (int i = 0; i < 4; i++) {
        if (chislo_igroka[i] == zag[i]) { // цифра на месте
            popal++;
        }
        else {
            if (find(zag.begin(), zag.end(), chislo_igroka[i]) != zag.end()) { // цифра не на месте
                est += 1;
                if (count(chislo_igroka.begin(), chislo_igroka.end(), chislo_igroka[i]) > 1) c += 1;
            }
        }
    }

    cout << "Попал: " << popal << endl;
    cout << "В наличии: " << (est - c) << endl;
}

void game1(vector <int> vec) {

    bool flag_win = false;

    while (!flag_win) {

        bool flag_igrok = true;

        while (flag_igrok) {

            int chislo_igroka;
            vector<int> igrok;
            string chislo_igroka1;

            cout << "Введи число: ";
            getline(cin, chislo_igroka1);
            chislo_igroka = convert2(chislo_igroka1);

            if (chislo_igroka != 0) { // делаем число как нам надо

                igrok.push_back(chislo_igroka / 1000);
                igrok.push_back((chislo_igroka / 100) % 10);
                igrok.push_back((chislo_igroka / 10) % 10);
                igrok.push_back(chislo_igroka % 10);

                flag_igrok = false;

                if (igrok == vec) { // попали

                    cout << "Ты не безнадёжен!" << endl;
                    cout << "Загаданное число действительно ";

                    for (int a : vec) cout << a << " ";

                    flag_win = true;
                }
                else {

                    prov1(igrok, vec); // угадываем дальше
                }
            }
        }

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // вступление :D
    cout << "Привет!" << endl;
    cout << "Ты попал в лучшую игру <<Великий комбинатор>>" << endl;
    cout << "Компьютер загадал четырёхзначное число из цифр от 1 до 6 (цифры в нём могут повторяться!)" << endl;
    cout << "Если ты хочешь угадывать сам, введи << 1 >>" << endl;
    cout << "Если хочешь, чтоб за тебя всё сделал компьютер, введи << 2 >>" << endl;

    vector <int> vec;
    srand(time(0));
    for (int i = 0; i < 4; i++) vec.push_back(rand() % (6) + 1); // генерация числа, которое нужно угадать
    /*
    cout << "Компьютер загадал число: ";
    for (int a : vec) cout << a << " "; // вывод числа
    cout << endl;
    */
    bool v = false;
    while (!v) {

        cout << "Твой выбор? "; // выбираем как хотим играть
        string vv;
        getline(cin, vv);
        int vvod;
        vvod = convert1(vv);

        if (vvod == 1) {

            v = true;
            game1(vec);
        }
        else if (vvod == 2) {

            v = true;
            game2(vec);
        }
        else cout << "Перечитай правила и возвращайся" << endl;
    }

    return 0;

}