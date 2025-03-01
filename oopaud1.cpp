#include <iostream>
#include <cstring>
using namespace std;
enum tip { POP, RAP, ROK };

class Pesna {
private:
    char *ime;
    int minuti;
    tip tipPesna;

public:
    Pesna(const char *ime = "", int minuti = 0, tip tipPesna = POP) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->minuti = minuti;
        this->tipPesna = tipPesna;
    }

    Pesna(const Pesna &p) {
        ime = new char[strlen(p.ime) + 1];
        strcpy(ime, p.ime);
        minuti = p.minuti;
        tipPesna = p.tipPesna;
    }

    Pesna &operator=(const Pesna &p) {
        if (this != &p) {
            delete[] ime;
            ime = new char[strlen(p.ime) + 1];
            strcpy(ime, p.ime);
            minuti = p.minuti;
            tipPesna = p.tipPesna;
        }
        return *this;
    }

    ~Pesna() {
        delete[] ime;
    }

    void pecati() const {
        cout << '"' << ime << "\"\-" << minuti << "min" << endl;
    }

    int getMinuti() const { return minuti; }
    tip getTip() const { return tipPesna; }
};

class CD {
private:
    Pesna pesni[10];
    int brojPesni;
    int maxMinuti;

public:
    CD(int maxMinuti = 0) {
        this->brojPesni = 0;
        this->maxMinuti = maxMinuti;
    }

    void dodadiPesna(const Pesna &p) {
        int vkupnoMinuti = 0;
        for (int i = 0; i < brojPesni; i++)
            vkupnoMinuti += pesni[i].getMinuti();

        if (brojPesni < 10 && (vkupnoMinuti + p.getMinuti() <= maxMinuti)) {
            pesni[brojPesni++] = p;
        }
    }

    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < brojPesni; i++) {
            if (pesni[i].getTip() == t) {
                pesni[i].pecati();
            }
        }
    }

    int getBroj() const { return brojPesni; }
    Pesna getPesna(int i) const { return pesni[i]; }
};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

return 0;
}