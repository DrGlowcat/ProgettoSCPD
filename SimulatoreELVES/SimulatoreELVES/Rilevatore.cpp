/*Similmente alla classe Ionosfera, Rilevatore è un contenitore di Pixel. Anche qui è possibile definire la "risoluzione" del rilevatore
ovvero il numero di pixel del rilevatore stesso. Diversamente dalla classe Ionosfera possiamo avere più oggetti di tipo Rilevatore presenti
contemporaneamente nel sistema. Ogni pixel del rilevatore è associato a uno o più IonPixel, va quindi implementata una funzione che, 
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
