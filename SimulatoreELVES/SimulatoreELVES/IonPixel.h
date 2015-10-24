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
	map<int,RelPixel*> InVista; //mappiamo i pixel in vista in modo dinamico.
	bool Status;
	int Time_bolt2ion;
	int Time_ion2rel;
public:
	IonPixel();
	IonPixel(double In_PosX, double In_PosY, map<int, Rilevatore*> In_GroundRel);
	~IonPixel();
	void SetInVista(map<int, Rilevatore*> In_GroundRel);
	void CalcolaImpulso(Fulmine in_Fulmine);
	bool GetStatus();
	double GetX();
	double GetY();
	double GetDensity();
};

