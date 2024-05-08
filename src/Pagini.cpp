#pragma once
#include "Pagini.h"
struct nod_arbore;

//constructori fereastra
fereastra::fereastra()
{	
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	latime = max_x;
	inaltime = max_x;
	poz_x = poz_y = 0;
	nume = "Fereastra";
	background = WHITE;
}

fereastra::fereastra(unsigned short int x):latime(x),inaltime(x) 
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	background=WHITE;
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	nume = "Fereastra";
}

fereastra::fereastra(unsigned short int  x, unsigned short int  y) :latime(x), inaltime(y)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	background = WHITE;
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	nume = "Fereastra";
}

fereastra::fereastra(Color culoare):background(culoare)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	latime = max_x;
	inaltime = max_x;
	poz_x = poz_y = 0;
	nume = "Fereastra";
	
}

fereastra::fereastra(string text) :nume(text)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	latime = max_x;
	inaltime = max_x;
	poz_x = poz_y = 0;
	background = WHITE;

}

fereastra::fereastra(unsigned short int x,Color culoare) :latime(x), inaltime(x),background(culoare)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	nume = "Fereastra";
}

fereastra::fereastra(unsigned short int x,string text):latime(x), inaltime(x),nume(text)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	background = WHITE;
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;

}

fereastra::fereastra(unsigned short int x,Color culoare,string text):latime(x), inaltime(x),background(culoare),nume(text)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;

}

fereastra::fereastra(unsigned short int  x, unsigned short int  y,Color culoare) :latime(x), inaltime(y),background(culoare)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	nume = "Fereastra";
}

fereastra::fereastra(unsigned short int  x, unsigned short int  y,string text) :latime(x), inaltime(y),nume(text)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	background = WHITE;
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	
}

fereastra::fereastra(unsigned short int  x, unsigned short int y,Color culoare, string text) :latime(x), inaltime(y),background(culoare),nume(text)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	
}

fereastra::fereastra(Color culoare,string text) :background(culoare),nume(text)
{
	max_x = GetScreenWidth();
	max_y = GetScreenHeight();
	latime = max_x;
	inaltime = max_x;
	poz_x = poz_y = 0;
	

}

//functii membre
void fereastra::initiere_fereastra()
{
	const char* c=nume.c_str();
	
	SetWindowSize(latime,inaltime);
	SetWindowPosition(poz_x, poz_y);
	ClearBackground(background);
}

Color fereastra::return_culoare_background()
{
	return background;
}

void fereastra::draw_page(fereastra d,int &cod,Font &font,login &conectare)
{
	if (cod == 0)
		draw_homepage( d ,cod,font);
	else if(cod==1)
		draw_fer_autentificare(d,cod, font,  conectare);
	else if (cod== 2)
		draw_fer_inregistrare(d,cod, font,  conectare);

}

void fereastra::draw_page(fereastra& d, int& code, Font font,Font font1, Font font2, string utilizator,login &conectare)
{
	if (code == 3)
		draw_fer_meniu(d,code, font,font1,font2,utilizator,conectare);
}

void fereastra:: resize_fereastra(int x, int y)
{
	latime = max(x,700);
	inaltime = max(y,630);

}

unsigned short int fereastra::get_latime_fereastra()
{
	return latime;
}

unsigned short int fereastra::get_inaltime_fereastra()
{
	return inaltime;
}

void fereastra::setare_pozitie_fereastra()
{
	poz_x = (max_x - latime) / 2;
	poz_y = (max_y - inaltime) / 2;
	SetWindowPosition(poz_x, poz_y);
}

void fereastra:: set_background_color(Color culoare)
{
	background = culoare;
}

