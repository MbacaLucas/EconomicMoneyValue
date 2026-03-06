#include <iostream>
#include <iomanip>

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

int main()
{
    // Fixed reference for March 2026 (Modern CPI Base 2023)
    double standardIpc{113};
    char resetWhile{};

    // Main application loop
    do
    {
        double currentAmount{};
        double ipc{};
        bool yearValid{true}; // Guard variable to prevent calculation errors
        int year{};

        // Setup numeric formatting for CLP (0 decimals)
        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Ingresa cuanta plata tienes: ";
        std::cin >> currentAmount;
        std::cout << "Ingresa el año de comparacion (ej: 2024): ";
        std::cin >> year;

        // Map historical CPI points for Chile (Source: INE)
        switch (year)
        {
        case 2022:
        {
            ipc = 89.5;
            break;
        }
        case 2023:
        {
            ipc = 100.3;
            break;
        }
        case 2024:
        {
            ipc = 104.0;
            break;
        }
        case 2025:
        {
            ipc = 112.1;
            break;
        }
        case 2026:
        {
            std::cout << "2026 te entregaria cero variacion... gracias!";
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

            // Output results: Purchasing power comparison
            std::cout << "el $" << currentAmount << " que tienes hoy en el 2026, en el año " << year << " podias comprar lo mismo pero con $" << adjustedValue << '\n';

            // Switch to 1 decimal for percentage precision
            std::cout << std::setprecision(1) << "vivir hoy en chile es " << inflationValue << "% mas caro\n";
        }

        // Prompt for session restart
        std::cout << "\n¿Deseas consultar otro año? (s/n): ";
        std::cin >> resetWhile;

    } while (resetWhile == 's' || resetWhile == 'S');

    std::cout << "\nGracias por usar mi tinyApp.!\n";

    return 0;
}
