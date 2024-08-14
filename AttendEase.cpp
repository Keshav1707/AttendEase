#include <iostream>
#include <string>
#include <map>
#include <memory>

// Abstract Base class for entities with an ID and a name
class Entity
{
public:
    Entity(int id, const std::string &name) : id(id), name(name) {}
    virtual ~Entity() = default; // Virtual destructor for proper cleanup of derived classes

    int getId() const { return id; }
    std::string getName() const { return name; }

protected:
    void setName(const std::string &newName) { name = newName; }

private:
    int id;
    std::string name;
};

// Abstract base class for attendance entities
class AttendanceEntity : public Entity
{
public:
    AttendanceEntity(int id, const std::string &name) : Entity(id, name) {}
    virtual void markAttendance() = 0;     // Pure virtual function
    virtual int getAttendance() const = 0; // Pure virtual function
};

// Subject class inheriting from AttendanceEntity
class Subject : public AttendanceEntity
{
public:
    Subject(const std::string &name) : AttendanceEntity(-1, name), attendanceCount(0) {}

    void markAttendance() override
    {
        ++attendanceCount;
    }

    int getAttendance() const override
    {
        return attendanceCount;
    }

private:
    int attendanceCount;
};

// Student class inheriting from Entity
class Student : public Entity
{
public:
    Student(int id, const std::string &name) : Entity(id, name) {}

    void addSubject(const std::string &subjectName)
    {
        subjects.emplace(subjectName, Subject(subjectName));
    }

    void markAttendance(const std::string &subjectName)
    {
        auto it = subjects.find(subjectName);
        if (it != subjects.end())
        {
            it->second.markAttendance();
        }
    }

    int getAttendance(const std::string &subjectName) const
    {
        auto it = subjects.find(subjectName);
        if (it != subjects.end())
        {
            return it->second.getAttendance();
        }
        return 0;
    }

    void displayDetails() const
    {
        std::cout << "Student ID: " << getId() << ", Name: " << getName() << std::endl;
        for (const auto &subject : subjects)
        {
            std::cout << "  Subject: " << subject.first
                      << ", Attendance: " << subject.second.getAttendance() << std::endl;
        }
    }

private:
    std::map<std::string, Subject> subjects;
};

// AttendanceManager class
class AttendanceManager
{
public:
    void addStudent(int id, const std::string &name)
    {
        students.emplace(id, Student(id, name));
    }

    void addSubjectToStudent(int id, const std::string &subjectName)
    {
        auto it = students.find(id);
        if (it != students.end())
        {
            it->second.addSubject(subjectName);
        }
    }

    void markStudentAttendance(int id, const std::string &subjectName)
    {
        auto it = students.find(id);
        if (it != students.end())
        {
            it->second.markAttendance(subjectName);
        }
    }

    int getStudentAttendance(int id, const std::string &subjectName) const
    {
        auto it = students.find(id);
        if (it != students.end())
        {
            return it->second.getAttendance(subjectName);
        }
        return 0;
    }

    void displayAllStudents() const
    {
        for (const auto &student : students)
        {
            student.second.displayDetails();
        }
    }

private:
    std::map<int, Student> students;
};

// Main function
int main()
{
    AttendanceManager manager;
    int choice;

    do
    {
        std::cout << "\n===== Attendance Management System =====\n";
        std::cout << "1. Add a new student\n";
        std::cout << "2. Add a subject to a student\n";
        std::cout << "3. Mark attendance\n";
        std::cout << "4. Get attendance for a student\n";
        std::cout << "5. Display all students\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            std::string name;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            manager.addStudent(id, name);
            std::cout << "Student added successfully.\n";
            break;
        }
        case 2:
        {
            int id;
            std::string subject;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter subject name: ";
            std::cin.ignore();
            std::getline(std::cin, subject);
            manager.addSubjectToStudent(id, subject);
            std::cout << "Subject added to student successfully.\n";
            break;
        }
        case 3:
        {
            int id;
            std::string subject;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter subject name: ";
            std::cin.ignore();
            std::getline(std::cin, subject);
            manager.markStudentAttendance(id, subject);
            std::cout << "Attendance marked successfully.\n";
            break;
        }
        case 4:
        {
            int id;
            std::string subject;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter subject name: ";
            std::cin.ignore();
            std::getline(std::cin, subject);
            int attendance = manager.getStudentAttendance(id, subject);
            std::cout << "Attendance for student " << id << " in " << subject << ": " << attendance << "\n";
            break;
        }
        case 5:
            manager.displayAllStudents();
            break;
        case 0:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
