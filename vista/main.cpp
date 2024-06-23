// vista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "conexionbd.h"
#include "estudiante.h"
using namespace std;

int main()
{
	string codigo, nombres, apellidos, direccion, fecha_nacimineto,correo_electronico;
	int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;
	
	cout << " ingrese codigo: ";
	cin >> codigo;
	cin.ignore();
	cout << "ingrese nombres: ";
	getline(cin, nombres);
	cout << "ingrese apellidos: ";
	getline(cin, apellidos);
	cout << "ingrese direccion: ";
	getline(cin, direccion);
	cout << "ingrese telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese fecha nacimineto: ";
	getline(cin, fecha_nacimineto);
	

	cout << "ingrese el tipo de sangre: ";
	cin >> id_tipo_sangre;
	cin.ignore();
	cout << "ingrese correo electronico: ";
	getline(cin, correo_electronico);
	
	estudiante e = estudiante(nombres, apellidos, direccion, telefono, fecha_nacimineto, id_tipo_sangre, codigo, id_estudiante,correo_electronico);
	e.crear();

	e.leer();

	//actualizar 
	
	cout << "ingrese el id a modificar :" ;
	cin >> id_estudiante;
	cout << " ingrese codigo: ";
	cin >> codigo;
	cin.ignore();
	cout << "ingrese nombres: ";
	getline(cin, nombres);
	cout << "ingrese apellidos: ";
	getline(cin, apellidos);
	cout << "ingrese direccion: ";
	getline(cin, direccion);
	cout << "ingrese telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese fecha nacimineto: ";
	getline(cin, fecha_nacimineto);
	cout << "ingrese el tipo de sangre: ";
	cin >> id_tipo_sangre;
	cin.ignore();
	cout << "ingrese correo electronico: ";
	getline(cin, correo_electronico);

	e.setid_estudiante(id_estudiante);
	e.setcodigo(codigo);
	e.setnombres(nombres);
	e.setapellidos(apellidos);
	e.setdireccion(direccion);
	e.settelefono(telefono);
	e.setfecha_nacimiento(fecha_nacimineto);
	e.setid_tipo_sangre(id_tipo_sangre);
	e.setcorreo_electronico(correo_electronico);

	e.actualizar();
	e.leer();

	
	cout << "ingrese el id a aliminar  :";
	cin >> id_estudiante;
	e.setid_estudiante(id_estudiante);
	e.eliminar();
	e.leer();




	system("pause"); 

		return 0;
}
