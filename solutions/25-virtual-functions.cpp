/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
public:
    virtual void getdata() {
        std::cin >> name >> age;
    }
    virtual void putdata() {
        std::cout << name << " " << age << " ";
    }
};

class Professor : public Person {
private:
    int publications;
    static int cur_id;
    int loc_id;
public:
    Professor() {
        cur_id++;
        loc_id = cur_id;
    }
    void getdata() override {
        Person::getdata();
        std::cin >> publications;
    }
    void putdata() override {
        Person::putdata();
        std::cout << publications << " " << loc_id << std::endl;
    }
};

class Student : public Person {
private:
    int marks[6];
    static int cur_id;
    int loc_id;
public:
    Student() {
        cur_id++;
        loc_id = cur_id;
    }
    void getdata() override {
        Person::getdata();
        for(int i = 0; i < 6; ++i)
            std::cin >> marks[i];
    }
    void putdata() override {
        Person::putdata();
        int sum = 0;
        for(int i = 0; i < 6; ++i)
            sum += marks[i];
        std::cout << sum << " " << loc_id << std::endl;
    }
};

int Professor::cur_id = 0;
int Student::cur_id = 0;

int main(){
    int n, val;
    std::cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++) {
        std::cin >> val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else per[i] = new Student; // Else the current object is of type Student
        per[i]->getdata(); // Get the data from the user.
    }

    for(int i=0; i<n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
} // end of main
