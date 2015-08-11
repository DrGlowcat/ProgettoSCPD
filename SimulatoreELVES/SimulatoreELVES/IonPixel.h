#pragma once
#include "Fulmine.h"
class IonPixel
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Density;
public:
	double Status;
public:
	IonPixel();
	~IonPixel();
	void CalcolaImpulso(Fulmine in_Fulmine);
	double GetStatus();
};

