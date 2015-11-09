/*Classe contenitore che ha responsabilità sulla gestione della matrice di pixel atmosferici
fra le cose che può fare c'è la definizione della dimensione della matrice, e la sua successiva
inizializzazione.
DA DECIDERE: il calcolo della funzione sui pixel potrebbe essere lanciato da qui, ma devo controllare
se ci sono problemi in fase di parallelizzazione.*/

#include "stdafx.h"
#include "Ionosfera.h"
#include "Tools.h"
using namespace std;


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
		map<int, IonPixel*> EmptyMatrix;
		Matrix = EmptyMatrix;
	}
}

Ionosfera::Ionosfera(int In_RResolution, int In_CResolution, double In_CurveRad, double In_CenterX, double In_CenterY, double In_DeltaX, double In_DeltaY, map<int, Rilevatore*> In_GroundRel)
{
	RowResolution = In_RResolution;
	ColResolution = In_CResolution;
	TotResolution = RowResolution*ColResolution; // davvero serve?
	CurveRad = In_CurveRad;
	CenterLat = In_CenterX; //vengono presi da Tools e sono tutti in gradi
	CenterLong = In_CenterY;
	DeltaLat = In_DeltaX;
	DeltaLong = In_DeltaY;
	GroundRel = In_GroundRel;// ora vedo i rilevatori
	if (!Matrix.empty())
	{
		map<int, IonPixel*> EmptyMatrix;
		Matrix = EmptyMatrix;
	}
	else
	{
		double pix_long = DeltaLong/RowResolution; //ampiezza in long del pixel, in gradi
		double pix_lat = DeltaLat/ColResolution;  //in gradi
		double pixX = longMin + 0.5*pix_long;  //coord riferite al centro del pixel, in gradi
		double pixY = latMin + 0.5*pix_lat;
		for (int i = 0; i < RowResolution; i++)
		{
			for(int j=0; j<ColResolution; j++)
			{
/*ho semplicemente suddiviso la ionosfera in celle in base a latitudine e longitudine,
 * per sapere in quale punto del cielo si verifica l'evento.
*/
				//Matrix.insert(std::pair<int, IonPixel> (i,IonPixel()));
				Matrix[(i*ColResolution)+j] = new IonPixel(pixX, pixY, GroundRel);
				//cout << (i*ColResolution) + j << endl;
				pixY += pix_lat;
			}
			pixX += pix_long;
			pixY = 0.5*pix_lat;
		}
		//cout << "donefor";
	}
	//cout << "done";
}


Ionosfera::~Ionosfera()
{
	//delete this;
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
