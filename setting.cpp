#include "setting.h"
#include <fstream>
#include "input.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include "edit_strings.h"
#include "formating_console.h"

int settings()
{
    std::ofstream fout("config.cnf"); // создаЄм объект класса ofstream дл€ записи и св€зываем его с файлом cppstudio.txt
    std::string lang = input("Select language: Ru - Russian, En - English: ");
    lang = lower(lang);
    while (true) {

        if (lang == "ru" or lang == "en") {
            fout << "lang=" + lang; // запись строки в файл
            break;
        }
        else {
            std::cout << "You entered the wrong value!\n";
            std::string lang = input("Select language: Ru - Russian, En - English: ");
            if (lang == "ru" or lang == "en") {
                fout << "lang=" + lang; // запись строки в файл
                break;
            }
        }
    }    

    fout.close(); // закрываем файл

    return 0;
}

int lang() {
    std::ifstream cFile("config.cnf");
    if (cFile.is_open())
    {
        std::string line;
        while (getline(cFile, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                line.end());
            if (line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos); // название конфиг строки
            auto value = line.substr(delimiterPos + 1); // значение конфиг строки

            if (name == "lang") {
                if (value == "ru") {
                    return 1; // –усский €зык
                }
                else if (value == "en") {
                    return 2; // јнглийский €зык
                }
            }
        }

    }
    else {
        SetColor(Red, Black);
        std::cerr << "Couldn't open config file for reading.\n";
        SetColor(LightGray, Black);
    }
    return 0; // язык не указан в конфиге или не удалось открыть файл

    /*
    std::string line;

    std::ifstream in("config.cnf"); // окрываем файл дл€ чтени€
    if (in.is_open())
    {
        while (getline(in, line))
        {
            char* ls = &line[0];

            std::cout << strtok(ls, "=")[0] << std::endl;
            std::cout << strtok(ls, "=")[1] << std::endl;

            if (strtok(ls, "=")[0] == 'lang') {
                if (strtok(ls, "=")[1] == 'ru') {
                    return 1;
                }
                else if (strtok(ls, "=")[1] == 'en') {
                    return 2;
                }
            }
        }
    }
    in.close();
    */
    return 0;
}