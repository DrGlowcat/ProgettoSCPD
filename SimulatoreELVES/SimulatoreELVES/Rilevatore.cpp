/*Similmente alla classe Ionosfera, Rilevatore è un contenitore di Pixel. Anche qui è possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere più oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore è associato a uno o più IonPixel, va quindi implementata una funzione che,
potenzialmente, possa sommare i vari contributi.*/
//#include "stdafx.h"
#include "Rilevatore.h"
#include "Ionosfera.h"


Rilevatore::Rilevatore()
{
	//costruttore di un oggetto vuoto.
	LatSite = 0;
	LongSite = 0;
	Orientation = 0;
	right_end = 0;
	left_end = 0;
	Status = 0;
	Resolution = 0;
	if (!Matrice_Osservazione.empty())
	{
		map<int, RelPixel> EmptyMatrix;
		Matrice_Osservazione = EmptyMatrix;
	}
}

Rilevatore::Rilevatore(double Lat, double Long, double r_e, int res)
{
	LatSite = Lat*CONST_degree;
	LongSite = Long*CONST_degree;
	right_end = r_e; //r_e si prende dal vettore backwall, che si trova in Tools.h
	left_end = r_e + CONST_pi;
	//Orientation = r_e + 0.5*CONST_pi;
	//Orientation = GetOrientation();  non so quale dei due è meglio
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
		double pixX=0.5*45.6;
		double pixY=0.5*26.33;
		for (int i = 0; i < 22; i++)//ciclo sulle righe
		{
			for(int j=0; j<20; j++)//ciclo sulle colonne
			{
				//larghezza del pixel=1.5°=45.6mm, altezza=0.866°=26.33mm
				//le coordinate si riferiscono al centro del pixel
				pixX += i*45.6;
				pixY += j*26.33;
				//pixZ = 31.13;
				Matrice_Osservazione[i] = RelPixel(pixX, pixY);
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

map<int, RelPixel> Rilevatore::Rel2Ion(double pix_lat, double pix_long)
{
	/*questa funzione è pensata per assegnare un certo pixel del rilevatore
	a un pixel della ionosfera. Il dato che ritorna dovrebbe essere un puntatore
	al pixel del rilevatore, in modo da rendere più facile la modifica da parte
	dei metodi degli IonPixel.*/
	//FoV del singolo pixel, in gradi;
	//forse è meglio metterla come informazione interna al pixel, perché in realtà si
	//calcola in base alla posizione del pixel e del singolo rilevatore
	double relpix_elev = 28.1/22;  //calcolo provvisorio
	double relpix_azimut = 30./20;
	Vector3D RelpixLocation(1.,1.,1.);
	RelpixLocation.SetMag(1.);
	RelpixLocation.SetTheta(relpix_elev);
	RelpixLocation.SetPhi(relpix_azimut);
	double *ionptr;
	int res = Ionosfera.GetTotResolution();
		for(int k=0, k<res, k++)
		{
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
                        Vector3D Est = PoloNord.Cross(RelpixLocation);
                        Est.SetMag(1.);
                        Vector3D Avector = RelpixLocation.Cross(IonLocation);
                        Avector.SetMag(1.);
                        Vector3D Bvector = Avector.Cross(RelpixLocation);
                        Bvector.SetMag(1.);
                        Vector3D Vertic = Bvector.Cross(Est);
                        double ion_azimut = Bvector.Angle(Est)/CONST_degree;
                        if(Vertic.Dot(RelpixLocation)>0.) ion_azimut = -ion_azimut;
		}
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
	return Resolution;
}
