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

void cinta(vector<pair<int, int>>& vec){
  quickSort(vec,0,vec.size()-1);

  int res = 0;
  int j=vec.size();
  for(int i = 0; i<vec.size(); i++, j--){
    res+=(j*vec[i].second);
  }

  cout<<res<<endl;
}

int main() {

  vector<pair<int,int>> v;
  pair<int,int> p1 = make_pair(1,5);
  pair<int,int> p2 = make_pair(2,10);
  pair<int,int> p3 = make_pair(3,3);

  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);

  for(int i=0; i<v.size(); i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
  }

  cout<<"Cinta"<<endl;

  cinta(v);
}
