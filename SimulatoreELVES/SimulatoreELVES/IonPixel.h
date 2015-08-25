#pragma once
#include "Fulmine.h"
#include "RelPixel.h"
#include <map>
using namespace std;
class IonPixel
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Density;
	map<int,RelPixel> InVista; //mappiamo i pixel in vista in modo dinamico.
	double Status;
public:
	IonPixel();
	IonPixel(double In_PosX, double In_PosY, double In_PosZ);
	~IonPixel();
	void SetInVista();
	void CalcolaImpulso(Fulmine in_Fulmine);
	double GetStatus();
	double GetX();
	double GetY();
	double GetZ();
	double GetDensity();
};

