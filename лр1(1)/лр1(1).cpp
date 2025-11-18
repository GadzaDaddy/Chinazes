#include "pch.h"
#include <windows.h>
using namespace System;

int main(array<String^>^ args) {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Запит на введення рядка від користувача
    Console::Write("введіть рядок: ");
    String^ first = Console::ReadLine()->Trim();

    String^ start = gcnew String("begin ");
    String^ end1 = gcnew String(" end");

    String^ result = start + first + end1;
    int length = result->Length;

    Console::WriteLine();
    Console::WriteLine("Одержаний рядок: {0}", result);
    Console::WriteLine("довжина рядка: {0}", length);

    return 0;
}