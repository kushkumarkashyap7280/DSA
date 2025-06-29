// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;

class Animal
{
public:
  string name;
  Animal(string n);
  virtual void speak();
};

#endif // ANIMAL_H
