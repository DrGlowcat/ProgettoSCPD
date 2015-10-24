#pragma once
class RelPixel
{
private:
	double Orientation;
	double pos_X;
	double pos_Y;
	double pixel_elev;
	double pixel_azimut;
	bool Status;
	int T_rec; // tempo di ricezione in uSec
	int DeltaColor;
public:
	RelPixel();
	RelPixel(double X, double Y, double Orient, double Elev, double Azim);
	~RelPixel();
	double GetStatus();
	void SetStatus(bool In_Status, int In_T_rec);
	double GetOrientation();
	void SetPixElev(double theta);
	void SetPixAzimut(double phi);
	double GetPixElev();
	double GetPixAzimut();
	setDeltaColor() // switch sul tempo per definire i colori
	getDeltaColor()

	//il riferimento alla classe va solo nel cpp
	//qui va solo il prototipo, nel cpp invece
	//va scritto "nome_classe::metodo()".
	//Attenzione, questo va messo solo per la definzione
	//quando usi un metodo riferito ad un oggetto si usa
	//la notazione oggetto.metodo() [vedi rilevatore per esempio]
};



