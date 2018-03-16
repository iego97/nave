#pragma once
#include "Modelo.h"

class Nave : public Modelo
{
	public:
		Nave();
		float angulo;
		vec3 coordenadas;
		float velocidadAngular = 0.001f;
		void rotarNave(int direccion);
		void moverNave();
		float velocidad = 0.0005f;
};

