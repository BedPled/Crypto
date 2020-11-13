#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
    int len_arr; // кол-во столбцов
    int hight_arr; // кол-во строк
    int len_str; // длинна строки + '\0'
    char* str = new char[1000]; // буфер ввода

    cout << "Шифрование сообщения методом двойной перестановки" << endl;
    cout << "Введите ваше сообщение:" << endl;
    cin.getline(str,1000,'\n');
    cout << "Введите ширину матрицы: ";
    cin >> len_arr;
    len_str = strlen(str) + 1;
    hight_arr = (len_str / len_arr);
    if (len_str % len_arr != 0) hight_arr += 1;

    char arr_encryption[hight_arr][len_arr]; // массив шифрования
    char arr_decryption[hight_arr][len_arr]; // массив дешифрования

    unsigned int key_hight[hight_arr]; // ключь строк
    unsigned int key_len[len_arr]; // ключь столбцов

    int count = 0; // счётчик символов буфера
    for (int i = 0; i < hight_arr; i++){  // создание матрицы
        for(int j = 0; j < len_arr; j++){
            if (count < len_str){ // запись сообщения
                arr_decryption[i][j] = str[count];
                count++;
            } else {  // закидываем рандомные символы латиницы
                arr_decryption[i][j] = 97 + rand() % 26; // 97 - 122
            }
        }
    }

    cout << endl << "Исходная матрица:" << endl;
    for (int i = 0; i < hight_arr; i++){
        for(int j = 0; j < len_arr; j++){
            cout << arr_decryption[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // создание ключе
    srand(time(0));
    bool gen;
    cout << "Ключ 1: ";
    for(int i = 0; i < len_arr; i++){
        do {
            gen = false;
            key_len[i] = rand() % len_arr + 1;
            for(int j = 0; j < i; j++){
                if (key_len[i] == key_len[j]) {
                    gen = true;
                }
            }
        } while (gen);
        cout << key_len[i] << " ";
    }
    cout << endl;

    cout << "Ключ 2: ";
    for(int i = 0; i < hight_arr; i++){
        do {
            gen = false;
            key_hight[i] = rand() % hight_arr + 1;
            for(int j = 0; j < i; j++){
                if (key_hight[i] == key_hight[j]) {
                    gen = true;
                }
            }
        } while (gen);
        cout << key_hight[i] << " ";
    }
    cout << endl;

    // шифрование
    for (int i = 0; i < len_arr; i++){
        for(int j = 0; j < hight_arr; j++){
            arr_encryption[key_hight[j] - 1][key_len[i] - 1] = arr_decryption[j][i];
        }
    }

    cout << "Зашифрованная матрица:" << endl;
    for (int i = 0; i < hight_arr; i++){
        for(int j = 0; j < len_arr; j++){
            cout << arr_encryption[i][j];
        }
        cout << endl;
    }
    cout << endl;


    cout << "Зашифрованное сообщение:";
    for (int i = 0; i < hight_arr; i++){  // вывод матрицы
        for(int j = 0; j < len_arr; j++){
            cout << arr_encryption[i][j];
        }
    }
    cout << endl;


    for (int i = 0; i < len_arr; i++){ // расшифровка
        for(int j = 0; j < hight_arr; j++){
            arr_decryption[j][i] = arr_encryption[key_hight[j] - 1][key_len[i] - 1] ;
        }
    }

    cout << "Расшифрованная матрица:" << endl;
    for (int i = 0; i < hight_arr; i++){  // вывод матрицы
        for(int j = 0; j < len_arr; j++){
            cout << arr_decryption[i][j];
        }
        cout << endl;
    }
    cout << endl;


    cout << "Расшифрованное сообщение:";
    for (int i = 0; i < hight_arr; i++){  // вывод матрицы
        for(int j = 0; j < len_arr; j++){
            cout << arr_decryption[i][j];
            if (arr_decryption[i][j] == 0) break;
        }
    }

    return 0;
}
