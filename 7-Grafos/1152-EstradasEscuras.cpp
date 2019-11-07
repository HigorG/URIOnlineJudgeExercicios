#include <iostream>
#include <algorithm> // Para usar sort()
#include <vector>

using namespace std;

int custoGlobal = 0;

class Aresta {
	   int vertice1, vertice2, peso;
	   
	   public:
	   	   Aresta(int v1, int v2, int p) {
				this->vertice1 = v1;
				this->vertice2 = v2;
				this->peso = p;
		   }
			
	   	   int getVertice1() {
			return vertice1;
		   }
		   
		   int getVertice2() {
				return vertice2;
		   }
			
		   int getPeso() {
				return peso;
		   }
		   
		   bool operator < (const Aresta& aresta2) const{
				return (peso < aresta2.peso);
		   }
};

class Grafo {
	int V;
	vector<Aresta> arestas;
	
	public:
		Grafo(int V) {
			this->V = V;
		}
		
		void adicionarAresta(int v1, int v2, int p) {
			Aresta aresta1(v1, v2, p);
			Aresta aresta2(v2, v1, p);
			
			arestas.push_back(aresta1);
			arestas.push_back(aresta2);
		}
		
		int metodoFind(int subset[], int i) {
			if(subset[i] == -1){
				return i;
			}else{
				return Grafo::metodoFind(subset, subset[i]);
			}
		}
		
		void metodoUnion(int subset[], int v1, int v2) {
			int setDeV1 = Grafo::metodoFind(subset, v1);
			int setDeV2 = Grafo::metodoFind(subset, v2);
			subset[setDeV1] = setDeV2;
		}

		void algoritmoDeKruskal() {
			vector<Aresta> arvore;
			int arestasSize = arestas.size();
			
			sort(arestas.begin(), arestas.end());
			int *subset = new int[V];
			
			for(int i = 0; i < V; i++){
				subset[i] = -1;
			}
			
			for(int i = 0; i < arestasSize; i++){
				int v1 = metodoFind(subset, arestas[i].getVertice1());
				int v2 = metodoFind(subset, arestas[i].getVertice2());
				
				if(v1 != v2){
					arvore.push_back(arestas[i]);
					metodoUnion(subset, v1, v2);
				}
			}
			
			imprimeMST(arvore);	
		}

		void imprimeMST(vector<Aresta> arvore) {
			int arvoreSize = arvore.size();
			
			for(int i = 0; i < arvoreSize; i++){
				char v1 = 'A' + arvore[i].getVertice1();
				char v2 = 'A' + arvore[i].getVertice2();
				
				custoGlobal += arvore[i].getPeso();
				cout << "[" << v1 << " <-> " << v2 << "] = " << arvore[i].getPeso() << endl;
			}
			cout << "Custo: " << custoGlobal << endl;
		}
};

int main(int argc, char** argv){
	int M, N;
	int X, Y, Z;
	
	cin >> M >> N;
	
	while((M != 0) && (N != 0)){
		Grafo grafo(M);
		for(int i = 0; i < N; i++){
			cin >> X >> Y >> Z;
		
			grafo.adicionarAresta(X, Y, Z);
		}
		grafo.algoritmoDeKruskal();
		cin >> M >> N;
	}
	
	return 0;
}