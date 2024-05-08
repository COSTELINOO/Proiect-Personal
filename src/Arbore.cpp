#include "Arbore.h"
#include <cmath>
#include<iostream>
int informatii_generale_arbore::poz_rad_x; 
int informatii_generale_arbore::poz_rad_y;
int informatii_generale_arbore::inaltime;
int informatii_generale_arbore::nr_max_fii;
int informatii_generale_arbore::lungime;
int informatii_generale_arbore::scris;
class arbore* informatii_generale_arbore::rad = nullptr;


void informatii_generale_arbore :: set_poz_x_rad(int x)
{
	poz_rad_x = x;
}


int informatii_generale_arbore::get_lungime_patrat()
{
	return lungime;
}


int informatii_generale_arbore::get_marime_scris()
{
	return scris ;
}

void informatii_generale_arbore::set_lungime_patrat(int x)
{
	lungime = x;
}

void informatii_generale_arbore::set_marime_scris(int x)
{
	scris = x;
}

int informatii_generale_arbore::get_poz_x_rad()
{
	return poz_rad_x;
}

void informatii_generale_arbore::set_poz_y_rad(int y)
{
	poz_rad_y = y;
}

int informatii_generale_arbore::get_poz_y_rad()
{
	return poz_rad_y;
}

void informatii_generale_arbore::set_inaltime(int h)
{
	inaltime = h;
}

int informatii_generale_arbore::get_inaltime()
{
	return inaltime;
}

//in caz de adaugare/stergere nod
void informatii_generale_arbore::reinitializare_nivele(arbore* a, int niv)
{
	if (a != nullptr)
	{
		a->set_nivel(niv);

		if(a->fiu!=nullptr)

		for (int i = 0; i < nr_max_fii; i++)

			reinitializare_nivele(a->fiu[i], niv + 1);
	}
}

//in caz de adaugare/stergere nod
void informatii_generale_arbore::calculare_inaltime(arbore* a)
{

	if (a != nullptr) {

		inaltime = std::max(inaltime, a->get_nivel());

		if(a->fiu!=nullptr)

		for (int i = 0; i < nr_max_fii; i++)
		{

			calculare_inaltime(a->fiu[i]);
		
		}
	}
		
	
	
	
}



void informatii_generale_arbore::set_radacina(arbore* a)
{
	rad = a;
}


//verific daca am dat click pe un nod
arbore* informatii_generale_arbore::cautare_click(int p_x, int p_y, arbore* a,int & code)
{
	if (a != nullptr )
	{
		
		if (p_x >= a->get_poz_x() && p_x <= a->get_poz_x() + get_lungime_patrat() && p_y >= a->get_poz_y() && p_y <= a->get_poz_y() + get_lungime_patrat())
		{

			if (a->fiu == nullptr)

				code = 1;

			else 

				code = 2;
			
			return a;
		}

		arbore* b;

		if (a->fiu != nullptr)

		for (int i = 0; i < nr_max_fii; i++)

		{
			b = cautare_click(p_x, p_y, a->fiu[i],code);

			if (b != nullptr)

				return b;
		}

	}
	

	code =std:: max(code,0);

	return nullptr;
}



arbore* informatii_generale_arbore::get_radacina()
{
	return rad;
}

int informatii_generale_arbore::get_nr_max_fii()
{
	return nr_max_fii;
}


arbore::arbore(int n)
{
	fiu = nullptr;
	nivel = n;
	
}


//desenarea arborelui
void informatii_generale_arbore::desenare_arbore(int deplasament_x, int deplasament_y, arbore *&n,int index,Color tema1[],Font font3)
{
	if (n != NULL)
	{

		int nr_max_fii = n->get_nr_max_fii();

		int inaltime = n->get_inaltime();

		int nivel = n->get_nivel();

		int poz_x_rad = n->get_poz_x_rad();

		int poz_y_rad = n -> get_poz_y_rad();

		int lungime = n->get_lungime_patrat();

		int marime_scris = n->get_marime_scris();

		//pozitia primul nod de pe un nivel fata de radacina, de la stanga, masurata in nr de noduri
		int p_n_k = pow(nr_max_fii, inaltime -nivel) - 1;

		//pozitia maxima de la radcina(pozitia primului nod de pe ultimul nivel
		int d_max = pow(nr_max_fii, inaltime - 1) - 1;

		int aux1 = pow(nr_max_fii, nivel - 1) ;

		//distnta dintre noduri
		int	d_n;
		if (aux1 - 1 == 0)
			d_n = 1;
		else
			d_n= (2*d_max+1-2*p_n_k-aux1)/(aux1-1)+1;
		
		int formula1 = poz_x_rad - d_max * lungime + p_n_k * lungime + d_n * index * lungime + deplasament_x;
		
		int formula1_y = nivel * lungime*2 + deplasament_y;

		n->set_poz_x_poz_y(formula1, formula1_y);
	
		if (n->fiu == nullptr)
		{
			
			DrawRectangle(formula1, formula1_y, lungime, lungime, tema1[3]);

			DrawRectangle(formula1+3, formula1_y +3, lungime - 6, lungime - 6, tema1[2]);

			DrawTextEx(font3, "NULL", {1.0f * formula1  + (lungime - MeasureTextEx(font3,"NULL",marime_scris,0).x) / 2,1.0f * formula1_y + (lungime - MeasureTextEx(font3,"NULL",marime_scris,0).y) / 2}, marime_scris, 0, tema1[1]);
		
		}
		else
		{
			DrawRectangle(formula1, formula1_y, lungime, lungime, tema1[4]);

			DrawRectangle(formula1+3, formula1_y + 3, lungime - 6, lungime - 6, LIGHTGRAY);

			DrawTextEx(font3, n->get_value(), {1.0f* formula1  + (lungime - MeasureTextEx(font3,n->get_value(),marime_scris,0).x) / 2,1.0f* formula1_y + (lungime - MeasureTextEx(font3,n->get_value(),marime_scris,0).y)/2 },marime_scris, 0, tema1[5]);
			
			int p_n_k_f = pow(nr_max_fii, n->inaltime - nivel - 1) - 1;
			
			int aux1_f = pow(nr_max_fii, nivel);

			int d_n_f;

			if (aux1_f == 1)

				 d_n_f = 1;
			else

			 d_n_f = (2 * d_max + 1 - 2 * p_n_k_f - aux1_f) / (aux1_f - 1) + 1;

			int formula2 = poz_x_rad - d_max * lungime + p_n_k_f * lungime + lungime/2 + deplasament_x;

			int formula2_y = formula1_y + lungime;

			for (int i = 0; i < nr_max_fii; i++)
			{				
				DrawLine(formula1+ lungime/2, formula2_y, formula2 + d_n_f *(i+ index * nr_max_fii) * lungime, formula2_y + lungime, tema1[3]);
				
				desenare_arbore(deplasament_x, deplasament_y, n->fiu[i], i+index*nr_max_fii, tema1, font3);				
			}

		
		}
	}
}


//se recalculeaza pozitiile fiecarui nod
void informatii_generale_arbore::recalculare_pozitii(arbore*& n, int index)
{
	if (n != NULL)
	{
		int nr_max_fii = n->get_nr_max_fii();

		int inaltime = n->get_inaltime();

		int nivel = n->get_nivel();

		int poz_x_rad = n->get_poz_x_rad();

		int poz_y_rad = n->get_poz_y_rad();

		int lungime = n->get_lungime_patrat();

		int p_n_k = pow(nr_max_fii, inaltime - nivel) - 1;

		int d_max = pow(nr_max_fii, inaltime - 1) - 1;

		int aux1 = pow(nr_max_fii, nivel - 1);

		int	d_n;

		if (aux1 - 1 == 0)

			d_n = 0;

		else

			d_n = (2 * d_max + 1 - 2 * p_n_k - aux1) / (aux1 - 1) + 1;

		int formula1 = poz_x_rad - d_max * lungime + p_n_k * lungime + d_n * index * lungime ;

		int formula1_y = nivel * lungime * 2 ;

		n->set_poz_x_poz_y(formula1, formula1_y);
		
		if (n->fiu != nullptr)
		{
			
			for (int i = 0; i < nr_max_fii; i++)
			{
				recalculare_pozitii( n->fiu[i], i + index * nr_max_fii);
			}


		}
	}
}

//functie pentru sortare
void informatii_generale_arbore::interclasare(int st, int m, int dr, arbore*& a)
{
	arbore** aux = new arbore * [nr_max_fii];

	int i = st, j = m + 1, k = 0;

	while (i <= m && j <= dr)
	{
		if (a->fiu[i]->fiu != nullptr)

		{
			if (a->fiu[j]->fiu == nullptr)
			{
				aux[k] = a->fiu[i];

				i++;
			}
			else
				if (strlen(a->fiu[i]->get_value()) > strlen(a->fiu[j]->get_value()))
				{
					aux[k] = a->fiu[j];

					j++;
				}
				else if (strlen(a->fiu[i]->get_value()) < strlen(a->fiu[j]->get_value()))
				{
					aux[k] = a->fiu[i];

					i++;
				}
				else
				if (strcmp(a->fiu[i]->get_value(), a->fiu[j]->get_value()) < 0)
				{
					aux[k] = a->fiu[i];

					i++;
				}
				else
				{
					aux[k] = a->fiu[j];

					j++;
				}
		}
		else

			if (a->fiu[j]->fiu == nullptr)
			{
				aux[k] = a->fiu[i];

				i++;

			}
			else
			{
				aux[k] = a->fiu[j];

				j++;

			}

		k++;
	}
	while (i <= m)
	{
		aux[k] = a->fiu[i];

		i++;

		k++;
	}
	while (j <= dr)
	{
		aux[k] = a->fiu[j];

		j++;

		k++;
	}

	k = 0;

	for (i = st; i <= dr; i++, k++)
	{
		a->fiu[i] = aux[k];
	}
}


//algoritm de sortare pentru un nivel
void informatii_generale_arbore::merge_sort(int st, int dr, arbore*& a)
{
	if (dr - st <= 1)
	{
		if (a->fiu[dr]->fiu != nullptr)
		{
			if (a->fiu[st]->fiu == nullptr)
			{
				arbore* aux = a->fiu[st];

				a->fiu[st] = a->fiu[dr];

				a->fiu[dr] = aux;
			}
			else
				if (strcmp(a->fiu[st]->get_value(), a->fiu[dr]->get_value()) > 0&& strlen(a->fiu[st]->get_value())==strlen(a->fiu[dr]->get_value()))
				{
					arbore* aux = a->fiu[st];

					a->fiu[st] = a->fiu[dr];

					a->fiu[dr] = aux;
				}
				else if (strlen(a->fiu[st]->get_value()) > strlen(a->fiu[dr]->get_value()))
				{
					
						arbore* aux = a->fiu[st];

						a->fiu[st] = a->fiu[dr];

						a->fiu[dr] = aux;
					
				}
		}
	}
	else
	{
		int m = (st + dr) / 2;

		merge_sort(st, m, a);

		merge_sort(m + 1, dr, a);

		interclasare(st, m, dr, a);
	}
}


//sortarea tuturor nivelelor
void informatii_generale_arbore::sortare(arbore*& a)
{

	if (a != nullptr && a->fiu != nullptr)
	{

		merge_sort(0, nr_max_fii - 1, a);

		for (int i = 0; i < a->get_nr_max_fii(); i++)
		{
			sortare(a->fiu[i]);

		}

	}

}

//cautarea unui nod dupa cheie/valoare
arbore* informatii_generale_arbore::cautare(arbore* a, const char* key)
{
	if (a->fiu != nullptr)
	{
		if (strcmp(a->get_value(), key) == 0)
		{
			return a;
		}
		arbore* ver;
		for (int i = 0; i < a->get_nr_max_fii(); i++)
		{
			ver = cautare(a->fiu[i], key);

			if (ver != nullptr)

				return ver;
		}

	}

	return nullptr;
}


void arbore::set_value(char* c)
{
	strcpy(value, c);
}

char* arbore::get_value()
{
	return value;
}

void arbore::set_poz_x_poz_y(int x, int y)
{
	poz_x = x;
	poz_y = y;
}

void arbore::set_nivel(int niv)
{
	nivel = niv;
}

bool arbore::operator !()
{
	if (fiu != NULL)
		return true;
	return false;
}

int arbore::get_nivel()
{
	return nivel;
}

int arbore::get_poz_x()
{
	return poz_x;
}

int arbore::get_poz_y()
{
	return poz_y;
}

//creare nod
void arbore::creare(const char* c)
{

	fiu = new arbore * [nr_max_fii];
	
	for (int i = 0; i < nr_max_fii; i++)
	{
		fiu[i] = new arbore(nivel + 1);


	}

	if (nivel + 1 > inaltime)

		inaltime = nivel + 1;

	value = new char[strlen(c)];

	strcpy(value, c);

}

void  informatii_generale_arbore::set_nr_max_fii(int n)
{

	nr_max_fii = n;
}

//stergere nod cu tot cu subarbore
void informatii_generale_arbore::stergere(arbore* a)
{
	if (a->fiu != nullptr)
	{
		for (int i = 0; i < nr_max_fii; i++)
		{
			stergere(a->fiu[i]);

		}

		delete[]a->fiu;

		a->fiu = nullptr;

	}



}

arbore::~arbore()
{
	value = nullptr;
	
	for (int i = nr_max_fii; i > 0; i--)
	{
		stergere(fiu[i]);

		delete fiu[i];
		
	}

	delete []fiu;


}