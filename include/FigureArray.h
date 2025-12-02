#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include <vector>
#include <memory>

class FigureArray {
private:
    std::vector<std::unique_ptr<Figure>> figures;

public:
    void addFigure(std::unique_ptr<Figure> figure);
    void removeFigure(int index);
    double calculateTotalArea() const;
    size_t size() const;
    Figure* operator[](size_t index) const;
};

#endif