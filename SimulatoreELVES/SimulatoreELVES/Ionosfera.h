//file intestazione della classe Ionosfera. 
//AGGIORNARLO OGNI VOLTA CHE SI CREA UN NUOVO METODO
#pragma once
#include "Fulmine.h"
#include "Rilevatore.h"
#include "IonPixel.h"
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
	IonPixel* Matrix; //da implementare usando il contenitore "map"
public:
	Ionosfera();
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

