#pragma once
#include<mysql.h>
#include<iostream>
using namespace std;
//
class conexionbd {
private: MYSQL * conector;
public:
	void abrir_conexion(){ 
	conector = mysql_init(0);
	conector = mysql_real_connect(conector, "127.0.0.1", "root", "root", "db_escuela", 3306, NULL, 0);

	
	
	};
	MYSQL* getconector() {
		return conector;
	}
	void cerrar_coxion() {
		mysql_close(conector);
	}

};

