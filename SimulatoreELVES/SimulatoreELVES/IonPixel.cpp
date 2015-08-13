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
}


IonPixel::~IonPixel()
{
	delete this;
}

void IonPixel::SetInVista()
{
/*da decidere gli input: magari è comodo usare un puntatore in modo da potergli 
passare anche più di un rilevatore (in caso siano presenti)*/
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