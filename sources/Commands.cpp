#include "Commands.h"
#include "AppTestList.h"
#include "ClassList.h"

ClassList& getSelectedClassList(int choice, ClassList& class_a, ClassList& class_b)
{
   return (choice == 1) ? class_a : class_b;
}

void CommandsAddStudent::execute(ClassList& class_a, ClassList& class_b)
{
   Student* newStudent= app.getUI().createStudent();
   ClassList::Nodelist* nl= new ClassList::Nodelist(*newStudent);
   int choice= app.getUI().classListDecision();
   ClassList& selected_list= getSelectedClassList(choice, class_a, class_b);

   switch (app.getUI().addStudentDecision()) {
   case 1:
      if (selected_list.initial_element) {
         nl->next= selected_list.initial_element;
         nl->prev= nullptr;
         selected_list.initial_element->prev= nl;
         selected_list.initial_element= nl;
      }
      else {
         selected_list.initial_element= selected_list.final_element= selected_list.cursor= nl;
         nl->prev= nl->next= nullptr;
      }

      break;

   case 2:
      if (selected_list.final_element) {
         nl->prev= selected_list.final_element;
         nl->next= nullptr;
         selected_list.final_element->next = nl;
         selected_list.final_element= nl;
      }

      else {
         selected_list.initial_element= selected_list.final_element= selected_list.cursor= nl;
         nl->prev= nl->next= nullptr;
      }
      
      break;

   case 3:
      int indice= app.getUI().indiceDecision();

      int parameter= selected_list.cont / 2;

      if (indice > parameter) {
         ClassList::Nodelist* temp= selected_list.final_element;
         for (int i= selected_list.cont; i > indice; i--) {
            temp= temp->prev;
         }
         nl->prev= temp->prev;
         nl->next= temp;
         if (temp->prev) {
            temp->prev->next= nl;
         }
         temp->prev= nl;
      }

      else {
         ClassList::Nodelist* temp= selected_list.initial_element;
         for (int i= 0; i < indice; i++) {
            temp= temp->next;
         }
         nl->next= temp;
         nl->prev= temp->prev;
         if (temp->prev) {
            temp->prev->next= nl;
         }
         temp->prev= nl;
      }
      
      break;
   }
   selected_list.cont++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CommandsPrintStudent::execute(ClassList& class_a,ClassList& class_b)
{
   int choice= app.getUI().classListDecision();
   ClassList& selected_list= getSelectedClassList(choice,class_a,class_b);

   switch (app.getUI().printStudentDecision()) {
   case 1: {
      ClassList::Nodelist* temp = selected_list.initial_element;

      while (temp != nullptr) {
         temp->s.PrintInfo();
         temp = temp->next;
      }
      break;
   }
   case 2: {
      ClassList::Nodelist* temp = selected_list.final_element;

      while (temp != nullptr) {
         temp->s.PrintInfo();
         temp = temp->prev;
      }
      break;
   }
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CommandsDeleteStudent::execute(ClassList& class_a,ClassList& class_b)
{
   int choice= app.getUI().classListDecision();
   ClassList& selected_list= getSelectedClassList(choice,class_a,class_b);

   switch (app.getUI().deleteStudentDecision()) {
   case 1: {
      if (selected_list.initial_element) {
         ClassList::Nodelist* temp = selected_list.initial_element->next;
         delete selected_list.initial_element;
         selected_list.initial_element = temp;
         if (temp) {
            temp->prev = nullptr;
         }
         else {
            selected_list.final_element = nullptr;
         }
      }
      break;
   }
   case 2: {
      if (selected_list.final_element) {
         ClassList::Nodelist* temp = selected_list.final_element->prev;
         delete selected_list.final_element;
         selected_list.final_element = temp;
         if (temp) {
            temp->next = nullptr;
         }
         else {
            selected_list.initial_element = nullptr; 
         }
      }
      break;
   }
   case 3: {
      int indice = app.getUI().indiceDecision();
      if (indice < 0 || indice >= selected_list.cont) {
         std::cerr << "Índice fora do intervalo!" << std::endl;
         break;
      }

      ClassList::Nodelist* choose = nullptr;
      int parameter = selected_list.cont / 2;

      if (indice > parameter) {
         choose = selected_list.final_element;
         for (int i = selected_list.cont - 1; i > indice; i--) {
            choose = choose->prev;
         }
      }
      else {
         choose = selected_list.initial_element;
         for (int i = 0; i < indice; i++) {
            choose = choose->next;
         }
      }

      if (choose) {
         if (choose->prev) {
            choose->prev->next = choose->next;
         }
         else {
            selected_list.initial_element = choose->next;
         }

         if (choose->next) {
            choose->next->prev = choose->prev;
         }
         else {
            selected_list.final_element = choose->prev;
         }

         delete choose;
      }
      break;
   }
   }

   if (selected_list.cont > 0) {
      selected_list.cont--;
   }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CommandsOrderAlphabet::execute(ClassList& class_a,ClassList& class_b)
{
   int choice= app.getUI().classListDecision();
   ClassList& selected_list= getSelectedClassList(choice,class_a,class_b);
   
   bool swapped; 
   do {
      swapped= false;
      ClassList::Nodelist* current= selected_list.initial_element;
      while (current->next != nullptr) {
         if (current->s.getName() > current->next->s.getName()) {
            std::swap(current->s,current->next->s);
            swapped= true;
         }
         current= current->next;
      }
   } while (swapped);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CommandsConcate::execute(ClassList& class_a,ClassList& class_b)
{
   int choice= app.getUI().classListDecision();
   ClassList& selected_list= getSelectedClassList(choice,class_a,class_b);

   switch (app.getUI().concateDecision()) {
   case 1:
      selected_list.final_element->next= class_b.initial_element;
      class_b.initial_element->prev= selected_list.final_element;
      class_b.initial_element= nullptr;
      class_b.final_element= nullptr;

      break;
   case 2:
      selected_list.final_element->next= class_a.initial_element;
      class_a.initial_element->prev= selected_list.final_element;
      class_a.initial_element= nullptr;
      class_a.final_element= nullptr;

      break;
   }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CommandsCleanClassList::execute(ClassList& class_a, ClassList& class_b)
{
   int choice= app.getUI().classListDecision();
   ClassList& selected_list= getSelectedClassList(choice,class_a,class_b);

   ClassList::Nodelist* temp= selected_list.initial_element;

   while (temp->next != nullptr) {
      ClassList::Nodelist* actual= temp;
      temp= temp->next;
      delete actual;
   }
}