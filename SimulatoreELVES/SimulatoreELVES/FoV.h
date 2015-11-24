#pragma once
class FoV
{
public:
	FoV();
	~FoV();
	static bool FoVchk2d(double CamDirX, double CamDirY, double pointX, double pointY, double In_FoV);
};

