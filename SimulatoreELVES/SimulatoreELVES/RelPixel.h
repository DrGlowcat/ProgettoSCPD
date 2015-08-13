#pragma once
class RelPixel
{
private:
	double PosX;
	double PosY;
	double PosZ;
	double Status;
public:
	RelPixel();
	RelPixel(double X, double Y, double Z);
	~RelPixel();
	double GetStatus();
	void SetStatus(double In_Status);
	double GetX();
	double GetY();
	double GetZ();
};

