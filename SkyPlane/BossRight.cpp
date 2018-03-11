#include "EnemyPlane.h"
#include "BossRight.h"
#include "Resource.h"
#include "StrangeFly.h"

BossRight::BossRight(Point& p) :EnemyPlane(Boss_Right_Height, Boss_Right_Width, p)
{
	Name("Enemy");
	DetailedName("BossRight");
	HP(Boss_Right_Init_HP);
	WeaponID(Boss_Right_Init_Waepon_ID);
	FireOpenTimes(Boss_Right_Fire_Open_Time);
	Speed(Boss_Right_Init_Speed);
	Load_Image(boss_right, Boss_Right_Image_Height, Boss_Right_Image_Width);
	flyBehavior_ = new StrangeFly(*(Position()), SpeedX(), SpeedY(), 7, Boss_Right_Image_Height);

}
BossRight::~BossRight() {}
void BossRight::PerformFly()
{
	flyBehavior_->Fly();
}