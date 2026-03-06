#include <iostream>
#include <iomanip>

double adjustedAmount(double currentValue, double currentIpc, double oldIpc)
{
    return currentValue * (oldIpc / currentIpc);
}

double calculateInflationRate(double currentIpc, double oldIpc)
{
    return ((currentIpc / oldIpc) - 1.0) * 100.0;
}

int main()
{
    double currentAmount{};
    double currentIpc{135.2};
    double oldIpc{110.5};

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Ingresa cuanta plata tienes: ";
    std::cin >> currentAmount;

    double adjustedValue{adjustedAmount(currentAmount, currentIpc, oldIpc)};
    double inflationValue(calculateInflationRate(currentIpc, oldIpc));

    std::cout << "el $" << currentAmount << " que tienes hoy, en el año 2022 equivale a " << adjustedValue << '\n';
    std::cout << std::setprecision(1) << "la inflacion fue de " << inflationValue << "%\n";

    return 0;
}