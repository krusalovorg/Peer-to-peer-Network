#include "command.h"
#include <string>
#include <windows.h>
#include <thread>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include "formating_console.h"
#include <iostream>
#include "language.h"
#include "setting.h"
#include "edit_strings.h"
#include "client.h"

int command()
{
    char command[80]{};
    std::cout << "> ";
    std::cin.getline(command, 80);
    std::string cmd = command;

    std::string syntax = " - -"; // Отступ

    boolean ru;

    if (lang() == 1) {
        ru = true;
    }
    else {
        ru = false;
    }


    if (cmd == "help") {

        if (ru) {
            std::cout << syntax << CloseInfoRu << std::endl;
            std::cout << syntax << ResetInfoRu << std::endl;
            std::cout << syntax << ClientInfoRu << std::endl;
        }
        else {
            std::cout << syntax << CloseInfoEn << std::endl;
            std::cout << syntax << ResetInfoEn << std::endl;
            std::cout << syntax << ClientInfoEn << std::endl;
        }
    }
    else if (cmd == "client") {
        client(127, 1234);
    }
    else if (cmd == "stop" || cmd == "close" || cmd == "exit") {
        char yon[80];

        SetColor(Red, Black);

        if (ru) {
            std::cout << CloseRu;
        }
        else {
            std::cout << CloseEn;
        }

        SetColor(LightGray, Black);

        std::cin.getline(yon, 80);

        std::string yon_ = lower(charToString(yon));

        if (yon_ == "yes" || yon_ == "y") {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

    }    
    else if (cmd == "reset") {
        char yon[80];

        SetColor(Red, Black);

        if (ru) {
            std::cout << ResetRu;
        }
        else {
            std::cout << ResetEn;
        }

        SetColor(LightGray, Black);

        std::cin.getline(yon, 80);

        std::string yon_ = lower(charToString(yon));

        if (yon_ == "yes" || yon_ == "y") {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            settings();
        }

    }
    else {
        if (ru) {
            std::cout << "Комманда \"" + cmd + "\" не найдена" << std::endl;
        }
        else {
            std::cout << "Command \"" + cmd + "\" not found" << std::endl;
        }
    }
    return 0;
}
