#pragma once
#include "Point.h"
#include "Weapon.h"
#include "FlyObject.h"

//������ڣ�������������豸֮һ��
//������ڵ������ķ��з�ʽ����򵥣�ֱ�����Ϸ��С�

#define Player_Wing_Gun_Height 21
#define Player_Wing_Gun_Width  21
#define Player_Wing_Gun_Image_Height 64
#define Player_Wing_Gun_Image_Width  64
#define Player_Wing_Gun_Power   3
#define Player_Wing_Gun_Init_Speed 5

class PlayerWingGun : public Weapon
{
protected:
public:
	PlayerWingGun(Point p);
	~PlayerWingGun();
};