/*Classe contenitore che ha responsabilità sulla gestione della matrice di pixel atmosferici
fra le cose che può fare c'è la definizione della dimensione della matrice, e la sua successiva
inizializzazione.
DA DECIDERE: il calcolo della funzione sui pixel potrebbe essere lanciato da qui, ma devo controllare
se ci sono problemi in fase di parallelizzazione.*/

//#include "stdafx.h"
#include "Ionosfera.h"


Ionosfera::Ionosfera()
{
	//sostituire con due angoli e due soglie limite.
	RowResolution = 0;
	ColResolution = 0;
	TotResolution = 0;
	CurveRad = 0.0;
	CenterLat = 0.0;
	CenterLong = 0.0;
	DeltaLat = 0.0;
	DeltaLong = 0.0;
	if (!Matrix.empty())
	{
		map<int, IonPixel> EmptyMatrix;
		Matrix = EmptyMatrix;
	}
}

Ionosfera::Ionosfera(int In_RResolution, int In_CResolution, int In_TResolution, double In_CurveRad, double In_CenterX, double In_CenterY, double In_DeltaX, double In_DeltaY, map<int, Rilevatore> In_GroundRel)
{
	RowResolution = In_RResolution;
	ColResolution = In_CResolution;
	TotResolution = In_TResolution;
	CurveRad = In_CurveRad;
	CenterLat = In_CenterX;
	CenterLong = In_CenterY;
	DeltaLat = In_DeltaX;
	DeltaLong = In_DeltaY;
	GroundRel = In_GroundRel;// ora vedo i rilevatori
	if (!Matrix.empty())
	{
		map<int, IonPixel> EmptyMatrix;
		Matrix = EmptyMatrix;
	}
	else
	{
		int pix_long = DeltaLong/RowResolution; //ampiezza in long del pixel
		int pix_lat = DeltaLat/ColResolution;
		double pixX=0.5*pix_long;  //coord riferite al centro del pixel
		double pixY=0.5*pix_lat;
		for (int i = 0; i < RowResolution; i++)
		{
			for(int j=0; j<ColResolution; j++)
			{
				// definire come calcolare la posizione del particolare pixel
/*ho semplicemente suddiviso la ionosfera in celle in base a latitudine e longitudine,
 * per sapere in quale punto del cielo si verifica l'evento.
*/
				pixX += pix_long;
				pixY += pix_lat;
				//Matrix.insert(std::pair<int, IonPixel> (i,IonPixel()));
				Matrix[i] = IonPixel(TotResolution, pixX, pixY, GroundRel);
				/*NOTA: per ora ogni pixel è vuoto devo implementare il
			costruttore idoneo per i pixel prima di poter proseguire*/
			}
		}
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

int Ionosfera::GetRowResolution()
{
	return RowResolution;
}

int Ionosfera::GetColResolution()
{
	return ColResolution;
}
int Ionosfera::GetTotResolution()
{
	return RowResolution*ColResolution;
}
double Ionosfera::GetCenterLat()
{
	return CenterLat;
}

double Ionosfera::GetCenterLong()
{
	return CenterLong;
}

double Ionosfera::GetDeltaLat()
{
	return DeltaLat;
}

double Ionosfera::GetDeltaLong()
{
	return DeltaLong;
}
