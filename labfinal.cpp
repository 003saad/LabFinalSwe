#include <iostream>
#include <list>
#include <string>
#include <gtest/gtest.h>
using namespace std;

class Student {
    int id; string name;
public:
    Student(int id = 0, string name = "") : id(id), name(name) {}
    int getId() const { return id; }
    string getName() const { return name; }
};

class StudentManager {
    list<Student> students;
    static StudentManager* instance;
    StudentManager() {}
public:
    static StudentManager* getInstance() {
        if (!instance) instance = new StudentManager();
        return instance;
    }
    void addStudent(const Student& s) { students.push_back(s); }
    bool removeStudent(int id) {
        auto it = find_if(students.begin(), students.end(), [id](const Student& s) { return s.getId() == id; });
        if (it != students.end()) { students.erase(it); return true; }
        return false;
    }
    void display() const {
        for (const auto& s : students) 
            cout << s.getName() << " (ID: " << s.getId() << ")\n";
    }
    void clear() { students.clear(); }
    size_t count() const { return students.size(); }
    bool has(int id) const {
        return any_of(students.begin(), students.end(), [id](const Student& s) { return s.getId() == id; });
    }
    Student get(int id) const {
        auto it = find_if(students.begin(), students.end(), [id](const Student& s) { return s.getId() == id; });
        return it != students.end() ? *it : Student();
    }
};
StudentManager* StudentManager::instance = nullptr;

TEST(StudentManagerTest, AddStudent) {
    auto* manager = StudentManager::getInstance();
    manager->clear();
    manager->addStudent(Student(1, "A Ahmed"));
    EXPECT_EQ(manager->count(), 1);
    EXPECT_TRUE(manager->has(1));
    EXPECT_EQ(manager->get(1).getName(), "A Ahmed");
}

TEST(StudentManagerTest, RemoveStudent) {
    auto* manager = StudentManager::getInstance();
    manager->clear();
    manager->addStudent(Student(1, "A Ahmed"));
    manager->addStudent(Student(2, "B Ahmed"));
    EXPECT_EQ(manager->count(), 2);
    EXPECT_TRUE(manager->removeStudent(1));
    EXPECT_EQ(manager->count(), 1);
    EXPECT_FALSE(manager->has(1));
    EXPECT_TRUE(manager->has(2));
}

int main(int argc, char** argv) {
    auto* manager = StudentManager::getInstance();
    manager->addStudent(Student(1, "Abul"));
    manager->addStudent(Student(2, "Kabul"));
    manager->addStudent(Student(3, "Babul"));
    cout << "Initial students:\n"; manager->display();
    manager->removeStudent(2);
    cout << "\nAfter removing ID 2:\n"; manager->display();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}