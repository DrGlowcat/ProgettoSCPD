/*Classe contenitore che ha responsabilità sulla gestione della matrice di pixel atmosferici
fra le cose che può fare c'è la definizione della dimensione della matrice, e la sua successiva
inizializzazione.
DA DECIDERE: il calcolo della funzione sui pixel potrebbe essere lanciato da qui, ma devo controllare
se ci sono problemi in fase di parallelizzazione.*/

#include "stdafx.h"
#include "Ionosfera.h"


Ionosfera::Ionosfera()
{
	Resolution = 0;
	CurveRad = 0.0;
	CenterX = 0.0;
	CenterY = 0.0;
	CenterZ = 0.0;
	DeltaX = 0.0;
	DeltaY = 0.0;
	DeltaZ = 0.0;
	if (!Matrix.empty())
	{
		map<int, IonPixel> EmptyMatrix;
		Matrix = EmptyMatrix;
	}
}

Ionosfera::Ionosfera(int In_Resolution, double In_CurveRad, double In_CenterX, double In_CenterY, double In_CenterZ, double In_DeltaX, double In_DeltaY, double In_DeltaZ)
{
	Resolution = In_Resolution;
	CurveRad = In_CurveRad;
	CenterX = In_CenterX;
	CenterY = In_CenterY;
	CenterZ = In_CenterZ;
	DeltaX = In_DeltaX;
	DeltaY = In_DeltaY;
	DeltaZ = In_DeltaZ;
	if (!Matrix.empty())
	{
		map<int, IonPixel> EmptyMatrix;
		Matrix = EmptyMatrix;
	}
	else
	{
		//allora riempila==> usare .insert con l'oggetto da inserire.
	}
}


Ionosfera::~Ionosfera()
{
	delete this;
}

void Ionosfera::CalcImpulso(Fulmine In_Fulmine)
{
	/*qui si calcola, per ogni IonPixel, il valore dell'impulso in base al fulmine
	corrente. Il calcolo di tale funzione è indipendente per ogni pixel e può essere
	parallelizzato.*/
}

void Ionosfera::SetRelPixel(Rilevatore In_Rilevatore)
{
	/*Qui si va ad associare un insieme di pixel dei rilevatore a un singolo IonPixel
	anche questa operazione può essere parallelizzata, dato che si accede ai 
	rilevatori solo in lettura e non si modificano mail.*/
}

int Ionosfera::GetResolution()
{
	return Resolution;
}

double Ionosfera::GetCenterX()
{
	return CenterX;
}

double Ionosfera::GetCenterY()
{
	return CenterY;
}

double Ionosfera::GetCenterZ()
{
	return CenterZ;
}

double Ionosfera::GetDeltaX()
{
	return DeltaX;
}

double Ionosfera::GetDeltaY()
{
	return DeltaY;
}

double Ionosfera::GetDeltaZ()
{
	return DeltaZ;
}