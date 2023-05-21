#include <gtest/gtest.h>

#include <class/Workers.h>

using namespace workers;

TEST(EmployeeTests, calculating) {

    EmployeePtr worker1 = Employee::create(Type::Laboratory, Name::нно, 1, 1);
    float result = worker1->calcul();
    std::cout << worker1;
    EXPECT_EQ(result, 2);
}

