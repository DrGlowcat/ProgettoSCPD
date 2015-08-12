#pragma once
#include "RelPixel.h"
class Rilevatore
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Orientation;
	bool Status; //indica se acceso o spento.
	int Resolution;
	RelPixel* Matrice_Osservazione;
public:
	Rilevatore();
	~Rilevatore();
	RelPixel FindPixel(double In_X, double In_Y, double In_Z);
	bool GetStatus();
	double GetOrientation();
	double GetX();
	double GetY();
	double GetZ();
	int GetResolution();
};

