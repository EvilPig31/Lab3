#include "../include/Rhombus.h"
#include "../include/Trapezoid.h"
#include "../include/Pentagon.h"
#include "../include/TotalArea.h"
#include <gtest/gtest.h>

TEST(test_1, TrapezoidConstGet){
    Trapezoid t(10, 6, 4, 2, 3);
    auto center = t.calculateCenter();
    EXPECT_DOUBLE_EQ(center.first, 2);
    EXPECT_DOUBLE_EQ(center.second, 5);
}
TEST(test_2, TrapezoidArea){
    Trapezoid t1(10, 6, 4, 2, 3);
    EXPECT_DOUBLE_EQ(t1.calculateArea(), 32.0);
    Trapezoid t2(5, 3, 4, 0, 0);
    EXPECT_DOUBLE_EQ(t2.calculateArea(), 16.0);
}
TEST(test_3, TrapezoidEq){
    Trapezoid t1(10, 6, 4, 2, 3);
    Trapezoid t2(5, 3, 4, 0, 0);
    Trapezoid t3(10, 6, 4, 2, 3);
    EXPECT_TRUE(t1.operator== (t3));
    EXPECT_FALSE(t1.operator== (t2));
}
TEST(test_4, RhombusConstGet){
    Rhombus r(8, 6, 2, 3);
    auto center = r.calculateCenter();
    EXPECT_DOUBLE_EQ(center.first, 2);
    EXPECT_DOUBLE_EQ(center.second, 3);
}
TEST(test_5, RhombusArea){
    Rhombus r1(8, 6, 2, 3);
    EXPECT_DOUBLE_EQ(r1.calculateArea(), 24.0);
    Rhombus r2(4, 5, 0, 0);
    EXPECT_DOUBLE_EQ(r2.calculateArea(), 10.0);
}
TEST(test_6, RhombusEq){
    Rhombus r1(8, 6, 2, 3);
    Rhombus r2(5, 4, 0, 0);
    Rhombus r3(8, 6, 2, 3);
    EXPECT_TRUE(r1.operator== (r3));
    EXPECT_FALSE(r1.operator== (r2));
}
TEST(test_7, PentagonConstGet){
    Pentagon p(5, 2, 3);
    auto center = p.calculateCenter();
    EXPECT_DOUBLE_EQ(center.first, 2);
    EXPECT_DOUBLE_EQ(center.second, 3);
}
TEST(test_8, RhombusArea){
    Pentagon p(1.0, 0, 0);
    double area = (5.0 * 1.0) / (4.0 * tan(M_PI / 5.0));
    EXPECT_NEAR(p.calculateArea(), area, 1e-10);
}
TEST(test_9, PentagonEq){
    Pentagon p1(6, 2, 3);
    Pentagon p2(4, 0, 0);
    Pentagon p3(6, 2, 3);
    EXPECT_TRUE(p1.operator== (p3));
    EXPECT_FALSE(p1.operator== (p2));
}
TEST(test_10, EmptyTotalArea){
    std::vector<std::unique_ptr<Figure>> figures;
    EXPECT_DOUBLE_EQ(calculateTotalArea(figures), 0.0);
}
TEST(test_11, TotalArea){
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Trapezoid>(4, 2, 3, 0, 0));
    figures.push_back(std::make_unique<Rhombus>(4, 5, 0, 0));
    double area = (5.0 * 1.0) / (4.0 * tan(M_PI / 5.0));
    figures.push_back(std::make_unique<Pentagon>(1.0, 0, 0));
    double total = 9.0 + 10.0 + area;
    EXPECT_NEAR(calculateTotalArea(figures), total, 1e-10);
    removeFigureByIndex(figures, 1);
    EXPECT_NEAR(calculateTotalArea(figures), total - 10.0, 1e-10);
}
TEST(test_12, TrapezoidCopy){
    Trapezoid t1(4, 2, 3, 1, 1);
    Trapezoid t2(0,0,0,0,0);
    t2 = t1;
    EXPECT_TRUE(t1.operator== (t2));
}
TEST(test_13, ZeroArea){
    Trapezoid t(0, 0, 0, 0, 0);
    Rhombus r(0, 0, 0,0);
    Pentagon p(0,0,0);
    EXPECT_DOUBLE_EQ(t.calculateArea(), 0.0);
    EXPECT_DOUBLE_EQ(r.calculateArea(), 0.0);
    EXPECT_DOUBLE_EQ(p.calculateArea(), 0.0);
}