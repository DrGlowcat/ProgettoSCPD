/*Similmente alla classe Ionosfera, Rilevatore è un contenitore di Pixel. Anche qui è possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere più oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore è associato a uno o più IonPixel, va quindi implementata una funzione che, 
potenzialmente, possa sommare i vari contributi.*/
#include "stdafx.h"
#include "Rilevatore.h"


Rilevatore::Rilevatore()
{

}


Rilevatore::~Rilevatore()
{

}

RelPixel Rilevatore::FindPixel(double In_X, double In_Y, double In_Z)
{

}
bool Rilevatore::GetStatus()
{

}
double Rilevatore::GetOrientation()
{
   /* è ancora una bozza: per la tesi avevo fatto il calcolo usando vettori 3D,
	 * che sono però una classe di ROOT. devo capire come farlo con gli strumenti del C++
	 */
	double degree = 3.14159265359/180.  //in realtà conviene fare un file .h con tutte le costanti
	double SiteLocation[2];  //coordinate del sito cui appartiene il rilevatore
	double Phi = LatSite*degree;  //coord espresse in radianti
	double Theta = LongSite*degree;
}
double Rilevatore::GetX()
{

}

double Rilevatore::GetY()
{

}

double Rilevatore::GetZ()
{

}
int Rilevatore::GetResolution()
{

}
