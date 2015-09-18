// SimulatoreELVES.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Fulmine.h"
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

	/*Inizializzazione dei rilevatori:
	Anche qui utilizziamo un file contenente i valori di posizione e orientamento dei 
	rilevatori. Contestualmente inizializziamo i pixel di ogni rilevatore rendendoli 
	pronti per la fase successiva. Qui abbiamo la possibilità di avere due livelli di
	esecuzione concorrente: la prima a livello di operazione, ovvero la creazione dei
	rilevatori è indipendente dal resto; la seconda si ha dato che i rilevatori sono 
	indipendenti l'uno con l'altro, possiamo quindi crearli in modo parallelo. In vero
	vi sarebbe anche un terzo livello, dato che i pixel di ogni rilevatore sono indipendenti
	e potrebbero essere creati anch'essi in modo concorrente.
	*/
	ifstream RelFile("DBRilevatori.txt", ios::in | ios::ate); //da modificare in caso non si chiami così
	if (RelFile.is_open())
	{
		streampos size = RelFile.tellg();
		char* RelString = new char[size];
		RelFile.seekg(0, ios::beg);
		RelFile.read(RelString, size);
		RelFile.close();
		//ora va parsificato per tirare fuori i singoli Rilevatori e metterli in una struttura appropriata.
	}
	else
	{
		cout << "File ERROR: Unable to open";
		return 1;
	}

	/*Inizializzazione Atmosfera
	In questa fase si inizializza l'atmosfera da file. Come sopra il grado di parallelismo
	è estendibile ai pixel dell'atmosfera stessa. 
	*/
	ifstream AtmFile("DBIonosfera.txt", ios::in | ios::ate); //da modificare in caso non si chiami così
	if (RelFile.is_open())
	{
		streampos size = AtmFile.tellg();
		char* AtmString = new char[size];
		AtmFile.seekg(0, ios::beg);
		AtmFile.read(AtmString, size);
		AtmFile.close();
		//ora va parsificato per tirare fuori i valori di inizializzaione dell'atmosfera.
	}
	else
	{
		cout << "File ERROR: Unable to open";
		return 1;
	}

	/*Da qui inizia la fase di computazione e calcolo della simulazione

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

