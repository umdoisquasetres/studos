#include <iostream>
#include <windows.h>
#include "./src/ui/Menu.h"
#include "src/infra/InMemoryClienteRepository.h"
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    InMemoryClienteRepository banco;

    Menu menu(&banco);
    menu.iniciar();

    return 0;
}