/*DA DECIDERE: non so se conviene costruire una classe per il fulmine o definire una sruct nel main.
Qui vengono conservate le informazioni di posizione e potenza del fulmine. Tali informazioni sono accessibili da tutti i pixel
e deve essere garantita l'accessibilità (in lettura) in parallelo. Ovviamente la scrittura è mutualmente esclusiva, ma una volta
che il fulmine è stato dichiarato non dovrebbe essere più modificato.*/
#include "stdafx.h"
#include "Fulmine.h"
#include "Tools.h"


Fulmine::Fulmine()
{
  //SetBolt(Tempo,Lat,Long,Energy);
	Lat = 0;
	Long = 0;
	Energy = 0;
	MaxRange = 0;
	MM = 0;
	DD = 0;
	YY = 0;
}

Fulmine::Fulmine(double In_Lat, double In_Long, double In_Energy, int in_MM, int in_DD, int in_YY, int in_hh, int in_mm, int in_ss, int in_usec)
{
	Lat = In_Lat;
	Long = In_Long;
	Energy = In_Energy;
	MM = in_MM;
	DD = in_DD;
	YY = in_YY;
	hh = in_hh;
	mm = in_mm;
	ss = in_ss;
	usec=in_usec;
	MaxRange = Energy * 3; //Formula giocattolo
}

Fulmine::~Fulmine()
{
	//delete this;
}

/*
lo lascio qui momentaneamente in modo da mantenere i calcolo del campo visivo masismo
void Fulmine::SetBolt(double &Tempo, double &Lat, double &Long, double &Energy)
{
	//Tempo=some rand();  misurato in microsec
	//Lat=some rand();   in gradi da Greenwich; range: [-41.5828;-25.25]
	//Long=some rand();   range: [-79.25;-59.25]
	//Energy=some rand();   in joule. forse non serve
}*/


double Fulmine::GetMaxRange()
{
	return MaxRange;
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

/*double BoltPropagation(double t)
{
//t è il tempo trascorso dalla caduta del fulmine
	double raggio = 0.;
	t = 0;
	
	raggio = CONST_spdoflight * t;
	return raggio;
	// return CONST_spdoflight * t; //metodo condensato ;)
}*/
