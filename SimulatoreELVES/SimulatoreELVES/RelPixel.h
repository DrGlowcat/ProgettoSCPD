#pragma once
class RelPixel
{
private:
	double Orientation;
	double pos_X;
	double pos_Y;
	double pixel_elev;
	double pixel_azimut;
	double Status;
public:
	RelPixel();
	RelPixel(double X, double Y, double Orient, double Elev, double Azim);
	~RelPixel();
	double GetStatus();
	void SetStatus(double In_Status);
	double GetOrientation();
	void SetPixElev(double theta);
	void SetPixAzimut(double phi);
	double GetPixElev();
	double GetPixAzimut();

	//il riferimento alla classe va solo nel cpp
	//qui va solo il prototipo, nel cpp invece
	//va scritto "nome_classe::metodo()".
	//Attenzione, questo va messo solo per la definzione
	//quando usi un metodo riferito ad un oggetto si usa
	//la notazione oggetto.metodo() [vedi rilevatore per esempio]
};



