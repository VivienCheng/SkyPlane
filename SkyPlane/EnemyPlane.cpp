#include "Plane.h"
#include "Point.h"
#include "EnemyPlane.h"
#include "Resource.h"

EnemyPlane::EnemyPlane(int h, int w, Point p):Plane(h,w,p)
{
	lock_ = FALSE;
	Name(_T("Enemy"));
	Group(-1);
}
EnemyPlane::~EnemyPlane() {}

void EnemyPlane::Lock() { lock_ = TRUE; }
BOOL EnemyPlane::GetLock() { return lock_; }