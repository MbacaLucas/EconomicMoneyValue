#include <iostream>
#include <iomanip>
#include <thread> // Para pausar el programa
#include <chrono> // Para medir el tiempo (milisegundos)

// Calculates the equivalent amount of money in a past year based on current purchasing power
double adjustedAmount(double currentValue, double ipc, double standardIpc)
{
    // Formula: Current Money * (Past IPC / Current IPC)
    return currentValue * (ipc / standardIpc);
}

// Calculates the cumulative inflation rate between a past year and the current year
double calculateInflationRate(double ipc, double standardIpc)
{
    // Formula: ((Current IPC / Past IPC) - 1) * 100
    return ((standardIpc / ipc) - 1.0) * 100.0;
}

void showLoadingBar()
{
    std::string bar = "--------------------"; // 20 guiones
    for (int i = 0; i <= 20; ++i)
    {
        std::cout << "\rCargando datos: [" << std::string(i, '#') << std::string(20 - i, ' ') << "] " << (i * 5) << "%" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    std::cout << "\n\n"; // Salt
}

int main()
{
    // Fixed reference for March 2026 (Modern CPI Base 2023)
    double standardIpc{113};
    double currentUnemployment{8.0};
    char resetWhile{};

    // Main application loop
    do
    {
        double currentAmount{};
        double ipc{};
        double compareUnemployment{};
        double unemployment{};
        bool yearValid{true}; // Guard variable to prevent calculation errors
        int year{};

        // Setup numeric formatting for CLP (0 decimals)
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "\tData Actualizada 2026 ";
        std::cout << "\n====================================\n";
        std::cout << "IPC: " << standardIpc << "pts" << "\tDesempleo: " << currentUnemployment << "%\n";
        std::cout << "====================================\n";
        std::cout << "Ingresa cuanta plata tienes: ";
        std::cin >> currentAmount;
        std::cout << "Ingresa el año de comparacion (Entre 2020-24): ";
        std::cin >> year;
        std::cout << '\n';

        // Map historical CPI points for Chile (Source: INE)
        switch (year)
        {
        case 2020:
        {
            ipc = 83.0;
            unemployment = 10.7;
        }
        case 2021:
        {
            ipc = 89.5;
            unemployment = 8.1;
        }
        case 2022:
        {
            ipc = 89.5;
            unemployment = 7.9;
            break;
        }
        case 2023:
        {
            ipc = 100.3;
            unemployment = 8.7;
            break;
        }
        case 2024:
        {
            ipc = 104.0;
            unemployment = 8.5;
            break;
        }
        case 2025:
        {
            ipc = 112.1;
            unemployment = 8.2;
            break;
        }
        case 2026:
        {
            std::cout << "2026 te entregaria cero variacion...!";
            yearValid = false;
            break;
        }
        default:
        {
            // Handles years outside the registered database
            std::cout << "Año fuera de registro";
            yearValid = false;
        }
        }

        // Only perform calculations if a valid year was selected
        if (yearValid)
        {
            double adjustedValue{adjustedAmount(currentAmount, ipc, standardIpc)};
            double inflationValue(calculateInflationRate(ipc, standardIpc));

            compareUnemployment = unemployment - currentUnemployment;
            showLoadingBar();
            std::cout << "-💰. Con $" << static_cast<long long>(currentAmount) << " que tienes hoy en el 2026, en el año " << year << " podias comprar lo mismo pero con $" << static_cast<long long>(adjustedValue) << "\n\n";
            std::cout << std::fixed << std::setprecision(1) << "-🇨🇱. Vivir hoy en chile es " << inflationValue << "% mas caro\n\n";

            std::cout << std::setprecision(1) << "-⚠️. En " << year << " habia un " << unemployment << "% de desempleo\n";
            if (compareUnemployment > 0)
            {
                std::cout << "\t(" << compareUnemployment << "% mas alto que hoy)\n";
            }
            else if (compareUnemployment < 0)
            {
                std::cout << "\t(" << -compareUnemployment << "% mas bajo que hoy)\n";
            }
            else
            {
                std::cout << "(igual que hoy)\n";
            }
        }

        // Prompt for session restart
        std::cout << "\n¿Deseas consultar otro año? (s/n): ";
        std::cin >> resetWhile;

    } while (resetWhile == 's' || resetWhile == 'S');

    std::cout << "\nGracias por usar mi tinyApp.!\n";

    return 0;
}