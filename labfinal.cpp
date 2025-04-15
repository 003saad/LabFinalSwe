# include<iostream>
#include<bits/stdc++.h>
#include<gtest/gtest.h>

using namespace std;

class Student {
private:
    int id;
    string name;
public:
    Student(int id = 0, string name = "") : id(id), name(name) {}
    
    int getId() const {
        return id;
    }
    
    string getName() const {
        return name;
    }
    
    void setId(int newId) {
        id = newId;
    }
    
    void setName(string newName) {
        name = newName;
    }
};
class StudentManager {
private:
    list<Student> students;
    
    StudentManager() {}
    
    static StudentManager* instance;
    
    StudentManager(const StudentManager&) = delete;
    StudentManager& operator=(const StudentManager&) = delete;
    
public:
    static StudentManager* getInstance() {
        if (instance == nullptr) {
            instance = new StudentManager();
        }
        return instance;
    }
    
    void addStudent(const Student& student) {
        students.push_back(student);
    }
    bool removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                return true;
            }
        }
        return false;
    }
    void displayStudentNames() const {
        cout << "Student List:" << endl;
        for (const auto& student : students) {
            cout << "- " << student.getName() << " (ID: " << student.getId() << ")" << endl;
        }
    }
    
    void clear() {
        students.clear();
    }
    
    size_t getStudentCount() const {
        return students.size();
    }

    bool hasStudent(int id) const {
        for (const auto& student : students) {
            if (student.getId() == id) {
                return true;
            }
            e
        }
        return false;
    }
    Student getStudent(int id) const {
        for (const auto& student : students) {
            if (student.getId() == id) {
                return student;
            }
        }
        return Student();
    }
};

StudentManager* StudentManager::instance = nullptr;

TEST(StudentManagerTest, AddStudent) {
    StudentManager* manager = StudentManager::getInstance();
    manager->clear();
    
    Student student1(1, "A ahmed");
    manager->addStudent(student1);
    
    EXPECT_EQ(manager->getStudentCount(), 1);
    EXPECT_TRUE(manager->hasStudent(1));
    EXPECT_EQ(manager->getStudent(1).getName(), "A ahmed");
}

TEST(StudentManagerTest, RemoveStudent) {
    StudentManager* manager = StudentManager::getInstance();
    manager->clear();
    
    Student student1(1, "A ahmed");
    Student student2(2, "B Ahmed");
    manager->addStudent(student1);
    manager->addStudent(student2);
    
    EXPECT_EQ(manager->getStudentCount(), 2);
    
    bool result = manager->removeStudent(1);
    
    EXPECT_TRUE(result);
    EXPECT_EQ(manager->getStudentCount(), 1);
    EXPECT_FALSE(manager->hasStudent(1));
    EXPECT_TRUE(manager->hasStudent(2));
}

