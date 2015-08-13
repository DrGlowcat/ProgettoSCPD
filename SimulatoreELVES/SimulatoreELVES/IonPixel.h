#pragma once
#include "Fulmine.h"
#include "RelPixel.h"
#include <map>
class IonPixel
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Density;
	std::map<int,RelPixel> InVista; //mappiamo i pixel in vista in modo dinamico.
	double Status;
public:
	IonPixel();
	~IonPixel();
	void SetInVista();
	void CalcolaImpulso(Fulmine in_Fulmine);
	double GetStatus();
	double GetX();
	double GetY();
	double GetZ();
	double GetDensity();
};

