#include <iostream>
#include <windows.h>
#include "./src/ui/Menu.h"
#include "./src/domain/Cliente.h"
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Menu menu;
    menu.iniciar();
    return 0;
}