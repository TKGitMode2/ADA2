#include <iostream>
#include <vector>

using namespace std;

void swap(pair<int, int>& a, pair<int, int>& b) {
  pair<int, int> temp = a;
  a = b;
  b = temp;
}

int partition(vector<pair<int, int>>& vec, int low, int high) {
  int pivot = vec[high].second; 
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
      if (vec[j].second < pivot) {
          i++;
          swap(vec[i], vec[j]);
      }
  }
  swap(vec[i + 1], vec[high]);
  return (i + 1);
}

void quickSort(vector<pair<int, int>>& vec, int low, int high) {
  if (low < high) {
      int pi = partition(vec, low, high);

      quickSort(vec, low, pi - 1);
      quickSort(vec, pi + 1, high);
  }
}

void seleccion(vector<pair<int,int>>& C) {
  quickSort(C,0,C.size()-1);     // ordenar según tiempo de finalización
  vector<pair<int,int>> s;

  s.push_back(C[0]);
  
  int i = 1;
  int prev = 0;
  
  while (i < C.size()) {         // ¿solución(S)?
    pair<int,int> x = C[i];                    // seleccionar x
    if (x.first >= s[prev].second){
      s.push_back(x); 
      ++prev;
    } // ¿factible(x)?
                  // añadir x a S
    i++;
  }

  for(int k = 0; k < s.size(); k++){
    cout << s[k].first << " " << s[k].second << endl;
  }
  
}

int main() { 
  vector<pair<int,int>> contenido;
  pair<int,int> p1 = make_pair(0,6);
  pair<int,int> p2 = make_pair(1,4);
  pair<int,int> p3 = make_pair(3,5);
  pair<int,int> p4 = make_pair(4,7);
  pair<int,int> p5 = make_pair(3,5);
  pair<int,int> p6 = make_pair(5,9);
  pair<int,int> p7 = make_pair(6,10);
  pair<int,int> p8 = make_pair(8,11);
  
  contenido.push_back(p1);
  contenido.push_back(p2);
  contenido.push_back(p3);
  contenido.push_back(p4);
  contenido.push_back(p5);
  contenido.push_back(p6);
  contenido.push_back(p7);
  contenido.push_back(p8);

  seleccion(contenido);
  
}
