#pragma once
#include "Pagini.h"


class login;

class fereastra;

void draw_homepage(fereastra d, int& cod, Font font);

void draw_fer_inregistrare(fereastra d, int& cod, Font &font, login& conectare);

void draw_fer_autentificare(fereastra d, int& cod, Font &font, login& conectare);

void draw_normal_rectangle(int x, int y, int lungime, int inaltime, const char* text, Font font, Font font2, int cnt_text, Color culoare1, Color culoare2);

void draw_special_rectangle(int x, int y, int lungime, int inaltime, const char* text1, const char* text2, Font font, Font font2, int cnt_text, int cnt_text1, Color culoare1, Color culoare2, Color culoare3);

void draw_fer_meniu(fereastra& d, int& code, Font font,Font font1, Font font2, string utilizator,login&conectare);

struct nod_arbore* getNode();

void draw_setare_nr_fii(int poz_x,int poz_y,int& nr_fii,Font font, char* find_arbore, int& poz_find,int &code, arbore*& tree);

void draw_adaugare_nod(int& nr_fii, Font font, char* find_arbore, int& poz_find, int& code,arbore *&temp,int& poz_x, int& poz_y);

void draw_modificare_nod(int& nr_fii, Font font, char* find_arbore, int& poz_find, int& code, arbore* &temp, int& poz_x, int& poz_y);

void draw_page_arbore(int x,int y,Font font,Font font3,int &code,int &poz_x,int &poz_y, int &xd, int&yd, int&xu, int&yu,char *find_arbore,int & poz_find,arbore *tree,arbore* &temp);