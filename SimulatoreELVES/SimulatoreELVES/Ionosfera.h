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
	/*l'ho pensata così: si prende un centro (che non è dove sono i rilevatori
	ma proprio il centro della zona visibile (se non ricordo male il grafico
	basta che dividi per due le coordinate e dovresti avere latitudine)*/
	double CenterLat;
	double CenterLong;
	double VertAngle;
	double HoriAngle;
	map<int, IonPixel> Matrix;
	map<int, Rilevatore> GroundRel;
public:
	Ionosfera();
	Ionosfera(int In_Resolution, double In_CurveRad, double In_CenterX, double In_CenterY, double In_CenterZ, double In_DeltaX, double In_DeltaY, double In_DeltaZ, map<int, Rilevatore> In_GroundRel);
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

