/*
 * Tools.h
 *
 *  Created on: 20 Aug 2015
 *      Author: grumpycat
 */
//PROVA DI COMMIT ECCETERA
/*file che contiene tutte le costanti ed eventuali funzioni user defined eccetera. Per il momento metto qui anche i
prototipi delle operazioni vettoriali, ma mi stavo chiedendo se non valga la pena di creare una classe "vettore 3D"
con tutta la sua algebra
*/

#pragma once
#include <cmath>
#include "Vector3D.h"

//#define CONST_spdoflight 0.3;  //in km/microsec
//#define CONST_pi 3.14159265359;
//#define CONST_degree CONST_pi/180;  //conversione gradi-radianti
//#define CONST_r_earth 6371;  //raggio terrestre in km

double const CONST_spdoflight { 0.3 };  //in km/microsec
double const CONST_pi{ 3.1415926535897932384626433832795 };
double const CONST_degree = CONST_pi / 180.0;  //conversione gradi-radianti
double const CONST_R_earth { 6371.0 };  //raggio terrestre in km
double const CONST_HD { 9000 };   //altezza dello strato di emissione
/**/

double const augerCentre[2] = {-35.25, -69.25}; //in gradi
double const deltaLong = 20; //in gradi
double const deltaLat = deltaLong*cos(augerCentre[0] * CONST_degree); //in gradi
double const latMax = augerCentre[0] + 10; //in gradi
double const latMin = latMax - deltaLat; //in gradi
double const longMin = augerCentre[1] - 0.5*deltaLong; //in gradi
double const longMax = augerCentre[1] + 0.5*deltaLong; //in gradi
double const longsites[4] = {-69.449673,-69.012203,-69.210845,-69.499633};  //longitudini dei 4 telescopi
double const latsites[4] = {-35.495759,-35.291974,-34.935916,-35.114138};  //latitudini dei telescopi
//per i vettori: 0=LosLeones, 1=LosMorados, 2=LomaAmarilla, 3=Coihueco
double const backwall[4] = {-30.00,60.03,-171.85,-116.68};  //orientamento della zona cieca di ciascun telesc, in gradi rispetto all'est
//FoV della camera: 30° in azimuth in 20 colonne, 28.1° in elevation in 22 righe
int const RelXRes = 20;
int const RelYRes = 22;
//int const IonXRes = 220;
int const IonXRes = 44;
//int const IonYRes = 200;
int const IonYRes = 40;
Vector3D const PoloNord = Vector3D(0., 0., 1.);
