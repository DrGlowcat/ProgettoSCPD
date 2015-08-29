#pragma once
class RelPixel
{
private:
	double Orientation;
	double VertAngle;
	double HoriAngle;
	double Status;
public:
	RelPixel();
	RelPixel(double X, double Y, double Z);
	~RelPixel();
	double GetStatus();
	void SetStatus(double In_Status);
	double GetOrientation();
	double GetVertAngle();
	double GetHoriAngle();
};

