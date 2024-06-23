#pragma once
#include "persona.h"
#include"conexionbd.h"
#include<iostream>
#include<mysql.h>
#include<string>

using namespace std;

class estudiante : persona
{
	//atributos
private: string codigo;
	   int id_estudiante = 0;

	   //constructos
public :

	   estudiante (){}
	   estudiante(string nom, string ape, string dir, int tel,string fn,int id_ts,string cod,int id_e, string correo)
		   : persona(nom,ape,dir,tel,fn,id_ts,correo) {
		   codigo = cod;
		   id_estudiante = id_e;
		   

	   }
	   //metodos get y set
	   void setid_estudiante(int e) { id_estudiante = e; }
	   void setcodigo(string c) { codigo = c; }
	   void setnombres(string n) { nombres = n; }
	   void setapellidos(string a) { apellidos = a; }
	   void setdireccion(string d) { direccion = d; }
	   void settelefono(int t) { telefono = t; }
	   void setfecha_nacimiento(string f) {fecha_nacimiento= f;  }
	   void setid_tipo_sangre(int ts) { id_tipo_sangre = ts; }
	   void setcorreo_electronico(string co) { correo_electronico = co; }

	   // retorna un valor
	   int getid_estudiante() { return id_estudiante ; }
	   string getcodigo() { return codigo; }
	   string getnombres() { return nombres; }
	   string getapellidos() { return apellidos ; }
	   string getdireccion() { return direccion ; }
	   int gettelefono() { return telefono ; }
	   string getfecha_nacimiento() { return fecha_nacimiento ; }
	   int getid_tipo_sangre() { return id_tipo_sangre ; }
	   string getcorreo_electronico() { return correo_electronico; }
	   //metodos 
	   void crear() {
		   int q_estado = 0;
		   conexionbd cn = conexionbd();
		   cn.abrir_conexion();
		   if (cn.getconector()) {
			   string t = to_string(telefono);
			   string id_ts = to_string(id_tipo_sangre);
			   string consulta = "INSERT INTO db_escuela.estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre,correo_electronico )VALUES('"+ codigo+"', '"+nombres+"','"+apellidos+"', '"+direccion+"', "+ t +", '"+ fecha_nacimiento+"', "+id_ts+", '"+correo_electronico+"');";
			   const char* c= consulta.c_str();
			   q_estado = mysql_query(cn.getconector(), c);
			   if (!q_estado) {
				   cout << "__________ingreso exitoso___________" << endl;
			   }
			   else {
				   cout << "xxxxxxxx consulta fallida xxxxxxxxx" << endl;
			   }
		   }
		   else {
			   cout << "xxxxxxxxxxxconexion fallidaxxxxx" << endl;
		   }


	   }
	   void leer() {
		   int q_estado = 0;
		   conexionbd cn = conexionbd();
		   MYSQL_ROW fila;
		   MYSQL_RES* resultado;
		   cn.abrir_conexion();
			   if (cn.getconector()) {
				   cout << "______________datos del estudiante________" << endl;
				   string consulta = "SELECT e.id_estudiante as id, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono, e.fecha_nacimiento,ts.sangre,e.correo_electronico FROM estudiantes as e inner join tipos_sangre as ts on e.id_tipo_sangre = ts.id_tipo_sangre ;";
				   const char* c = consulta.c_str();

				   q_estado = mysql_query(cn.getconector(), c);
				   if (!q_estado) {

					   resultado = mysql_store_result(cn.getconector());
					   while (fila = mysql_fetch_row(resultado))
						   cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << " / " << fila[5] << " / " << fila[6] << " / " << fila[7] << " / " << fila[8]<< endl;
				   }

			   }
			   else { cout << "xxxxxx fallo la conexion "; }
			   cn.cerrar_coxion();
		   
	   }
	   void actualizar() {
		   int q_estado = 0;
		   conexionbd cn = conexionbd();
		   cn.abrir_conexion();
		   if (cn.getconector()) {
			   string t = to_string(telefono);
			   string id_ts = to_string(id_tipo_sangre);
			   string id_e = to_string(id_estudiante);
			   string consulta = "UPDATE db_escuela.estudiantes SET  codigo ='" + codigo + "' ,nombres ='" + nombres + "' ,apellidos='" + apellidos + "' ,direccion = '" + direccion + "',telefono =" + t + " ,fecha_nacimiento= '" + fecha_nacimiento + "',id_tipo_sangre =" + id_ts +"  , correo_electronico = '"+correo_electronico+"' WHERE id_estudiante= " + id_e + "";
			   const char* c = consulta.c_str();
			   q_estado = mysql_query(cn.getconector(), c);
			   if (!q_estado) {
				   cout << "__________modificacion exitoza ___________" << endl;
			   }
			   else {
				   cout << "xxxxxxxx modificacion fallida xxxxxxxxx" << endl;
			   }
		   }
		   else {
			   cout << "xxxxxxxxxxxconexion fallidaxxxxx" << endl;
		   }


	   }
		void eliminar () {
			int q_estado = 0;
			conexionbd cn = conexionbd();
			cn.abrir_conexion();
			if (cn.getconector()) {
				string t = to_string(telefono);
				string id_ts = to_string(id_tipo_sangre);
				string id_e = to_string(id_estudiante);
				string consulta = "DELETE FROM db_escuela.estudiantes WHERE id_estudiante= " + id_e + ";";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getconector(), c);
				if (!q_estado) {
					cout << "__________eliminacion exitoza ___________" << endl;
				}
				else {
					cout << "xxxxxxxx modificacion fallida xxxxxxxxx" << endl;
				}
			}
			else {
				cout << "xxxxxxxxxxxconexion fallidaxxxxx" << endl;
			}


		}


};

