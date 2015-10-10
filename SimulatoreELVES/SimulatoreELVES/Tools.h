/*
 * Tools.h
 *
 *  Created on: 20 Aug 2015
 *      Author: grumpycat
 */

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

/*non mi chedere perchè, ma in qualche modo gli da fastidi
il define, per ovviare a tutto ciò ho definito le variabili
come double const. Ora ci sono due vie percorribili, o si lascia
così, o si inventano dei getter per le costanti. Io opterei
per la prima che è più semplice e meno caotica.*/
double const CONST_spdoflight { 0.3 };  //in km/microsec
double const CONST_pi { 3.14159265359 };
double const CONST_degree { CONST_pi / 180 };  //conversione gradi-radianti
double const CONST_R_earth { 6371 };  //raggio terrestre in km
double const CONST_HD { 9000 };   //altezza dello strato di emissione
/**/

double const augerCentre[2] = {-35.25, -69.25};
double const deltaLong = 20;
double const deltaLat = deltaLong*cos(augerCentre[0] * CONST_degree);
double const latMax = augerCentre[0] + 10;
double const latMin = latMax - deltaLat;
double const longMin = augerCentre[1] - 0.5*deltaLong;
double const longMax = augerCentre[1] + 0.5*deltaLong;
double const longsites[4] = {-69.449673,-69.012203,-69.210845,-69.499633};  //longitudini dei 4 telescopi
double const latsites[4] = {-35.495759,-35.291974,-34.935916,-35.114138};  //latitudini dei telescopi
//per i vettori: 0=LosLeones, 1=LosMorados, 2=LomaAmarilla, 3=Coihueco
double const backwall[4] = {-30.00,60.03,-171.85,-116.68};  //orientamento della zona cieca di ciascun telesc, in gradi rispetto all'est
//FoV della camera: 30° in azimuth in 20 colonne, 28.1° in elevation in 22 righe
int const RelXRes = 20;
int const RelYRes = 22;
int const IonXRes = 220;
int const IonYRes = 200;
Vector3D const PoloNord = Vector3D(0., 0., 1.);
