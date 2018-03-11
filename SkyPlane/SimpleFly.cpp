#pragma once
#include "FlyBehavior.h"
#include "SimpleFly.h"
#include "Point.h"
#include "Resource.h"


SimpleFly::SimpleFly(Point& a,double sp):FlyBehavior(a),sp_(sp){};

SimpleFly::~SimpleFly() {};

void SimpleFly::Fly() 
{
	a_->MoveY(sp_);
}