#include "GameObject.h"
#include "Player.h"
#include "Plane.h"
#include "Tool.h"

Tool::Tool(int h ,int w ,Point m,CString name):FlyObject(h,w,m),enemyName_(name)
{
	
	Speed(Tool_Init_Speed);
	Name(_T("Tool"));
}
Tool::~Tool() {};
void Tool::DestroyTool()
{
	Killed();
}

CString Tool::EnemyName()
{
	return enemyName_;
}

void Tool::DetailedName(CString s) { detailedName_ = s; }
CString Tool::DetailedName() {	return detailedName_;}