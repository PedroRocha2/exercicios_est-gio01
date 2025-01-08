#pragma once
#ifndef INCLUDED_COMMANDS_H
#define INCLUDED_COMMANDS_H
#include "ClassList.h"

class Commands
{
public:
   virtual void execute(ClassList& class_a,  ClassList& class_b)= 0;
};

////////////////////////////////////////////////

class CommandsAddStudent : public Commands
{
public:
   void execute(ClassList& class_a, ClassList& class_b);
};

////////////////////////////////////////////////

class CommandsPrintStudent : public Commands
{
public:
   void execute(ClassList& class_a, ClassList& class_b);
};

//////////////////////////////////////////////// 

class CommandsDeleteStudent : public Commands
{
public:
   void execute(ClassList& class_a, ClassList& class_b);
};


//////////////////////////////////////////////

class CommandsOrderAlphabet : public Commands
{
public:
   void execute(ClassList& class_a, ClassList& class_b);
};

/////////////////////////////////////////////

class CommandsConcate : public Commands
{
public:
   void execute(ClassList& class_a,ClassList& class_b);
};

/////////////////////////////////////////////

class CommandsCleanClassList : public Commands
{
public:
   void execute(ClassList& class_a, ClassList& class_b);
};

#endif