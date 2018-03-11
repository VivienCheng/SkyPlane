#pragma once
#include "FlyNoWay.h"
#include "FlyBehavior.h"

FlyNoWay::FlyNoWay(Point& p):FlyBehavior(p){};
FlyNoWay::~FlyNoWay() {}
void FlyNoWay::Fly() {};