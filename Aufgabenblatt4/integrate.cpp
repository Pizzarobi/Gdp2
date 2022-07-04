#include <exception>
#include <iostream>
#include <string>

class IntegralException : public std::exception
{
private:
    std::string message;
public:
    IntegralException(std::string pMessage) : std::exception()
    {
        message = pMessage;
    }

    std::string getMessage()
    {
        return message;
    }
};


double integrate(const double left, const double right,
                 const int steps, double (*f)(const double x))
{
    if (steps <= 0)
        throw IntegralException("Error: steps < 0");

    if (right < left)
        throw IntegralException("Error: right < left");

    double result = 0.0;
    double delta = (right - left) / steps;
    double xi = left + delta / 2.0;

    for (int i = 0; i < steps; i++)
    {
        result += (*f)(xi);
        xi += delta;
    }

    return delta * result;
}

double poly(const double x)
{
    return -2 * x * x + 2;
}

int main()
{
    try
    {
        //std::cout << integrate(-1.0, 1.0, 100, &poly) << '\n';
        std::cout << integrate(-1.0, 1.0, 100, [](double x) {return -2 * x * x + 2;}) << '\n';
    }
    catch (IntegralException& ex)
    {
        std::cout << ex.getMessage() << '\n';
    }
}
