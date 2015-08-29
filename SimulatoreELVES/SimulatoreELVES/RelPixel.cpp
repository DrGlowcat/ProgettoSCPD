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
	VertAngle = 0;
	HoriAngle = 0;
	Status = 0;
}

RelPixel::RelPixel(double X, double Y, double Z)
{
	//Costruttore di inizializzazione
	Orientation = X;
	VertAngle = Y;
	HoriAngle = Z;
	Status = 0;
}

RelPixel::~RelPixel()
{
	delete this;
}

double RelPixel::GetStatus()
{
	return Status;
}

void RelPixel::SetStatus(double In_Status)
{
	Status = In_Status;
}

double RelPixel::GetOrientation()
{
	return Orientation;
}

double RelPixel::GetVertAngle()
{
	return VertAngle;
}

double RelPixel::GetHoriAngle()
{
	return HoriAngle;
}