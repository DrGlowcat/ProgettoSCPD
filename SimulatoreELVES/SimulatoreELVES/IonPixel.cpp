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
	Density = 0;
	Status = 0;
	//inserire tempo dell'evento
}

IonPixel::IonPixel(double In_PosX, double In_PosY, map<int, Rilevatore*> In_GroundRel)
{
	PosX = In_PosX;
	PosY = In_PosY;
	Density = 0;
	Status = 0;
	/*NOTA, useremo il SetInVista per riempire la matrice InVista
	questo però ha senso farlo in un secondo momento.*/
	SetInVista(In_GroundRel);
}

IonPixel::~IonPixel()
{
	//delete this;
}

void IonPixel::SetInVista(map<int, Rilevatore*> In_GroundRel)
{
	/*va a settare la mappa dei pixel in vista calcolando Rel2Ion e aggiungendo
	a InVista i risultati.*/
/*da decidere gli input: magari è comodo usare un puntatore in modo da potergli 
passare anche più di un rilevatore (in caso siano presenti)*/
	int counter = 0;
	map<int, RelPixel*> risultati;
	for (auto i : In_GroundRel)
	{
		risultati = i.second->Rel2Ion(PosX, PosY);
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
	cout << counter<<endl;
}

void IonPixel::CalcolaImpulso(Fulmine InFulmine)
{
	//aggiornare con i bool e i due calcoli del tempo.
		double bolt_lat = InFulmine->GetLat;
		double bolt_long = InFulmine->GetLong;
		double pixLat = pixY * CONST_degree;
		double pixLong = pixX * CONST_degree;
	    double arg = cos(0.5*CONST_pi - pixLat)*cos(0.5*CONST_pi - bolt_lat) + sin(0.5*CONST_pi - pixLat)*sin(0.5*CONST_pi - bolt_lat)*cos(pixLong - bolt_long);
		double alpha = acos(arg);
	    double distance2bolt = alpha * CONST_R_earth ; //in km
		if (distance2bolt <= 300)
	{
		Status = true;
		//inserire formula per il calcolo del tempo
		Time_bolt2ion = 300; //in usec
		Time_ion2rel = distance2bolt / CONST_spdoflight;
		for (auto k : InVista)
		{
			k.second->SetStatus(true, Time_bolt2ion + Time_ion2rel);
		}
	}
		/*qui si calcola, per ogni IonPixel, il valore dell'impulso in base al fulmine
	corrente. Il calcolo di tale funzione è indipendente per ogni pixel e può essere
	parallelizzato.*/
	/*
	forall (Ionpixel in Ionosfera)
			{
						{
			double t=0;
			double waveradius =0.;
			double Energy = Fulmine.GetEnergy(); //non so se è necessario // si lo è, Energy è privata ;)
			while(Energy >0)
			{
			waveradius = Fulmine.BoltPropagation(t);
			t += dt; con dt da definire
			Energy = Fulmine.GetEnergy();
			if (waveradius > CONST_HD){
			for each (RelPixel in InVista)
				{
				double K = cos((90.-Fulmine.GetLat())*CONST_degree)sin((90.-PixLat)*CONST_degree) + sin((90.-Fulmine.GetLat())*CONST_degree)*sin((90.-PixLat)*CONST_degree)*cos((Fulmine.GetLong()-PixLong)*CONST_degree);
				double angle = acos(K);
				double distance = (CONST_R_earth+CONST_HD)/sin(angle);
				if(distance > waveradius-err AND distance < waveradius+err)  //err = tolleranza da definire
				{
				Enlight RelPixel
				}
				}
			 }//fine if
				
			}
	*/
}

bool IonPixel::GetStatus()
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

double IonPixel::GetDensity()
{
	return Density;
}
