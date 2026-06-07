#include <utility>
#include <iostream>
#include <string>
#include <cmath>

struct coefficient {
    double a;
    double b;
    double c;
};

std::pair<bool, std::pair<double, double>> solveQuadratic(double a, double b, double c) {
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return {false, {0.0, 0.0}};
    } else {
        double sqrt_d = std::sqrt(discriminant);
        double x1 = (-b + sqrt_d) / (2 * a);
        double x2 = (-b - sqrt_d) / (2 * a);
        return {true, {x1, x2}};
    }
}

double parseSignedNumber(char sign, char digit) {
    int value = digit - '0';
    if (sign == '-') {
        value = -value;
    }
    return (double)value;
}

struct coefficient getCoefficient(const std::string & input) {
    coefficient coef;
    coef.a = parseSignedNumber(input[0], input[1]);
    coef.b = parseSignedNumber(input[5], input[6]);
    coef.c = parseSignedNumber(input[8], input[9]);
    return coef;
}

int main () {
    std::string input =  "+2x^2-6x+4";

    if (input.length() != 10) {
        std::cout << "input must be in +1x^2-1x+0 format" << std::endl;
        return 1;
    }
    
    coefficient c = getCoefficient(input);
    auto solution = solveQuadratic(c.a, c.b, c.c);

    if (solution.first) {
        std::cout << "x1= " << solution.second.first << std::endl;
        std::cout << "x2= " << solution.second.second << std::endl;
    } else {
        std::cout << "no real solution" << std::endl;
    }
    return 0;
}