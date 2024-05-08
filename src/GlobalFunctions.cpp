
#include "Pagini.h"
#include "GlobalFunctions.h"
ofstream fout("Utilizatori+parole/utilizatori.txt", std::ios::app);

//tema default
Color tema1[] = { BLACK,WHITE,MAROON,GOLD,YELLOW,DARKBROWN,BROWN };

//structura pentru gestionarea diferitelor evenimente de pe diferite pagini
struct even_meniu {
	int util = 0;
	int tema = 0;
	int caseta_cautare = 0;
	int adaugare_nod = 0;
	int modificare_nod = 0;
}even;

struct nod_arbore* getNode()
{
	struct nod_arbore* nod1 = new nod_arbore;
	nod1->este_cuvant = false;
	for (int i = 0; i < dim_carcat_val; i++)
		nod1->fii[i] = NULL;
	return nod1;
}

void draw_homepage(fereastra d, int& cod, Font font)
{
	d.background = tema1[6];
	ClearBackground(d.background);

	//DREPTUNGHI STANGA
	DrawRectangle(0, 0, d.latime / 2, d.inaltime, tema1[5]);

	//"Proiect realizat de: ARSENI COSTEL-IONUT"
	DrawTextEx(font, "Proiect realizat de: \n\n\n               ARSENI COSTEL-IONUT", { (float)(50), (float)(d.inaltime - 150.0) }, 35, 0, LIGHTGRAY);

	//Centrat text "BUN VENUT"
	Vector2  marime_text = MeasureTextEx(font, "VENIT      ", 200, 0);
	Vector2  marime_text1 = MeasureTextEx(font, "BUN", 200, 0);

	//text "BUN VENIT"
	char text[] = "    BUN\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n   VENIT";
	DrawTextEx(font, text, { (float)((d.latime / 2 - marime_text.x) / 2), 100 }, 200, 0, WHITE);
	DrawRectangle((d.latime / 2 - marime_text1.x) / 2, marime_text1.y + 75, marime_text1.x, 5, WHITE);
	DrawRectangle((d.latime / 2 - marime_text1.x) / 2 - 60, marime_text1.y + 330, marime_text1.x + 125, 5, WHITE);

	//desenare omulet bulina
	DrawCircle(d.latime / 2 + d.latime / 4, d.inaltime / 2 - d.inaltime / 4, 160, tema1[5]);
	DrawCircle(d.latime / 2 + d.latime / 4, d.inaltime / 2 - d.inaltime / 4 + 128, 140, tema1[6]);
	DrawCircle(d.latime / 2 + d.latime / 4, d.inaltime / 2 - d.inaltime / 4 - 50, 80, tema1[5]);
	DrawCircle(d.latime / 2 + d.latime / 4, d.inaltime / 2 - d.inaltime / 4 - 50, 70, tema1[6]);
	DrawCircleLines(d.latime / 2 + d.latime / 4, d.inaltime / 2 - d.inaltime / 4, 160, tema1[5]);

	//caseta autentificare (fara mouse peste)
	Rectangle rect3 = { d.latime / 2 + 125, static_cast<float>(d.inaltime) / 2 + 50, 375, 125 };
	DrawRectangleRounded(rect3, 0.5f, 0, tema1[5]);
	DrawTextEx(font, "Autentificare", { (float)d.latime / 2 + 165, (float)d.inaltime / 2 + 90 }, 50, 0, WHITE);

	//caseta inregistrare (fara mouse peste)
	Rectangle rect4 = { d.latime / 2 + 125, static_cast<float>(d.inaltime) / 2 + 250, 375, 125 };
	DrawRectangleRounded(rect4, 0.5f, 0, tema1[5]);
	DrawTextEx(font, "Inregistrare", { (float)d.latime / 2 + 180, (float)d.inaltime / 2 + 290 }, 50, 0, WHITE);

	//buton autentificare daca am mouse-ul peste el
	if (GetMouseX() >= d.latime / 2 + 125 && GetMouseX() <= d.latime / 2 + 125 + 375 && GetMouseY() >= (d.inaltime) / 2 + 50 && GetMouseY() <= (d.inaltime) / 2 + 50 + 125 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Rectangle rect11 = { d.latime / 2 + 100, static_cast<float>(d.inaltime) / 2 + 25, 425, 175 };
		DrawRectangleRounded(rect11, 0.5f, 0, tema1[2]);
		DrawTextEx(font, "Autentificare", { (float)d.latime / 2 + 110, (float)d.inaltime / 2 + 80 }, 68, 0, WHITE);
	}

	//am apasat butonul de autentificare
	if (GetMouseX() >= d.latime / 2 + 125 && GetMouseX() <= d.latime / 2 + 125 + 375 && GetMouseY() >= (d.inaltime) / 2 + 50 && GetMouseY() <= (d.inaltime) / 2 + 50 + 125 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		cod = 1;
		SetWindowTitle("Autentificare");
	}



	////buton inregistrare daca am mouse-ul peste el
	if (GetMouseX() >= d.latime / 2 + 125 && GetMouseX() <= d.latime / 2 + 125 + 375 && GetMouseY() >= (d.inaltime) / 2 + 250 && GetMouseY() <= (d.inaltime) / 2 + 250 + 125 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Rectangle rect10 = { d.latime / 2 + 100, static_cast<float>(d.inaltime) / 2 + 225, 425, 175 };
		DrawRectangleRounded(rect10, 0.5f, 0, tema1[2]);
		DrawTextEx(font, "Inregistrare", { (float)d.latime / 2 + 130, (float)d.inaltime / 2 + 280 }, 68, 0, WHITE);
	}

	//am apasat butonul de inregistrare
	if (GetMouseX() >= d.latime / 2 + 125 && GetMouseX() <= d.latime / 2 + 125 + 375 && GetMouseY() >= (d.inaltime) / 2 + 250 && GetMouseY() <= (d.inaltime) / 2 + 250 + 125 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		cod = 2;
		SetWindowTitle("Inregistrare");
	}
}

void elemnte_com_autentificare_inregistrare(short int latime, short int inaltime, Color background, int& code, login& conectare, Font font)
{
	background = tema1[6];
	ClearBackground(background);

	//dreptungi mare maroniu
	DrawRectangle(0, 0, latime / 2 + latime / 6 + 50, inaltime, tema1[5]);

	//dreptunghi griu pentru autentificare
	DrawRectangle(latime / 2 - 10, 65, latime / 3 + 120, inaltime - 130, BLACK);
	DrawRectangle(latime / 2, 75, latime / 3 + 100, inaltime - 150, LIGHTGRAY);

	//desenare monitor
	DrawRectangle(75, 200, 490, 300, BLACK);
	DrawRectangle(90, 215, 460, 270, LIGHTGRAY);
	DrawRectangle(300, 500, 40, 150, BLACK);
	Rectangle rect1 = { 160, 650, 300, 50 };
	DrawRectangleRounded(rect1, 1.0f, 0, BLACK);

	//buton inapoi(intoarce pagina principala)
	Rectangle rect2 = { 240,305,160,80 };
	DrawRectangleRounded(rect2, 0.5f, 0, tema1[5]);
	DrawTextEx(font, "INAPOI", { 195 + 65, 330 }, 35, 0, WHITE);

	//OMULET UTILIZATOR
	DrawCircle(latime / 2 + 120, 350, 40, BLACK);
	DrawCircle(latime / 2 + 120, 290, 27, LIGHTGRAY);
	DrawCircle(latime / 2 + 120, 290, 23, BLACK);
	DrawRectangle(latime / 2 + 120 - 40, 350, 80, 40, LIGHTGRAY);

	//lacat parola
	DrawCircle(latime / 2 + 120, 560, 30, BLACK);
	DrawCircle(latime / 2 + 120, 560, 25, LIGHTGRAY);
	DrawRectangle(latime / 2 + 120 - 40, 560, 80, 40, BLACK);
	DrawCircle(latime / 2 + 120, 580, 8, LIGHTGRAY);

	//dreptunghi + scirs "UTILIZATOR"
	Rectangle rect5 = { latime / 2 + 70, 250, latime / 3 - 40, 100 };
	DrawRectangleLinesEx(rect5, 2, tema1[5]);
	DrawTextEx(font, "UTILIZATOR", { (float)latime / 2 + 140, 200 }, 45, 0, tema1[5]);

	//dreptunghi + scirs "PAROLA"
	Rectangle rect6 = { latime / 2 + 70, 500, latime / 3 - 40, 100 };
	DrawRectangleLinesEx(rect6, 2, tema1[5]);
	DrawTextEx(font, "PAROLA", { (float)latime / 2 + 180, 450 }, 45, 0, tema1[5]);

	// buton inapoi daca tin mouse-ul peste el (si daca nu-l apasat) 
	if (GetMouseX() >= 240 && GetMouseX() <= 400 && GetMouseY() >= 305 && GetMouseY() <= 385 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Rectangle rect8 = { 210,295,  220,  100 };
		DrawRectangleRounded(rect8, 0.5f, 0, tema1[2]);
		DrawTextEx(font, "INAPOI", { 228, 325 }, 55, 0, WHITE);
	}

	//am apasat butonul INAPOI
	if (GetMouseX() >= 240 && GetMouseX() <= 400 && GetMouseY() >= 305 && GetMouseY() <= 385 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		conectare.set_default();
		code = 0;
	}

	//am dat click pe caseta utilizator
	if (GetMouseX() >= latime / 2 + 70 && GetMouseX() <= latime / 2 + 70 + latime / 3 - 40 && GetMouseY() >= 250 && GetMouseY() <= 350 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		conectare.setare_caseta(1);
	}

	//am dat click pe caseta parola
	else
		if (GetMouseX() >= latime / 2 + 70 && GetMouseX() <= latime / 2 + 70 + latime / 3 - 40 && GetMouseY() >= 500 && GetMouseY() <= 600 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			conectare.setare_caseta(2);
		}
	//am dat click in alta parte
		else
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				//verific daca am apasat patratul pentru afisarea parolei
				if (GetMouseX() >= latime / 2 + latime / 3 + 45 && GetMouseX() <= latime / 2 + latime / 3 + 75 && GetMouseY() >= 535 && GetMouseY() <= 565)
					conectare.set_vizualizare_parola();
				else
					//daca am apasat oriunde altundeva decat un buton, imi deselecteaza casetele utilizator si parola, in caz de erau selectate
					conectare.setare_caseta(0);
			}
	//patrat vizualizare parola
	DrawRectangle(latime / 2 + latime / 3 + 45, 535, 30, 30, tema1[5]);
	if (conectare.vizualizare_par() == false)
		DrawRectangle(latime / 2 + latime / 3 + 50, 540, 20, 20, LIGHTGRAY);

	//daca am apasat caseta utilizator si am apasat o tasta
	if (conectare.util_apasat() == true)
	{
		//daca am apsat caps nu-mi face nimic
		if (IsKeyPressed(KEY_CAPS_LOCK))
		{		}
		else
			//daca am apasat backstage imi sterge ultimul caracter din caseta utilizator(daca exista)
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				conectare.util_eli_caract();
			}
			else
				//verific ce tasta am apasat si o inserez
				for (int key = 0; key < 512; key++)
				{
					//daca e caracter valid(litera mica, mare sau numar) o insereaza, in caz contrar imi pune '#'
					if (IsKeyPressed(key)) {
						conectare.util_add_caract(GetCharPressed(), MeasureTextEx(font, conectare.get_util(), 40, 0).x);

					}

				}
		//imi verifica daca utilizatorul are numai caractere valide si schimb codul de eroare
		conectare.verificare_user();

	}
	//daca am apasat caseta parola si am apasat o tasta
	if (conectare.parola_apasata() == true)
	{
		//daca am apsat caps nu-mi face nimic
		if (IsKeyPressed(KEY_CAPS_LOCK))
		{

		}
		//daca am apasat backstage imi sterge ultimul caracter din caseta parola(daca exista)
		else
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				conectare.parol_eli_caract();
			}
		//verific ce tasta am apasat si o inserez
			else
				for (short key = 0; key < 512; key++)
				{
					//daca e caracter valid(litera mica, mare sau numar) o insereaza, in caz contrar imi pune '#'

					if (IsKeyPressed(key)) {
						conectare.parol_add_caract(GetCharPressed(), MeasureTextEx(font, conectare.get_par(), 40, 0).x);
					}
				}
		//imi verifica daca parola are numai caractere valide si schimb codul de eroare

		conectare.verificare_parola();
	}
}

void draw_fer_autentificare(fereastra d, int& code, Font &font, login& conectare) {
	
	elemnte_com_autentificare_inregistrare(d.latime, d.inaltime, d.background, code, conectare, font);

	//buton autentificare
	Rectangle rect4 = { d.latime / 2 + 70,d.inaltime - 130 - 75,d.latime / 3 - 40,100 };
	DrawRectangleRounded(rect4, 0.5f, 0, tema1[5]);
	DrawTextEx(font, "AUTENTIFICARE", { (float)d.latime / 2 + 95, (float)d.inaltime - 130 - 40 }, 45, 0, WHITE);
	
	// buton autentificare daca tin mouse-ul peste el (si daca nu-l apasat)
	if (GetMouseX() >= d.latime / 2 + 70 && GetMouseX() <= d.latime / 2 + 70 + d.latime / 3 - 40 && GetMouseY() >= d.inaltime - 130 - 85 && GetMouseY() <= d.inaltime - 130 - 75 + 100 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Rectangle rect7 = { d.latime / 2 + 50,d.inaltime - 130 - 85,  20 + d.latime / 3,  120 };
		DrawRectangleRounded(rect7, 0.5f, 0, tema1[2]);
		DrawTextEx(font, "AUTENTIFICARE", { (float)d.latime / 2 + 70, (float)d.inaltime / 2 + 270 }, 55, 0, WHITE);
	}

	//am apasat butonul de autentificare
	if (GetMouseX() >= d.latime / 2 + 70 && GetMouseX() <= d.latime / 2 + 70 + d.latime / 3 - 40 && GetMouseY() >= d.inaltime - 130 - 85 && GetMouseY() <= d.inaltime - 130 - 75 + 100 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		
		string aux;
		//verifica daca utilizatorul exista in baza de date
		if (conectare.cautare_cuvant(conectare.get_util(), aux) != true)
			conectare.set_cod_eroare(0, 2);

		//verific daca parola se potriveste cu utilizatorul
		if (aux != conectare.get_par())
			conectare.set_cod_eroare(1, 2);
		
		//verific daca am cel putin un caracter la utilizator
		if (strlen(conectare.get_util()) == 0)
			conectare.set_cod_eroare(0, 0);
		
		//verific daca am cel putin un caracter la parola
		if (strlen(conectare.get_par()) == 0)
			conectare.set_cod_eroare(1, 0);

		//daca nu am erori pot apela cu succes butonul de autentificare
		if (conectare.eroare_util() == -1 && conectare.eroare_par() == -1)
		{
			conectare.utilizator_global=(conectare.get_util());
			
			conectare.set_default();
			SetWindowState(FLAG_WINDOW_RESIZABLE);
			SetWindowTitle("Meniu");
			code = 3;
		}
	}


	if ((conectare.util_apasat() == true || conectare.parola_apasata() == true) && conectare.eroare_par() == 2)
	{
		conectare.set_cod_eroare(1, -1);
	}

		//verific daca utilizatorul nu are caractere invalide
	if (conectare.eroare_util() == 1) {
		DrawTextEx(font, conectare.get_util(), { (float)d.latime / 2 + 175, 300 }, 40, 0, RED);
		DrawTextEx(font, "        Poti folosi doar litere si cifre!\n\n(orice tasta apasata se ia in considerare)", { (float)d.latime / 2 + 35, 375 }, 25, 0, RED);

	}
	//verific daca utilizatorul exista
	else if (conectare.eroare_util() == 2)
	{
		DrawTextEx(font, conectare.get_util(), { (float)d.latime / 2 + 175, 300 }, 40, 0, RED);
		DrawTextEx(font, "Utilizatorul nu exista!", { (float)d.latime / 2 + 70, 375 }, 25, 0, RED);
	}
	else
		
		if (conectare.eroare_util() == -1)
		{
			DrawTextEx(font, conectare.get_util(), { (float)d.latime / 2 + 175, 300 }, 40, 0, DARKGREEN);

		}
	//analog pentru parola
	if (conectare.eroare_par() == -1)
	{
		if (conectare.vizualizare_par() == true)
			DrawTextEx(font, conectare.get_par(), { (float)d.latime / 2 + 175, 550 }, 40, 0, DARKGREEN);
		else
			DrawTextEx(font, conectare.get_par_asc(), { (float)d.latime / 2 + 175, 550 }, 40, 0, DARKGREEN);

	}
	else if (conectare.eroare_par() == 1)
	{
		if (conectare.vizualizare_par() == true)
			DrawTextEx(font, conectare.get_par(), { (float)d.latime / 2 + 175, 550 }, 40, 0, RED);

		else
			DrawTextEx(font, conectare.get_par_asc(), { (float)d.latime / 2 + 175, 550 }, 40, 0, RED);
		DrawTextEx(font, "        Poti folosi doar litere si cifre!\n\n(orice tasta apasata se ia in considerare)", { (float)d.latime / 2 + 35, 625 }, 25, 0, RED);

	}
	else if (conectare.eroare_par() == 2)
	{
		if (conectare.vizualizare_par() == true)
			DrawTextEx(font, conectare.get_par(), { (float)d.latime / 2 + 175, 550 }, 40, 0, RED);

		else
			DrawTextEx(font, conectare.get_par_asc(), { (float)d.latime / 2 + 175, 550 }, 40, 0, RED);
		
		if (conectare.eroare_util() != 2)
			DrawTextEx(font, "Parola incorecta!", { (float)d.latime / 2 + 70, 625 }, 25, 0, RED);	
	}

	if (conectare.eroare_util() == 0)
	{
		DrawTextEx(font, "Utilizatorul invalid!", { (float)d.latime / 2 + 70, 375 }, 25, 0, RED);

	}
	if (conectare.eroare_par() == 0)
		DrawTextEx(font, "Parola invalida!", { (float)d.latime / 2 + 70, 625 }, 25, 0, RED);

}

void draw_fer_inregistrare(fereastra d, int& code, Font &font, login& conectare) {


	elemnte_com_autentificare_inregistrare(d.latime, d.inaltime, d.background, code, conectare, font);

	//buton inregistrare
	Rectangle rect4 = { d.latime / 2 + 70,d.inaltime - 130 - 75,d.latime / 3 - 40,100 };
	DrawRectangleRounded(rect4, 0.5f, 0, tema1[5]);
	DrawTextEx(font, " INREGISTRARE", { (float)d.latime / 2 + 95, (float)d.inaltime - 130 - 40 }, 45, 0, WHITE);

	// buton inregistrare daca tin mouse-ul peste el (si daca nu-l apasat)
	if (GetMouseX() >= d.latime / 2 + 70 && GetMouseX() <= d.latime / 2 + 70 + d.latime / 3 - 40 && GetMouseY() >= d.inaltime - 130 - 85 && GetMouseY() <= d.inaltime - 130 - 75 + 100 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Rectangle rect7 = { d.latime / 2 + 50,d.inaltime - 130 - 85,  20 + d.latime / 3,  120 };
		DrawRectangleRounded(rect7, 0.5f, 0, tema1[2]);
		DrawTextEx(font, " INREGISTRARE", { (float)d.latime / 2 + 70, (float)d.inaltime / 2 + 270 }, 55, 0, WHITE);
	}

	//am apasat butonul de inregistrare
	if (GetMouseX() >= d.latime / 2 + 70 && GetMouseX() <= d.latime / 2 + 70 + d.latime / 3 - 40 && GetMouseY() >= d.inaltime - 130 - 85 && GetMouseY() <= d.inaltime - 130 - 75 + 100 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		string aux;
		//verific daca utilizatorul exista in baza de date
		if (conectare.cautare_cuvant(conectare.get_util(), aux) == true)
			conectare.set_cod_eroare(0, 2);
		//verific daca utilizatorul are cel putin un caracter
		if (strlen(conectare.get_util()) == 0)
			conectare.set_cod_eroare(0, 0);

		//verific daca parola are cel putin un caracter
		if (strlen(conectare.get_par()) == 0)
			conectare.set_cod_eroare(1, 0);
		
		//daca nu am erori, adaug noul utilizator in "baza de date" :)) 
		if (conectare.eroare_util() == -1 && conectare.eroare_par() == -1)
		{
			conectare.inserare_cuvant(conectare.get_rad(), (string)conectare.get_util(), (string)conectare.get_par(),conectare.get_tema(),conectare.get_index());

			fout << conectare.get_tema()<<' ' << conectare.get_util() << ' ' << conectare.get_par() <<' ' << conectare.get_index() + 1 << '\n';
			conectare.utilizator_global = (conectare.get_util());
			
			conectare.set_default();
			SetWindowState(FLAG_WINDOW_RESIZABLE);
			SetWindowTitle("Meniu");
			code = 3;
		}
	}



	if (conectare.eroare_util() == 1) {

		DrawTextEx(font, conectare.get_util(), { (float)d.latime / 2 + 175, 300 }, 40, 0, RED);
		DrawTextEx(font, "        Poti folosi doar litere si cifre!\n\n(orice tasta apasata se ia in considerare)", { (float)d.latime / 2 + 35, 375 }, 25, 0, RED);

	}
	else if (conectare.eroare_util() == 2)
	{

		DrawTextEx(font, conectare.get_util(), { (float)d.latime / 2 + 175, 300 }, 40, 0, RED);
		DrawTextEx(font, "Utilizatorul exista deja!", { (float)d.latime / 2 + 70, 375 }, 25, 0, RED);

	}
	else
		if (conectare.eroare_util() == -1)
		{

			DrawTextEx(font, conectare.get_util(), { (float)d.latime / 2 + 175, 300 }, 40, 0, DARKGREEN);
		}

	if (conectare.eroare_par() == -1)
	{
		if (conectare.vizualizare_par() == true)
			DrawTextEx(font, conectare.get_par(), { (float)d.latime / 2 + 175, 550 }, 40, 0, DARKGREEN);
		else
			DrawTextEx(font, conectare.get_par_asc(), { (float)d.latime / 2 + 175, 550 }, 40, 0, DARKGREEN);
	}
	else if (conectare.eroare_par() == 1)
	{
		if (conectare.vizualizare_par() == true)
			DrawTextEx(font, conectare.get_par(), { (float)d.latime / 2 + 175, 550 }, 40, 0, RED);

		else
			DrawTextEx(font, conectare.get_par_asc(), { (float)d.latime / 2 + 175, 550 }, 40, 0, RED);
		DrawTextEx(font, "        Poti folosi doar litere si cifre!\n\n(orice tasta apasata se ia in considerare)", { (float)d.latime / 2 + 35, 625 }, 25, 0, RED);

	}

	if (conectare.eroare_util() == 0)
	{
		DrawTextEx(font, "Utilizatorul invalid!", { (float)d.latime / 2 + 70, 375 }, 25, 0, RED);

	}
	if (conectare.eroare_par() == 0)
		DrawTextEx(font, "Parola invalida!", { (float)d.latime / 2 + 70, 625 }, 25, 0, RED);
}



//subprograme auxiliare pentru fereastra meniu
void modificare_tema_fisier(login &conectare)
{
	fstream fin("Utilizatori+parole/utilizatori.txt", std::ios::in | std::ios::out);

	std::streampos currentPosition;
	std::string line;

	
	for (int i = 1; i <conectare.get_index(); ++i) {
		
		std::getline(fin, line);
			
	}
	currentPosition = fin.tellg(); 
	if (!std::getline(fin, line))
	{
		return;
	}
		
		
	

	if (line.empty() || line.find_first_not_of(" \t") == std::string::npos) {
		
		return;
	}

	line[0] = conectare.get_tema() + '0';

	fin.seekp(currentPosition);

	fin << line;
	fin.close();
	
}
void draw_normal_rectangle(int x, int y, int lungime, int inaltime, const char* text, Font font, Font font2, int cnt_text, Color culoare1, Color culoare2)
{
	Rectangle rect1 = { x,y + 10,lungime,inaltime };
	DrawRectangleRounded(rect1, 0.5f, 0, culoare1);

	Rectangle rect2 = { x,y,lungime,inaltime };
	DrawRectangleRounded(rect2, 0.5f, 0, culoare2);
	Vector2 masura = MeasureTextEx(font, text, cnt_text, 0);
	DrawTextEx(font, text, { x + (lungime - masura.x) / 2,(float)(y + (inaltime - masura.y) / 2) }, cnt_text, 0, culoare1);
}
void draw_special_rectangle(int x, int y, int lungime, int inaltime, const char* text1, const char* text2,Font font, Font font2,int cnt_text,int cnt_text1,Color culoare1,Color culoare2,Color culoare3)
{
	Rectangle rect1 = { x,y + 10,lungime,inaltime };
	DrawRectangleRounded(rect1, 0.5f, 0, culoare1);

	Rectangle rect = { x,y - 30,lungime,inaltime };
	DrawRectangleRounded(rect, 0.5f, 0, culoare3);

	Vector2  masura = MeasureTextEx(font, text1, cnt_text, 0);
	DrawTextEx(font, text1, { x + ( lungime- masura.x) / 2,(float)(y + (inaltime - masura.y) / 2 - 30) }, cnt_text, 0, tema1[1]);
	masura = MeasureTextEx(font2, text2, cnt_text1, 0);
	DrawTextEx(font2, text2, { x + (lungime - masura.x) / 2,(float)(y + inaltime - 24) }, cnt_text1, 0, culoare2);
}

//            0       1    2     3     4         5      6
//tema1[] = {BLACK,WHITE,MAROON,GOLD,YELLOW,DARKBROWN,BROWN}
void modificare_culoare_tema(Color col1, Color col2, Color col3, Color col4, Color col5, Color col6, Color col7)
{
	tema1[0] = col1;
	tema1[1] = col2;
	tema1[2] = col3;
	tema1[3] = col4;
	tema1[4] = col5;
	tema1[5] = col6;
	tema1[6] = col7;
}


void draw_fer_meniu(fereastra& d, int& code, Font font,Font font1, Font font2, string utilizator,login &conectare)
{
	ClearBackground(WHITE);

	
	DrawRectangle(0, 0, d.latime , 40, tema1[2]);
	DrawRectangle(0, 2, d.latime, 36, tema1[1]);
	
	//modificare tema
	
	//tema bear
	if (conectare.get_tema() == 1)
	{
		modificare_culoare_tema(BLACK, WHITE, MAROON, GOLD, YELLOW, DARKBROWN, BROWN);
	}
	else
		//tema aqua
		if (conectare.get_tema() == 2)
		{
			modificare_culoare_tema(BLACK, WHITE, DARKPURPLE, PURPLE, PINK, DARKBLUE, SKYBLUE);
		}
	//tema emerald
		else if (conectare.get_tema() == 3)
		{
			modificare_culoare_tema(BLACK, WHITE, ORANGE, GOLD, MAROON, DARKGREEN, LIME);
		}
		else
			//tema space
			if (conectare.get_tema() ==4 )
			{
				modificare_culoare_tema(BLACK, WHITE, BLACK, LIGHTGRAY, WHITE, DARKGRAY, GRAY);
			}
	
	//x_start=0,y_start=2,x_stop=261,y_stop=38
	//desenare butoare ( utilizator, tema, buton

	//buton deconectare
	 if ((GetMouseX() >= 0 && GetMouseX() <= 261 && GetMouseY() >= 2 && GetMouseY() <= 38 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))||even.util==1)

	{
		DrawRectangle(0, 0, 261, 40, tema1[0]);
		DrawRectangle(2, 2, 258, 36, tema1[2]);
		DrawTextEx(font1, (char*)utilizator.c_str(), { 55 + (201 - MeasureTextEx(font,(char*)utilizator.c_str(),30,0).x) / 2, 8 }, 30, 0, tema1[1]);
		
		DrawCircle(25, 17, 9, tema1[1]);
		DrawCircle(25, 52, 25, tema1[1]);
		
	}
	else
	{
		DrawTextEx(font1, (char*)utilizator.c_str(), { 55 + (201 - MeasureTextEx(font,(char*)utilizator.c_str(),30,0).x) / 2, 8 }, 30, 0, tema1[2]);
		DrawCircle(25, 17, 9, tema1[2]);
		DrawCircle(25, 52, 25, tema1[2]);
	}
	
	//x_start=261,y_start=2,x_stop=384,y_stop=38

	//buton tema
	if ((GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 2 && GetMouseY() <= 38 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))||even.tema!=0)
	{
		DrawRectangle(261, 0, 123, 40, tema1[0]);
		DrawRectangle(263, 2, 119, 36, tema1[2]);
		DrawTextEx(font1, "Tema", { 284,8 }, 30, 0, tema1[1]);

	}
	else
		DrawTextEx(font1, "Tema", { 284,8 }, 30, 0, tema1[2]);

	//x_start=384,y_start=2,x_stop=502,y_stop=48
	//buton
	if (GetMouseX() >= 384 && GetMouseX() <= 502 && GetMouseY() >= 2 && GetMouseY() <= 38 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))

	{
		DrawRectangle(384, 0, 123, 40, tema1[0]);
		DrawRectangle(386, 2, 119, 36, tema1[2]);
		DrawTextEx(font1, "Buton", { 404,8 }, 30, 0, tema1[1]);

	}
	else
		DrawTextEx(font1, "Buton", { 404,8 }, 30, 0, tema1[2]);
	//x_start = 502, y_start = 2, x_stop = 620, y_stop = 48
	if (GetMouseX() >= 502 && GetMouseX() <= 620 && GetMouseY() >= 2 && GetMouseY() <= 38 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))

	{
		DrawRectangle(502, 0, 123, 40, tema1[0]);
		DrawRectangle(504, 2, 119, 36, tema1[2]);
		DrawTextEx(font1, "Buton", { 522,8 }, 30, 0, tema1[1]);

	}
	else
		DrawTextEx(font1, "Buton", { 522,8 }, 30, 0, tema1[2]);
	//Vector2 a = MeasureTextEx(font,"Buton", 30, 0);

	int cnt_text = 0,cnt_text1=24;
	while (MeasureTextEx(font,"MMM",cnt_text,0).x <= d.latime / 25)
		cnt_text++;


	
	
	cnt_text *= 3;


	Vector2 masura;
	float l5 = d.latime / 5, i5 = d.inaltime / 5,l2=d.latime/2,i2=d.inaltime/2,l=d.latime,i=d.inaltime;

	DrawRectangle(0, 40, l2,i-40, tema1[5]);
	DrawRectangle(l2, 40, l2, i-40, tema1[6]);

	Rectangle rect1 = { l5/8,i5,l2-l5/8,i5*3 };
	DrawRectangleRounded(rect1,0.3f,0,tema1[6]);
	DrawRectangle(l5/8+ (l2 - l5/8)/2, i5, (l2 - l5/8) / 2, i5 * 3,tema1[6]);
	
	Rectangle rect6 = { l2,i5,l2 -l5 / 8,i5 * 3 };
	DrawRectangleRounded(rect6, 0.3f, 0, tema1[5]);
	DrawRectangle(l2 , i5, (l2 - l5/8) / 2, i5 * 3, tema1[5]);

	//dreptunghiuri stanga

	//stanga sus
	if (GetMouseX() >= l5 / 8 * 2 && GetMouseX() <= l5 / 8 * 2 + l5 && GetMouseY() >= i5 * 1.33 && GetMouseY() <= i5 * 1.33 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&&even.util == 0 && even.tema == 0)

	{
		draw_special_rectangle(l5 / 8 * 2, i5 * 1.33, l5, i5, "Tree", "Arbore", font, font2, cnt_text, cnt_text1, tema1[3], tema1[5], tema1[2]);
	}
	else

	{
		draw_normal_rectangle(l5 / 8 * 2, i5 * 1.33, l5, i5, "Tree", font, font2, cnt_text, tema1[3], tema1[5]);

	}


	//dreapta sus
	if (GetMouseX() >= l5 / 8 * 3 + l5 && GetMouseX() <= l5 / 8 * 3 + 2 * l5 && GetMouseY() >= i5 * 1.33 && GetMouseY() <= i5 * 1.33 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)
	{
		draw_special_rectangle(l5 / 8 * 3 + l5, i5 * 1.33, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[3], tema1[5], tema1[2]);
	}
	else
	{
		draw_normal_rectangle(l5 / 8 * 3 + l5, i5 * 1.33, l5, i5, "Soon", font, font2, cnt_text, tema1[3], tema1[5]);

	}


	//stanga jos
	if (GetMouseX() >= l5 / 8 * 2 && GetMouseX() <= l5 / 8 * 2 + l5 && GetMouseY() >= i5 * 2.66 && GetMouseY() <= i5 * 2.66 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)
	{
		draw_special_rectangle(l5 / 8 * 2, i5 * 2.66, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[3], tema1[5], tema1[2]);
	}
	else
	{
		draw_normal_rectangle(l5 / 8 * 2, i5 * 2.66, l5, i5, "Soon", font, font2, cnt_text, tema1[3], tema1[5]);

	}

	//dreapta jos
	if (GetMouseX() >= l5 / 8 * 3 + l5 && GetMouseX() <= l5 / 8 * 3 + 2 * l5 && GetMouseY() >= i5 * 2.66 && GetMouseY() <= i5 * 2.66 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)
	{
		draw_special_rectangle(l5 / 8 * 3 + l5, i5 * 2.66, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[3], tema1[5], tema1[2]);
	}
	else
	{
		draw_normal_rectangle(l5 / 8 * 3 + l5, i5 * 2.66, l5, i5, "Soon", font, font2, cnt_text, tema1[3], tema1[5]);

	}




	//dreptunghiuri dreapta


	//stanga sus
	if (GetMouseX() >= l5 / 8 + l2 && GetMouseX() <= l5 / 8 + l2 + l5 && GetMouseY() >= i5 * 1.33 && GetMouseY() <= i5 * 1.33 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)

	{
		draw_special_rectangle(l5 / 8 + l2, i5 * 1.33, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[4], tema1[6], tema1[2]);
	}
	else

	{
		draw_normal_rectangle(l5 / 8 + l2, i5 * 1.33, l5, i5, "Soon", font, font2, cnt_text, tema1[4], tema1[6]);

	}

	//dreapta sus
	if (GetMouseX() >= l5 / 8 * 2 + l5 + l2 && GetMouseX() <= l5 / 8 * 2 + 2 * l5 + l2 && GetMouseY() >= i5 * 1.33 && GetMouseY() <= i5 * 1.33 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)
	{
		draw_special_rectangle(l5 / 8 * 2 + l5 + l2, i5 * 1.33, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[4], tema1[6], tema1[2]);
	}
	else
	{
		draw_normal_rectangle(l5 / 8 * 2 + l5 + l2, i5 * 1.33, l5, i5, "Soon", font, font2, cnt_text, tema1[4], tema1[6]);

	}

	//stanga jos
	if (GetMouseX() >= l5 / 8 + l2 && GetMouseX() <= l5 / 8 + l2 + l5 && GetMouseY() >= i5 * 2.66 && GetMouseY() <= i5 * 2.66 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)
	{
		draw_special_rectangle(l5 / 8 + l2, i5 * 2.66, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[4], tema1[6], tema1[2]);
	}
	else
	{
		draw_normal_rectangle(l5 / 8 + l2, i5 * 2.66, l5, i5, "Soon", font, font2, cnt_text, tema1[4], tema1[6]);

	}

	//dreapta jos
	if (GetMouseX() >= l5 / 8 * 2 + l2 + l5 && GetMouseX() <= l5 / 8 * 2 + l2 + 2 * l5 && GetMouseY() >= i5 * 2.66 && GetMouseY() <= i5 * 2.66 + i5 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && even.util == 0 && even.tema == 0)
	{
		draw_special_rectangle(l5 / 8 * 2 + l2 + l5, i5 * 2.66, l5, i5, "Soon", "Curand", font, font2, cnt_text, cnt_text1, tema1[4], tema1[6], tema1[2]);
	}
	else
	{
		draw_normal_rectangle(l5 / 8 * 2 + l2 + l5, i5 * 2.66, l5, i5, "Soon", font, font2, cnt_text, tema1[4], tema1[6]);

	}


	//buton utilizator apasat
	if (even.util == 1)
	{
		DrawRectangle(0, 40, 261, 50, tema1[2]);
		if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 2 && GetMouseY() <= 38 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			even.tema = 1;
			even.util = 0;
			WaitTime(0.1);
			//Sleep(100);
		}
		else
		if (GetMouseX() >= 0 && GetMouseX() <= 261 && GetMouseY() >= 40 && GetMouseY() <= 90 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			code = 0;
			even.util = 0; conectare.set_default();
		
		}
		else
		if (GetMouseX() >= 0 && GetMouseX() <= 261 && GetMouseY() >= 2 && GetMouseY() <= 38 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			even.util = 0;
			WaitTime(0.1);
			//Sleep(100);
		}
		else
			
				if (GetMouseX() >= 0 && GetMouseX() <= 261 && GetMouseY() >= 40 && GetMouseY() <= 46 + 50 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					DrawRectangle(2, 42, 257, 46, LIGHTGRAY);
					DrawTextEx(font1, "Deconectare", { 45,50 }, 30, 0, BLACK);


				}
				else
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
						even.util = 0;
		else
		{
			DrawRectangle(2, 42, 257, 46, tema1[1]);
			DrawTextEx(font1, "Deconectare", { 45,50 }, 30, 0, tema1[2]);
			
		}

	}

	//botun tema apasat
	else if (even.tema != 0)
	{
		
		DrawRectangle(261, 40, 384-261, 50 , tema1[2]);
		DrawRectangle(261, 90, 384 - 261, 50 , tema1[2]);
		DrawRectangle(261, 140, 384 - 261, 50 , tema1[2]);
		DrawRectangle(261, 190, 384 - 261, 50 , tema1[2]);
		if (GetMouseX() >= 0 && GetMouseX() <= 261 && GetMouseY() >= 2 && GetMouseY() <= 38 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			even.tema = 0;
			even.util = 1;
		}
		else
		if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 2 && GetMouseY() <= 38 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			even.tema = 0;
			WaitTime(0.1);
			//Sleep(100);
		}
		else
			if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 40 && GetMouseY() <= 90 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				conectare.modificare_tema(1);
				modificare_tema_fisier(conectare);
				even.tema = 0;

			}
			else
				if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 90 && GetMouseY() <= 140 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					conectare.modificare_tema(2);
					modificare_tema_fisier(conectare);
					even.tema = 0;

				}
				else
					if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >=140 && GetMouseY() <= 190 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						conectare.modificare_tema(3);
						modificare_tema_fisier(conectare);
						even.tema = 0;

					}
					else
						if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >=190 && GetMouseY() <=240 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
						{
							conectare.modificare_tema(4);
							modificare_tema_fisier(conectare);
							even.tema = 0;

						}
					else
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
								even.tema = 0;

							if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 50 && GetMouseY() <= 90 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
							{
								DrawRectangle(263, 42, 380 - 263, 46, LIGHTGRAY);
								DrawTextEx(font1, "Bear", { 265,50 }, 30, 0, BLACK);

							}
							else
							{
								DrawRectangle(263, 42, 380 - 263, 46, tema1[1]);
								DrawTextEx(font1, "Bear", { 265,50 }, 30, 0, tema1[2]);

							}
		if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 90 && GetMouseY() <= 140 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))

		{
			DrawRectangle(263, 92, 380 - 263, 46, LIGHTGRAY);
			DrawTextEx(font1, "Aqua", { 265,100 }, 30, 0, BLACK);
		}

		else {
			DrawRectangle(263, 92, 380 - 263, 46, tema1[1]);
			DrawTextEx(font1, "Aqua", { 265,100 }, 30, 0, tema1[2]);

		}

		if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 140 && GetMouseY() <= 190 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawRectangle(263, 142, 380 - 263, 46, LIGHTGRAY);
			DrawTextEx(font1, "Emerald", { 265,150 }, 30, 0, BLACK);
		}

		else
		{
			DrawRectangle(263, 142, 380 - 263, 46, tema1[1]);
			DrawTextEx(font1, "Emerald", { 265,150 }, 30, 0, tema1[2]);

		}
		if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 190 && GetMouseY() <= 240 && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawRectangle(263, 192, 380 - 263, 46, LIGHTGRAY);
			DrawTextEx(font1, "Space", { 265,200 }, 30, 0, BLACK);
		
		}
		else
		{

			DrawRectangle(263, 192, 380 - 263, 46, tema1[1]);
			DrawTextEx(font1, "Space", { 265,200 }, 30, 0, tema1[2]);

		}

				
				
					
					
	}
	else
	if (GetMouseX() >= 0 && GetMouseX() <= 261 && GetMouseY() >= 2 && GetMouseY() <= 38 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{

		even.util = 1;
		even.tema = 0;

	}
	else
		if (GetMouseX() >= 261 && GetMouseX() <= 384 && GetMouseY() >= 2 && GetMouseY() <= 38 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			even.util = 0;
			even.tema = conectare.get_tema();
		}
		else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			even.util = 0;
			even.tema = 0;
			
			//am apasat butonul de arbore
			if (GetMouseX() >= l5 / 8 * 2 && GetMouseX() <= l5 / 8 * 2 + l5 && GetMouseY() >= i5 * 1.33 && GetMouseY() <= i5 * 1.33 + i5 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				code = 4;
			}
		}
	

	//sunt redimensionabile pana la un punct
	if (IsWindowResized())
	{
		
		d.resize_fereastra(GetScreenWidth(), GetScreenHeight());
		
	}

}

void dreptunghi_rotunjit(int a, int b, int c, int d, Color culoare)
{
	Rectangle rec = { a,b,c,d };
	DrawRectangleRounded(rec, 0.8f, 0, culoare);

}

void draw_setare_nr_fii(int poz_x, int poz_y, int& nr_fii,Font font, char* find_arbore, int& poz_find,int &code,arbore*&tree)
{
	int x = 700, y = 400;
	DrawRectangle(0+poz_x, 0+poz_y, x, y, tema1[5]);
	DrawRectangle(10+poz_x, 10+poz_y, x-20, y-20, tema1[6]);

	nr_fii = 0;
	//creare numar
	for (int i = 0; i < poz_find; i++)
	{
		nr_fii = nr_fii * 10 + find_arbore[i] - '0';
	}

	//am apasat pe buton si numarul este conform cu specificatiile
	if ((GetMouseX() >= 35 + poz_x && GetMouseX() <= x - 70 + poz_x && GetMouseY() >= 45 + poz_y && GetMouseY() <= 200 + poz_y))

	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (nr_fii >= 1 && nr_fii <= 1000)
			{
				code = 5;
				SetWindowPosition(0, 40);
				tree->set_nr_max_fii(nr_fii);
				poz_find = 0;
				find_arbore[0] = 0;
				WaitTime(0.15);
				//Sleep(150);
			}
		}
			dreptunghi_rotunjit(30 + poz_x, 35 + poz_y, x - 60, 240, tema1[2]);
			dreptunghi_rotunjit(30 + poz_x, 200 + poz_y, x - 60, 100, tema1[2]);

	}
	else
	{
		dreptunghi_rotunjit(35 + poz_x, 45 + poz_y, x - 70, 250, tema1[5]);
		dreptunghi_rotunjit(35 + poz_x, 200 + poz_y, x - 70, 100, tema1[5]);
	}

	DrawTextEx(font, "Dati numarul maxim\n\n\n\n  de fii al unui nod", { 120 + poz_x*1.0f,80 + poz_y*1.0f }, 50, 0, tema1[1]);

	dreptunghi_rotunjit(37 + poz_x, 202 + poz_y, x - 70-4, 100-4, LIGHTGRAY);

	DrawTextEx(font, "  Numar cuprins intre 1 si 1000!\n\n\nSe accepta maxim 4 caractere!!!!", { 125 + poz_x*1.0f,310 + poz_y*1.0f }, 30, 0, tema1[2]);


	//am apasat o tasta
	if (IsKeyPressed(KEY_CAPS_LOCK))
	{
	}
	else
		//daca am apasat backstage imi sterge ultimul caracter din caseta utilizator(daca exista)
		if (IsKeyPressed(KEY_BACKSPACE) && poz_find > 0)
		{
			poz_find--;
			find_arbore[poz_find] = 0;


		}
		else if (poz_find <= 4)
			//verific ce tasta am apasat si o inserez
			for (int key = 0; key < 512; key++)
			{
				//daca e caracter valid(litera mica, mare sau numar) o insereaza, in caz contrar imi pune '#'
				if (IsKeyPressed(key)) {
					if ( (key >= '0' && key <= '9'))
						if (poz_find <= 3)
						{
							
								find_arbore[poz_find] = GetCharPressed();
								poz_find++;
								find_arbore[poz_find] = 0;
						
						}
				}

			}

	DrawTextEx(font, find_arbore, { (float) 55+ (x-105 - MeasureTextEx(font,find_arbore,50,0).x) / 2 + poz_x*1.0f,230 + poz_y*1.0f }, 50, 0, tema1[0]);
	
	
}

//pagina adaugare nod( am apasat pe un nod null)
void draw_adaugare_nod(int& nr_fii, Font font, char* find_arbore, int& poz_find, int& code, arbore*& temp,int &poz_x,int &poz_y)
{
	int x = GetScreenWidth(), y = GetScreenHeight();

	DrawRectangle(0, 0, x, y, tema1[5]);

	DrawRectangle(10, 10, x - 20, y - 20, tema1[6]);
	
	
	if ((GetMouseX() >= 35 && GetMouseX() <= x - 70 && GetMouseY() >= 45 && GetMouseY() <= 200))

	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (poz_find>0)
			{
			
				if (temp->cautare(temp->rad, find_arbore) == nullptr)
				{
				
					code = 5;
					SetWindowPosition(0, 40);
					poz_find = 0;
					temp->creare(find_arbore);
					temp->recalculare_pozitii(temp->rad, 0);

					int p1 = temp->get_poz_x_rad(), p2 = temp->get_poz_x();

					if (p2 >= p1)
					{
						poz_x = p2 - p1;
						poz_x *= (-1);
					}
					else
					{
						poz_x = p1 - p2;

					}
					poz_y = temp->get_poz_y_rad() - temp->get_poz_y();
					
					find_arbore[0] = 0;
					even.adaugare_nod = 0;
					WaitTime(0.2);
					//Sleep(200);
				}
				else
				{
					even.adaugare_nod = 1;
				}
				
				
				
			}
		}
		dreptunghi_rotunjit(30, 35, x - 60, 240, tema1[2]);
		dreptunghi_rotunjit(30, 200, x - 60, 100, tema1[2]);

	}
	else
	{
		dreptunghi_rotunjit(35, 45, x - 70, 250, tema1[5]);
		dreptunghi_rotunjit(35, 200, x - 70, 100, tema1[5]);
		
	}

	if ((GetMouseX() >= 35 && GetMouseX() <= x - 70 && GetMouseY() >= 350 && GetMouseY() <= 450))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			find_arbore[0] = 0;
			poz_find = 0;
			code = 5;
			WaitTime(0.2);
			//Sleep(200);
		}
		dreptunghi_rotunjit(30, 345, x - 60, 110, tema1[2]);
	}
	else
	{
		dreptunghi_rotunjit(35, 350, x - 70, 100, tema1[5]);
	}
	DrawTextEx(font, "Dati cheia pentru noul\n\n\n\n      nod al arborelui", { 100,80 }, 50, 0, tema1[1]);
	DrawTextEx(font, "Anulare", { 275,375 }, 50, 0, tema1[1]);

	dreptunghi_rotunjit(37, 202, x - 70 - 4, 100 - 4, LIGHTGRAY);

	
	if(even.adaugare_nod==1)
		DrawTextEx(font, "Cheia exista deja!!!!", { 225,310 }, 30, 0, tema1[2]);
	else
		DrawTextEx(font, "Maxim 5 litere/cifre!!!!", { 200,310 }, 30, 0, tema1[2]);

	if (IsKeyPressed(KEY_CAPS_LOCK))
	{
	}
	else
		//daca am apasat backstage imi sterge ultimul caracter din caseta utilizator(daca exista)
		if (IsKeyPressed(KEY_BACKSPACE) && poz_find > 0)
		{
			poz_find--;
			find_arbore[poz_find] = 0;


		}
		else if (poz_find <= 5)
			//verific ce tasta am apasat si o inserez
			for (int key = 0; key < 512; key++)
			{
				//daca e caracter valid(litera mica, mare sau numar) o insereaza, in caz contrar imi pune '#'
				if (IsKeyPressed(key)) {
					even.adaugare_nod = 0;
					if ((key >= '0' && key <= '9')||(key >= 'a' && key <= 'z')||(key >= 'A' && key <= 'Z'))
						if (poz_find < 5)
						{

							find_arbore[poz_find] = GetCharPressed();
							poz_find++;
							find_arbore[poz_find] = 0;

						}
				}

			}

	DrawTextEx(font, find_arbore, { (float)55 + (x - 105 - MeasureTextEx(font,find_arbore,50,0).x) / 2,230 }, 50, 0, tema1[0]);



}

//pagina modificare nod sau stergere(am apasat pe un nod nenul)
void draw_modificare_nod(int& nr_fii, Font font, char* find_arbore, int& poz_find, int& code, arbore* &temp, int& poz_x, int& poz_y)
{
	int x = GetScreenWidth(), y = GetScreenHeight();
	DrawRectangle(0, 0, x, y, tema1[5]);
	DrawRectangle(10, 10, x - 20, y - 20, tema1[6]);


	if ((GetMouseX() >= 35 && GetMouseX() <= x - 70 && GetMouseY() >= 45 && GetMouseY() <= 200))

	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (poz_find > 0)
			{
				
				if (temp->cautare(temp->rad, find_arbore) == nullptr)
				{

					code = 5;
					SetWindowPosition(0, 40);
					poz_find = 0;
					temp->set_value(find_arbore);

					find_arbore[0] = 0;
					even.modificare_nod = 0;
					WaitTime(0.2);
					//Sleep(200);

				}
				else
				{
					if (strcmp(temp->get_value(), find_arbore) == 0)
						even.modificare_nod = 2;
					else even.modificare_nod = 1;
				}



			}
		}
		dreptunghi_rotunjit(30, 35, x - 60, 240, tema1[2]);
		dreptunghi_rotunjit(30, 200, x - 60, 100, tema1[2]);

	}
	else
	{
		dreptunghi_rotunjit(35, 45, x - 70, 250, tema1[5]);
		dreptunghi_rotunjit(35, 200, x - 70, 100, tema1[5]);

	}

	if ((GetMouseX() >= 35 && GetMouseX() <= x - 70 && GetMouseY() >= 500 && GetMouseY() <= 600))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			find_arbore[0] = 0;
			poz_find = 0;
			code = 5;
			WaitTime(0.2);
			//Sleep(200);
		}
		dreptunghi_rotunjit(30, 495, x - 60, 110, tema1[2]);
	}
	else
	{
		dreptunghi_rotunjit(35, 500, x - 70, 100, tema1[5]);
	}
	if ((GetMouseX() >= 35 && GetMouseX() <= x - 70 && GetMouseY() >= 350 && GetMouseY() <= 450))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			find_arbore[0] = 0;
			poz_find = 0;
			code = 5;
			int niv = temp->get_nivel();
			temp->stergere(temp);
			
			arbore* aux = temp->rad;
			
			temp = new arbore(niv);
			temp->inaltime = 1;
			
			temp->reinitializare_nivele(temp->rad,1);
			temp->calculare_inaltime(temp->rad);
			temp->recalculare_pozitii(temp->rad,0);
			WaitTime(0.2);
			//Sleep(200);
		}
		dreptunghi_rotunjit(30, 345, x - 60, 110, tema1[2]);
	}
	else
	{
		dreptunghi_rotunjit(35, 350, x - 70, 100, tema1[5]);
	}



	DrawTextEx(font, "Modificare cheii\n\n\n\nnodului selectat", { 175,80 }, 50, 0, tema1[1]);
	DrawTextEx(font, "Stergere nod/subarbore", {75,375 }, 50, 0, tema1[1]);
	DrawTextEx(font, "Anulare", { 275,525 }, 50, 0, tema1[1]);

	dreptunghi_rotunjit(37, 202, x - 70 - 4, 100 - 4, LIGHTGRAY);


	if (even.modificare_nod == 1)
		DrawTextEx(font, "Cheia exista deja!!!!", { 225,310 }, 30, 0, tema1[2]);
	else
		if (even.modificare_nod == 2)
			DrawTextEx(font, "Aceasta este cheia curenta!!!!", { 150,310 }, 30, 0, tema1[2]);
		else
		
		DrawTextEx(font, "Maxim 5 litere/cifre!!!!", { 200,310 }, 30, 0, tema1[2]);

	if (IsKeyPressed(KEY_CAPS_LOCK))
	{
	}
	else
		//daca am apasat backstage imi sterge ultimul caracter din caseta utilizator(daca exista)
		if (IsKeyPressed(KEY_BACKSPACE) && poz_find > 0)
		{
			poz_find--;
			find_arbore[poz_find] = 0;


		}
		else if (poz_find <= 5)
			//verific ce tasta am apasat si o inserez
			for (int key = 0; key < 512; key++)
			{
				//daca e caracter valid(litera mica, mare sau numar) o insereaza, in caz contrar imi pune '#'
				if (IsKeyPressed(key)) {
					even.adaugare_nod = 0;
					if ((key >= '0' && key <= '9') || (key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
						if (poz_find < 5)
						{

							find_arbore[poz_find] = GetCharPressed();
							poz_find++;
							find_arbore[poz_find] = 0;

						}
				}

			}

	DrawTextEx(font, find_arbore, { (float)55 + (x - 105 - MeasureTextEx(font,find_arbore,50,0).x) / 2,230 }, 50, 0, tema1[0]);



}

void draw_page_arbore(int x, int y, Font font, Font font3, int& code, int& poz_x, int& poz_y, int& xd, int& yd, int& xu, int& yu, char* find_arbore, int& poz_find, arbore* tree, arbore* &temp)
{
	SetWindowPosition(0, 40);

	DrawRectangle(0, 0, x - 550, y, tema1[5]);

	//desenare arbore
	tree->desenare_arbore(poz_x, poz_y, tree, 0, tema1, font3);


	//desenare butoane zoom
	DrawRectangle(x - 650, y - 300, 100, 200, tema1[0]);
	DrawRectangle(x - 640, y - 290, 100 - 20, 180, LIGHTGRAY);

	//am apasat buton zoom in
	if ((GetMouseX() >= x - 650 && GetMouseX() <= x - 550 && GetMouseY() >= y - 300 && GetMouseY() <= y - 200))
	{
		DrawRectangle(x - 640, y - 290, 100 - 20, 90, tema1[2]);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			
			int x1 = tree->get_lungime_patrat(), y1 = tree->get_marime_scris();
			x1 = min(x1 + 15, 400);
			y1 = min(y1 + 3, 80);
		
			tree->set_lungime_patrat(x1);

			tree->set_marime_scris(y1);

		}

	}

	//am apasat buton zoom out
	if ((GetMouseX() >= x - 650 && GetMouseX() <= x - 550 && GetMouseY() >= y - 200 && GetMouseY() <= y - 100))
	{
		DrawRectangle(x - 640, y - 200, 100 - 20, 90, tema1[2]);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			
			int x1 = tree->get_lungime_patrat(), y1 = tree->get_marime_scris();
			x1 = max(x1 - 15, 20);
			y1 = max(y1 - 3, 4);
			
			tree->set_lungime_patrat(x1);
			tree->set_marime_scris(y1);

		}
	}

	DrawRectangle(x - 630, y - 255, 60, 10, tema1[0]);
	DrawRectangle(x - 605, y - 280, 10, 60, tema1[0]);
	DrawRectangle(x - 630, y - 155, 60, 10, tema1[0]);
	DrawRectangle(x - 640, y - 205, 100, 10, tema1[0]);



	//afisare deplasament fata de radacina
	DrawRectangle(x - 1000, 0, 450, 180, tema1[0]);
	DrawRectangle(x - 990, 10, 450 - 20, 180 - 20, LIGHTGRAY);
	DrawTextEx(font, "Deplasament fata de radacina: ", { x * 1.0f - 980   ,30 }, 28, 0, tema1[5]);
	char numarText[1000];
	snprintf(numarText, sizeof(numarText), "%d", poz_x);
	DrawTextEx(font, "X: ", { x * 1.0f - 980   ,80 }, 28, 0, tema1[5]);
	DrawTextEx(font, numarText, { x * 1.0f - 930   ,80 }, 28, 0, tema1[2]);
	snprintf(numarText, sizeof(numarText), "%d", poz_y);
	DrawTextEx(font, "Y: ", { x * 1.0f - 980   ,130 }, 28, 0, tema1[5]);
	DrawTextEx(font, numarText, { x * 1.0f - 930   ,130 }, 28, 0, tema1[2]);





	DrawRectangle(x - 550, 0, 550, y, tema1[6]);
	DrawRectangle(x - 500, 50, 450, y - 200, BLACK);
	DrawRectangle(x - 490, 60, 430, y - 220, LIGHTGRAY);

	int aux = (y - 220) / 17;

	
	
			
	//calculare deplasament
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				xd = GetMouseX();
				xu = xd;
				yd = GetMouseY();
				yu = yd;

			}

			if ( ((xd >= x - 1000 && xd <= x - 550) && (yd >= 0 && yd <= 180)))
			{ }
			else
				if ( (xd >= x - 650 && xd <= x - 550 && (yd >= y - 300 & yd <= y - 100)))
				{
				}
				else
			if (xd <= x - 550 && GetMouseX() >= 0 && GetMouseX() <= x - 550 && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			{
				xu = GetMouseX();
				yu = GetMouseY();

				if (xd > xu)
					poz_x -= (xd - xu);
				else
					poz_x += (xu - xd);

				if (yd > yu)
					poz_y -= (yd - yu);
				else
					poz_y += (yu - yd);
				xd = xu, yd = yu;
			}
			


	
		
	
	//buton intoarce-te la radacina
	if ((GetMouseX() >= x-470 && GetMouseX() <= x-80 && GetMouseY() >= 60+aux && GetMouseY() <= 60+aux*4 ))

	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			poz_x = poz_y = 0;
		}
		dreptunghi_rotunjit(x - 490, 60 + aux-20, 430, aux * 3+40, tema1[2]);
		DrawTextEx(font, "Intoarce-te\n\n\n\nla radacina", { (float)x - 440,75 + aux * 1.0f }, 65, 0, tema1[1]);

	}
	else
	{
		dreptunghi_rotunjit(x - 470, 60 + aux, 390, aux * 3, tema1[5]);
		DrawTextEx(font, "Intoarce-te\n\n\n\nla radacina", { (float)x - 410,80 + aux *1.0f }, 50, 0, tema1[1]);

	}

	//buton cautare
	if ((GetMouseX() >= x - 470 && GetMouseX() <= x - 80 && GetMouseY() >= 60 + aux * 5+aux * 3 / 2 && GetMouseY() <= 60 + aux * 8 )&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		even.caseta_cautare = 1;
	}
	else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		even.caseta_cautare = 0;
	}
	
	if (even.caseta_cautare == 1)
	{
		if (IsKeyPressed(KEY_CAPS_LOCK))
		{
		}
		else
			//daca am apasat backstage imi sterge ultimul caracter din caseta utilizator(daca exista)
			if (IsKeyPressed(KEY_BACKSPACE)&&poz_find>0)
			{
				poz_find --;
				find_arbore[poz_find] = 0;
				
				
			}
			else if(poz_find<=4)
				//verific ce tasta am apasat si o inserez
				for (int key = 0; key < 512; key++)
				{
					//daca e caracter valid(litera mica, mare sau numar) o insereaza, in caz contrar imi pune '#'
					if (IsKeyPressed(key)) {
							if((key>='a'&&key<='z')|| (key >= 'A' && key <= 'Z')||(key >= '0' && key <= '9'))
								if (poz_find <= 4)
								{
									
									find_arbore[poz_find] = GetCharPressed();
									poz_find++;
									find_arbore[poz_find] = 0;
								}
					}

				}
	}


	//buton cautare
	if ((GetMouseX() >= x - 470 && GetMouseX() <= x - 80 && GetMouseY() >= 60 + aux*5 && GetMouseY() <= 60 + aux * 5+aux*3/2 ))

	{

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			//cautare 
			

			arbore* aux2=tree->cautare(tree->get_radacina(), find_arbore);
			if (aux2 != nullptr)
			{

				aux2->set_poz_x_rad((x - 550 - aux2->get_lungime_patrat() / 2) / 2);
				aux2->set_poz_y_rad(200);
				tree->recalculare_pozitii(tree,0);

				int p1 = aux2->get_poz_x_rad(), p2 = aux2->get_poz_x();
				
				if (p2 >= p1)
				{
					poz_x = p2 - p1;
					poz_x *= (-1);
				}
				else
				{
					poz_x = p1 - p2;
					
				}				
				poz_y = aux2->get_poz_y_rad()- aux2->get_poz_y();	
				find_arbore[0] = 0;
				poz_find = 0;
			}
			
			
		}
		dreptunghi_rotunjit(x - 490, 60 + aux * 5-20, 430, aux * 3+20, tema1[2]);
		dreptunghi_rotunjit(x - 490, 60 + aux * 5 + aux * 3 / 2, 430, aux * 3 / 2, tema1[2]);
		dreptunghi_rotunjit(x - 490 + 2, 60 + aux * 5 + aux * 3 / 2 + 2, 430 - 4, aux * 3 / 2 - 4, LIGHTGRAY);

		DrawTextEx(font, "Cautare", { (float)x - 385,55 + aux * 5.0f }, 65, 0, tema1[1]);

	}
	else
	{
		dreptunghi_rotunjit(x - 470, 60 + aux * 5, 390, aux * 3, tema1[5]);
		dreptunghi_rotunjit(x - 470, 60 + aux * 5+ aux * 3 / 2, 390, aux * 3/2, tema1[5]);
		dreptunghi_rotunjit(x - 470+2, 60 + aux * 5 + aux * 3 / 2+2, 390-4, aux * 3 / 2-4, LIGHTGRAY);

		DrawTextEx(font, "Cautare", { (float)x - 355,80 + aux * 5.0f }, 50, 0, tema1[1]);

	}

	DrawCircle(x - 420, 95 + aux * 5 + aux * 3 / 2, 25, tema1[5]);
	DrawCircle(x - 120, 95 + aux * 5 + aux * 3 / 2, 25, tema1[5]);
	if (even.caseta_cautare == 0)
	{
		DrawCircle(x - 420, 95 + aux * 5 + aux * 3 / 2, 22, LIGHTGRAY);
		DrawCircle(x - 120, 95 + aux * 5 + aux * 3 / 2, 22, LIGHTGRAY);
	}
	else
	{
		DrawCircle(x - 420, 95 + aux * 5 + aux * 3 / 2, 22, tema1[2]);
		DrawCircle(x - 120, 95 + aux * 5 + aux * 3 / 2, 22, tema1[2]);
		DrawTextEx(font, "Maxim 5 caractere!( 0->9 , a->z , A->Z )", { (float)x - 475,80 + aux * 8.0f - 15 }, 22, 0, tema1[2]);

	}
	if(poz_find>0)
		DrawTextEx(font, find_arbore, { (float)x - 388 + (240-MeasureTextEx(font,find_arbore,50,0).x) / 2,80 + aux * 5.0f + aux * 3 / 2 }, 50, 0, tema1[0]);


	//buton sortare
	if ((GetMouseX() >= x - 470 && GetMouseX() <= x - 80 && GetMouseY() >= 60 + aux*9 && GetMouseY() <= 60 + aux * 12  ))

	{

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			///arbore.sort()
			arbore* aux = tree->get_radacina();
			tree->sortare(aux);
		}

		dreptunghi_rotunjit(x - 490, 60 + aux * 9 - 20, 430, aux * 3 + 40, tema1[2]);
		DrawTextEx(font, "    Sortare\n\n\n\ndescendenti", { (float)x - 460,75 + aux * 9.0f }, 65, 0, tema1[1]);

	}
	else
	{
		dreptunghi_rotunjit(x - 470, 60 + aux * 9, 390, aux * 3, tema1[5]);
		DrawTextEx(font, "    Sortare\n\n\n\ndescendenti", { (float)x - 420,80 + aux * 9.0f }, 50, 0, tema1[1]);
	}
	
	
	//buton inapoi
	if (GetMouseX() >= x - 470 && GetMouseX() <= x - 80 && GetMouseY() >= 60 + aux*13 && GetMouseY() <= 60 + aux * 16 )

	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			code = 3;
			find_arbore[0] = 0;
			poz_find = 0;
			SetWindowPosition((x - 1280) / 2, (y - 900) / 2);
			poz_x = poz_y = 0;
			temp = tree->rad;
			temp->stergere(temp);
			
		
			poz_x = poz_y = 0;
			tree->set_lungime_patrat(100);
			tree->set_marime_scris(20);
			tree->set_poz_x_rad((x - 550 - tree->get_lungime_patrat() / 2) / 2);
			tree->set_poz_y_rad(200);
			tree->calculare_inaltime(tree->get_radacina());
			tree->recalculare_pozitii(tree, 0);

			
		}
		dreptunghi_rotunjit(x - 490, 60 + aux * 13-20, 430, aux * 3+40, tema1[2]);
		DrawTextEx(font, "Inapoi", { (float)x - 370,105 + aux * 13.0f }, 65, 0, tema1[1]);

	}
	else
	{
		

		dreptunghi_rotunjit(x - 470, 60 + aux * 13, 390, aux * 3, tema1[5]);
		DrawTextEx(font, "Inapoi", { (float)x - 350,110 + aux * 13.0f }, 50, 0, tema1[1]);
	}

	
	//adaugare nod
	//modficare sau stergere nod
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() <= x - 550)
		if (!((GetMouseX() >= x - 1000 && GetMouseX() <= x - 550) && (GetMouseY() >= 0 && GetMouseY() <= 180)))
		
			if (!(GetMouseX() >= x - 650 && GetMouseX() <= x - 550 && (GetMouseY() >= y - 300 && GetMouseY() <= y - 100)))
	{
		int buton_pressed_x = GetMouseX(), buton_pressed_y=GetMouseY();
		int cod_buton = -1;
		temp= tree->cautare_click(buton_pressed_x, buton_pressed_y, tree->get_radacina(), cod_buton);
		
		if (cod_buton == 1)
		{
			 code = 6;
		}
		else if (cod_buton == 2)
		{
			
			code = 7;
		}

			cout << cod_buton<<'\n';
		
	}


}