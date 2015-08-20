/*file che contiene tutte le costanti ed eventuali funzioni user defined eccetera. Per il momento metto qui anche i
prototipi delle operazioni vettoriali, ma mi stavo chiedendo se non valga la pena di creare una classe "vettore 3D"
con tutta la sua algebra
*/

#pragma once
#include <cmath>

#define CONST_spdoflight = 0.3;  //in km/microsec
#define CONST_pi = 3.14159265359;
#define CONST_degree = pi/180.  //conversione gradi-radianti
#define CONST_r_earth = 6371.  //raggio terrestre in km

double longsites[4] = {-69.449673,-69.012203,-69.210845,-69.499633};  //longitudini dei 4 telescopi
double latsites[4] = {-35.495759,-35.291974,-34.935916,-35.114138};  //latitudini dei telescopi
//per i vettori: 0=LosLeones, 1=LosMorados, 2=LomaAmarilla, 3=Coihueco
double backwall[4] = {-30.00,60.03,-171.85,-116.68};  //orientamento della zona cieca di ciascun telesc, in gradi rispetto all'est

//algebra vettoriale; supponiamo che i vettori 3D siano del tipo v={x,y,z}
double Norma(double *);  //calcola norma del vettore dato un puntatore al vettore
double Dot(double *,double *);  //prodotto scalare tra due vettori
double Cross(double *,double *);  //prodotto vettoriale tra due vettori --> restituisce un vettore, non so se il prototipo è giusto così
double GetTheta(double *);  //restituisce angolo polare, devo capire in quale sistema di riferimento conviene mettersi
double GetPhi(double *);  //restituisce azimut
double Angle(double *,double *);  //angolo tra due vettori

//ho delle librerie per la risoluzione di equazioni differenziali, prenderemo da lì i metodi che ci servono per le eqMax
