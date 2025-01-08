#pragma once
#ifndef INCLUDED_APPTESTLIST_H
#define INCLUDED_APPTESTLIST_H

#include "Commands.h"
#include "Interface.h"
#include "ClassList.h"

class AppTestList
{
public:
   void run();
   Interface& getUI() { return ui; }

private:
   Commands* actualcmd;
   Interface ui;
};

extern AppTestList app;

#endif