/*Similmente alla classe Ionosfera, Rilevatore è un contenitore di Pixel. Anche qui è possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere più oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore è associato a uno o più IonPixel, va quindi implementata una funzione che, 
potenzialmente, possa sommare i vari contributi.*/
#include "stdafx.h"
#include "Rilevatore.h"


Rilevatore::Rilevatore()
{
	//costruttore di un oggetto vuoto.
	LatSite = 0;
	LongSite = 0;
	Orientation = 0;
	FoV = 0;
	Status = 0;
	Resolution = 0; 
	if (!Matrice_Osservazione.empty())
	{
		map<int, RelPixel> EmptyMatrix;
		Matrice_Osservazione = EmptyMatrix;
	}
}

Rilevatore::Rilevatore(double Lat, double Long, double fOv, int res)
{
	LatSite = Lat;
	LongSite = Long;
	Orientation = 0; //il codice di GetOrientation penso che vada qui.
	FoV = fOv;
	Status = 0;
	Resolution = res;
	if (!Matrice_Osservazione.empty())
	{
		map<int, RelPixel> EmptyMatrix;
		Matrice_Osservazione = EmptyMatrix;
	}
}

Rilevatore::~Rilevatore()
{
	delete this;
}

RelPixel Rilevatore::Rel2Ion(double In_X, double In_Y, double In_Z)
{
	/*questa funzione è pensata per assegnare un certo pixel del rilevatore 
	a un pixel della ionosfera. Il dato che ritorna dovrebbe essere un puntatore
	al pixel del rilevatore, in modo da rendere più facile la modifica da parte 
	dei metodi degli IonPixel.*/
}
bool Rilevatore::GetStatus()
{
	return Status;
}
double Rilevatore::GetOrientation()
{
   /* è ancora una bozza: per la tesi avevo fatto il calcolo usando vettori 3D,
	 * che sono però una classe di ROOT. devo capire come farlo con gli strumenti del C++
	 */
	double degree = 3.14159265359 / 180;  //in realtà conviene fare un file .h con tutte le costanti
	double SiteLocation[2];  //coordinate del sito cui appartiene il rilevatore
	double Phi = LatSite*degree;  //coord espresse in radianti
	double Theta = LongSite*degree;
}
/*
double Rilevatore::GetX()
{
	return PosX;
}

double Rilevatore::GetY()
{
	return PosY;
}

double Rilevatore::GetZ()
{
	return PosZ;
}
*/
double Rilevatore::GetLatSite()
{
	return LatSite;
}
double Rilevatore::GetLongSite()
{
	return LongSite;
}
int Rilevatore::GetResolution()
{
	return Resolution;
}
