#include "AppTestList.h"

AppTestList app;

static void newCommand(Commands* actualcmd, ClassList& class_a, ClassList& class_b)
{
   if (actualcmd)
      actualcmd->execute(class_a, class_b);

   delete actualcmd;
}

void AppTestList::run() 
{
   bool loop= true;
   ClassList class_a, class_b;

   while (loop) {
      switch (app.getUI().clientDecision()) {
      case 1: newCommand(new CommandsAddStudent, class_a, class_b); break;

      case 2: newCommand(new CommandsPrintStudent, class_a, class_b); break;

      case 3: newCommand(new CommandsDeleteStudent, class_a, class_b); break;

      case 4: newCommand(new CommandsOrderAlphabet, class_a, class_b); break;

      case 5: newCommand(new CommandsConcate, class_a, class_b); break;

      case 6: newCommand(new CommandsCleanClassList, class_a, class_b); break;

      case 7: loop= false; break;
      
      }  
   }
}