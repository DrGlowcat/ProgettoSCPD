/*
 * Vector3D.cpp
 *
 *  Created on: 26 Aug 2015
 *      Author: grumpycat
 */
#include "Vector3D.h"
#include "Tools.h"

Vector3D::Vector3D()
{

}

Vector3D::Vector3D(double x, double y, double z)
{
	comp_x=x;
	comp_y=y;
	comp_z=z;
}

Vector3D::~Vector3D()
{

}

double Vector3D::GetX()
{
	return comp_x;
}

double Vector3D::GetY()
{
	return comp_y;
}

double Vector3D::GetZ()
{
	return comp_z;
}

void Vector3D::SetX(double xx)
{
	comp_x = xx;
}

void Vector3D::SetY(double yy)
{
	comp_y = yy;
}

void Vector3D::SetZ(double zz)
{
	comp_z = zz;
}

//calcola norma del vettore dato un puntatore al vettore
double Vector3D::Norma()
{
	double norma = sqrt(comp_x*comp_x + comp_y*comp_y + comp_z*comp_z);
	return norma;
}

//calcola norma al quadrato del vettore
double Vector3D::Norma2()
{
	double norma2 = comp_x*comp_x + comp_y*comp_y + comp_z*comp_z;
	return norma2;
}

//prodotto scalare tra due vettori
double Vector3D::Dot(Vector3D *v1)
{
	double scal = comp_x*v1->GetX() + comp_y*v1->GetY() + comp_z*v1->GetZ();
	return scal;
}
//prodotto vettoriale tra due vettori
Vector3D Vector3D::Cross(Vector3D *v1)
{
	Vector3D vett(comp_y*v1->GetZ()-v1->GetY()*comp_z, comp_z*v1->GetX()-v1->GetZ()*comp_x, comp_x*v1->GetY()-v1->GetX()*comp_y);
	return vett;
}
//imposta angolo polare
void Vector3D::SetTheta(double th)
{
	double mag = Norma();
	double ph = GetPhi();
	SetX(mag*sin(th)*cos(th));
	SetY(mag*sin(th)*sin(ph));
	SetZ(mag*cos(th));
}
//imposta angolo azimutale
void Vector3D::SetPhi(double ph)
{
	double xy = sqrt(comp_x*comp_x + comp_y*comp_y);
	SetX(xy*cos(ph));
	SetY(xy*sin(ph));
}
//restituisce angolo polare
double Vector3D::GetTheta()
{
	double theta = atan2(comp_y,comp_x);
	return theta;
}

//restituisce azimut
double Vector3D::GetPhi()
{
	double phi = atan2(sqrt(comp_x*comp_x + comp_y*comp_y), comp_z);
	return phi;
}

//angolo tra due vettori
double Vector3D::Angle(Vector3D *v)
{
	double ntot = Norma2()*v->Norma();
	if(ntot <= 0) return 0.;
	else
	{
		double arg = Dot(v)/sqrt(ntot);
		if(arg > 1.) arg = 1.;
		if(arg < -1.) arg = -1.;
		double angle = acos(arg);
		return angle;
	}
}

//imposta la norma di un vettore al valore del double fornito
void Vector3D::SetMag(double n)
{
	double factor = Norma();
	if(factor != 0)
	{
		factor = n/factor;
		SetX(comp_x*factor);
		SetY(comp_y*factor);
		SetZ(comp_z*factor);
	}
}
