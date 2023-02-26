// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

// Ваші файли загловки 
//
#include "Lab5Exmaple.h"
int main()
{
    std::cout << " Lab #5  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    if (chain == 4) chain = mainExample4();
    if (chain == 5) chain = mainExample5();


//lab5 task1
#include <iostream>
#include <string>
using namespace std;

class Human {
    string name;
    int age;
    float weight;
public:
    Human() {
        name = "Unknown";
        age = 0;
        weight = 0;
    }
    Human(string n, int a, float w) {
        name = n;
        age = a;
        weight = w;
    }
    ~Human() {
        cout << "Destructor called for Human" << endl;
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }
    void setAge(int a) {
        age = a;
    }
};

class Schoolkid : public Human {
    string grade;
public:
    Schoolkid() : Human() {
        grade = "Unknown";
    }
    Schoolkid(string n, int a, float w, string g) : Human(n, a, w) {
        grade = g;
    }
    ~Schoolkid() {
        cout << "Destructor called for Schoolkid" << endl;
    }
    void print() {
        Human::print();
        cout << "Grade: " << grade << endl;
    }
    void setAge(int a) {
        Human::setAge(a);
        if (a < 6) {
            grade = "Kindergarten";
        }
        else if (a >= 6 && a < 13) {
            grade = "Elementary school";
        }
        else if (a >= 13 && a < 16) {
            grade = "Middle school";
        }
        else if (a >= 16 && a < 19) {
            grade = "High school";
        }
        else {
            grade = "College/University";
        }
    }
};

int main() {
    Human h1("John Smith", 30, 75.5);
    h1.print();
    cout << endl;
    
    Schoolkid s1("Emily Jones", 10, 40, "Grade 5");
    s1.print();
    cout << endl;
    
    s1.setAge(12);
    s1.print();
    cout << endl;
    
    return 0;
}

//task2

#include <iostream>
using namespace std;

class Window {
public:
    virtual void draw() {
        cout << "Window" << endl;
    }
};

class TitledWindow : public Window {
public:
    void draw() {
        cout << "Titled Window" << endl;
    }
};

class ButtonWindow : public TitledWindow {
public:
    void draw() {
        cout << "Button Window" << endl;
    }
};

int main() {
    Window* w1 = new Window();
    w1->draw();
    delete w1;
    cout << endl;

    Window* w2 = new TitledWindow();
    w2->draw();
    delete w2;
    cout << endl;

    Window* w3 = new ButtonWindow();
    w3->draw();
    delete w3;
    cout << endl;

    return 0;
}

//task 3
// Оголошення класу "Студент"
class Student {
public:
// Конструктор за замовчуванням
Student() {}
// Конструктор з параметрами
Student(std::string name, int age, std::string group)
    : name_(name), age_(age), group_(group) {}

// Конструктор копіювання
Student(const Student& other)
    : name_(other.name_), age_(other.age_), group_(other.group_) {}

// Оператор присвоювання
Student& operator=(const Student& other) {
    if (this != &other) {
        name_ = other.name_;
        age_ = other.age_;
        group_ = other.group_;
    }
    return *this;
}

// Деструктор
virtual ~Student() {}

// Функції для отримання значень полів
std::string getName() const { return name_; }
int getAge() const { return age_; }
std::string getGroup() const { return group_; }

// Функція для виведення даних у потік
virtual void print(std::ostream& os) const {
    os << "Name: " << name_ << std::endl;
    os << "Age: " << age_ << std::endl;
    os << "Group: " << group_ << std::endl;
}

// Функція для введення даних з потоку
virtual void read(std::istream& is) {
    std::cout << "Enter name: ";
    is >> name_;
    std::cout << "Enter age: ";
    is >> age_;
    std::cout << "Enter group: ";
    is >> group_;
}
private:
std::string name_;
int age_;
std::string group_;
};

// Оголошення класу "Студент дипломник"
class GraduateStudent : public Student {
public:
// Конструктор за замовчуванням
GraduateStudent() {}

// Конструктор з параметрами
GraduateStudent(std::string name, int age, std::string group, std::string thesis)
    : Student(name, age, group), thesis_(thesis) {}

// Конструктор копіювання
GraduateStudent(const GraduateStudent& other)
    : Student(other), thesis_(other.thesis_) {}

// Оператор присвоювання
GraduateStudent& operator=(const GraduateStudent& other) {
    if (this != &other) {
        Student::operator=(other);
        thesis_ = other.thesis_;
    }
    return *this;
}

// Функція для виведення даних у потік
void print(std::ostream& os) const override {
    Student::print(os);
    os << "Thesis: " << thesis_ << std::endl;
}

// Функція для введення даних з потоку
void read(std::istream& is) override {
    Student::read(is);
    std::cout << "Enter thesis: ";
    is >> thesis_;
}
private:
std::string thesis_;
};

int main() {
// Створення об'єкту класу "Студент"
}
}
