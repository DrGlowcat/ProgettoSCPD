#include "stdafx.h"
#include "FoV.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>


FoV::FoV()
{
}


FoV::~FoV()
{
}

//#include "resource.h"

// your path for this include may vary
//#include "GraphicsFramework.h"

//// Global variable to store the graphics framwork object
//GraphicsFramework* PGraphics;

//HWND HOutput = 0;  // handle to the output control
//HWND HDialog = 0;

const double PI = 3.1415927;

// 2D point or vector
struct Vector2 {
	double x, y;		// coordinates

	// default constructor - sets coordinates to 0
	Vector2() {
		x = y = 0.0;
	}

	Vector2(double In_x, double In_y)
	{
		x = In_x;
		y = In_y;
	}

	// returns the squared length of this vector
	double squaredLength() {
		return((x * x) + (y * y));
	}

	// returns length of this vector 
	double length() {
		return(sqrt(squaredLength()));
	}

	// normalizes this vector
	void normalize() {
		double len = length();
		// make sure we don't divide by zero
		if (len != 0.0) {
			scale(1 / length());
		}
	}

	// scales this vector uniformly by s
	void scale(double s) {
		x *= s;
		y *= s;
	}

};

// return the dot product of vectors a and b
double Vector2Dot(Vector2 a, Vector2 b)
{
	return((a.x * b.x) + (a.y * b.y));
}



// function to get the absolute value of an integer
int Abs(int x) {
	if (x < 0)  return -x;
	else		return x;
}

// function to get the sign (+1 or -1) of an integer
int Sign(int x) {
	if (x < 0)  return -1;
	else		return 1;
}


//void Circle(int xCenter, int yCenter, int r, unsigned int color) {
//	double d;
//	int rSquared;
//	int x, y;
//
//	rSquared = r * r;
//
//	x = 0;
//	y = r;
//
//	d = rSquared - ((x + 1) * (x + 1) + (y - 0.5) * (y - 0.5));
//
//	while (y >= x) {
//		PGraphics->AddPoint(xCenter + x, yCenter + y, color);
//		PGraphics->AddPoint(xCenter - x, yCenter + y, color);
//		PGraphics->AddPoint(xCenter + x, yCenter - y, color);
//		PGraphics->AddPoint(xCenter - x, yCenter - y, color);
//		PGraphics->AddPoint(xCenter + y, yCenter + x, color);
//		PGraphics->AddPoint(xCenter - y, yCenter + x, color);
//		PGraphics->AddPoint(xCenter + y, yCenter - x, color);
//		PGraphics->AddPoint(xCenter - y, yCenter - x, color);
//		if (d > 0) {
//		}
//		else {
//			y--;
//		}
//		x++;
//		d = rSquared - ((x + 1) * (x + 1) + (y - 0.5) * (y - 0.5));
//	}
//}

// function to draw a line between two points
//void DrawLine(int x1, int y1, int x2, int y2, unsigned int color) {
//	int dx, dy;						 // dy / dx is the slope
//	int x, y;						   // loop and point variables
//
//	// calculate changes in y and x between the points
//	dy = y2 - y1;
//	dx = x2 - x1;
//
//	if (Abs(dy) > Abs(dx)) {
//		// since there is a greater change in y than x we must
//		// loop in y, calculate x and draw
//		for (y = y1; y != y2; y += Sign(dy)) {
//			x = x1 + (y - y1) * dx / dy;
//			PGraphics->AddPoint(x, y, color);
//		}
//	}
//	else {
//		// since there is a greater (or equal) change in x than y we must
//		// loop in x, calculate y and draw
//		for (x = x1; x != x2; x += Sign(dx)) {
//			y = y1 + (x - x1) * dy / dx;
//			PGraphics->AddPoint(x, y, color);
//		}
//	}
//
//	// draw the last pixel
//	PGraphics->AddPoint(x2, y2, color);
//}

// function to return the bounding angle of a camera's field of view
// assumes camera is at the origin
// v1, v2 will be filled in with the 1st & 2nd (going CCW) bounding vectors
// for the given camera direction and field of view
// v1 and v2 will be normalized
void GetFOVExtents(Vector2 camDir, double fov, Vector2* v1, Vector2* v2) {
	double camAngle;		// camera angle in standard position
	double a1, a2;		  // angles of fov bounding vectors v1 & v2 in std pos

	// calculate the camera angle = arctan(y/x)
	// use the atan2 function to account for different quadrants
	camAngle = atan2(camDir.y, camDir.x);

	// calculate the angles of the bounding vectors on either side of the fov
	// fov is in degrees must convert to radians in calculations
	a1 = camAngle - fov / 2 * (PI / 180);
	a2 = camAngle + fov / 2 * (PI / 180);

	// calculate the fov bounding vectors
	v1->x = cos(a1);
	v1->y = sin(a1);
	v2->x = cos(a2);
	v2->y = sin(a2);
}

/*questa funzione esegue il test in 2d del FoV e restituisce un valore di verità
a seconda che il punto appartenga o meno al campo di vista.*/
bool FoV::FoVchk2d(double CamDirX, double CamDirY, double pointX, double pointY, double In_FoV)
{
	double fov=In_FoV;
	Vector2 camDirection=Vector2(CamDirX,CamDirY);
	Vector2 userPoint=Vector2(pointX,pointY);
	
	//Vector2 fovPt1, fovPt2;
	//GetFOVExtents(camDirection, fov, &fovPt1, &fovPt2);
	//fovPt1.scale(50);
	//fovPt2.scale(50);

	if (acos(Vector2Dot(camDirection, userPoint) / (camDirection.length() * userPoint.length())) * (180 / PI) <= fov / 2)
		return true;
	else
		return false;
}
//
//void DrawStuff() {
//	COLORREF green = RGB(0, 255, 0);	// green color to draw with
//	COLORREF red = RGB(255, 0, 0);	  // red color to draw with
//	COLORREF blue = RGB(0, 0, 255);	 // blue color to draw with
//	Vector2 camDirection;
//	Vector2 userPoint;
//
//	Vector2 fovPt1, fovPt2;			 // field of view extent points
//	double fov;						 // camera field of view (in degrees)
//
//	char* str;					   // string to store user input
//	RECT rect;						  // rectangle for the output window
//	int xMin, xMax, wdRect;			 // min & max x rectangle coords
//
//	// clear the scene and add an axis
//	PGraphics->ClearScene(RGB(0, 0, 0));
//	PGraphics->AddAxis(RGB(150, 150, 150), 10);
//
//	// get the rectangle info for this window
//	GetClientRect(HOutput, &rect);
//	wdRect = rect.right - rect.left;
//	xMin = -wdRect / 2;
//	xMax = wdRect / 2;
//
//	// get the user input from the edit boxes and 
//	// convert string input to double
//	GetDlgItemText(HDialog, IDC_EDIT_CAMDIRX, str, 32);
//	camDirection.x = atof(str);
//	GetDlgItemText(HDialog, IDC_EDIT_CAMDIRY, str, 32);
//	camDirection.y = atof(str);
//	GetDlgItemText(HDialog, IDC_EDIT_POINTX, str, 32);
//	userPoint.x = atof(str);
//	GetDlgItemText(HDialog, IDC_EDIT_POINTY, str, 32);
//	userPoint.y = atof(str);
//	GetDlgItemText(HDialog, IDC_EDIT_VIEWANGLE, str, 32);
//	fov = atof(str);
//
//	// get the normalized fov extent points
//	GetFOVExtents(camDirection, fov, &fovPt1, &fovPt2);
//
//	// scale these points before drawing the fov rays
//	fovPt1.scale(50);
//	fovPt2.scale(50);
//
//	// draw the fov rays
//	DrawLine(0, 0, fovPt1.x, fovPt1.y, green);
//	DrawLine(0, 0, fovPt2.x, fovPt2.y, green);
//
//	// determine if user point is within the field of view here
//	//we are assuming carmera location is at origin
//	//*************************************
//	float dot_product(float *a, float *b, int size)
//	{
//		float dp = 0.0f;
//		for (int i = 0; i<size; i++)
//			dp += a[i] * b[i];
//		return dp;
//	}
//
//	Circle(userPoint.x, userPoint.y, 1, blue);
//	//You are to color this point green or red,
//	//depending on whether or not it is inside									   
//	//or outside fov. An if statement may be used
//	if (acos(Vector2Dot(camDirection, userPoint) / (camDirection.length() * userPoint.length())) * (180 / PI) <= fov / 2)
//	{
//		Circle(userPoint.x, userPoint.y, 1, green);
//	}
//	else {
//		Circle(userPoint.x, userPoint.y, 1, red);
//	}
//	// draw the points
//	PGraphics->Draw();
//}
