// SimulatoreELVES.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include "Fulmine.h"
//#include "Tools.h"
//#include "Rilevatore.h"
//#include "Ionosfera.h"
#include "FoV.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*La procedura main serve da punto di ingresso e di controllo del flusso del programma
	qui si avrà l'inizializzazione delle strutture dati e delle classi. Inoltre qui si avranno 
	gli strumenti per la valutazione delle prestazioni del codice insisme a tutti i metodi che 
	ci permettono di salvare i vari risultati in appositi file.*/

	/*Rilevatore testrel;
	testrel = Rilevatore(0.1, 0.2, 0.3);*/
	//map<int, Rilevatore*> ProvaMultiRel;
	//for (int i = 0; i < 4; i++)
	//{
	//	ProvaMultiRel[i] = new Rilevatore(latsites[i], longsites[i], backwall[i]);
	//}
	//Rilevatore* estrazione = ProvaMultiRel[2];
	//Ionosfera testIonosfera = Ionosfera(IonXRes, IonYRes, CONST_R_earth, augerCentre[0], augerCentre[1], deltaLong, deltaLat, ProvaMultiRel);

	bool chk;
	FoV XYTest;
	chk = XYTest.FoVchk2d(1.0, 0.0, 0.0, 1.0, 45.0);
	if (chk)
	{
		cout << "dentro"<<endl;
	}
	else
	{
		cout << "fuori"<<endl;
	}

	int fine;
	cin >>  fine;

	///*
	//Inizializzazione del DB dei fulmini:
	//per prima cosa si vanno a caricare i dati dei fulmini tramite un apposito file.
	//Posso prevedere anche la possibilità di introdurre dei valori manualmente e vedere
	//cosa succede. Questa operazione è indipendente dalle altre, e se vogliamo possiamo
	//eseguirla in modo parallelo ad altre attività.
	//*/
	//map<int, Fulmine> DBfulmini;
	////ATTENZIONE: file non presente ancora
	//ifstream ThunderFile ("AE_selection2013.txt",ios::in|ios::ate); //da modificare in caso non si chiami così
	//if (ThunderFile.is_open())
	//{
	//	int counter{ 1 };
	//	int ThunCounter{ 0 };
	//	double wwlln_lat, wwlln_long, wwlln_dt, wwlln_energy, wwlln_errEnergy;
	//	int wwlln_nstat, wwlln_nstat2;
	//	string mmddyy, hhmmss;
	//	string MM, DD, YY;
	//	string hh, mm, ss, usec;
	//	while (!ThunderFile.eof())
	//	{
	//		ThunderFile >> 
	//			mmddyy >> //data
	//			hhmmss >> //ora
	//			wwlln_lat >> //latitudine
	//			wwlln_long >> //longitudine
	//			wwlln_dt >> //durata (?)
	//			wwlln_nstat >> //(?)
	//			wwlln_energy >> //energia impulso
	//			wwlln_errEnergy >> //errore relativo sull'energia (?)
	//			wwlln_nstat2;//(?)
	//		MM = mmddyy.substr(5,2);
	//		DD = mmddyy.substr(8, 2);
	//		YY = mmddyy.substr(0, 4);
	//		hh= hhmmss.substr(0, 2);
	//		mm = hhmmss.substr(3, 2);
	//		ss = hhmmss.substr(6, 2); 
	//		usec=hhmmss.substr(9, 6);
	//		if (counter==10)
	//		{
	//			counter = 1;
	//			//riempi una riga
	//			Fulmine nuovoFul = Fulmine(
	//				wwlln_lat, 
	//				wwlln_long, 
	//				wwlln_energy, 
	//				stoi(MM), 
	//				stoi(DD), 
	//				stoi(YY), 
	//				stoi(hh), 
	//				stoi(mm), 
	//				stoi(ss), 
	//				stoi(usec));
	//			DBfulmini[ThunCounter] = nuovoFul;
	//			ThunCounter++;
	//		}
	//		else{ counter++; }
	//	}

	//}
	//else
	//{
	//	cout << "File ERROR: Unable to open";
	//	return 1;
	//}
	////iniziaizzazioni dei rilevatori.
	//map<int, Rilevatore> Rilevatori;
	//for (int i = 0; i < 4; i++)
	//{
	//	Rilevatori[1] = Rilevatore(latsites[i], longsites[i], backwall[i]);
	//}
	////inizializzazione ionosfera (NOTA: non sono sicuro che siano i parametri giusti)
	//Ionosfera ActualIonosphere = Ionosfera(IonXRes,IonYRes,CONST_R_earth,augerCentre[0],augerCentre[1],deltaLong,deltaLat,Rilevatori);
	///*Da qui inizia la fase di computazione e calcolo della simulazione
	//NOTA: Pseudocodice
	//for each(Bolt in DBFulmine)
	//	{
	//	Ionosfera.CalcImpulso(Bolt)
	//	forall (Rilevatore in DBRilevatori)
	//		{
	//		Rilevatore.CollectImage()
	//		}
	//	}
	//*/
	return 0;
}
