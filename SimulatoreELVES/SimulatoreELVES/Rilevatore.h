#pragma once
#include "RelPixel.h"
class Rilevatore
{
private:
	double PosX;  //si riferiscono alla posizione del rilevatore una sorta di media della posizione dei singoli pixel
	double PosY;
	double PosZ;
	double LatSite;  //latitudine del telescopio cui appartiene il rilevatore
	double LongSite;
//4 telescopi --> 4 gruppi di 6 rilevatori e 4 posizioni diverse
	double Orientation;
	double FoV;  //Field of View: campo visivo del rivelatore, in gradi, centrato sull'Orientation
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

