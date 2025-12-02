#include "../include/FigureArray.h"
#include <iostream>

void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void FigureArray::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}


double FigureArray::calculateTotalArea() const {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += figure->calculateArea();
    }
    return total;
}

size_t FigureArray::size() const {
    return figures.size();
}

Figure* FigureArray::operator[](size_t index) const {
    return figures[index].get();
}