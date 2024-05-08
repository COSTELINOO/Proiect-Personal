 Tutorial

1. Instalare Microsoft Visual Studio
   
-> Descarcati "Visual Studio Community 2022" de pe urmatorul link:

https://visualstudio.microsoft.com/

-> In Installer selectati "Desktop development with C++"

-> Apoi apasati click stanga pe "install"



*Descarcati(apasati click stanga pe: "Code->Download ZIP") si dezarhivati directorul principal

*Daca aveti configurata biblioteca raylib, puteti omite urmatorul pas(pasul 2)

2.Instalare bibliotecii raylib si configurarea cu Visual Studio

->Dezarhivati directorul "vcpkg"

->Deschideti directorul "vcpkg"(dezarhivat)

->Click dreapta(in director) si apasati pe "Open in Terminal"

->Scrieti comanda "./bootstrap-vcpkg.bat" urmata de enter

->Scrieti comanda "./vcpkg integrate install" urmata de enter

->Scrieti comanda "./vcpkg install raylib" urmata de enter

3.Compilare cod

->Deschideti Visual Studio

->Apsati pe "Create a new project"

->Apasati pe "Empty Project"

->Alegeti numele si locatia(eu o sa-l numesc "Proiect" cu locatia "C:\Desktop")

->Copiati in al doilea director "Proiect"(Exemplu: "C:\Desktop\Proiect\Proiect") fisierele din urmatoarele directoare descarcate: "Fisiere necesare"(de aici se copiaza directoare), "include" si "src"

->In Visual Studio dati click dreapta pe "Header Files"

->Apasati pe "Add", "Existing Item" si adaugati fisierele header(Arbore.h,GlobalFunctions.h,Librarii.h,Pagini.h)
*(fisierele header din: "C:\Desktop\Proiect\Proiect")

->In Visual Studio dati click dreapta pe "Source Files"

->Apasati pe "Add", "Existing Item" si adaugati fisierele cpp(Arbore.cpp,GlobalFunctions.cpp,Login.cpp,Pagini.cpp,Project.cpp)
*(fisierel cpp din: "C:\Desktop\Proiect\Proiect")

->Dublu click stanga pe "Project.cpp"

->Apasati "CTRL+F5" pentru a compila aplicatia

*In caz de aplicatia compileaza, dar nu arata ca in videoclipul de prezentare din directorul: "Videoclip_prezentare", reluati pasul 3 mai in detaliu



In caz de sunt erori in configurarea librariei grafice "raylib", va las urmatorul tutorial:

https://www.youtube.com/watch?v=UiZGTIYld1M




