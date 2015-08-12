#pragma once
#include "Fulmine.h"
#include "RelPixel.h"
class IonPixel
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Density;
	RelPixel* InVista; //usare una mappa associativa al posto del puntatore
public:
	double Status;
public:
	IonPixel();
	~IonPixel();
	void CalcolaImpulso(Fulmine in_Fulmine);
	double GetStatus();
	double GetX();
	double GetY();
	double GetZ();
	double GetDensity();
};

