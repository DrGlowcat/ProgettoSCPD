/*Similmente alla classe Ionosfera, Rilevatore è un contenitore di Pixel. Anche qui è possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere più oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore è associato a uno o più IonPixel, va quindi implementata una funzione che,
potenzialmente, possa sommare i vari contributi.*/
#include "stdafx.h"
#include "Rilevatore.h"
#include "RelPixel.h"
#include "Ionosfera.h"
#include "Tools.h"


Rilevatore::Rilevatore()
{
	//costruttore di un oggetto vuoto.
	LatSite = 0;
	LongSite = 0;
	Orientation = 0;
	right_end = 0;
	left_end = 0;
	Status = 0;
	ResolutionX = 0;
	ResolutionY = 0;
	if (!Matrice_Osservazione.empty())
	{
		map<int, RelPixel*> EmptyMatrix;
		Matrice_Osservazione = EmptyMatrix;
	}
}

Rilevatore::Rilevatore(double Lat, double Long, double r_e)
{
	LatSite = Lat*CONST_degree;
	LongSite = Long*CONST_degree;
	right_end = r_e; //r_e si prende dal vettore backwall, che si trova in Tools.h
	left_end = r_e + CONST_pi;
	Orientation = r_e + 0.5*CONST_pi; //meglio questa a occhio
	//Orientation = GetOrientation();  non so quale dei due è meglio
	Status = 0;
	ResolutionX = 20;
	ResolutionY = 22;
	if (!Matrice_Osservazione.empty())
	{
		map<int, RelPixel*> EmptyMatrix;
		Matrice_Osservazione = EmptyMatrix;
	}
	else
	{
		double PixOrientation = 0.0;
		double VertAngle = 0.0;
		double HoriAngle = 0.0;
		double pixX=0.5*45.6;
		double pixY=0.5*26.33;
		double pixel_theta=(28.1/22)*CONST_degree; //ampiezza in elevation di un pixel
		double pixel_phi=(30/20)*CONST_degree;  //ampiezza in azimut di un pixel
		int ResCounter = 0;
		for (int i = 0; i < 22; i++)//ciclo sulle righe
		{
			for(int j=0; j<20; j++)//ciclo sulle colonne
			{
				//larghezza del pixel=1.5°=45.6mm, altezza=0.866°=26.33mm
				//le coordinate si riferiscono al centro del pixel
				
				//l'orientamento del pixel è 0 in quanto pari a quella del rilevatore?

				pixX += i*45.6;
				pixY += j*26.33;
				/*
				RelPixel.SetPixElev(28.1*CONST_degree-j*pixel_theta);
				RelPixel.SetPixAzimut(right_end*CONST_degree+i*pixel_phi);
				Matrice_Osservazione[i] = RelPixel(pixX, pixY);
				*/
				// te lo segna come errore perchè devi riferirti ad un oggetto:
				double PixElev = 28.1*CONST_degree - j*pixel_theta;
				double PixAzim = right_end*CONST_degree + i*pixel_phi;
				//RelPixel New_pixel = RelPixel(pixX, pixY, PixOrientation,PixElev,PixAzim);
				Matrice_Osservazione[ResCounter] = &RelPixel(pixX, pixY, PixOrientation, PixElev, PixAzim);
				ResCounter++;
			}
		}
	}
	/*come si vede, è del tutto simile a quanto accade in Ionosfera, ma la
	"catena" di chiamate a funzione è molto più breve, ovvero si crea direttamente
	il pixel e non si va oltre.*/
}

Rilevatore::~Rilevatore()
{
	//delete this;
}

map<int, RelPixel*> Rilevatore::Rel2Ion(double pix_lat, double pix_long)
{
	map<int, RelPixel*> SeenMatrix;
	int SeenMatrixIndex = { 0 };
	/*questa funzione è pensata per assegnare un certo pixel del rilevatore
	a un pixel della ionosfera. Il dato che ritorna dovrebbe essere un puntatore
	al pixel del rilevatore, in modo da rendere più facile la modifica da parte
	dei metodi degli IonPixel.*/
	//FoV del singolo pixel, in gradi;
	//forse è meglio metterla come informazione interna al pixel, perché in realtà si
	//calcola in base alla posizione del pixel e del singolo rilevatore
	double relpix_elev = 28.1/22;  //RelPix.GetPixElev
	double relpix_azimut = 30./20;
	Vector3D RelpixLocation(1.,1.,1.);
	RelpixLocation.SetMag(1.);
	RelpixLocation.SetTheta(relpix_elev);
	RelpixLocation.SetPhi(relpix_azimut);
	int res = GetResolution();
	Vector3D LocalNord = PoloNord;
	//for (int k = 0; k < res; k++)
	for (auto k :Matrice_Osservazione)
		{
			RelPixel * ActualRelPixel = k.second;
			/*
			avevi ragione tu sui puntatori a classe, per usare i metodu di ActualRelPixel
			devi usare l'operatore -> per fare un esempio ActualRelPixel->GetPixelElev()
			Altra cosa, non è testato che funzioni, sembra solo che piaccia al compilatore
			ergo incrocia le dita!!
			*/
			//calcola distanza del piede della verticale dell'ionpixel
			pix_lat *= CONST_degree;
			pix_long *= CONST_degree;
			double arg = cos(0.5*CONST_pi-pix_lat)*cos(0.5*CONST_pi-LatSite) + sin(0.5*CONST_pi-pix_lat)*sin(0.5*CONST_pi-LatSite)*cos(pix_long-LongSite);
			double alpha = acos(arg);
			double dist = alpha*CONST_R_earth;
			//calcola elevation del centro dell'ionpixel
            double ion_elev = CONST_HD/dist - dist/(2.*CONST_R_earth);
            //calcola azimut dell'ionpixel
            Vector3D IonLocation(1.,1.,1.);
            IonLocation.SetMag(1.);
            IonLocation.SetPhi(pix_long);
            IonLocation.SetTheta(0.5*CONST_pi-pix_lat);
			// se il metodo richiede un puntatore devi passargli un riferimento
            Vector3D Est = LocalNord.Cross(&RelpixLocation);
            Est.SetMag(1.);
            Vector3D Avector = RelpixLocation.Cross(&IonLocation);
            Avector.SetMag(1.);
            Vector3D Bvector = Avector.Cross(&RelpixLocation);
            Bvector.SetMag(1.);
            Vector3D Vertic = Bvector.Cross(&Est);
            double ion_azimut = Bvector.Angle(&Est)/CONST_degree;
            if(Vertic.Dot(&RelpixLocation)>0.) ion_azimut = -ion_azimut;
            //controlla se ionpixel è nel fov del k-esimo pixel del rivelatore

            if(ion_azimut > relpix_azimut && ion_azimut < relpix_azimut + ActualRelPixel->GetPixAzimut())
            {
            	if(ion_elev > relpix_elev - ActualRelPixel->GetPixElev() && ion_elev < relpix_elev)
            	{
					/*
					questo è il codice da usare per mettere il riferimento nella matrice
					dato che ActualRelPixel è già un puntatore, non c'è bisogno della &
					*/
					SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
					SeenMatrixIndex++;
            	}
            }
		}
	return SeenMatrix;
}
bool Rilevatore::GetStatus()
{
	return Status;
}
bool Rilevatore::Spotted(double alpha)
{
	bool spotted = 0;
	double event_azimut = alpha;
	if(alpha >= right_end && alpha <= left_end) spotted = 1;
	return spotted;
}
double Rilevatore::GetOrientation() //risultato in radianti
{
	double orientation = right_end + 0.5*CONST_pi;
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
	return ResolutionX*ResolutionY;
}
