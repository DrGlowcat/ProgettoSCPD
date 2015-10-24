/*Pixel del rilevatore. Oltre ad avere informazioni sulla posizione (magari condivise con tutti i pizel di uno stesso rilevatore)
ha le "referenze" di ogni pixel atmosferico che vede in modo da sapere da chi prendere i dati. Una funzione importante dei 
RelPixel è il calcolo dell'ordine di ricezione dei vari segnali in modo da poter creare delle immagini in funzione del tempo
che siano significative e soprattutto correte.*/
#include "stdafx.h"
#include "RelPixel.h"


RelPixel::RelPixel(void)
{
	//costruttore vuoto da usare per la dichiarazione e dimensionamento
	Orientation = 0;
	pixel_azimut = 0;
	pixel_elev = 0;
	Status = 0;
}

RelPixel::RelPixel(double X, double Y, double Orient, double Elev, double Azim)
{
	//Costruttore di inizializzazione
	pos_X = X;
	pos_Y = Y;
	Orientation = Orient;
	pixel_elev = Elev;
	pixel_azimut = Azim;
	Status = 0;
}

RelPixel::~RelPixel(void)
{
	//delete this;
}

double RelPixel::GetStatus()
{
	return Status;
}

void RelPixel::SetStatus(bool In_Status, int In_T_rec)
{
	
	if (Status != false)
	{
		if (In_T_rec > T_rec)
		{
			T_rec = In_T_rec;
		}
	}
	else
	{
		Status = In_Status;
		T_rec = In_T_rec;
	}
}

double RelPixel::GetOrientation()
{
	return Orientation;
}

void RelPixel::SetPixElev(double theta)
{
	pixel_elev = theta;
}

void RelPixel::SetPixAzimut(double phi)
{
	pixel_azimut = phi;
}
double RelPixel::GetPixElev()
{
	return pixel_elev;
}
double RelPixel::GetPixAzimut()
{
	return pixel_azimut;
}
void RelPixel::setDeltaColor(int In_Time) // switch sul tempo per definire i colori
{
	//definire esattamente l'intervallo di tempo
	switch (In_Time)//i case lavorano solo su interi mettere espressione di divisione qui.
	{
	case 1:
		DeltaColor = 1;
		break;
	case 2:
		DeltaColor = 2;
		break;
	case 3:
		DeltaColor = 3;
		break;
	case 4:
		DeltaColor = 4;
		break;
	case 5:
		DeltaColor = 5;
		break;
	case 6:
		DeltaColor = 6;
		break;
	default:
		break;
	}
}

int RelPixel::getDeltaColor()
{
	return DeltaColor;
}
