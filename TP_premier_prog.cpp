// Nom du projet : Mes premiers programmes
// Nom de l’auteur : Trompier Téo
// Date de création : 17/09/2024
// Résumé : Mes premiers prog fonctions

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

using namespace std;

// Vérifier si une chaine de chars est un nombre
bool ceciEstUnNombre(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

// Calcul du nombre de pièces
void exercice5() {
	double pieceCent1 = 0.00, pieceCent2 = 0.00, pieceCent5 = 0.00, pieceCent10 = 0.00, pieceCent20 = 0.00, pieceCent50 = 0.00, pieceEuro1 = 0.00, pieceEuro2 = 0.00;
	double total = 0.00;

	cout << "Entrer le nombre de piece(s) de 1c\n";
	cin >> pieceCent1;

	cout << "\nEntrer le nombre de piece(s) de 2c\n";
	cin >> pieceCent2;

	cout << "\nEntrer le nombre de piece(s) de 5c\n";
	cin >> pieceCent5;

	cout << "\nEntrer le nombre de piece(s) de 10c\n";
	cin >> pieceCent10;

	cout << "\nEntrer le nombre de piece(s) de 20c\n";
	cin >> pieceCent20;

	cout << "\nEntrer le nombre de piece(s) de 50c\n";
	cin >> pieceCent50;

	cout << "\nEntrer le nombre de piece(s) de 1EUR\n";
	cin >> pieceEuro1;

	cout << "\nEntrer le nombre de piece(s) de 2EUR\n";
	cin >> pieceEuro2;

	total = (pieceCent1 * .01) + (pieceCent2 * .02) + (pieceCent5 * .05) + (pieceCent10 * .10) + (pieceCent20 * .20) + (pieceCent50 * .50) + pieceEuro1 + (pieceEuro2 * 2);

	cout << "Le resultat est de : " << total << "EUR\n";

	this_thread::sleep_for(chrono::seconds(1));
	cout << "Au revoir !";
}

void supplement2() {
	double total = 100;

	for (int pieceCent10 = 0; pieceCent10 <= total / 10; pieceCent10++) {
		for (int pieceCent5 = 0; pieceCent5 <= (total - pieceCent10 * 10) / 5; pieceCent5++) {
			int pieceCent2 = (total - pieceCent10 * 10 - pieceCent5 * 5) / 2;
			if (pieceCent10 * 10 + pieceCent5 * 5 + pieceCent2 * 2 == total) {
				cout << "1 euro = " << pieceCent2 << " X 2c";
				if (pieceCent5 > 0) cout << " " << pieceCent5 << " X 5c";
				if (pieceCent10 > 0) cout << " " << pieceCent10 << " X 10c";
				cout << endl;
			}
		}
	}
}

void exercice6() {
	/*
	Pseudocode :

	Démarrer le programme
	Demander à l'utilisateur d'entrer un caractère
	Lire le caractère saisi
	Convertir le caractère en son code ASCII en décimal
	Convertir le caractère en son code ASCII en hexadécimal
	Afficher le code ASCII en décimal
	Afficher le code ASCII en hexadécimal
	Terminer le programme
	*/

	char caractere;

	cout << "Entrez un caractere : ";
	cin >> caractere;

	cout << "Le caractere '" << caractere << "' a pour code ASCII : " << endl;
	cout << "En decimal : " << static_cast<int>(caractere) << endl;
	cout << "En hexadecimal : " << hex << static_cast<int>(caractere) << endl;
}

void exercice7() {
	/*
	Pseudocode :
	Démarrer le programme
	Parcourir les codes ASCII de 32 à 127 inclus :
		Convertir chaque tour en un caractère
		Afficher le caractère
		Afficher le code ASCII en décimal
		Afficher le code ASCII en hexadécimal
	Terminer le programme
	*/

	/*
	for (int i = 32; i <= 127; i++) {
		char caractere = static_cast<char>(i);

		cout << "Caractere :	'" << caractere << "'	ASCII decimal : " << i
			<< "	 ASCII hexadecimal : " << hex << i << dec << endl;
	}
	*/

	for (char caractere = 32; caractere <= 126; caractere++) {
		cout << "Caractere :	'" << caractere << "'		ASCII decimal : "
			<< static_cast<int>(caractere)
			<< "		ASCII hexadecimal : " << hex << static_cast<int>(caractere)
			<< dec << endl;
	}

	char caractere127 = 127;
	cout << "Caractere :	'DEL'		ASCII decimal : "
		<< static_cast<int>(caractere127)
		<< "		ASCII hexadecimal : " << hex << static_cast<int>(caractere127)
		<< dec << endl;
}

void exercice8() {
	/*
	Pseudocode :
	Démarrer le programme.
	Afficher la taille en octets d'un char.
	Afficher la taille en octets d'un bool.
	Afficher la taille en octets d'un int.
	Afficher la taille en octets d'un float.
	Afficher la taille en octets d'un double.
	Terminer le programme.
	*/

	cout << "Taille d'un char : " << sizeof(char) << " octets" << endl;
	cout << "Taille d'un bool : " << sizeof(bool) << " octets" << endl;
	cout << "Taille d'un int : " << sizeof(int) << " octets" << endl;
	cout << "Taille d'un float : " << sizeof(float) << " octets" << endl;
	cout << "Taille d'un double : " << sizeof(double) << " octets" << endl;
}

void exercice9() {
	/*
	Pseudocode :
	Démarrer le programme en initialisant le générateur de nombres aléatoires.
	Demander à l'utilisateur de saisir la valeur maximale pour le nombre à deviner.
	Générer un nombre aléatoire entre 0 et la valeur maximale choisie.
	Demander à l'utilisateur de deviner le nombre.
	Tant que l'utilisateur n'a pas deviné le bon nombre, lire le nombre saisi par l'utilisateur et comparer :
	Si le nombre est plus petit, informer l'utilisateur que c'est trop bas.
	Si le nombre est plus grand, informer l'utilisateur que c'est trop élevé.
	Si le nombre est correct, féliciter l'utilisateur et terminer le programme.
	*/

	srand(static_cast<unsigned int>(time(0)));

	int valeurMax;
	cout << "Entrez la valeur maximale pour le nombre a deviner : ";
	cin >> valeurMax;

	int nombreADeviner = rand() % valeurMax + 1;
	int trouver = -1;

	while (trouver != nombreADeviner) {
		cout << "Devinez le nombre : ";
		cin >> trouver;

		if (trouver < nombreADeviner) {
			cout << "C'est plus grand !" << endl;
		}
		else if (trouver > nombreADeviner) {
			cout << "C'est plus petit !" << endl;
		}
		else {
			cout << "Bravo ^^\nVous avez gagne." << endl;
		}
	}
}

void police(const wstring& fontName, int fontSize) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
	cfi.dwFontSize.Y = fontSize;
	wcscpy_s(cfi.FaceName, fontName.c_str());
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void effetTyping(const string& mot, const int temps) {
	for (char lettre : mot) {
		cout << lettre << flush;
		this_thread::sleep_for(chrono::milliseconds(temps));
	}
	cout << endl;
}

void centrer(const string& texte, const int temps) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	int largeurConsole = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int longueurTexte = texte.length();
	int espaceAvant = (largeurConsole - longueurTexte) / 2;
	cout << string(espaceAvant, ' ');
	effetTyping(texte, temps);
	cout << endl;
}

string analyseDeSentiment(const string& reponse) {
	const vector<string> reponsesPositives = {
		"oui", "o", "yes", "y", "bien sûr", "évidemment", "nous sommes plusieurs",
		"plusieurs", "je suis pas seul", "vrai", "true", "réel", "effectivement"
	};

	const vector<string> reponsesNegatives = {
		"non", "n", "f", "false", "pas du tout", "no", "seul", "faux"
	};

	const vector<string> negations = { "non", "ne", "pas", "jamais", "aucun", "rien" };

	istringstream iss(reponse);
	string mot;
	bool contientNegation = false;

	while (iss >> mot) {
		if (find(negations.begin(), negations.end(), mot) != negations.end()) {
			contientNegation = true;
		}
		if (find(reponsesNegatives.begin(), reponsesNegatives.end(), mot) != reponsesNegatives.end()) {
			return contientNegation ? "negative" : "positive";
		}
		if (find(reponsesPositives.begin(), reponsesPositives.end(), mot) != reponsesPositives.end()) {
			return contientNegation ? "negative" : "positive";
		}
	}

	return "inconnue";
}

void couleurVert() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

void couleurBleu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

void couleurRouge() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

void couleurJaune() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
}

void couleurBlanc() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

string PhraseDepart(vector<string>& options, int& dernierIndex) {
	int index;
	do {
		index = rand() % options.size();
	} while (index == dernierIndex);
	dernierIndex = index;
	return options[index];
}

string difficulte(const string& reponse) {
	vector<string> motsFaciles = {
		"facile", "easy", "f", "e", "simple",
		"pas difficile", "doucement", "moins dur",
		"cool", "tranquille"
	};

	vector<string> motsNormaux = {
		"normal", "n", "moyen", "standard",
		"équilibré", "modéré", "classique",
		"régulier", "ni facile ni difficile"
	};

	vector<string> motsDifficiles = {
		"difficile", "hard", "d", "h", "dur",
		"compliqué", "sévère",
		"difficilement", "éprouvant"
	};

	if (find(motsFaciles.begin(), motsFaciles.end(), reponse) != motsFaciles.end()) {
		return "facile";
	}
	if (find(motsNormaux.begin(), motsNormaux.end(), reponse) != motsNormaux.end()) {
		return "normal";
	}
	if (find(motsDifficiles.begin(), motsDifficiles.end(), reponse) != motsDifficiles.end()) {
		return "difficile";
	}

	return "inconnue";
}

int generation(const string& niveau) {
	auto tempsActuel = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 generateur(static_cast<unsigned long>(tempsActuel));

	int minComplexe, maxComplexe;
	int minBase, maxBase, sinCoef, cosCoef;

	if (niveau == "facile") {
		minBase = 1 + rand() % 9;
		maxBase = 15 + (rand() % 7);
		sinCoef = 2;
		cosCoef = 2;
	}
	else if (niveau == "normal") {
		minBase = 1 + (rand() % 17);
		maxBase = 42 + (rand() % 18);
		sinCoef = 3;
		cosCoef = 3;
	}
	else {
		minBase = 1 + (rand() % 72);
		maxBase = 148 + (rand() % 88);
		sinCoef = 5;
		cosCoef = 5;
	}

	int variationMin = static_cast<int>(sin(minBase) * sinCoef + rand() % 5);
	int variationMax = static_cast<int>(cos(maxBase) * cosCoef + rand() % 5);
	minComplexe = minBase + variationMin;
	maxComplexe = maxBase + variationMax;

	if (minComplexe >= maxComplexe) {
		minComplexe = maxComplexe - 1;
	}

	uniform_int_distribution<int> distribution(minComplexe, maxComplexe);
	return distribution(generateur);
}

void effacerDerniereLigne() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	COORD lastLine = { 0, csbi.dwCursorPosition.Y };
	SetConsoleCursorPosition(hConsole, lastLine);
}

void effetAleatoire() {
	auto tempsActuel = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 generateur(static_cast<unsigned long>(tempsActuel));
	uniform_int_distribution<int> distribution(0, 500);

	int dureeTotale = 3000;
	int intervalle = 50;
	int tempsPasse = 0;

	while (tempsPasse < dureeTotale) {
		int nombre = distribution(generateur);
		effacerDerniereLigne();
		cout << nombre << flush;

		this_thread::sleep_for(chrono::milliseconds(intervalle));
		tempsPasse += intervalle;
	}
	cout << endl;
}

string phraseAleatoirePlusPetit() {
	couleurJaune();
	vector<string> phrasesPlusPetit = {
		"Le nombre à deviner est plus petit.",
		"C'est plus petit.",
		"Essayez avec un nombre plus petit.",
		"Trop grand, il faut baisser.",
		"Vous visez trop haut.",
		"Il faut viser plus bas."
	};

	static mt19937 generateur(static_cast<unsigned long>(chrono::high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<size_t> distribution(0, phrasesPlusPetit.size() - 1);

	return phrasesPlusPetit[distribution(generateur)];
}

string phraseAleatoirePlusGrand() {
	couleurRouge();
	vector<string> phrasesPlusGrand = {
		"Le nombre à deviner est plus grand.",
		"C'est plus grand.",
		"Essayez avec un nombre plus grand.",
		"Trop petit, il faut monter.",
		"Vous visez trop bas.",
		"Il faut viser plus haut"
	};

	static mt19937 generateur(static_cast<unsigned long>(chrono::high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<size_t> distribution(0, phrasesPlusGrand.size() - 1);

	return phrasesPlusGrand[distribution(generateur)];
}

void afficherVies(int vies) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	COORD position;
	position.X = csbi.srWindow.Right - 10;
	position.Y = csbi.srWindow.Bottom - 1;
	SetConsoleCursorPosition(hConsole, position);

	couleurRouge();
	for (int i = 0; i < vies; ++i) {
		cout << "♥";
	}
	cout << endl;
	couleurBlanc();
}

void afficherPerdu() {
	system("cls");
	couleurRouge();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	int largeurConsole = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int hauteurConsole = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	string message = "Vous avez perdu !";
	int longueurMessage = message.length();
	int espaceAvant = (largeurConsole - longueurMessage) / 2;
	COORD position;
	position.X = espaceAvant;
	position.Y = hauteurConsole / 2;
	SetConsoleCursorPosition(hConsole, position);
	cout << message << endl;
	couleurBlanc();
}

void supplement3() {
	SetConsoleOutputCP(CP_UTF8);
	bool modeHardcore = false, fin = false, etape = true;
	int nombreUtilisateur;
	string pseudo = "utilisateur", hardcoreReponse, niveauReponse, niveau, recommencer;
	police(L"Terminal", 24);
	centrer("Bienvenue dans le jeu de la devinette !", 50);
	centrer("Un jeu réalisé par Téo Trompier ^^", 40);
	police(L"Lucida Console", 24);
	while (etape) {
		bool etape1 = false, etape2 = false;
		int vies = 7;
		couleurBleu();
		effetTyping("Voulez activer le mode hardcore ? (7 vies ♥)", 50);
		couleurBlanc();
		while (!etape1) {
			cin >> hardcoreReponse;
			cin.clear();
			cin.ignore(1000, '\n');
			if (analyseDeSentiment(hardcoreReponse) == "positive") {
				modeHardcore = true;
				effetTyping("Hardcore activé ^^\n", 30);
				etape1 = true;
			}
			else if (analyseDeSentiment(hardcoreReponse) == "negative") {
				modeHardcore = false;
				etape1 = true;
			}
			else {
				couleurRouge();
				effetTyping("Répondez à la question s'il vous plaît ^^", 35);
				couleurBlanc();
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		cout << "\n";
		couleurBleu();
		effetTyping("Choissisez un niveau de difficulté : ", 50);
		couleurVert();
		cout << "facile			";
		couleurJaune();
		cout << "normal			";
		couleurRouge();
		cout << "difficile" << endl;
		couleurBlanc();
		while (!etape2) {
			cin >> niveauReponse;
			if (niveauReponse.empty() || difficulte(niveauReponse) == "inconnue") {
				couleurRouge();
				effetTyping("Répondez à la question s'il vous plaît ^^", 35);
				couleurBlanc();
			}
			else {
				etape2 = true;
				niveau = difficulte(niveauReponse);
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		cout << "\n";
		couleurBleu();
		srand(static_cast<unsigned int>(time(0)));
		vector<string> approbation = {
			"C'est génial,", "C'est cool,", "Super,", "Parfait,",
			"Très bien,", "Ok,", "Formidable,", "Excellent,"
		};
		vector<string> encouragement = {
			"c'est parti !", "allons-y !", "on va pouvoir commencer !",
			"commençons !", "le jeu va pouvoir commencer.",
			"en avant !", "nous allons pouvoir démarrer.", "tout est prêt !",
		};
		int indexProbApprobation = -1;
		int indexProbEncouragement = -1;
		string phrase1 = PhraseDepart(approbation, indexProbApprobation);
		string phrase2 = PhraseDepart(encouragement, indexProbEncouragement);
		string phrase = phrase1 + " " + phrase2;
		effetTyping(phrase, 45);
		couleurBlanc();
		this_thread::sleep_for(chrono::seconds(2));
		const int nombreADeviner = generation(niveau);
		couleurBleu();
		effetTyping("Preparez-vous...", 50);
		couleurBlanc();
		this_thread::sleep_for(chrono::seconds(2));
		effetAleatoire();
		system("cls");
		this_thread::sleep_for(chrono::seconds(1));
		couleurBleu();
		effetTyping("À vous de jouer !\n", 50);
		this_thread::sleep_for(chrono::seconds(1));
		effetTyping("Essayer de deviner le nombre !", 50);
		couleurBlanc();
		while (!fin) {
			bool etape3 = false;
			while (!etape3) {
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> nombreUtilisateur;
				if (cin.fail()) {
					couleurRouge();
					effetTyping("Entrez un nombre pour jouer ^^", 35);
					couleurBlanc();
				}
				else {
					etape3 = true;
				}
			}
			if (modeHardcore) {
				afficherVies(vies);
			}
			this_thread::sleep_for(chrono::seconds(1));
			couleurBleu();
			if (nombreUtilisateur != nombreADeviner) {
				if (modeHardcore) {
					vies--;
					if (vies < 0) {
						cin.clear();
						cin.ignore(1000, '\n');
						afficherPerdu();
						couleurRouge();
						effetTyping("Voulez-vous recommencer ?\n", 50);
						cin >> recommencer;
						while (recommencer.empty() || analyseDeSentiment(recommencer) == "inconnue") {
							effetTyping("Répondez à la question s'il vous plaît ^^", 35);
							cin >> recommencer;
						}
						if (analyseDeSentiment(recommencer) == "positive") {
							system("cls");
							break;
						}
						else {
							couleurBleu();
							effetTyping("\nAu revoir ^^", 30);
							return;
						}
						cout << "\n";
						couleurBlanc();
					}
				}
			}
			if (nombreUtilisateur > nombreADeviner) {
				string phrase = phraseAleatoirePlusPetit();
				effetTyping(phrase + "\n", 50);
			}
			else if (nombreUtilisateur < nombreADeviner) {
				string phrase = phraseAleatoirePlusGrand();
				effetTyping(phrase + "\n", 50);
			}
			else {
				couleurVert();
				effetTyping("Félicitations ! Vous avez trouvé le bon nombre !\n", 50);
				this_thread::sleep_for(chrono::seconds(1));
				effetTyping("Voulez-vous recommencer ?\n", 50);
				cin >> recommencer;
				while (recommencer.empty() || analyseDeSentiment(recommencer) == "inconnue") {
					effetTyping("Répondez à la question s'il vous plaît ^^", 35);
					cin >> recommencer;
				}
				if (analyseDeSentiment(recommencer) == "positive") {
					system("cls");
					break;
				}
				else {
					couleurBleu();
					effetTyping("\nAu revoir ^^", 30);
					return;
				}
				cout << "\n";
				couleurBlanc();
			}
			couleurBlanc();
		}
	}

}

void exercice10_version1() {
	/*
	Pseudocode :
	Demander à l'utilisateur la taille du triangle.
	Pour chaque ligne i allant de 1 à la taille du triangle :
	   - Afficher i étoiles sur la ligne.
	Fin de l'algorithme.
	*/
	int tailleTriangle = 0;
	do {
		cout << "Entrez la taille du triangle d'etoiles : ";
		cin >> tailleTriangle;
		if (tailleTriangle <= 0) {
			cout << "\x1B[31mEntrez un nombre positif superieur a 0.\033[0m" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (tailleTriangle <= 0);
	for (int i = 1; i <= tailleTriangle; ++i) {
		cout << string(i, '*') << endl;
	}
}

void exercice10_version2() {
	/*
	Pseudocode :
	Initialiser la variable tailleTriangle à 0.
	Demander à l'utilisateur d'entrer la taille du triangle.
	Tant que tailleTriangle est inférieur ou égal à 0, faire :
		- Afficher un message demandant un nombre positif supérieur à 0.
		- Lire la nouvelle valeur de tailleTriangle.
	Créer un tableau de chaînes de caractères nommé triangle de taille tailleTriangle.
	Utiliser une boucle pour construire et mémoriser chaque ligne du triangle :
		- Pour chaque index i allant de 0 à tailleTriangle - 1, faire :
			- Initialiser une chaîne vide pour ligne.
			- Utiliser une boucle pour ajouter (i + 1) étoiles à ligne :
				- Pour chaque index j allant de 0 à i, faire :
					- Ajouter un "*" à ligne en utilisant strncat_s.
			- Assigner la chaîne ligne à triangle[i].
	Après la construction du triangle, parcourir le tableau triangle et afficher chaque ligne.
	Fin de l'algorithme.
	*/
	int tailleTriangle = 0;

	cout << "Entrez la taille du triangle d'etoiles : ";
	cin >> tailleTriangle;

	while (tailleTriangle <= 0) {
		cout << "\x1B[31mEntrez un nombre positif superieur a 0.\033[0m" << endl;
		cin >> tailleTriangle;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	vector<char*> triangle(tailleTriangle);

	for (int i = 0; i < tailleTriangle; ++i) {
		triangle[i] = new char[i + 2];
		triangle[i][0] = '\0';
		for (int j = 0; j <= i; ++j) {
			strncat_s(triangle[i], i + 2, "*", 1);
		}
	}
	for (const auto& ligne : triangle) {
		cout << ligne << endl;
		delete[] ligne;
	}
}

void supplement4() {
	int tailleTriangle = 0;
	char typeTriangle, modeRempli;
	cout << "Entrez la taille du triangle d'etoiles : ";
	cin >> tailleTriangle;

	while (tailleTriangle <= 0) {
		cout << "\x1B[31mEntrez un nombre positif superieur a 0.\033[0m" << endl;
		cin >> tailleTriangle;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << "Choisissez le type de triangle (r pour rectangle, i pour isocele) : ";
	cin >> typeTriangle;
	cout << "Choisissez le mode de remplissage (r pour rempli, v pour vide) : ";
	cin >> modeRempli;

	bool rempli = (modeRempli == 'r');
	if (typeTriangle == 'r') {
		for (int i = 1; i <= tailleTriangle; ++i) {
			if (rempli) {
				cout << string(i, '*') << endl;
			}
			else {
				cout << "*";
				if (i > 1) {
					cout << string(i - 2, ' ') << "*";
				}
				cout << endl;
			}
		}
	}
	else if (typeTriangle == 'i') {
		for (int i = 0; i < tailleTriangle; ++i) {
			if (rempli) {
				cout << string(tailleTriangle - i - 1, ' ')
					<< string(2 * i + 1, '*') << endl;
			}
			else {
				cout << string(tailleTriangle - i - 1, ' ') << "*";
				if (i > 0) {
					cout << string(2 * i - 1, ' ') << "*";
				}
				cout << endl;
			}
		}
	}
	else {
		cout << "Type de triangle non reconnu." << endl;
	}
}

void main() {
	/* Posibilité d'executer les exercices suivants : */
	// exercice5();
	// supplement2();
	// exercice6();
	// exercice7();
	// exercice8();
	// exercice9();
	supplement3();
	// exercice10_version1();
	// exercice10_version2();
	// supplement4();
}