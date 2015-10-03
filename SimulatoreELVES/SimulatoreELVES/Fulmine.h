#pragma once
class Fulmine
{
private:
	double Lat;
	double Long;
	double Energy;
	int MM,DD,YY;
	int hh, mm, ss, usec;
public:
	double MaxRange;
public:
	Fulmine();
	Fulmine(double In_Lat, double In_Long, double In_Energy, int MM, int DD, int YY, int hh, int mm, int ss, int usec);
	~Fulmine();
	//void SetBolt(double &,double &,double &,double &);
	double GetMaxRange();
	double GetLat();
	double GetLong();
	double GetEnergy();
	double BoltPropagation(double t);
};
