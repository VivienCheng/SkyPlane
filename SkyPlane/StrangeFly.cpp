#pragma once
#include "FlyBehavior.h"
#include "StrangeFly.h"
#include "Point.h"
#include "Resource.h"


StrangeFly::StrangeFly(Point& a, double xp, double yp,int op,double h):FlyBehavior(a), xp_(xp), yp_(yp), op_(op),height_(h)
{
	first = FALSE;
	second = FALSE;
	third = FALSE;
	forth = FALSE;
	fifth = FALSE;

}

StrangeFly::~StrangeFly() {};

void StrangeFly::Fly()
{
	if (op_ == 1)
	{
		if (a_->Y() > 0 && a_->Y() < Game_Height  - 100) {
			if (a_->X() > 5 && a_->X() < Game_Width / 3)
			{
				if (first == FALSE)
				{
					a_->MoveX(-xp_);
					a_->MoveY(-yp_ + 0.25);
				}
				else if (first == TRUE)
				{
					a_->MoveX(xp_);
					a_->MoveY(-yp_ + 0.25);
				}
			}
			if (a_->X() <= 5) {
				first = TRUE;
				a_->MoveX(xp_);
				a_->MoveY(-yp_ + 0.25);
			}
			if (a_->X() >= Game_Width / 3)
			{
				first = FALSE;
				a_->MoveX(-xp_);
				a_->MoveY(-yp_ + 0.25);
			}
		}
		else if (a_->Y() <= 0)
		{
			yp_ = -yp_;
			first = TRUE;
			a_->MoveX(-xp_);
			a_->MoveY(-yp_ + 0.25);
		}
		else if (a_->Y() >= Game_Height - 100)
		{ 
			yp_ = -yp_;
			first = FALSE;
			a_->MoveX(xp_);
			a_->MoveY(-yp_ + 0.25);
		}
	}
	else if (op_ == 2)
	{
		if (a_->Y() > 0 && a_->Y() < Game_Height - 100) {
			if (a_->X() > Game_Width / 3 * 2 && a_->X() < Game_Width - 60)
			{
				if (second == FALSE)
				{
					a_->MoveX(xp_);
					a_->MoveY(-yp_ + 0.25);
				}
				else if (second == TRUE)
				{
					a_->MoveX(-xp_);
					a_->MoveY(-yp_ + 0.25);
				}
			}

			if (a_->X() <= Game_Width / 3 * 2) {
				second = FALSE;
				a_->MoveX(xp_);
				a_->MoveY(-yp_ + 0.25);
			}
			if (a_->X() >= Game_Width - 60) {
				second = TRUE;
				a_->MoveX(-xp_);
				a_->MoveY(-yp_ + 0.25);
			}
		}
		else if (a_->Y() <= 0)
		{
			yp_ = -yp_;
			second = TRUE;//true
			a_->MoveX(-xp_);//-
			a_->MoveY(-yp_ + 0.25);
		}
		else if (a_->Y() >= Game_Height - 100)
		{
			yp_ = -yp_;
			second = FALSE;//false
			a_->MoveX(xp_);//+
			a_->MoveY(-yp_ + 0.25);
		}
	}
	else if (op_ == 5)
	{
		if (a_->Y() > 0 && a_->Y() < Game_Height - 313) {
			if (a_->X() > 0 && a_->X() < Game_Width - (81+81+223))
			{
				if (third == FALSE)
				{
					a_->MoveX(-xp_);
					a_->MoveY(-yp_ + 0.25);
				}
				else if (third == TRUE)
				{
					a_->MoveX(xp_);
					a_->MoveY(-yp_ + 0.25);
				}
			}
			if (a_->X() <= 0) {
				third = TRUE;
				a_->MoveX(xp_);
				a_->MoveY(-yp_ + 0.25);
			}
			if (a_->X() >= Game_Width - (81 + 81 + 223))
			{
				third = FALSE;
				a_->MoveX(-xp_);
				a_->MoveY(-yp_ + 0.25);
			}
		}
		else if (a_->Y() <= 0)
		{
			yp_ = -yp_;
			third = TRUE;
			a_->MoveX(-xp_);
			a_->MoveY(-yp_ + 0.25);
		}
		else if (a_->Y() >= Game_Height - 313)
		{
			yp_ = -yp_;
			third = FALSE;
			a_->MoveX(xp_);
			a_->MoveY(-yp_ + 0.25);
		}
	}
	else if (op_ == 6)
	{
		if (a_->Y() > 0 && a_->Y() < Game_Height - 313) {
			if (a_->X() > 81 && a_->X() < Game_Width - (81+223))
			{
				if (forth == FALSE)
				{
					a_->MoveX(-xp_);
					a_->MoveY(-yp_ + 0.25);
				}
				else if (forth == TRUE)
				{
					a_->MoveX(xp_);
					a_->MoveY(-yp_ + 0.25);
				}
			}
			if (a_->X() <= 81) {
				forth = TRUE;
				a_->MoveX(xp_);
				a_->MoveY(-yp_ + 0.25);
			}
			if (a_->X() >= Game_Width - (81 + 223))
			{
				forth = FALSE;
				a_->MoveX(-xp_);
				a_->MoveY(-yp_ + 0.25);
			}
		}
		else if (a_->Y() <= 0)
		{
			yp_ = -yp_;
			forth = TRUE;
			a_->MoveX(-xp_);
			a_->MoveY(-yp_ + 0.25);
		}
		else if (a_->Y() >= Game_Height - 313)
		{
			yp_ = -yp_;
			forth = FALSE;
			a_->MoveX(xp_);
			a_->MoveY(-yp_ + 0.25);
		}
	}
	else if (op_ == 7)
	{
		if (a_->Y() > 0 && a_->Y() < Game_Height - 313) {
			if (a_->X() > 81+223 && a_->X() < Game_Width - 81)
			{
				if (fifth == FALSE)
				{
					a_->MoveX(-xp_);
					a_->MoveY(-yp_ + 0.25);
				}
				else if (fifth == TRUE)
				{
					a_->MoveX(xp_);
					a_->MoveY(-yp_ + 0.25);
				}
			}
			if (a_->X() <= 81+223) {
				fifth = TRUE;
				a_->MoveX(xp_);
				a_->MoveY(-yp_ + 0.25);
			}
			if (a_->X() >= Game_Width - 81)
			{
				fifth = FALSE;
				a_->MoveX(-xp_);
				a_->MoveY(-yp_ + 0.25);
			}
		}
		else if (a_->Y() <= 0)
		{
			yp_ = -yp_;
			fifth = TRUE;
			a_->MoveX(-xp_);
			a_->MoveY(-yp_ + 0.25);
		}
		else if (a_->Y() >= Game_Height - 313)
		{
			yp_ = -yp_;
			fifth = FALSE;
			a_->MoveX(xp_);
			a_->MoveY(-yp_ + 0.25);
		}
	}

}