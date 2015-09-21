// SimulatoreELVES.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Fulmine.h"
#include "Tools.h"
#include "Rilevatore.h"
#include "Ionosfera.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*La procedura main serve da punto di ingresso e di controllo del flusso del programma
	qui si avrà l'inizializzazione delle strutture dati e delle classi. Inoltre qui si avranno 
	gli strumenti per la valutazione delle prestazioni del codice insisme a tutti i metodi che 
	ci permettono di salvare i vari risultati in appositi file.*/

	/*
	Inizializzazione del DB dei fulmini:
	per prima cosa si vanno a caricare i dati dei fulmini tramite un apposito file.
	Posso prevedere anche la possibilità di introdurre dei valori manualmente e vedere
	cosa succede. Questa operazione è indipendente dalle altre, e se vogliamo possiamo
	eseguirla in modo parallelo ad altre attività.
	*/
	ifstream ThunderFile ("DBFulmini.txt",ios::in|ios::ate); //da modificare in caso non si chiami così
	if (ThunderFile.is_open())
	{
		streampos size = ThunderFile.tellg();
		char* ThunderString = new char[size];
		ThunderFile.seekg(0, ios::beg);
		ThunderFile.read(ThunderString, size);
		ThunderFile.close();
		//ora va parsificato per tirare fuori i singoli fulmini e metterli in una struttura appropriata.
	}
	else
	{
		cout << "File ERROR: Unable to open";
		return 1;
	}

	//iniziaizzazioni dei rilevatori.
	map<int, Rilevatore> Rilevatori;
	for (int i = 0; i < 4; i++)
	{
		Rilevatori[1] = Rilevatore(latsites[i], longsites[i], backwall[i], RelXRes, RelYRes);
	}

	//inizializzazione ionosfera (NOTA: non sono sicuro che siano i parametri giusti)
	Ionosfera ActualIonosphere = Ionosfera(IonXRes,IonYRes,CONST_R_earth,augerCentre[0],augerCentre[1],deltaLong,deltaLat,Rilevatori);

	/*Da qui inizia la fase di computazione e calcolo della simulazione
	NOTA: Pseudocodice
	for each(Bolt in DBFulmine)
		{
		throw Bolt to Ionosfera
		forall (Ionpixel in Ionosfera)
			{
			propagate Bolt
			for each (RelPixel in InVista)
				{
				Enlight RelPixel
				}
			}
		forall (Rilevatore in DBRilevatori)
			{
			Rilevatore.CollectImage()
			}
		}
	*/
	return 0;
}

