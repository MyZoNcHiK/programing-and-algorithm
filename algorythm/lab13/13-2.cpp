#include <iostream>
#include <cstring>
using namespace std;
void compPref(string &pat, int pref[]){
  int m = pat.length();
  pref[0] = 0;
  int j=0;
  
  for(int i=1; i < m; i++){
    while( j > 0 && pat[i] != pat[j]){
      j = pref[j-1];
    }
    if(pat[i]== pat[j]){
      j++;
    }
    pref[i] = j;
  }
}

void KMP(string &text, string &pat){
  int n = text.length();
  int m = pat.length();
  int *pref = new int[m];
  compPref(pat, pref);
  int j = 0;
  bool found = false;
  
  for(int i=0;i<n;i++){
    while(j > 0 && text[i] != pat[j]){
      j = pref[j-1];
    }
    if(text[i] == pat[j]){
      j++;
    }
    if(j==m){
      cout << "Found in:" << (i - m +1) << endl;
      found = true;
      j = pref[j-1];
    }
  }
  if(!found){
    cout << "Not found" << endl;
  }
  delete[] pref;
}
int main(){
    string text = "a black cat and two white cat", pat = "cat";
    KMP(text, pat);
    return 0;
}
