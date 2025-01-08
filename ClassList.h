#pragma once
#ifndef INCLUDED_CLASSLIST_H
#define INCLUDED_CLASSLIST_H

#include "Students.h"
#include "Commands.h"

class ClassList
{
public:
   struct Nodelist {
      Student s;
      Nodelist* next= nullptr;
      Nodelist* prev= nullptr;

      Nodelist(Student s) : s(s) {}
   };

   Nodelist* initial_element= nullptr;
   Nodelist* cursor= nullptr;
   Nodelist* final_element= nullptr;
   int cont;
};

#endif