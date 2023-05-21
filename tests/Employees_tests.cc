#include <gtest/gtest.h>

#include <class/Workers.h>

using namespace workers;

TEST(EmployeesTests, search_max_salary1)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create(Type::Laboratory, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Laboratory, Name::Физра, 100, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    ASSERT_EQ(search_max_by_name(_Worker, Name::Физра), 400);
}

TEST(EmployeesTests, addPerson)
{
    Employees _Worker;
    Employee person();
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    const auto getting_size = _Worker.get_size();
    EXPECT_EQ(getting_size, 1);
}
TEST(EmployeesTests, deletePersonGood1)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));

    _Worker.delete_person(0);

    const auto get_size = _Worker.get_size();

    EXPECT_EQ(get_size, 1);
}
TEST(EmployeesTests, insertPerson)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.insert_person(Employee::create(Type::Practic, Name::История, 10, 2), 0);
    EXPECT_EQ(_Worker[0]->get_name(), Name::История);
}

TEST(EmployeesTests, search_max)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    ASSERT_EQ(search_max_by_name(_Worker, Name::ООП), 60);
}

TEST(EmployeesTests, insertPerson1)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.add_worker(Employee::create(Type::Practic, Name::ООП, 10, 2));
    _Worker.insert_person(Employee::create(Type::Practic, Name::История, 10, 2) , 1);
    EXPECT_EQ(_Worker[1]->get_name(), Name::История);
    EXPECT_EQ(_Worker[0]->get_name(), Name::ООП);
}
/*TEST(EmployeesTests, CapacityAddWorkerRange1) {
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    ASSERT_ANY_THROW(_Worker.change_data(worker1, 2));
}
TEST(EmployeesTests, CapacityAddWorkerRange2) {
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    EXPECT_ANY_THROW(_Worker.change_data(worker1, 5), std::out_of_range);
}*/