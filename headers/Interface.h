#pragma once
#ifndef INCLUDED_INTERFACE_H
#define INCLUDED_INTERFACE_H

#include "Students.h"

class Interface
{
public:
   int deleteStudentDecision() const;
   int printStudentDecision() const;
   int addStudentDecision() const;
   int classListDecision() const;
   int concateDecision() const;
   int clientDecision() const;
   int indiceDecision() const;
   Student* createStudent();  
};

#endif