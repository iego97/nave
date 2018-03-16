#include "stdafx.h"
#include "Nave.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

Nave::Nave()
{
	angulo = 90.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	transformaciones = mat4(1.0f);
}

void Nave::rotarNave(int direccion)
{
	float rotacion = velocidadAngular;
	if (direccion == 1)
	{
		rotacion = -rotacion;
	}

	transformaciones = rotate(transformaciones, rotacion, vec3(0.0f, 0.0f, 1.0f));

	angulo += rotacion;

}

void Nave::moverNave()
{

	vec3 traslaciones = (transformaciones, vec3(cos(angulo * 3.14159 / 180) * velocidad,
		sin(angulo * 3.14159 / 180.0f), 0.0f)*velocidad);
	
	transformaciones = translate(transformaciones, vec3(cos(angulo * 3.14159 / 180) * velocidad,
		sin(angulo * 3.14159 / 180.0f), 0.0f)*velocidad);

	coordenadas += traslaciones;

	if (coordenadas.y >= 1)
	{
		coordenadas.y -= 2;

		transformaciones = translate(transformaciones, vec3(0.0f, -2.0f, 0.0f));
	}
}