#pragma once
class Fulmine
{
private:
	double Lat;
	double Long;
	double Energy;
public:
	double MaxRange;
public:
	Fulmine();
	Fulmine(double In_Lat, double In_Long, double In_Energy);
	~Fulmine();
	//void SetBolt(double &,double &,double &,double &);
	double GetMaxRange();
	double GetLat();
	double GetLong();
	double GetEnergy();
};
