#include "../include/TotalArea.h"

double calculateTotalArea(const std::vector<std::unique_ptr<Figure>> &figures){
    double total = 0.0;
    for (const auto &figure : figures){
        total += figure->calculateArea();
    }
    return total;
}