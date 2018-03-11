#pragma once;
#include "Weapon.h"
#include "FlyObject.h"

Weapon::Weapon(int h, int w, Point p) :FlyObject(h, w, p) {}
Weapon::~Weapon(){}

//set
void Weapon::Power(int x) { power_ = x; }

//get
int Weapon::Power() { return power_; }