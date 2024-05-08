#pragma once
#include "Pagini.h"

login::login()
{
	struct nod_arbore* rad;

	 utilizator, parola_ascunsa , parola_normala ;

	 caseta_util = false, caseta_parola = false;

	 caractere_valide = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	 vizualizare_parola = false;

	  cod_eroare_util = -1, cod_eroare_par = -1;
}

void login::setare_caseta(short int x)
{
	if (x == 0)
		caseta_parola = caseta_util = false;
	else
		//x=1, am apasat caseta utilizator
		if (x == 1)
		{
			caseta_parola = false;
			caseta_util = true;

		}
	//am apasat caseta parola
		else
		{
			caseta_parola = true;
			caseta_util = false;
		}
}

bool login::util_apasat()
{
	return caseta_util;
}

bool login::parola_apasata()
{
	return caseta_parola;
}

char * login::get_util()
{
	return ( char*)utilizator.c_str();
}

char* login::get_par()
{
	return (char*)parola_normala.c_str();
}

char* login::get_par_asc()
{
	return (char*)parola_ascunsa.c_str();
}

//x=0->cod utilizator, x=1->cod parola
//cod=-1 nu sunt erori, cod=0 nu sunt caractere, cod=1 caractere invalide, cod = 2 -> parola gresita,utilizator invalid,utilizator inexistent
void login::set_cod_eroare(int x,int y)
{
	if (x == 0)
		cod_eroare_util = y;
	else
		cod_eroare_par = y;
}

void login::verificare_user()
{
	
	if (utilizator.find('#') != string::npos)
	{
		cod_eroare_util = 1;
	}
	else
	cod_eroare_util = -1;
}

void login::verificare_parola()
{
	if (parola_normala.find("#") != string::npos)
	{
		cod_eroare_par = 1;
	}
	else
	cod_eroare_par = -1;
}

void login::set_default()
{
	 utilizator = "", parola_ascunsa = "", parola_normala = "";
	 caseta_util = false, caseta_parola = false;
	 vizualizare_parola = false;
	 cod_eroare_util = -1, cod_eroare_par = -1;


}

void login:: util_add_caract(int x,int y)
{
	if (y<250) {
		if (caractere_valide.find(x) != string::npos)
			utilizator.push_back(x);
		else
			utilizator.push_back('#');
	}
}

void login::parol_add_caract(int x,int y)
{
	if (y<250) {
		if (caractere_valide.find(x) != string::npos)
			parola_normala.push_back(x);
		else
			parola_normala.push_back('#');
		parola_ascunsa.push_back('*');
	}
}

void login::util_eli_caract()
{
	if (utilizator.size() > 0)
		utilizator.pop_back();
}

void login::parol_eli_caract()
{
	if (parola_normala.size() > 0)
	{
		parola_normala.pop_back();
		parola_ascunsa.pop_back();
	}
}

void login::set_vizualizare_parola()
{
	if (vizualizare_parola == true)
		vizualizare_parola = false;
	else
		vizualizare_parola = true;
}

bool login::vizualizare_par()
{
	return vizualizare_parola;
}

int login::eroare_par()
{
	return cod_eroare_par;
}

int login::eroare_util()
{
	return cod_eroare_util;
}

//inserare in arborele digital(baza de date)
void login::inserare_cuvant( struct nod_arbore *r,string cuvant, string parola,int temaa,int index_lin)
{
	struct nod_arbore* nod2 = r;
	for (short int i = 0; i < cuvant.length(); i++)
	{
		int index;
		if (cuvant[i] >= 'a' && cuvant[i] <= 'z')
			index = cuvant[i] - 'a';
		else if (cuvant[i] >= 'A' && cuvant[i] <= 'Z')
			index = cuvant[i] - 'A' + 26;
		else
			index = cuvant[i] - '0' + 52;

		if (!nod2->fii[index])
			nod2->fii[index] = getNode();
		nod2 = nod2->fii[index];
	}
	nod2->este_cuvant = true;
	nod2->parola = parola;
	nod2->tema = temaa;
	nod2->index_linie = index_lin;
	index_linie = max(index_linie, index_lin);
}

void login::inserare_cuvant1(struct nod_arbore* r, string cuvant, int temaa)
{
	struct nod_arbore* nod2 = r;
	for (short int i = 0; i < cuvant.length(); i++)
	{
		int index;
		if (cuvant[i] >= 'a' && cuvant[i] <= 'z')
			index = cuvant[i] - 'a';
		else if (cuvant[i] >= 'A' && cuvant[i] <= 'Z')
			index = cuvant[i] - 'A' + 26;
		else
			index = cuvant[i] - '0' + 52;

		if (!nod2->fii[index])
			nod2->fii[index] = getNode();
		nod2 = nod2->fii[index];
	}
	nod2->este_cuvant = true;
	
	nod2->tema = temaa;
	
	
}

//cautare in arborele digital(baza de date)
bool login::cautare_cuvant( string cuvant, string& parola)
{
	struct nod_arbore* nod2 = rad;
	for (int i = 0; i < cuvant.size(); i++)
	{
		int index;
		if (cuvant[i] >= 'a' && cuvant[i] <= 'z')
			index = cuvant[i] - 'a';
		else if (cuvant[i] >= 'A' && cuvant[i] <= 'Z')
			index = cuvant[i] - 'A' + 26;
		else
			index = cuvant[i] - '0' + 52;

		if (!nod2->fii[index])
			return false;
		nod2 = nod2->fii[index];
	}
	if (nod2 != NULL && nod2->este_cuvant)
		parola = nod2->parola;
	tema = nod2->tema;
	index_linie = nod2->index_linie;
	return (nod2 != NULL && nod2->este_cuvant);
}

//creez un nou nod in arborele digital
void login:: getNodee()
{
	struct nod_arbore* nod1 = new nod_arbore;
	nod1->este_cuvant = false;
	for (int i = 0; i < dim_carcat_val; i++)
		nod1->fii[i] = NULL;
	rad = nod1;
}

//returnez radacina arborelui digital
struct nod_arbore* login::get_rad()
{
	return rad;
}

int login::get_tema()
{
	return tema;
}

int login::get_index()
{
	return index_linie;
}

void login::modificare_tema(int temaa)
{
	inserare_cuvant1(rad, utilizator_global, temaa);
	tema = temaa;
}
