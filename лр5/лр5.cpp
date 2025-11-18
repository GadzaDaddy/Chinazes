#include "pch.h"
using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    // Задані константи
    double D = 1.5;    // діаметр маховика (м)
    double m = 0.5;    // маса маховика (т) = 500 кг
    double R = D / 2.0; // радіус маховика (м)

    // Масив значень обертів
    array<int>^ n_values = gcnew array<int>{ 50, 150, 200, 350, 550, 900, 1000 };

    Console::WriteLine(L"Розрахунок параметрів маховика");
    Console::WriteLine(L"Діаметр маховика: {0} м", D);
    Console::WriteLine(L"Маса маховика: {0} т", m);
    Console::WriteLine(L"Радіус маховика: {0:F2} м", R);
    Console::WriteLine();

    // Заголовок таблиці
    Console::WriteLine(L"┌─────┬──────────┬────────────┬──────────────┬──────────────┐");
    Console::WriteLine(L"│  №  │   n      │    ω       │      v       │     Wk       │");
    Console::WriteLine(L"│     │ (об/хв)  │ (рад/с)    │    (м/с)     │     (Дж)     │");
    Console::WriteLine(L"├─────┼──────────┼────────────┼──────────────┼──────────────┤");

    // Розрахунок та вивід результатів для кожного значення n
    for (int i = 0; i < n_values->Length; i++)
    {
        int n = n_values[i];

        // Розрахунок кутової швидкості
        double omega = (Math::PI * n) / 30.0;

        // Розрахунок лінійної швидкості
        double v = omega * R;

        // Розрахунок кінетичної енергії (m переводимо з тонн в кг)
        double Wk = (m * 1000 * v * v) / 2.0;

        // Вивід результатів у таблицю
        Console::WriteLine(L"│ {0,3} │ {1,8} │ {2,10:F4} │ {3,12:F4} │ {4,12:F2} │",
            i + 1, n, omega, v, Wk);
    }

    Console::WriteLine(L"└─────┴──────────┴────────────┴──────────────┴──────────────┘");
    Console::WriteLine();
    Console::WriteLine(L"Формули розрахунку:");
    Console::WriteLine(L"ω = π·n/30");
    Console::WriteLine(L"v = ω·R");
    Console::WriteLine(L"Wk = m·v²/2");
    Console::WriteLine();

    Console::ReadKey();
    return 0;
}