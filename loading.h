#pragma once

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

enum Type
{
    d,
    r,
    g,
    b,
    w
};

int loading(std::string text, int speed_str, Type color);