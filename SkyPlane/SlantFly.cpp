#pragma once
#include "FlyBehavior.h"
#include "SlantFly.h"
#include "Point.h"
#include "Resource.h"


SlantFly::SlantFly(Point& a, double xp,double yp):FlyBehavior(a), xp_(xp),yp_(yp) {};

SlantFly::~SlantFly() {};

void SlantFly::Fly()
{
	a_->MoveX(xp_ );
	a_->MoveY(yp_);
}