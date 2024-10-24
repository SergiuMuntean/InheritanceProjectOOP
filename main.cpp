#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class Persoana {
protected:
	char nume[30];
	char prenume[30];
public:
	Persoana() {}
	Persoana(const char* nume, const char* prenume) {
		strcpy(Persoana::nume, nume);
		strcpy(Persoana::prenume, prenume);
	}
	void afisare();
	char* getNume();
	char* getPrenume();
};

void Persoana::afisare() {
	cout << "Nume: " << nume << endl;
	cout << "Prenume: " << prenume << endl;
}

char* Persoana::getNume() {
	return nume;
}

char* Persoana::getPrenume() {
	return prenume;
}

class Student : public Persoana {
protected:
	int grade;
	char serie[30];
public:
	Student() {}
	Student(int grade, const char* serie, const char* nume, const char* prenume) : Persoana(nume, prenume) {
		Student::grade = grade;
		strcpy(Student::serie, serie);
	}
	void afisare();
};

void Student::afisare() {
	cout << "Nota: " << grade << endl;
	cout << "Serie: " << serie << endl;
}

class Angajat : public Persoana {
protected:
	float salariu;
	int vechime;
public:
	Angajat() {}
	Angajat(float salariu, int vechime, const char* nume, const char* prenume) : Persoana(nume, prenume) {
		Angajat::salariu = salariu;
		Angajat::vechime = vechime;
	}
	void afisare();
};

void Angajat::afisare() {
	cout << "Salariu: " << salariu << endl;
	cout << "Vechime: " << vechime << endl;
}

class StudentLicenta : public Student {
	char titluLicenta[30];
public:
	StudentLicenta() {}
	StudentLicenta(const char* nume, const char* prenume, int grade, const char* serie, const char* titluLicenta)
		: Student(grade, serie, nume, prenume) {
		strcpy(StudentLicenta::titluLicenta, titluLicenta);
	}
	void afisare();
};

void StudentLicenta::afisare() {
	Persoana::afisare();
	Student::afisare();
	cout << "Titlul licentei: " << titluLicenta << endl;
	cout << endl;
}

class StudentMaster : public Student {
	char titluDisertatie[30];
public:
	StudentMaster() {}
	StudentMaster(const char* nume, const char* prenume, int grade, const char* serie, const char* titluDisertatie)
		: Student(grade, serie, nume, prenume) {
		strcpy(StudentMaster::titluDisertatie, titluDisertatie);
	}
	void afisare();
};

void StudentMaster::afisare() {
	Persoana::afisare();
	Student::afisare();
	cout << "Titlul disertatiei: " << titluDisertatie << endl;
	cout << endl;
}

class StudentDoctorand : public Student {
	char titluTeza[30];
public:
	StudentDoctorand() {}
	StudentDoctorand(const char* nume, const char* prenume, int grade, const char* serie, const char* titluTeza)
		: Student(grade, serie, nume, prenume) {
		strcpy(StudentDoctorand::titluTeza, titluTeza);
	}
	void afisare();
};

void StudentDoctorand::afisare() {
	Persoana::afisare();
	Student::afisare();
	cout << "Titlul tezei de doctorat: " << titluTeza << endl;
	cout << endl;
}

class Profesor : public Angajat {
	int gradDidactic;
public:
	Profesor() {}
	Profesor(float salariu, int vechime, const char* nume, const char* prenume, int gradDidactic) 
	: Angajat(salariu, vechime, nume, prenume) {
		Profesor::gradDidactic = gradDidactic;
	}
	void afisare();
};

void Profesor::afisare() {
	Persoana::afisare();
	Angajat::afisare();
	cout << "Gradul didactic: " << gradDidactic << endl;
	cout << endl;
}

class Inginer : public Angajat {
	char postOcupat[30];
public:
	Inginer() {}
	Inginer(float salariu, int vechime, const char* nume, const char* prenume, const char* postOcupat)
	: Angajat(salariu, vechime, nume, prenume) {
		strcpy(Inginer::postOcupat, postOcupat);
	}
	void afisare();
};

void Inginer::afisare() {
	Persoana::afisare();
	Angajat::afisare();
	cout << "Postul ocupat: " << postOcupat << endl;
	cout << endl;
}

int main() {
	StudentLicenta licenta[10];
	StudentMaster master[10];
	StudentDoctorand doctorat[10];
	Profesor profesor[10];
	Inginer inginer[10];
	int nr1{ 0 }, nr2{ 0 }, nr3{ 0 }, nr4{ 0 }, nr5{ 0 };
	int opt;
	do {
		cout << "1 - Introduceti tipul de Persoana:(a - licenta, b - master, c - doctorat, d - profesor, e - inginer " << endl;
		cout << "2 - Afisati toate persoanele." << endl;
		cout << "3 - Cautati o persoana dupa nume." << endl;
		cout << "4 - Stergeti o persoana dupa nume." << endl;
		cout << "0 - Iesire" << endl;
		cout << "Dati optiunea: ";
		cin >> opt;
		getchar();
		switch (opt) {
			case 1: {
				cout << "Introduceti tipul de persoana:(a-e):" << endl;
				char subopt;
				cin >> subopt;
				getchar();
				switch (subopt) {
					case 'a': {
						cout << "Introduceti numarul de studenti de licenta: ";
						cin >> nr1;
						getchar();
						for (int i{ 0 }; i < nr1; i++) {
							char nume[30], prenume[30];
							int grade;
							char serie[30], titluLicenta[30];
							cout << "Introduceti numele: ";
							cin.getline(nume, 30);
							cout << "Introduceti prenumele: ";
							cin.getline(prenume, 30);
							cout << "Introduceti nota: ";
							cin >> grade;
							getchar();
							cout << "Introduceti seria: ";
							cin.getline(serie, 30);
							cout << "Introduceti titlul licentei: ";
							cin.getline(titluLicenta, 30);
							licenta[i] = StudentLicenta(nume, prenume, grade, serie, titluLicenta);
						}
						break;
					}
					case 'b': {
						cout << "Introduceti numarul de studenti de disertatie: ";
						cin >> nr2;
						getchar();
						for (int i{ 0 }; i < nr2; i++) {
							char nume[30], prenume[30];
							int grade;
							char serie[30], titluDisertatie[30];
							cout << "Introduceti numele: ";
							cin.getline(nume, 30);
							cout << "Introduceti prenumele: ";
							cin.getline(prenume, 30);
							cout << "Introduceti nota: ";
							cin >> grade;
							getchar();
							cout << "Introduceti seria: ";
							cin.getline(serie, 30);
							cout << "Introduceti titlul disertatiei: ";
							cin.getline(titluDisertatie, 30);
							master[i] = StudentMaster(nume, prenume, grade, serie, titluDisertatie);
						}
						break;
					}
					case 'c': {
						cout << "Introduceti numarul de studenti doctoranzi: ";
						cin >> nr3;
						getchar();
						for (int i{ 0 }; i < nr3; i++) {
							char nume[30], prenume[30];
							int grade;
							char serie[30], titluTeza[30];
							cout << "Introduceti numele: ";
							cin.getline(nume, 30);
							cout << "Introduceti prenumele: ";
							cin.getline(prenume, 30);
							cout << "Introduceti nota: ";
							cin >> grade;
							getchar();
							cout << "Introduceti seria: ";
							cin.getline(serie, 30);
							cout << "Introduceti titlul disertatiei: ";
							cin.getline(titluTeza, 30);
							doctorat[i] = StudentDoctorand(nume, prenume, grade, serie, titluTeza);
						}
						break;
					}
					case 'd': {
						cout << "Introduceti numarul de profesori: ";
						cin >> nr4;
						getchar();
						for (int i{ 0 }; i < nr4; i++) {
							float salariu; 
							char nume[30], prenume[30];
							int gradDidactic;
							cout << "Introduceti numele: ";
							cin.getline(nume, 30);
							cout << "Introduceti prenumele: ";
							cin.getline(prenume, 30);
							cout << "Introduceti salariul: ";
							cin >> salariu;
							getchar();
							cout << "Introduceti gradul didactic: ";
							cin >> gradDidactic;
							getchar();
							int vechime;
							cout << "Introduceti vechimea: ";
							cin >> vechime;
							getchar();
							profesor[i] = Profesor(salariu, vechime, nume, prenume, gradDidactic);
						}
						break;
					}
					case 'e': {
						cout << "Introduceti numarul de ingineri: " << endl;
						cin >> nr5;
						getchar();
						for (int i{ 0 }; i < nr5; i++) {
							float salariu;
							char nume[30], prenume[30];
							char postOcupat[30];
							cout << "Introduceti numele: ";
							cin.getline(nume, 30);
							cout << "Intrdocueti prenumele: ";
							cin.getline(prenume, 30);
							cout << "Introduceti salariul: ";
							cin >> salariu;
							getchar();
							cout << "Introduceti postul ocupat: ";
							cin.getline(postOcupat, 30);
							int vechime;
							cout << "Introduceti vechimea: ";
							cin >> vechime;
							getchar();
							inginer[i] = Inginer(salariu, vechime, nume, prenume, postOcupat);
						}
						break;
					}
					default: {
						cout << "Optiune gresita. Revenim la meniul principal." << endl;
						break;
					}
				}
				break;
			}
			case 2: {
				cout << endl;
				cout << "Persoanele existe sunt:" << endl;
				cout << "Studenti de licenta (" << nr1 << "): " << endl;
				for (int i{ 0 }; i < nr1; i++) {
					licenta[i].afisare();
				}
				cout << "Studenti de master (" << nr2 << "): " << endl;
				for (int i{ 0 }; i < nr2; i++) {
					master[i].afisare();
				}
				cout << "Studenti de doctorat (" << nr3 << "): " << endl;
				for (int i{ 0 }; i < nr3; i++) {
					doctorat[i].afisare();
				}
				cout << "Profesori (" << nr4 << "): " << endl;
				for (int i{ 0 }; i < nr4; i++) {
					profesor[i].afisare();
				}
				cout << "Ingineri (" << nr5 << "): " << endl;
				for (int i{ 0 }; i < nr5; i++) {
					inginer[i].afisare();
				}
				break;
			}
			case 3: {
				cout << "Introduceti numele persoanei de cautat: ";
				char nume[30];
				cin.getline(nume, 30);
				bool gasit = false;
				for (int i{ 0 }; i < nr1; i++) {
					if (strcmp(nume, licenta[i].getNume()) == 0 && !gasit) {
						gasit = true;
						cout << "Am gasit studentul de licenta cu numele: " << nume << endl;
						break;
					}
				}
				for (int i{ 0 }; i < nr2; i++) {
					if (strcmp(nume, master[i].getNume()) == 0 && !gasit) {
						gasit = true;
						cout << "Am gasit studentul de master cu numele: " << nume << endl;
						break;
					}
				}
				for (int i{ 0 }; i < nr3; i++) {
					if (strcmp(nume, doctorat[i].getNume()) == 0 && !gasit) {
						gasit = true;
						cout << "Am gasit studentul doctorand cu numele: " << nume << endl;
						break;
					}
				}
				for (int i{ 0 }; i < nr4; i++) {
					if (strcmp(nume, profesor[i].getNume()) == 0 && !gasit) {
						gasit = true;
						cout << "Am gasit profesorul cu numele: " << nume << endl;
						break;
					}
				}
				for (int i{ 0 }; i < nr5; i++) {
					if (strcmp(nume, inginer[i].getNume()) == 0 && !gasit) {
						gasit = true;
						cout << "Am gasit inginerul cu numele: " << nume << endl;
						break;
					}
				}
				if (!gasit) {
					cout << "Nu s-a gasit persoana cu numele: " << nume << endl;
				}
				break;
			}
			case 4: {
				cout << "Introduceti prenumele persoanei pe care doriti sa o stergeti: ";
				char prenume[30];
				cin.getline(prenume, 30);
				bool gasit = false;
				for (int i{ 0 }; i < nr1; i++) {
					if (strcmp(prenume, licenta[i].getPrenume()) == 0) {
						for (int j{ i }; j < nr1 - 1; j++) {
							licenta[j] = licenta[j + 1];
						}
						gasit = true;
						nr1--;
						break;
					}
				}
				for (int i{ 0 }; i < nr2; i++) {
					if (strcmp(prenume, master[i].getPrenume()) == 0 && !gasit) {
						for (int j{ i }; j < nr2 - 1; j++) {
							master[j] = master[j + 1];
						}
						gasit = true;
						nr2--;
						break;
					}
				}
				for (int i{ 0 }; i < nr3; i++) {
					if (strcmp(prenume, doctorat[i].getPrenume()) == 0 && !gasit) {
						for (int j{ i }; j < nr3 - 1; j++) {
							doctorat[j] = doctorat[j + 1];
						}
						gasit = true;
						nr3--;
						break;
					}
				}
				for (int i{ 0 }; i < nr4; i++) {
					if (strcmp(prenume, profesor[i].getPrenume()) == 0 && !gasit) {
						for (int j{ i }; j < nr4 - 1; j++) {
							profesor[j] = profesor[j + 1];
						}
						gasit = true;
						nr4--;
						break;
					}
				}
				for (int i{ 0 }; i < nr5; i++) {
					if (strcmp(prenume, inginer[i].getPrenume()) == 0 && !gasit) {
						for (int j{ i }; j < nr5 - 1; j++) {
							inginer[j] = inginer[j + 1];
						}
						gasit = true;
						nr5--;
						break;
					}
				}
				break;
			}
			case 0: {
				cout << "Iesire din program." << endl;
				return 0;
			}
			default: {
				cout << "Optiune gresita. Reintroduceti optiunea." << endl;
				break;
			}
		}
	} while (opt);
	system("pause");
	return 0;
}
