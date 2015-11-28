/*Similmente alla classe Ionosfera, Rilevatore è un contenitore di Pixel. Anche qui è possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere più oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore è associato a uno o più IonPixel, va quindi implementata una funzione che,
potenzialmente, possa sommare i vari contributi.
Ho deciso di tenere le coordinate in gradi, perché è più facile controllarle a occhio; all'inizio di
ogni funzione le convertirò in radianti per i calcoli*/
#include "stdafx.h"
#include "Rilevatore.h"
#include "RelPixel.h"
#include "Ionosfera.h"
#include "Tools.h"
#include "FoV.h"


Rilevatore::Rilevatore()
{
	//costruttore di un oggetto vuoto.
	LatSite = 0;
	LongSite = 0;
	Orientation = 0;
	right_end = 0;
	left_end = 0;
	Status = false;
	ResolutionX = 0;
	ResolutionY = 0;
	if (Mirror1.empty())
	{
		map<int, RelPixel*> EmptyMatrix;
		Mirror1 = EmptyMatrix;
		Mirror2 = EmptyMatrix;
		Mirror3 = EmptyMatrix;
		Mirror4 = EmptyMatrix;
		Mirror5 = EmptyMatrix;
		Mirror6 = EmptyMatrix;
	}
}

Rilevatore::Rilevatore(double Lat, double Long, double r_e)
{
	//trasformazione delle coordinate in radianti
	LatSite = Lat;
	LongSite = Long;
	right_end = r_e; //r_e si prende dal vettore backwall, che è in gradi
	//left_end = r_e + CONST_pi; //R_e è in gradi!
	left_end = r_e + 180;
	Orientation = r_e; //orientazione dell'intero rilevatore, in gradi
	Status = false;
	ResolutionX = 20;
	ResolutionY = 22;
	if (!Mirror1.empty())
	{
		map<int, RelPixel*> EmptyMatrix;
		Mirror1 = EmptyMatrix;
		Mirror2 = EmptyMatrix;
		Mirror3 = EmptyMatrix;
		Mirror4 = EmptyMatrix;
		Mirror5 = EmptyMatrix;
		Mirror6 = EmptyMatrix;
	}
	else
	{
		double PixOrientation = r_e;
		double VertAngle = 0.0;
		double HoriAngle = 0.0;
		double pixX=0.5*45.6;
		double pixY=0.5*26.33;
		double pixel_elev=28.1/22; //ampiezza (gradi) in elevation di un pixel
		double pixel_azim=30/20;  //ampiezza (gradi) in azimut di un pixel
		int ResCounter = 0;
		for (int i = 0; i < ResolutionY; i++)//ciclo sulle righe
		{
			for(int j=0; j< ResolutionX; j++)//ciclo sulle colonne
			{ 
				
				Mirror1[ResCounter] = new RelPixel(pixX, pixY, PixOrientation, 28.1 - (j+0.5)*pixel_elev, right_end + (i+0.5)*pixel_azim);
				ResCounter++;
				pixY += 26.33;
			}
			pixX += 45.6;
			pixY = 0.5*26.33;//dopo un ciclo di y lo si riporta ad un valore iniziale
		}
		PixOrientation += 30.;
		for (int i = 0; i < ResolutionY; i++)//ciclo sulle righe
		{
			for(int j=0; j< ResolutionX; j++)//ciclo sulle colonne
			{ 
				
				Mirror2[ResCounter] = new RelPixel(pixX, pixY, PixOrientation, 28.1 - (j+0.5)*pixel_elev, right_end + (i+0.5)*pixel_azim);
				ResCounter++;
				pixY += 26.33;
			}
			pixX += 45.6;
			pixY = 0.5*26.33;//dopo un ciclo di y lo si riporta ad un valore iniziale
		}
		PixOrientation += 30.;
		for (int i = 0; i < ResolutionY; i++)//ciclo sulle righe
		{
			for(int j=0; j< ResolutionX; j++)//ciclo sulle colonne
			{ 
								
				Mirror3[ResCounter] = new RelPixel(pixX, pixY, PixOrientation, 28.1 - (j+0.5)*pixel_elev, right_end + (i+0.5)*pixel_azim);
				ResCounter++;
				pixY += 26.33;
			}
			pixX += 45.6;
			pixY = 0.5*26.33;//dopo un ciclo di y lo si riporta ad un valore iniziale
		}

		PixOrientation += 30.;
		for (int i = 0; i < ResolutionY; i++)//ciclo sulle righe
		{
			for(int j=0; j< ResolutionX; j++)//ciclo sulle colonne
			{ 
							
				Mirror4[ResCounter] = new RelPixel(pixX, pixY, PixOrientation, 28.1 - (j+0.5)*pixel_elev, right_end + (i+0.5)*pixel_azim);
				ResCounter++;
				pixY += 26.33;
			}
			pixX += 45.6;
			pixY = 0.5*26.33;//dopo un ciclo di y lo si riporta ad un valore iniziale
		}

		PixOrientation += 30.;
		for (int i = 0; i < ResolutionY; i++)//ciclo sulle righe
		{
			for(int j=0; j< ResolutionX; j++)//ciclo sulle colonne
			{ 
				PixOrientation += 30.;				
				Mirror5[ResCounter] = new RelPixel(pixX, pixY, PixOrientation, 28.1 - (j+0.5)*pixel_elev, right_end + (i+0.5)*pixel_azim);
				ResCounter++;
				pixY += 26.33;
			}
			pixX += 45.6;
			pixY = 0.5*26.33;//dopo un ciclo di y lo si riporta ad un valore iniziale
		}

		PixOrientation += 30.;
		for (int i = 0; i < ResolutionY; i++)//ciclo sulle righe
		{
			for(int j=0; j< ResolutionX; j++)//ciclo sulle colonne
			{ 
								
				Mirror6[ResCounter] = new RelPixel(pixX, pixY, PixOrientation, 28.1 - (j+0.5)*pixel_elev, right_end + (i+0.5)*pixel_azim);
				ResCounter++;
				pixY += 26.33;
			}
			pixX += 45.6;
			pixY = 0.5*26.33;//dopo un ciclo di y lo si riporta ad un valore iniziale
		}
	}
}

Rilevatore::~Rilevatore()
{
	//delete this;
}

map<int, RelPixel*> Rilevatore::Rel2Ion(double In_pix_lat, double In_pix_long)
{
	map<int, RelPixel*> SeenMatrix;

	RelPixel * ActualRelPixel;
	Vector3D CamLocation;
	Vector3D IonLocation;

	//coordinate assolute aventi origine il centro della terra
	Vector3D CamLocationABS; CamLocationABS.SetAzEl(0.0, 90.0, CONST_R_earth * 1000); 
	Vector3D IonLocationABS; IonLocationABS.SetAzEl(In_pix_long, In_pix_lat, (CONST_R_earth * 1000) + CONST_HD);
	//ora trasliamo le suddette in modo da ottenere un sistema centrato nel rilevatore
	CamLocation = CamLocationABS; CamLocation.SetZ(IonLocation.GetZ() - (CONST_R_earth * 1000));
	IonLocation = IonLocationABS; IonLocation.SetZ(IonLocation.GetZ() - (CONST_R_earth * 1000));
	//a questo punto ho due coordinate le quali tengono conto della curvatura terrestre
	// ovviamnete, per non uscire pazzo, per me la terra è sferica.

	

	int SeenMatrixIndex = { 0 };
	double DirCamXZ;
	double DirCamXY;
	bool testXY=false;
	bool testXZ = false;
	for (auto k : Mirror1)
	{
		ActualRelPixel = k.second;
		DirCamXZ = ActualRelPixel->GetPixElev();
		DirCamXY = ActualRelPixel->GetPixAzimut();
		//non sono sicuro
		//dovrebbe andare bene in quanto mi basta un vettore che sia parallelo a dove
		//guarda il pixel
		Vector3D Camera(1, 1, 1);
		Camera.SetAzEl(DirCamXY, DirCamXZ);
		//fine parte di insicureza
		testXY = FoV::FoVchk2d(Camera.GetX(), Camera.GetY(), IonLocation.GetX(), IonLocation.GetY(), 28.1 / 22);
		testXZ = FoV::FoVchk2d(Camera.GetX(), Camera.GetZ(), IonLocation.GetX(), IonLocation.GetZ(), 30 / 20);
		if (testXY && testXZ)
		{
			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
			SeenMatrixIndex++;
			cout << "\a";
		}
	}

	for (auto k : Mirror2)
	{
		ActualRelPixel = k.second;
		DirCamXZ = ActualRelPixel->GetPixElev();
		DirCamXY = ActualRelPixel->GetPixAzimut();
		//non sono sicuro
		//dovrebbe andare bene in quanto mi basta un vettore che sia parallelo a dove
		//guarda il pixel
		Vector3D Camera(1, 1, 1);
		Camera.SetAzEl(DirCamXY, DirCamXZ);
		//fine parte di insicureza
		testXY = FoV::FoVchk2d(Camera.GetX(), Camera.GetY(), IonLocation.GetX(), IonLocation.GetY(), 28.1 / 22);
		testXZ = FoV::FoVchk2d(Camera.GetX(), Camera.GetZ(), IonLocation.GetX(), IonLocation.GetZ(), 30 / 20);
		if (testXY && testXZ)
		{
			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
			SeenMatrixIndex++;
			cout << "\a";
		}
	}

	for (auto k : Mirror3)
	{
		ActualRelPixel = k.second;
		DirCamXZ = ActualRelPixel->GetPixElev();
		DirCamXY = ActualRelPixel->GetPixAzimut();
		//non sono sicuro
		//dovrebbe andare bene in quanto mi basta un vettore che sia parallelo a dove
		//guarda il pixel
		Vector3D Camera(1, 1, 1);
		Camera.SetAzEl(DirCamXY, DirCamXZ);
		//fine parte di insicureza
		testXY = FoV::FoVchk2d(Camera.GetX(), Camera.GetY(), IonLocation.GetX(), IonLocation.GetY(), 28.1 / 22);
		testXZ = FoV::FoVchk2d(Camera.GetX(), Camera.GetZ(), IonLocation.GetX(), IonLocation.GetZ(), 30 / 20);
		if (testXY && testXZ)
		{
			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
			SeenMatrixIndex++;
			cout << "\a";
		}
	}

	for (auto k : Mirror4)
	{
		ActualRelPixel = k.second;
		DirCamXZ = ActualRelPixel->GetPixElev();
		DirCamXY = ActualRelPixel->GetPixAzimut();
		//non sono sicuro
		//dovrebbe andare bene in quanto mi basta un vettore che sia parallelo a dove
		//guarda il pixel
		Vector3D Camera(1, 1, 1);
		Camera.SetAzEl(DirCamXY, DirCamXZ);
		//fine parte di insicureza
		testXY = FoV::FoVchk2d(Camera.GetX(), Camera.GetY(), IonLocation.GetX(), IonLocation.GetY(), 28.1 / 22);
		testXZ = FoV::FoVchk2d(Camera.GetX(), Camera.GetZ(), IonLocation.GetX(), IonLocation.GetZ(), 30 / 20);
		if (testXY && testXZ)
		{
			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
			SeenMatrixIndex++;
			cout << "\a";
		}
	}

	for (auto k : Mirror5)
	{
		ActualRelPixel = k.second;
		DirCamXZ = ActualRelPixel->GetPixElev();
		DirCamXY = ActualRelPixel->GetPixAzimut();
		//non sono sicuro
		//dovrebbe andare bene in quanto mi basta un vettore che sia parallelo a dove
		//guarda il pixel
		Vector3D Camera(1, 1, 1);
		Camera.SetAzEl(DirCamXY, DirCamXZ);
		//fine parte di insicureza
		testXY = FoV::FoVchk2d(Camera.GetX(), Camera.GetY(), IonLocation.GetX(), IonLocation.GetY(), 28.1 / 22);
		testXZ = FoV::FoVchk2d(Camera.GetX(), Camera.GetZ(), IonLocation.GetX(), IonLocation.GetZ(), 30 / 20);
		if (testXY && testXZ)
		{
			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
			SeenMatrixIndex++;
			cout << "\a";
		}
	}

	for (auto k : Mirror6)
	{
		ActualRelPixel = k.second;
		DirCamXZ = ActualRelPixel->GetPixElev();
		DirCamXY = ActualRelPixel->GetPixAzimut();
		//non sono sicuro
		//dovrebbe andare bene in quanto mi basta un vettore che sia parallelo a dove
		//guarda il pixel
		Vector3D Camera(1, 1, 1);
		Camera.SetAzEl(DirCamXY, DirCamXZ);
		//fine parte di insicureza
		testXY = FoV::FoVchk2d(Camera.GetX(), Camera.GetY(), IonLocation.GetX(), IonLocation.GetY(), 28.1 / 22);
		testXZ = FoV::FoVchk2d(Camera.GetX(), Camera.GetZ(), IonLocation.GetX(), IonLocation.GetZ(), 30 / 20);
		if (testXY && testXZ)
		{
			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
			SeenMatrixIndex++;
			cout << "\a";
		}
	}
	//for (auto k :Mirror1)
	//	{
		//	ActualRelPixel = k.second;
		//	relpix_elev = ActualRelPixel->GetPixElev();
		//	relpix_azimut = ActualRelPixel->GetPixAzimut();
		//	RelpixLocation = Vector3D(1.,1.,1.);
		//	RelpixLocation.SetMag(1.);
		//	RelpixLocation.SetTheta(relpix_elev);
		//	RelpixLocation.SetPhi(relpix_azimut);
		//	
		//	
		//	//calcola elevation del centro dell'ionpixel
  //          ion_elev = CONST_HD/dist - dist/(2.*CONST_R_earth);
  //          //calcola azimut dell'ionpixel
		//	IonLocation = Vector3D(1., 1., 1.);
  //          IonLocation.SetMag(1.);
  //          IonLocation.SetPhi(pix_long/CONST_degree);
  //          IonLocation.SetTheta(0.5*CONST_pi-pix_lat/CONST_degree);
		//	// se il metodo richiede un puntatore devi passargli un riferimento
  //          Est = LocalNord.Cross(&RelpixLocation);
  //          Est.SetMag(1.);
  //          Avector = RelpixLocation.Cross(&IonLocation);
  //          Avector.SetMag(1.);
  //          Bvector = Avector.Cross(&RelpixLocation);
  //          Bvector.SetMag(1.);
  //          Vertic = Bvector.Cross(&Est);
  //          ion_azimut = Bvector.Angle(&Est); //già in gradi
  //          if(Vertic.Dot(&RelpixLocation)>0.) ion_azimut = -ion_azimut;
  //          //controlla se ionpixel è nel fov del k-esimo pixel del rivelatore
		//	
		//	pixel_elev=(28.1/22); //ampiezza (gradi) in elevation di un pixel
		//    pixel_azim=(30/20);  //ampiezza (gradi) in azimut di un pixel
  //          if(ion_azimut<(relpix_azimut+0.5*pixel_elev) && ion_azimut>(relpix_azimut-0.5*pixel_elev))
  //          {
  //          	if(ion_elev<(relpix_elev+0.5*pixel_azim) && ion_elev>(relpix_elev-0.5*pixel_azim))
  //          	{
		//			/*
		//			questo è il codice da usare per mettere il riferimento nella matrice
		//			dato che ActualRelPixel è già un puntatore, non c'è bisogno della &
		//			*/
		//			SeenMatrix[SeenMatrixIndex] = ActualRelPixel;
		//			SeenMatrixIndex++;
		//			//cout << "finalmente" << endl;
  //          	}
  //          }
		//}
	//if (SeenMatrixIndex!=0) cout << SeenMatrixIndex << endl;
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
double Rilevatore::GetOrientation() 
{
	double orientation = right_end + 90.; //in gradi
	return orientation;
}
double Rilevatore::GetLatSite()
{
	return LatSite; //in gradi
}
double Rilevatore::GetLongSite()
{
	return LongSite; //in gradi
}
int Rilevatore::GetResolution()
{
	return ResolutionX*ResolutionY;
}
void Rilevatore::SetStatus(bool In_Status)
{
	this->Status = In_Status;
}
