#include "PlayerTrackFly.h"
#include "FlyBehavior.h"
#include "Point.h"
#include "EnemyPlane.h"
#include "Resource.h"
#include "GameObject.h"


PlayerTrackFly::PlayerTrackFly(Point& a, EnemyPlane& t,double c,double b):FlyBehavior(a),tar_(&t),xp_(c),yp_(b)
{
	num = 0;
}
PlayerTrackFly::~PlayerTrackFly() {}



void PlayerTrackFly::Fly()
{
	Point tarPos(0, 0);
	if (tar_ != NULL)
	{
		tarPos = *(tar_->Position());
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
		
	}
}