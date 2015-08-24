//file intestazione della classe Ionosfera. 
//AGGIORNARLO OGNI VOLTA CHE SI CREA UN NUOVO METODO
#pragma once
#include "Fulmine.h"
#include "Rilevatore.h"
#include "IonPixel.h"
#include <map>
using namespace std;
class Ionosfera
{
private :
	int Resolution;
	double CurveRad;
	double CenterX;
	double CenterY;
	double CenterZ;
	double DeltaX;
	double DeltaY;
	double DeltaZ;
	map<int, IonPixel> Matrix;
public:
	Ionosfera();
	Ionosfera(int In_Resolution, double In_CurveRad, double In_CenterX, double In_CenterY, double In_CenterZ, double In_DeltaX, double In_DeltaY, double In_DeltaZ);
	~Ionosfera();
	void CalcImpulso(Fulmine In_Fulmine);
	void SetRelPixel(Rilevatore In_Rilevatore);
	int GetResolution();
	double GetCenterX();
	double GetCenterY();
	double GetCenterZ();
	double GetDeltaX();
	double GetDeltaY();
	double GetDeltaZ();
};

