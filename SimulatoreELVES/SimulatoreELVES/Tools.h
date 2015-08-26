/*file che contiene tutte le costanti ed eventuali funzioni user defined eccetera. Per il momento metto qui anche i
prototipi delle operazioni vettoriali, ma mi stavo chiedendo se non valga la pena di creare una classe "vettore 3D"
con tutta la sua algebra
*/

#pragma once
#include <cmath>

#define CONST_spdoflight = 0.3;  //in km/microsec
#define CONST_pi = 3.14159265359;
#define CONST_degree = CONST_pi/180.  //conversione gradi-radianti
#define CONST_r_earth = 6371.  //raggio terrestre in km

double longsites[4] = {-69.449673,-69.012203,-69.210845,-69.499633};  //longitudini dei 4 telescopi
double latsites[4] = {-35.495759,-35.291974,-34.935916,-35.114138};  //latitudini dei telescopi
//per i vettori: 0=LosLeones, 1=LosMorados, 2=LomaAmarilla, 3=Coihueco
double backwall[4] = {-30.00,60.03,-171.85,-116.68};  //orientamento della zona cieca di ciascun telesc, in gradi rispetto all'est

//ho delle librerie per la risoluzione di equazioni differenziali, prenderemo da lì i metodi che ci servono per le eqMax
