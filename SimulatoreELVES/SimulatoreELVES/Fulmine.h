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
	~Fulmine();
	void SetBolt(double &,double &,double &,double &);
	double GetTempo();
	double GetLat();
	double GetLong();
	double GetEnergy();
};
