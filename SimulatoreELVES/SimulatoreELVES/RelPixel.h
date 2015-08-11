#pragma once
class RelPixel
{
private:
	double PosX;
	double PosY;
	double PosZ;
public:
	double Status;
public:
	RelPixel();
	~RelPixel();
	double GetStatus();
};

