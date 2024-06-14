#include <iostream>// ввод(Сin) и ввывод(cout)
#include <fstream>// работа с файлами
#include <windows.h>// работа функции sleep(пауза)
#include <clocale>// локализация
#include <locale.h>

using namespace std;// использование стандартного пространства имен (хранятся имена функций, переменных и т.д.)

fstream file;// обьявление файла


void openfiletoread(int topic) { //функция для открытия файла и считования 
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    switch (topic) {// открытие файла выбраной темы пользыватилем
        
    case 1:
        file.open("City.txt", ios_base::in); //открытие файла на считывание
        break;// выход с switch
    case 2:
        file.open("Animal.txt", ios_base::in); //открытие файла на считывание
        break;// выход с switch
    case 3:
        file.open("Plants.txt", ios_base::in); //открытие файла на считывание
        break;// выход с switch
    case 4:
        file.open("Food.txt", ios_base::in); //открытие файла на считывание
        break;// выход с switch
    case 5:
        file.open("Technique.txt", ios_base::in); //открытие файла на считывание
        break;// выход с switch
    default:// если ни одно с условий не выполнится
        cout << "Ошибка!";// вывод сообщения на экран
        break;
    }
}

void createfile(int topic) { //функция для создания файла
    switch (topic) {// открытие файла выбраной темы пользыватилем
    case 1:
        file.close();
        file.open("City.txt", ios_base::out); //открытие файла для записи и чтения
        file.close();
        break;
    case 2:
        file.close();
        file.open("Animal.txt", ios_base::out); //открытие файла для записи и чтения
        file.close();
        break;
    case 3:
        file.close();
        file.open("Plants.txt", ios_base::out); //открытие файла для записи и чтения
        file.close();
        break;
    case 4:
        file.close();
        file.open("Food.txt", ios_base::out); //открытие файла для записи и чтения
        file.close();
        break;
    case 5:
        file.close();
        file.open("Technique.txt", ios_base::out); //открытие файла для записи и чтения
        file.close();
        break;
    default:// если ни одно с условий не выполнится
        cout << "Ошибка!";//вывод сообщения на экран
        break;
    }
}

void checkDB(int topic, string wordplayer) { //Функция для занесения слова в БД
    switch (topic) {//Занесение слова в БД
    case 1:
        file.close();
        file.open("City.txt", ios_base::app); //Занесение слова в конец файла
        file << wordplayer + "\n"; //записывает в конец файла слово пользывателя
        file.close();
        file.open("City.txt", ios_base::in); //Считывание с файла
        break;
    case 2:
        file.close();
        file.open("Animal.txt", ios_base::app); //Занесение слова в конец файла
        file << wordplayer + "\n"; //записывает в конец файла слово пользывателя
        file.close();
        file.open("Animal.txt", ios_base::in); //Считывание с файла
        break;
    case 3:
        file.close();
        file.open("Plants.txt", ios_base::app); //Занесение слова в конец файла
        file << wordplayer + "\n"; //записывает в конец файла слово пользывателя
        file.close();
        file.open("Plants.txt", ios_base::in); //Считывание с файла
        break;
    case 4:
        file.close();
        file.open("Food.txt", ios_base::app); //Занесение слова в конец файла
        file << wordplayer + "\n"; //записывает в конец файла слово пользывателя
        file.close();
        file.open("Food.txt", ios_base::in); //Считывание с файла
        break;
    case 5:
        file.close();
        file.open("Technique.txt", ios_base::app); //Занесение слова в конец файла
        file << wordplayer + "\n"; //записывает в конец файла слово пользывателя
        file.close();
        file.open("Technique.txt", ios_base::in); //Считывание с файла
        break;
    default:// если ни одно с условий не выполнится
        cout << "Ошибка!";//вывод сообщения на экран
        break;
    }
}

void game(int topic) {
    openfiletoread(topic);
    if (file.is_open() == false) { // если файл не открылся
        cout << "Файл з БД не вiдкрився та був створен новий файл, спробуйте знов!\n";// вывод сообщения на экран
        createfile(topic);// обращение к функции которая создает новый файл
    }
    else { //Логика игрока
        const int scoretowin = 100; // Баллов к победе
        bool lose = false, win = false, find, magkiy;// создание bool переменных
        string wordplayer, wordbot, used[scoretowin * 2], temp;// создание строк для пользывателя, бота, для хранения слов которые уже использывались, для выбора меню
        for (int i = 0; i < scoretowin * 2; i = i + 2) { //игра пока игрок не наберет баллы 
            do {
                do {
                    cout << "Введите слово: ";
                    cin >> wordplayer; //Ввод слова с клавиатуры
                    if (i > 0) {
                        magkiy = false;
                        if (used[i - 1][used[i - 1].length() - 1] == 'ь' || used[i - 1][used[i - 1].length() - 1] == 'ы') //если последняя буква  Ь,Ы
                            magkiy = true;
                        if (wordplayer[0] + 32 == used[i - 1][used[i - 1].length() - 1 - magkiy]) { //Проверка на совпадение равенства первой буквы пользывателя и последней буквой бота
                            break;
                        }
                        else if (wordplayer == "Сдаюсь" || wordplayer == "сдаюсь") //Проверка на слово "Сдаюсь" для окончания гри
                            break;
                        else if (wordplayer == "Правила" || wordplayer == "правила") //Проверка на слово "Правила" для вывода правил
                            break;
                        else
                            cout << "Последняя буква предыдущего слова не совпадает с первой буквой вашего слова" << endl;
                    }
                    else if (i == 0) {// первая иперация пропускается
                        break;
                    }
                } while (true);
                if (wordplayer == "Сдаюсь" || wordplayer == "сдаюсь") { //Проверка на слово "Сдаюсь" для окончания гри
                    lose = true;// пользыватель проиграл
                    break;
                }
                else if (wordplayer == "Правила" || wordplayer == "правила") { //Проверка на слово "Правила" для вывода правил
                    cout << "Нужно вводить слова на русском языке на БОЛЬШУЮ букву предыдущего слова. Чтобы победить нужно набрать необходимое количество баллов, или у бота закончатся слова. Во время игры напишите 'Правила' для того чтобы, посмотреть правила. Во время игры напишите 'Сдаюсь' для того чтобы, закончить игру " << endl;
                }
                else {
                    find = false;// прекращение проверки слов в файле
                    file.close();
                    openfiletoread(topic); //Див функцию openfiletoread, которая открывает файлы на считывание
                    while (file >> wordbot) //Проверка на нахождение слова в БД
                    {
                        if (wordbot == wordplayer) //если найдено слово у БД
                        {
                            find = true;// возобновление проверки слов в файле
                            break;
                        }
                    }
                    if (find == false) { //если не найдено слово у БД
                        cout << "Слово не найдено в БД. Слово введенно верно?" << endl << "1. Да" << endl << "2. Нет" << endl << "Введите: ";
                        cin >> temp;
                        if (atoi(temp.c_str()) == 1) {// конвертируем переменную string в int
                            checkDB(topic, wordplayer); //Див функцию checkDB, открываем функцию на добавление слова в конец
                            used[i] = wordplayer; //Запись к использованным cловам
                            break;
                        }
                    }
                    else { //если найдено слово у БД
                        find = false;
                        for (int y = 0; y < i; y++) {// цикл для проверки повторяющихся слов
                            if (wordplayer == used[y]) { //проверка на использованные слова
                                find = true;
                                break;
                            }
                        }
                        if (find == false) {// если слово не повторялось
                            used[i] = wordplayer; //Запись к использованным cловам
                            break;
                        }
                        else {
                            cout << "Это слово уже было!" << endl;
                        }
                    }
                }
            } while (true); //Логика игрока


            if (lose != true) { //Логика бота, если пользыватель не проиграл
                win = true; //Победа,если у бота нету слов в БД
                file.close();
                openfiletoread(topic); //Див функцию openfiletoread, чтение файла
                while (file >> wordbot) //Переборка слов в БД
                {
                    magkiy = false;
                    if (wordplayer[wordplayer.size() - 1] == 'ь')// size - узнает размер переменной
                        magkiy = true;
                    if (wordbot[0] + 32 == wordplayer[wordplayer.size() - 1 - magkiy]) //Проверка на нахождение правильного слова
                    {
                        find = false;
                        for (int z = 0; z < i; z++) {
                            if (wordbot == used[z]) { //Проверка на использованное слово
                                find = true;
                                break;
                            }
                        }
                        if (find == false) {
                            used[i + 1] = wordbot; //Запись в использованному слову
                            cout << "Бот отвечает: " << wordbot << endl;
                            win = false;
                            break;
                        }
                    }
                }
            }
            if (lose == true || win == true || i == (scoretowin * 2 - 2)) { //Проверка на победу або поражение
                if (lose == true)
                    cout << "Поражение" << endl;
                else if (i == (scoretowin * 2 - 2))
                    cout << "Победа по баллам" << endl;
                else
                    cout << "Победа, бот не может ничого ответить" << endl;
                file.close();
                break;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string number;
    do {
        cout << "1. Города" << endl << "2. Животные" << endl << "3. Растения" << endl << "4. Еда" << endl << "5. Техника" << endl << "6. Правила" << endl << "7. Выход" << endl << "Введите номер пункта: "; //Вывод меню
        cin >> number; //Выбор параметра меню
        switch (atoi(number.c_str())) { //Преобразования переменного str на int, а также выбор пункта меню
        case 1:
            game(1); //Выбор темы 1 для игры
            break;
        case 2:
            game(2); //Выбор темы 2 для игры
            break;
        case 3:
            game(3); //Выбор темы 3 для игры
            break;
        case 4:
            game(4); //Выбор темы 4 для игры
            break;
        case 5:
            game(5); //Выбор темы 5 для игры
            break;
        case 6:
            cout << "Нужно вводить слова на русском языке на БОЛЬШУЮ букву предыдущего слова. Чтобы победить нужно набрать необходимое количество баллов, или у бота закончатся слова. Во время игры напишите 'Правила' для того чтобы, посмотреть правила. Во время игры напишите 'Сдаюсь' для того чтобы, закончить игру " << endl;
            break;
        case 7:
            cout << "Выход" << endl;
            break;
        default:
            cout << "НЕПРАВИЛЬНО!" << endl;
            break;
        }
        system("pause");// задержка консольного окна
        system("cls");//очистка окна
    } while (number != "7");//ограничитель
}
