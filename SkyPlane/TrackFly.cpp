#include "TrackFly.h"
#include "Point.h"
#include "FlyBehavior.h"
#include "Resource.h"


TrackFly::TrackFly(Point& p,Point& t,double a,double b):FlyBehavior(p),tar_(&t),xp_(a),yp_(b)
{
	num = 0;
}
TrackFly::~TrackFly() {};
void TrackFly::Fly()
{
	num++;
	if (num <= 200) {
		if (tar_->X() == 0 && tar_->Y() == 0)
		{
			a_->MoveY(-yp_);
		}
		else {
			if (a_->X() < tar_->X())
			{
				a_->MoveX(xp_);
			}
			else if (a_->X() > tar_->X())
			{
				a_->MoveX(-xp_);
			}
			if (a_->Y() < tar_->Y())
			{
				a_->MoveY(yp_);
			}
			else if (a_->Y() > tar_->Y())
			{
				a_->MoveY(-yp_);
			}
		}
	}
	else {
		a_->MoveX(xp_);
		a_->MoveY(yp_);
	}
}
