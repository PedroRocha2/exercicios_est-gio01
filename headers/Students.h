#ifndef INCLUDED_STUDENTS_H
#define INCLUDED_STUDENTS_H
#include <string>
#include <iostream>

class Student
{
public:
   Student(const std::string& name,const int& age); 
   ~Student();

public: 
   void PrintInfo() const {
      std::cout << name << std::endl;
      std::cout << age << std::endl;
   }

   std::string getName() const {return name;}
   int getAge() const { return age; }

private:
   std::string name;
   int age;
};
  
#endif // INCLUDED_STUDENTS_H

