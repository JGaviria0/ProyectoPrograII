// autor: Jhon Alex Gaviria Tobón
// fecha: 15/11/19 08:48

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void menu();
void mostrar ();
void espacios (int n, int h);
void aniadir ();
int contar ();
void buscar ();
void buscarN ();
void eliminar ();
int esta (int n, string peli);
void graficoM();
void graficoN();
void graficoA();
void graficoB ();
void graficoE();
void graficoFinal();

int easter_egg = 0;

int main (){
	
	menu();
	

	return 0;
}

void menu(){
	
	int opcion;
	
	graficoM();
	if (easter_egg > 5) { system("cls"); graficoFinal(); easter_egg = 4; }
	opcion=toupper(getch());
	
	switch (opcion){
		
		case '1': mostrar (); break;
		case '2': aniadir (); break;
		case '3': buscar (); break;
		case '4': eliminar (); break;
		case '5': exit (1); break;
		default: {
			 system("cls");
			 graficoFinal();
			 easter_egg = easter_egg + 1;
			 menu();
			break;
		}
	}
	int nada;
	nada=toupper(getch());
	system("cls");
	
	menu();
}

void graficoM(){
	
	cout << endl << endl<< endl<< endl;
cout << "                                              ";
cout << "___  ___ _____ _   _ _   _ " << endl;
cout << "                                              ";
cout << "|  \\/  ||  ___| \\ | | | | |" << endl;
cout << "                                              ";
cout << "| .  . || |__ |  \\| | | | |" << endl;
cout << "                                              ";
cout << "| |\\/| ||  __|| . ` | | | |" << endl;
cout << "                                              ";
cout << "| |  | || |___| |\\  | |_| |" << endl;
cout << "                                              ";
cout << "\\_|  |_/\\____/\\_| \\_/\\___/ " << endl;
	
	cout << endl << endl<< endl<< endl;
	cout << "                                            ";
	cout << "  [1]-Mostrar peliculas."<< endl; 
	cout << "                                            ";
	cout << "  [2]-Agregar nueva pelicula."<< endl; 
	cout << "                                            "; 
	cout << "  [3]-Buscar pelicula."<< endl;
	cout << "                                            ";
	cout << "  [4]-Eliminar pelicula."<< endl;
	cout << "                                            ";
	cout << "  [5]-salir."<< endl;
	cout << "                                            ";
	cout << endl<< endl<< endl<< endl<< endl;
	cout << "                                                           ";
cout << "                                 )___("<< endl;
cout << "                                                           ";
cout << "                          _______/__/_"<< endl;
cout << "                                                           ";
cout << "                 ___     /===========|   ___"<< endl;
cout << "                                                           ";
cout << " ___       __   [\\\\\\]___/____________|__[///]   __ "<< endl; 
cout << "                                                           ";
cout << "\\   \\_____[\\\\]__/___________________________\\__[//]___"<< endl;
cout << "                                                           ";
cout << " \\40A                                                 |"<< endl;
cout << "                                                           ";
cout << "  \\                                                  /"<< endl;
cout << "                                                           ";
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	
}

// ---------------------------------------------  MOSTRAR  ------------------------------------------------------//

void mostrar (){
	system("cls");
	int nada;
	int contador = 0, cambio = 0;
	
	
	graficoN();
	
	ifstream archivo;
	string nombreArchivo,texto;
	
	archivo.open("peliculas.txt",ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout << "               ";
	cout << "N°  " << "Nombre               " << "Director            "  << "Genero               ";
	cout << "Puntuacion " << "Duracion"<< endl;
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
		if (texto [0] != '\0'){
			cout << "               ";
		for (int i=0; texto[i] != '\0'; i++){
			if (texto [i] != '/'){
				cout << texto [i];
				contador = contador + 1;
			}
			else{
				espacios (contador, cambio);
				cambio = cambio + 1;
				contador = 0;
			}
		}
		cout << endl;
		cambio = 0;
	}
	}
	archivo.close(); //Cerramos el archivo
	
}

void espacios (int n, int h){
	switch (h){
		case 0: h = 3; break;
		case 1: h = 21; break;
		case 2: h = 20; break;
		case 3: h = 25; break;
		case 4: h = 7; break;
		case 5: h = 9; break;	
	}
	n = h - n;
	for (int i= 0; i<n; i++){
		cout << " ";
	}
	
	
}

void graficoN(){
cout << "                                            ";
cout << "______    _ _            _           " << endl;
cout << "                                            ";
cout << "| ___ \\  | (_)          | |          " << endl;
cout << "                                            ";
cout << "| |_/ /__| |_  ___ _   _| | __ _ ___ " << endl;
cout << "                                            ";
cout << "|  __/ _ \\ | |/ __| | | | |/ _` / __|" << endl;
cout << "                                            ";
cout << "| | |  __/ | | (__| |_| | | (_| \\__ \\" << endl;
cout << "                                            ";
cout << "\\_|  \\___|_|_|\\___|\\__,_|_|\\__,_|___/" << endl;	
cout << endl<< endl;
}

// ---------------------------------------------  AÑADIR   ------------------------------------------------------//

void aniadir (){
	system("cls");
	int n = contar() + 1;
	ofstream archivo;
	string texto;
	char rpt, hora;
	
	archivo.open("peliculas.txt",ios::app);
	archivo << endl;
	graficoA();
	if (n < 10){
		archivo << n<< "  / ";
	}
	else{
		archivo << n << " / ";
	}
	do{
		fflush(stdin);
		int  ele, con = 0, bandera = 0;
		char genero [50] = "";
		char aux [50] = "";
		cout << "                                            ";
		cout<<"Digite el nombre de la nueva pelicula: ";
		getline(cin,texto);
		archivo<<texto << " / ";
		cout << endl;
		cout << "                                            ";
		cout << "Digite el director de la pelicula: ";
		getline(cin,texto);
		archivo<<texto << " / ";
		cout << endl;
		cout << "                                            ";
		cout << " -- ESCOJA EL GENERO: -- "<< endl;cout << "                                            ";
		cout << " [1] - Accion.       [6] - Horror. " << endl;	cout << "                                            ";
		cout << " [2] - Aventura.     [7] - Misterio. " << endl;cout << "                                            ";
		cout << " [3] - Comedia.      [8] - Romance.  " << endl;cout << "                                            ";
		cout << " [4] - Crimen.       [9] - C. ficcion." << endl;cout << "                                            ";
		cout << " [5] - Drama.        [10]- Thriller." << endl;
		do{
			cout << "                                            ";
			cout<< "Escoja un genero: ";
			cin >> ele;
			cin.ignore();
			switch (ele){
				case 1:{ strcat(genero, "Accion");break;}
				case 2:{ strcat(genero, "Aventura");break;}
				case 3:{ strcat(genero, "Comedia");break;}
				case 4:{ strcat(genero, "Crimen");break;}
				case 5:{ strcat(genero, "Drama");break;}
				case 6:{ strcat(genero, "Horror");break;}
				case 7:{ strcat(genero, "Misterio");break;}
				case 8:{ strcat(genero, "Romance");break;}
				case 9:{ strcat(genero, "C. ficcion");break;}
				case 10:{ strcat(genero,"Thriller");break;}
				default : cout << "Ingrese una opcion valida."; break;
			}
			if (bandera == 0){
			cout << "                                            ";
			cout << "Quiere elegir un genero adicional? (s/n): ";
			cin>>rpt;
			cin.ignore();
			if ((rpt == 'S') || (rpt == 's')){
				strcat(genero, ", ");
			}
		}
			con = con +1;
			if (con <= 2){
				strcpy(aux,genero);
			}
			bandera = bandera + 1;
		}while(((rpt == 'S') || (rpt == 's')) && bandera < 2 );
		
		archivo << aux;
		
		cout << endl << "                                            "<< "Digite la puntuacion de la pelicula: ";
		getline(cin,texto);
		archivo <<" / " << texto << " / ";
		cout << endl;
		cout << "                                            ";
		cout << "Digite la duracion de la pelicula (formato --h --min): ";
		getline(cin,texto); 
		archivo<<texto << endl;
		cout << endl;
		
		cout << "                                            ";
		cout<<"Desea agregar otra pelicula? (s/n): ";
		cin>>rpt;
		cin.ignore();
	}while((rpt == 'S') || (rpt == 's'));
	
	cout << endl << endl << endl;
	archivo.close();
	
} 

void graficoA(){
	cout << "                                            ";
cout << "  ___ "<< endl;    cout << "                                            ";                             
cout << " / _ \\   "<< endl;  cout << "                                            ";                             
cout << "/ /_\\ \\ __ _ _ __ ___  __ _  __ _ _ __ "<< endl; cout << "                                            ";
cout << "|  _  |/ _` | '__/ _ \\/ _` |/ _` | '__|"<< endl; cout << "                                            ";
cout << "| | | | (_| | | |  __/ (_| | (_| | |   "<< endl; cout << "                                            ";
cout << "\\_| |_/\\__, |_|  \\___|\\__, |\\__,_|_|   "<< endl; cout << "                                            ";
cout << "        __/ |          __/ |           "<< endl; cout << "                                            ";
cout << "       |___/          |___/            "<< endl; 
cout << endl << endl;
}

int contar (){
	
	ifstream archivo;
	int n = 0;
	string texto;
	
	archivo.open("peliculas.txt",ios::in); 
	
	while(!archivo.eof()){ 
		getline(archivo,texto);
		if (texto [0] != '\0') n = n + 1;
	}
	
	return n;
}

// ---------------------------------------------  BUSCAR   ------------------------------------------------------//

void buscar (){
	system("cls");
	char opcion;

	graficoB();
	
	opcion=getch();
	
	switch (opcion){
		case '1': { 
			cout << endl<< "                                            " <<"Digite el nombre de la pelicula que desea buscar: ";
			buscarN ();
			break;
		}
		case '2':{ 
			cout << endl<< "                                            " <<"Digite el director que desea buscar: ";
			buscarN ();
			break;
		}
		case '3': { 
			cout << endl<< "                                            " <<"Digite el genero que desea buscar: ";
			buscarN ();
			break;
		}
		default:{ 
			cout<<endl << endl <<"                                            " << "Digite una opcion valida"<<endl;
			buscar();
			break;
		}
		}
		cin.ignore();
	}
	
void buscarN (){
	
	int contador = 0, cambio = 0, bandera = 0;
	string peli;
	ifstream archivo;
	string texto, aux;
	archivo.open("peliculas.txt",ios::in); 
	getline(cin, peli);
	
	bandera = esta (0, peli);
	
	if (bandera == 0){
		cout <<endl<<endl <<"                                            "<< '"' << peli <<'"'<< "no encontrada"<< endl; 
		}
	else{
		graficoN();
		cout << "               ";
		cout << "N°  " << "Nombre               " << "Director            "  << "Genero               ";
		cout << "Puntuacion " << "Duracion"<< endl ;
		while(!archivo.eof()){ 
			getline(archivo,texto);
			if (texto.find(peli) != string::npos){
				cout << "               ";
				for (int i=0; texto[i] != '\0'; i++){
					if (texto [i] != '/'){
						cout << texto [i];
						contador = contador + 1;
					}
					else{
						espacios (contador, cambio);
						cambio = cambio + 1;
						contador = 0;
					}
				}
				cout << endl;
				cambio = 0;
			}
		}
	}
	archivo.close(); //Cerramos el archivo
	
}

int esta (int n, string peli){
	
	ifstream archivo;
	string texto;
	archivo.open("peliculas.txt",ios::in); 
	while(!archivo.eof()){ 
		getline(archivo,texto);
		if (texto.find(peli) != string::npos) n = 1;
	}
	archivo.close();
	return n;
}

void graficoB(){
	
	
	cout << "                                            ";
cout << "______  " << endl;
cout << "                                            ";
cout << "| ___ \\ " << endl;
cout << "                                            ";
cout << "| |_/ /_   _ ___  ___ __ _ _ __ " << endl;
cout << "                                            ";
cout << "| ___ \\ | | / __|/ __/ _` | '__|" << endl;
cout << "                                            ";
cout << "| |_/ / |_| \\__ \\ (_| (_| | |" << endl;
cout << "                                            ";
cout << "\\____/ \\__,_|___/\\___\\__,_|_| " << endl;	
cout << endl<< endl;
cout << "                                            ";
cout << "[1] - Buscar nombre de la pelicula."<< endl;
cout << "                                            ";
cout << "[2] - Buscar el director de la pelicula."<< endl;
cout << "                                            ";
cout << "[3] - Buscar el genero de la pelicula."<< endl;
}

// --------------------------------------------- ELIMINAR  ------------------------------------------------------//

void eliminar (){
	system("cls");
	string texto, nombre;
	
	ifstream salida;
	salida.open("peliculas.txt", ios::in);
	
	ofstream entrada;
	entrada.open("temporal.txt", ios::out);
	
	if (salida.fail()){
		cout << "hubo un problema";
		exit (1);
	}
	graficoE();
	cout << "                                            Digite el nombre de la pelicula a eliminar: ";
	getline(cin,nombre);
	int bandera = 0;
	bandera = esta (0, nombre);
	if (bandera == 0){
		cout << endl <<endl <<"                                            "<< '"' << nombre <<'"'<< "no encontrada"<< endl; 
		entrada.close();
		salida.close();
		}
	else{	
		while (!salida.eof()){
			getline(salida, texto);
			if (texto [0] != '\0'){
				if (texto.find(nombre) != string::npos){
					cout << "                                            Pelicula eliminada.";
				}
				else {
					if (bandera == 1 ) entrada << endl;
					entrada << texto;
				}
			}
		}
	entrada.close();
	salida.close();
	remove("peliculas.txt");
	rename ("temporal.txt", "peliculas.txt");
	}
}

void graficoE(){
	
		cout << endl << endl<< endl<< endl;
cout << "                                              ";
cout << " _____ _ _           _                  " << endl;
cout << "                                              ";
cout << "|  ___| (_)         (_)                 " << endl;
cout << "                                              ";
cout << "| |__ | |_ _ __ ___  _ _ __   __ _ _ __ " << endl;
cout << "                                              ";
cout << "|  __|| | | '_ ` _ \\| | '_ \\ / _` | '__|" << endl;
cout << "                                              ";
cout << "| |___| | | | | | | | | | | | (_| | |   " << endl;
cout << "                                              ";
cout << "\\____/|_|_|_| |_| |_|_|_| |_|\\__,_|_|  " << endl;

cout << endl << endl<< endl<< endl;
}

void graficoFinal(){
	
cout << endl << endl << endl << endl;
cout << "                                                          ^^"<< endl;
cout << "                       ^^      ..                                       .."<< endl;
cout << "                               []                                       []"<< endl;
cout << "                             .:[]:_          ^^                       ,:[]:."<< endl;
cout << "                           .: :[]: :-.                             ,-: :[]: :."<< endl;
cout << "                         .: : :[]: : :`._                       ,.': : :[]: : :."<< endl;
cout << "                       .: : : :[]: : : : :-._               _,-: : : : :[]: : : :."<< endl;
cout << "                   _..: : : : :[]: : : : : : :-._________.-: : : : : : :[]: : : : :-._"<< endl;
cout << "                   _:_:_:_:_:_:[]:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:[]:_:_:_:_:_:_"<< endl;
cout << "                   !!!!!!!!!!!![]!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!![]!!!!!!!!!!!!!"<< endl;
cout << "                   ^^^^^^^^^^^^[]^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^[]^^^^^^^^^^^^^"<< endl;
cout << "                               []                                       []"<< endl;
cout << "                               []                                       []"<< endl;
cout << "                               []                                       []"<< endl;
cout << "                    ~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/  \\~^-~_~^-~~- "<< endl;
cout << "                   ~ _~~- ~^-^~-^~~- ^~_^-^~~_ -~^_ -~_-~~^- _~~_~-^_ ~^-^~~-_^-~ ~^"<< endl;
cout << "                      ~ ^- _~~_-  ~~ _ ~  ^~  - ~~^ _ -  ^~-  ~ _  ~~^  - ~_   - ~^_~"<< endl;
cout << "                        ~-  ^_  ~^ -  ^~ _ - ~^~ _   _~^~-  _ ~~^ - _ ~ - _ ~~^ -"<< endl;
cout << "                           ~^ -_ ~^^ -_ ~ _ - _ ~^~-  _~ -_   ~- _ ~^ _ -  ~ ^-"<< endl;
cout << "                               ~^~ - _ ^ - ~~~ _ - _ ~-^ ~ __- ~_ - ~  ~^_-"<< endl;
cout << "                                   ~ ~- ^~ -  ~^ -  ~ ^~ - ~~  ^~ - ~	"<< endl;

}

