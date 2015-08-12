#pragma once
class Fulmine
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Energy;
public:
	double Tempo;
public:
	Fulmine();
	~Fulmine();
	double GetTempo();
	double GetX();
	double GetY();
	double GetZ();
	double GetEnergy();
};