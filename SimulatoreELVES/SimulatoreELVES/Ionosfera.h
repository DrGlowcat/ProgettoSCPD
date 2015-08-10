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
	IonPixel* Matrix;
public:
	Ionosfera();
	~Ionosfera();
	void CalcImpulso(Fulmine In_Fulmine);
	void SetRelPixel(Rilevatore In_Rilevatore);
};

