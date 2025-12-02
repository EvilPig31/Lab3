#ifndef TOTALAREA_H
#define TOTALAREA_H

#include "Figure.h"
#include <memory>
#include <vector>

double calculateTotalArea(const std::vector<std::unique_ptr<Figure>> &figures);
#endif