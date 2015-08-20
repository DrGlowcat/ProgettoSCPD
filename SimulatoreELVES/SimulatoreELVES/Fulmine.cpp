/*DA DECIDERE: non so se conviene costruire una classe per il fulmine o definire una sruct nel main.
Qui vengono conservate le informazioni di posizione e potenza del fulmine. Tali informazioni sono accessibili da tutti i pixel
e deve essere garantita l'accessibilità (in lettura) in parallelo. Ovviamente la scrittura è mutualmente esclusiva, ma una volta
che il fulmine è stato dichiarato non dovrebbe essere più modificato.*/
#include "stdafx.h"
#include "Fulmine.h"


Fulmine::Fulmine()
{
  SetBolt(Tempo,Lat,Long,Energy);
}


Fulmine::~Fulmine()
{
}

void SetBolt(double &Tempo, double &Lat, double &Long, double &Energy)
{
	//Tempo=some rand();  misurato in microsec
	//Lat=some rand();   in gradi da Greenwich; range: [-41.5828;-25.25]
	//Long=some rand();   range: [-79.25;-59.25]
	//Energy=some rand();   in joule. forse non serve
}


double Fulmine::GetTempo()
{
	return Tempo;
}

//il fulmine ha solo latitudine e longitudine
double Fulmine::GetLat()
{
	return Lat;
}

double Fulmine::GetLong()
{
	return Long;
}

double Fulmine::GetEnergy()
{
	return Energy;
}
