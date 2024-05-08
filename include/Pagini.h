#pragma once
#include "Librarii.h"
#include "GlobalFunctions.h"
const int dim_carcat_val = 62;

struct nod_arbore
{
    struct nod_arbore* fii[dim_carcat_val];

    bool este_cuvant;

    string parola;

    int tema;

    int index_linie;
};

class login;

class fereastra
{
private:
    unsigned short int max_x ;
    
    unsigned short int max_y ;

    unsigned short int inaltime;

    unsigned short int latime;

    unsigned short int poz_x;

    unsigned short int poz_y;
     
    Color background;

    string nume;
   

public:

    fereastra();

    fereastra(unsigned short int x) ;

    fereastra(unsigned short int x,Color culoare);

    fereastra(unsigned short int x,string text);

    fereastra(unsigned short int x,Color culoare,string text);


    fereastra(unsigned short  int x, unsigned short  int y);

    fereastra(unsigned short  int x, unsigned short   int y, Color culoare);

    fereastra(unsigned short  int x, unsigned short   int y, string text );

    fereastra(unsigned short int x, unsigned short  int y, Color culoare, string text);


    fereastra(Color culoare);

    fereastra(Color culoare,string text);

    fereastra(string text);

    
 

    Color return_culoare_background();

    unsigned short int get_latime_fereastra();

    unsigned short int get_inaltime_fereastra();
   
    void resize_fereastra(int x, int y);
   
    void initiere_fereastra();

    void setare_pozitie_fereastra();

    //pagina bun venit,autentificare si inregistrare
    void draw_page(fereastra d,int &code,Font &font, login &conectare);

    //restul paginilor
    void draw_page(fereastra& d, int& code, Font font,Font font1,Font font2,string utilizator ,login & conectare);

    void set_background_color(Color culoare);

    friend void draw_homepage(fereastra  d,int& cod, Font font);
    friend void draw_fer_inregistrare(fereastra d,int& cod, Font &font, login& conectare);
    friend void draw_fer_autentificare(fereastra d,int& cod, Font &font, login& conectare);
    friend void draw_fer_meniu(fereastra& d, int& code, Font font,Font font1,Font font2, string utilizator,login &conectare);
};

class login
{
private: 
   struct nod_arbore *rad ;

   string utilizator , parola_ascunsa , parola_normala ;

    bool caseta_util, caseta_parola;

    string caractere_valide ;

    bool vizualizare_parola ;

    short int cod_eroare_util ,cod_eroare_par;
    short int tema = 1;
   int index_linie=0;

public:
    string utilizator_global;
	login();

    void set_vizualizare_parola();

    void set_cod_eroare(int x, int y);

    bool vizualizare_par();

    void util_add_caract(int x,int y);

    void parol_add_caract(int x,int y);

    void util_eli_caract();

    void parol_eli_caract();

    void set_default();

    void verificare_user();

   void  inserare_cuvant1(struct nod_arbore* r, string cuvant, int temaa);

    void verificare_parola();


    void setare_caseta(short int i);

    bool util_apasat();

    bool parola_apasata();

    char * get_util();

    char *get_par();

    char *get_par_asc();

    int eroare_util();

    int eroare_par();

    void getNodee();

    struct nod_arbore * get_rad();
    int get_tema();

    void inserare_cuvant(struct nod_arbore *node, string cuvant, string parola,int tema,int index_lin);

    bool cautare_cuvant( string cuvant, string& parola);

    void modificare_tema(int temaa);

    int get_index();

};
