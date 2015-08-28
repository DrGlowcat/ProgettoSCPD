#pragma once
class Fulmine
{
private:
	double Lat;
	double Long;
	double Energy;
public:
	double Tempo;//inutile, si parte da t0
	//inserire raggio massimo.
public:
	Fulmine();
	Fulmine(double In_Tempo, double In_Lat, double In_Long, double In_Energy);
	~Fulmine();
	void SetBolt(double &,double &,double &,double &);
	double GetTempo();
	double GetLat();
	double GetLong();
	double GetEnergy();
};
