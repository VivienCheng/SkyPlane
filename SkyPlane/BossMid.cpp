#include "EnemyPlane.h"
#include "BossMid.h"
#include "Resource.h"
#include "StrangeFly.h"

BossMid::BossMid(Point& p) :EnemyPlane(Boss_Mid_Height, Boss_Mid_Width, p)
{
	Name("Enemy");
	DetailedName("BossMid");
	HP(Boss_Mid_Init_HP);
	WeaponID(Boss_Mid_Init_Waepon_ID);
	FireOpenTimes(Boss_Mid_Fire_Open_Time);
	Speed(Boss_Mid_Init_Speed);
	Load_Image(boss_mid, Boss_Mid_Image_Height, Boss_Mid_Image_Width);
	flyBehavior_ = new StrangeFly(*(Position()), SpeedX(), SpeedY(), 6, Boss_Mid_Image_Height);

}
BossMid::~BossMid() {}
void BossMid::PerformFly()
{
	flyBehavior_->Fly();
}