/*Similmente alla classe Ionosfera, Rilevatore � un contenitore di Pixel. Anche qui � possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere pi� oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore � associato a uno o pi� IonPixel, va quindi implementata una funzione che, 
potenzialmente, possa sommare i vari contributi.*/
#include "stdafx.h"
#include "Rilevatore.h"


Rilevatore::Rilevatore()
{

}


Rilevatore::~Rilevatore()
{

}

RelPixel Rilevatore::FindPixel(double In_X, double In_Y, double In_Z)
{

}
double Rilevatore::GetStatus()
{

}
