#include "loading.h"

int loading(std::string text, int speed_str, Type color) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "                 " << "\t\r" << std::flush;

    int i = 0;
    boolean gb = false;
    while (i < text.length() + 1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(speed_str));

        if (gb) {
            gb = false;
        }
        else {
            gb = true;
        }

        if (i == text.length()) {
            switch (color)
            {
            case d:
                SetColor(LightGray, Black);
                break;
            case r:
                SetColor(Red, Black);
                break;
            case w:
                SetColor(White, Black);
                break;
            case g:
                SetColor(Green, Black);
                break;
            case b:
                SetColor(Blue, Black);
                break;
            }

            std::cout << text.substr(0, i) << "\t\r";
        }
        else {
            switch (color)
            {
            case d:
                SetColor(LightGray, Black);

                break;
            case r:
                SetColor(Red, Black);
                break;
            case w:
                SetColor(White, Black);
                break;
            case g:
                SetColor(Green, Black);
                break;
            case b:
                SetColor(Blue, Black);
                break;
            }
            std::cout << text.substr(0, i);
            if (gb) {
                SetColor(Green, Black);
            }
            else {
                SetColor(Black, Black);
            }
            std::cout << "|" << "\t\r" << std::flush;
        }
        i += 1;
    }
    std::cout << "\n" << std::endl;
    SetColor(LightGray, Black);

    return 0;
}