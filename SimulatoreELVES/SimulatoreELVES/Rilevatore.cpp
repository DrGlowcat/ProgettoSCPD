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
	else
	{
		// Andrebbe cambiato il nome perchè so che non si chiamano così gli angoli...
		double PixOrientation = 0.0;
		double VertAngle = 0.0;
		double HoriAngle = 0.0;
		double pixX=0.;
		double pixY=0.;
		for (int i = 0; i < 22; i++)//ciclo sulle colonne
		{
			for(int j=0; j<20; j++)//ciclo sulle righe
			{
				//larghezza del pixel=1.5°=45.6mm, altezza=0.866°=26.33mm
				//le coordinate si riferiscono al centro del pixel
				pixX = i*0.5*45.6;
				pixY = j*0.5*26.33;
				//pixZ = 31.13;
				Matrice_Osservazione[i] = RelPixel(pixX, pixY, pixZ);
			}
		}
	}
	/*come si vede, è del tutto simile a quanto accade in Ionosfera, ma la 
	"catena" di chiamate a funzione è molto più breve, ovvero si crea direttamente
	il pixel e non si va oltre.*/
}

Rilevatore::~Rilevatore()
{
	delete this;
}

map<int, RelPixel> Rilevatore::Rel2Ion(double In_X, double In_Y, double In_Z)
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
	//PROVVISORIO: VALE SOLO PER IL TELESCOPIO DI LL,
	//quando ci saranno tutti i telesc bisognerà usare il vettore dei backwall
	double backwall = -30.;  //gradi rispetto all'est del bordo del FoV di LL
	double orientation = backwall + 90.;
	return orientation;
}
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
