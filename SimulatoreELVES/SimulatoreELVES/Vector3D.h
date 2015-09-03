 /* vector3D.h
 *
 *  Created on: 26 Aug 2015
 *      Author: grumpycat
 */
#pragma once
#ifndef VECTOR3D_H_
#define VECTOR3D_H_

class Vector3D
{
//algebra vettoriale; supponiamo che i vettori 3D siano del tipo v={x,y,z}
private:
	double comp_x;
	double comp_y;
	double comp_z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();
	double GetX();
	double GetY();
	double GetZ();
	void SetX(double);
	void SetY(double);
	void SetZ(double);
	double Norma();  //calcola norma del vettore dato un puntatore al vettore
	double Norma2();  //calcola norma al quadrato del vettore
	double Dot(Vector3D *);  //prodotto scalare tra due vettori
	Vector3D Cross(Vector3D *);  //prodotto vettoriale tra due vettori --> restituisce un vettore, non so se il prototipo è giusto così
	void SetTheta(double th); //imposta angolo polare
	void SetPhi(double ph);  //imposta angolo azimutale
	double GetTheta();  //restituisce angolo polare, devo capire in quale sistema di riferimento conviene mettersi
	double GetPhi();  //restituisce azimut
	double Angle(Vector3D *);  //angolo tra due vettori
	void SetMag(double);  //imposta la norma di un vettore al valore del double fornito
};
#endif /* VECTOR3D_H_ */

