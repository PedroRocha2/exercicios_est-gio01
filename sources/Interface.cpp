#include "Interface.h"
#include <iostream>
#include <string>

int Interface::clientDecision() const 
{  
   int selector;
   std::cout << "Escolha uma operação\n"
             << "1 - Adicionar\n"
             << "2 - Listar\n"
             << "3 - Deletar\n"
             << "4 - Ordenar\n"
             << "5 - Concatenar\n"
             << "6 - Esvaziar\n"
             << "7 - Parar\n";

   std::cin >> selector;
   
   system("cls");
   return selector;
}

int Interface::addStudentDecision() const
{
   int choice;

   std::cout << "Deseja adicionar aonde?\n"
             << "1 - Adicionar no inicio\n"
             << "2 - Adicionar no fim\n"
             << "3 - Adicionar no indice\n";
   std::cin >> choice;

   system("cls");
   return choice;
}

Student* Interface::createStudent() 
{
   std::string name;
   int age;

   std::cout << "Digite seu nome" << std::endl;
   std::cin >> name;
   std::cout << "Digite sua idade" << std::endl;
   std::cin >> age;

   system("cls");
   return new Student(name,age);
}

int Interface::indiceDecision() const 
{
   int indice;

   std::cout << "Qual o indice?:" << std::endl;
   std::cin >> indice;

   system("cls");
   return indice;
}

int Interface::printStudentDecision() const 
{
   int choice;

   std::cout << "1 - listar do inicio\n"
             << "2 - listar do fim\n";
   std::cin >> choice;

   return choice;
}

int Interface::deleteStudentDecision() const 
{
   int choice;

   std::cout << "1 - Deleter no inicio\n"
             << "2 - Deletar no fim\n"
             << "3 - Deletar no indice\n";
   std::cin >> choice;

   system("cls");
   return choice;
}

int Interface::concateDecision() const 
{
   int choice;
   
   std::cout << "1 - Concatenar A + B\n"
             << "2 - Concatenar B + A\n";
   std::cin >> choice;
   
   system("cls");
   return choice;
}

int Interface::classListDecision() const
{
   int choice;

   std::cout << "1 - Turma A\n"
             << "2 - Turma B\n";
   std::cin >> choice;

   system("cls");
   return choice;
}