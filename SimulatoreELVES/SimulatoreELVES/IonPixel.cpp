/*Pixel virtuale della ionosfera. Qesta classe contiene tutte le informazioni (lato ionosfera) per il calcolo della funzione
F(.) per la definizione dell'impulso visibile dal rilevatore. Di sicuro avremo informazioni riguardanti la posizione del pixel, 
inoltre è possibile aggiungere informazioni secondarie (densità, altezza ionosfera, ecc). Di fatto lo IonPixel è il dato "dataparallel"
su cui si lavora.*/

#include "stdafx.h"
#include "IonPixel.h"
using namespace std;

IonPixel::IonPixel()
{
	PosX = 0;
	PosY = 0;
	PosZ = 0;
	Density = 0;
	Status = 0;
	//inserire tempo dell'evento
}

IonPixel::IonPixel(double In_PosX, double In_PosY, double In_PosZ, map<int, Rilevatore> In_GroundRel)
{
	PosX = In_PosX;
	PosY = In_PosY;
	PosZ = In_PosZ;
	Density = 0;
	Status = 0;
	/*NOTA, useremo il SetInVista per riempire la matrice InVista
	questo però ha senso farlo in un secondo momento.*/
	SetInVista(In_GroundRel);
}

IonPixel::~IonPixel()
{
	delete this;
}

void IonPixel::SetInVista(map<int, Rilevatore> In_GroundRel)
{
	/*va a settare la mappa dei pixel in vista calcolando Rel2Ion e aggiungendo
	a InVista i risultati.*/
/*da decidere gli input: magari è comodo usare un puntatore in modo da potergli 
passare anche più di un rilevatore (in caso siano presenti)*/
	int counter = 0;
	for (auto i : In_GroundRel)
	{
		auto risultati = i.second.Rel2Ion(PosX, PosY, PosZ);
		for (auto j : risultati)
		{
			/*questi cicli sono necessari per evitare che RelPixel
			con indici uguali si eliminino a vicenda nella matrice in vista.
			ATTENZIONE: forse vanno impiegati i puntatori per assicurarci di lavorare
			su un unica istanza dei pixel.*/
			InVista[counter] = j.second;
			counter++;
		}
	}
}

void IonPixel::CalcolaImpulso(Fulmine InFulmine)
{
	Status = (PosX*Density) + (PosY*Density) + (PosZ*Density);
	cout << "calcolata la funzione" << endl;
}

double IonPixel::GetStatus()
{
	return Status;
}

double IonPixel::GetX()
{
	return PosX;
}

double IonPixel::GetY()
{
	return PosY;
}

double IonPixel::GetZ()
{
	return PosZ;
}

double IonPixel::GetDensity()
{
	return Density;
}