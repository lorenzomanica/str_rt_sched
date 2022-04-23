// tempo_de_resposta.cpp (Roland Teodorowitsch; 31/03/2022)

#include <iostream>

#define MAX_N 26

using namespace std;

class Tarefa {
private:
	int c;
	int p;
	int d;
	int r;
	char escalonavel;
public:
	Tarefa(int cp=0, int pp=0, int dp=0) {
		c = cp;
		p = pp;
		d = dp;
		r = -1;
		escalonavel = '?';
		#ifdef DEBUG
		cout << "+ Tarefa("<<c<<","<<p<<","<<d<<") criada..." << endl;
		#endif
	}
	~Tarefa() {
		#ifdef DEBUG
		cout << "- Tarefa("<<c<<","<<p<<","<<d<<") destruída..." << endl;
		#endif
	}
	int obtemC() { return c; }
	int obtemP() { return p; }
	int obtemD() { return d; }
	int obtemR() { return r; }
	char ehEscalonavel() { return escalonavel; }
	void defineC(int cp) { c = cp; }
	void defineP(int pp) { p = pp; }
	void defineD(int dp) { d = dp; }
	void defineR(int rp) { r = rp; }
	void defineEscalonavel(char e) { escalonavel = e; }
	friend ostream &operator<<(ostream &out, const Tarefa &t) {
		out << t.r << " " << t.escalonavel;
		return out;
	}
	friend istream &operator>>(istream &in, Tarefa &t) {
		in >> t.c;
		in >> t.p;
		in >> t.d;
		return in;
	}
};

int main() {
	unsigned n, t;

	Tarefa tarefas[MAX_N];
	while (1) {

		// LEITURA
		cin >> n >> t;
		if (n==0 || t==0)
			break;
		for (int i=0; i<n; ++i)
			cin >> tarefas[i];
			
		// PROCESSAMENTO
		// ...
		for (int i=0; i<n; ++i) { // PROVISORIAMENTE...
			tarefas[i].defineR(-1);
			tarefas[i].defineEscalonavel('N');
		}
		
		// ESCRITA
		for (int i=0; i<n; ++i)
			cout << tarefas[i] << endl;
		cout << endl;

	}
	return 0;
}

