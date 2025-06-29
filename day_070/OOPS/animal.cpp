// animal.cpp
#include "animal.h"
#include <iostream>
using namespace std;

Animal::Animal(string n) : name(n) {}

void Animal::speak()
{
  cout << name << " makes a sound." << endl;
}
