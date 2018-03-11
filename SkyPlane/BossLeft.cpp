#include "EnemyPlane.h"
#include "BossLeft.h"
#include "Resource.h"
#include "StrangeFly.h"

BossLeft::BossLeft(Point& p):EnemyPlane(Boss_Left_Height, Boss_Left_Width,p)
{
	Name("Enemy");
	DetailedName("BossLeft");
	HP(Boss_Left_Init_HP);
	WeaponID(Boss_Left_Init_Waepon_ID);
	FireOpenTimes(Boss_Left_Fire_Open_Time);
	Speed(Boss_Left_Init_Speed);
	Load_Image(boss_left, Boss_Left_Image_Height, Boss_Left_Image_Width);
	flyBehavior_ = new StrangeFly(*(Position()), SpeedX(), SpeedY(), 5, Boss_Left_Image_Height);

}
BossLeft::~BossLeft() {}
void BossLeft::PerformFly()
{
	flyBehavior_->Fly();
}