#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 
#include "raylib.h"
#include<cstring>

#include<iostream>
class arbore;

class informatii_generale_arbore
{
	
public:
	static arbore* rad;

	static int poz_rad_x, poz_rad_y, inaltime,nr_max_fii;

	static int lungime, scris;

	void set_radacina(arbore* a);

	arbore* get_radacina();

	void set_poz_x_rad(int x);

	int get_poz_x_rad();

	void set_poz_y_rad(int y);

	int get_poz_y_rad();

	void set_nr_max_fii(int n);

	int get_nr_max_fii();

	void set_lungime_patrat(int x);

	void set_marime_scris(int x);

	int get_lungime_patrat();

	int get_marime_scris();	

	void set_inaltime(int h);

	int get_inaltime();

	void calculare_inaltime(arbore *a);

	void reinitializare_nivele(arbore* a, int niv);

	void recalculare_pozitii( arbore*& n, int index);

	void desenare_arbore(int deplasament_x,int deplasament_y,arbore *&n,int index,Color tema1[],Font font3);

	void interclasare(int st, int m, int dr, arbore*& a);

	void merge_sort(int st, int dr, arbore*& a);

	void sortare(arbore*& a);

	arbore* cautare(arbore* a, const char* key);

	arbore* cautare_click(int p_x, int p_y, arbore* a,int &code);

	void stergere(arbore* a);
};


class arbore:public informatii_generale_arbore
{
	
	char* value ;

	int nr_fii;

	int nivel=1;

	int poz_x, poz_y;

	
public:
	arbore** fiu;

	arbore(int n);

	~arbore();

	void set_nivel(int niv);

	bool operator !();

	int get_nivel();

	int get_poz_x();

	int get_poz_y();

	 void set_value(char* c);

	 char* get_value();

	 void set_poz_x_poz_y(int x, int y);

	 void creare(const char* c);
	 
};




