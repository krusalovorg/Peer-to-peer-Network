// Peer-to-peer client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include "formating_console.h"
#include "command.h"
#include "input.h"
#include "loading.h"
#include "setting.h"
#include "language.h"

int server() {
    return 0;
}

int client() {
    return 0;
}

int Contract() {
    std::cout << "I ";
    char output_inp[80]{};
    std::cin.getline(output_inp, 80);
    std::cout << "пук пук";
    return 0;
}

int main()
{
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251. Нужно только будет изменить шрифт консоли на Lucida Console или Consolas

    boolean ru;
    if (lang() == 1) {
        ru = true;
    }
    else {
        ru = false;
    }

    if (lang() == 1) { // Если язык русский
        loading("---------------------------------", 30, d);
        loading(WelcomeRu, 30, d);
        loading("---------------------------------", 30, d);

        loading(ResponsibilityRu, 30, r);
    }
    else if (lang() == 2) { // Если язык английский
        loading("---------------------------------", 30, d);
        loading(WelcomeEn, 30, d);
        loading("---------------------------------", 30, d);

        loading(ResponsibilityEn, 30, r);
    }
    else if (lang() == 0) { // Если конфиг не найден или не указано en или ru
        loading("---------------------------------", 30, d);
        loading(WelcomeEn, 30, d);
        loading(WelcomeRu, 30, d);
        loading("---------------------------------", 30, d);

        loading(ResponsibilityEn, 30, r);
        loading(ResponsibilityRu, 30, r);
    }

    if (lang() == 0){
        settings();

        Contract();
    }

    std::thread s(server);
    std::thread c(client);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    while (true)
    {
        command();
    }
    c.join();
    s.join();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
