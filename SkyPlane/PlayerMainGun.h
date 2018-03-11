#pragma once
#include "Point.h"
#include "Weapon.h"
#include "FlyObject.h"

//������ڣ��������������豸��
//������ڵ������ķ��з�ʽ����򵥣�ֱ�����Ϸ��С�

#define Player_Main_Gun_Height 38
#define Player_Main_Gun_Width  6
#define Player_Main_Gun_Image_Height 84
#define Player_Main_Gun_Image_Width  15
#define Player_Main_Gun_Power   5
#define Player_Main_Gun_Init_Speed 5

class PlayerMainGun : public Weapon
{
protected:
public:
	PlayerMainGun(Point p);
	~PlayerMainGun();

};