#pragma once
#include "Fulmine.h"
#include "RelPixel.h"
#include"Rilevatore.h"
#include "Ionosfera.h"
#include <map>
using namespace std;
class IonPixel
{
private:
	double PosX;
	double PosY;
	double Density;
	map<int,RelPixel> InVista; //mappiamo i pixel in vista in modo dinamico.
	double Status;
public:
	IonPixel();
	IonPixel(double TotRes, double In_PosX, double In_PosY, map<int, Rilevatore> In_GroundRel);
	~IonPixel();
	void SetInVista(double TotRes, map<int, Rilevatore> In_GroundRel);
	void CalcolaImpulso(Fulmine in_Fulmine);
	double GetStatus();
	double GetX();
	double GetY();
	double GetDensity();
};

