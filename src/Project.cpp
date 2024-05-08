#include "Pagini.h"
#include "GlobalFunctions.h"

fstream fin("Utilizatori+parole/utilizatori.txt",std::ios::in | std::ios::out);

int main() {

   
    int poz_x = 0, poz_y = 0,xd=0,yd=0,xu=0,yu=0;
    char find_arbore[10];
    find_arbore[0] = 0;
    int nr_fii = 0;
    int  poz_find = 0;
    string parola, utilizator;
    int tema,index_linie;
    login conectare;
    conectare.getNodee();
    while (fin >> tema>>utilizator >> parola>>index_linie)
       conectare.inserare_cuvant(conectare.get_rad(),utilizator, parola,tema,index_linie);
   
    //prima pagina
    int pag_curenta = 0;
    

    //aici obtin dimensiunea maxima a ecranului
    int x = GetScreenWidth();
    int y = GetScreenHeight();
    InitWindow(x, y, "");
    x = 1920, y = 1080;

    //initializare aplicatie arbore
    arbore* tree = new arbore(1);
    arbore* temp=new arbore(1);
    tree->set_radacina(tree); 
    tree->set_lungime_patrat(100);
    tree->set_marime_scris(20);
    tree->set_poz_x_rad((x - 550 - tree->get_lungime_patrat() / 2) / 2);
    tree->set_poz_y_rad(200);
    tree->calculare_inaltime(tree->get_radacina());
    tree->recalculare_pozitii(tree, 0);
 
    //incarcare FONT
    Font font = LoadFontEx("Fonts/seguiemj.ttf", 300, 0, NULL);
    Font font1 = LoadFontEx("Fonts/seguiemj.ttf", 30, 0, NULL);
    Font font2 = LoadFontEx("Fonts/seguiemj.ttf", 24, 0, NULL);
    Font font3 = LoadFontEx("Fonts/seguiemj.ttf", 19, 0, NULL);
    //initializare fereastra acasa("BUN VENIT")
    fereastra pagina_start(1280,900,BROWN,"Bun venit!");
    pagina_start.initiere_fereastra();


    fereastra pagina_autentificare(1280,900, BROWN,"Autentificare");
    fereastra pagina_inregistrare(1280, 900, BROWN, "Inregistrare");
   fereastra meniu(1280, 900, BROWN, "Meniu");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        WaitTime(0.025);
       // Sleep(25);
        BeginDrawing();

        //0 = fereastra acasa
        //1 = fereastra autentificare
        //2 = fereastra inregistrare
        // 3 =meniu
        // 4=setare nr max fi
        // 5 = aplicatie arbore
        // 6=adaugare nod
        // 7= modificare/stergere nod(subarbore)

        if (pag_curenta == 0)
        {
            SetWindowSize(1280, 900);
            SetWindowState(!FLAG_WINDOW_RESIZABLE);
            meniu.resize_fereastra(1280, 900);
            pagina_start.draw_page(pagina_start, pag_curenta, font, conectare);
        }
        else if (pag_curenta == 1)
        {
            //pagina_autentificare.initiere_fereastra();
            pagina_autentificare.draw_page(pagina_autentificare,pag_curenta, font,conectare);
        }
        else if (pag_curenta == 2)
        {
           // pagina_inregistrare.initiere_fereastra();
            pagina_inregistrare.draw_page(pagina_inregistrare,pag_curenta, font,conectare);
        }
        else if (pag_curenta == 3)
        {

            SetWindowSize(meniu.get_latime_fereastra(), meniu.get_inaltime_fereastra());
            meniu.draw_page(meniu, pag_curenta, font,font1,font2,conectare. utilizator_global,conectare);
        }
        else if (pag_curenta == 4)
        {
           

            x = 1920, y = 1080;
            SetWindowPosition((x-700)/2, (y-400)/2);
            SetWindowSize(700, 400);
            draw_setare_nr_fii(poz_x,poz_y,nr_fii,font,find_arbore,poz_find,pag_curenta,tree);
            poz_x = poz_y = 0;
        }
        else if (pag_curenta == 5)
        {
           
            x = 1920, y = 1080;
            SetWindowSize(x, y);
           
            draw_page_arbore(x,y-35,font,font3,pag_curenta,poz_x,poz_y,xd,yd,xu,yu,find_arbore,poz_find,tree,temp);
        }
        else if (pag_curenta == 6)
        {
            x = 1920, y = 1080;
            SetWindowPosition((x - 700) / 2, (y - 500) / 2);
            SetWindowSize(700, 500);
            draw_adaugare_nod(nr_fii, font, find_arbore, poz_find, pag_curenta,temp,poz_x,poz_y);
        }
        else if (pag_curenta == 7)
        {
            x = 1920, y = 1080;
            SetWindowPosition((x - 700) / 2, (y - 650) / 2);
            SetWindowSize(700, 650);
            draw_modificare_nod(nr_fii, font, find_arbore, poz_find, pag_curenta,temp,poz_x,poz_y);
        }
        else

        {
            EndDrawing();
            
            break;

        }
        EndDrawing();
    }
    CloseWindow();
  

    fin.close();


    return 0;

    
   
}
