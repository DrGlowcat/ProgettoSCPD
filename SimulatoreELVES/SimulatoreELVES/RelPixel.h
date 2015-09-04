#pragma once
class RelPixel
{
private:
	double Orientation;
	double pixel_elev;
	double pixel_azimut;
	double Status;
public:
	RelPixel();
	RelPixel(double X, double Y, double Z);
	~RelPixel();
	double GetStatus();
	void SetStatus(double In_Status);
	double GetOrientation();
	void RelPixel::SetPixElev(double theta);
	void RelPixel::SetPixAzimut(double phi);
	double RelPixel::GetPixElev();
	double RelPixel::GetPixAzimut();
};



