#include <iostream>

double kelvintoFahrenheit(double kelvin)
{
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int main()
{
    double kelvin;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

    std::cout << "Temperature in Fahrenheit: "
              << kelvintoFahrenheit(kelvin)
              << std::endl;

    return 0;
}