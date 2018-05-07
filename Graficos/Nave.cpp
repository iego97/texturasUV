#include "stdafx.h"
#include "nave.h"

Nave::Nave() {

	angulo = 90.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	modelo = mat4(1.0f);
}

void Nave::rotanave(int direccion) {
	float rotacion = velocidadAngular;
	if (direccion == 1) {
		rotacion = -rotacion;
	}
	modelo =
		rotate(modelo, rotacion, vec3(0.0f, 0.0f, 1.0f));

	angulo += rotacion;
}

void Nave::movernave() {
	vec3 traslacion = vec3(cos(angulo * 3.14159f / 180.0f)* velocidad,
		sin(angulo * 3.14159f / 180.0f) * velocidad, 0.0f);


		modelo =
			translate(modelo, traslacion);
		coordenadas += traslacion;

		if (coordenadas.y >= 1.2f) {
			coordenadas.y -= 2.2f;
			modelo =
				translate(modelo, vec3(0.0f, -2.2f, 0.0f));
		}
}
