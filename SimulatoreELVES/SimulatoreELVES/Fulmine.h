#pragma once
class Fulmine
{
private:
	double Lat;
	double Long;
	double Energy;
public:
	double Tempo;
public:
	Fulmine();
	Fulmine(double In_Tempo, double In_Lat, double In_Long, double In_Energy);
	~Fulmine();
	//forse mi sbaglio io, ma non si dovrebbe usare l'asterisco al posto di &?
	void SetBolt(double &,double &,double &,double &);
	double GetTempo();
	double GetLat();
	double GetLong();
	double GetEnergy();
};
