// TRABALHO MATEMATICA DISCRETA
// GRUPO: ISABELE ROCHA, GUILHERME BOIKO, LUCAS PEREIRA E MATHEUS PEREIRA
// O seu programa inicialmente deverá ler a quantidade de elementos do conjunto A, 
// do conjunto B e do conjunto C. A seguir o programa deverá ler os elementos do
// conjunto A, os elementos do conjunto B e os elementos do conjunto C. O programa
// deverá calcular e exibir Ax(BuC) e calcular e exibir (AxB)u(AxC) provando que
// os resultados são iguais. Para facilitar considere que os 3 conjuntos terão
// apenas números inteiros positivos.

#include <iostream>
using namespace std;

int buscarElemento(int totalVetorvet2, int vetorvet2[], int vet3) {
  int achei = 0;
  for(int i=0;i < totalVetorvet2;i++){ 
    if (vetorvet2[i] == vet3) {
      achei++;
      i++;
    }
  }
  if (achei > 0) {
    return 1;
  } else {
    return 0;
  }
}
void produto(int vet1[], int tamvet1, int vet2[], int tamvet2, int vet3[], int tamvet3,int unirElementos[], int totalVetorvet2vet3) {
  int totalvet2vet3 = tamvet2 + tamvet3, vet4[tamvet2], vet5[tamvet1];
  int i = 0, j = 0;
  for (i = 0; i < tamvet2; i++) {
    vet4[i] = vet2[i];
  }
  for (j = 0; j < tamvet1; j++) {
    vet5[j] = vet1[j];
  }
  cout << "\nAx(BUC) -> {";
  for (i = 0; i < tamvet1; i++) {
    for (j = 0; j < totalVetorvet2vet3; j++) {
      cout << "(" << vet1[i] << "," << unirElementos[j] << ")";
    }
  }
  cout << "}";
  cout << "\nAxB -> {";
  for (i = 0; i < tamvet1; i++) {
    for (j = 0; j < tamvet2; j++) {
      cout << "(" << vet1[i] << "," << vet4[j] << ")";
    }
  }
  cout << "}";
  cout << "\nAxC -> {";
  for (i = 0; i < tamvet1; i++) { //"\nvet1xvet3 = {";
    for (j = 0; j < tamvet3; j++) {
      if (buscarElemento(tamvet3, vet2, vet3[j]) == 0 && vet3[j] != vet3[j - 1]) {
        cout << "(" << vet1[i] << "," << vet3[j] << ")";
      }
    }
  }
  cout << "}";
  cout << "\n(AxB)U(AxC) -> {";
  for (i = 0; i < tamvet1; i++) {
    for (j = 0; j < tamvet2; j++) {
      cout << "(" << vet1[i] << "," << vet2[j] << ")";
    }
  }
  for (i = 0; i < tamvet1; i++) { //"\nvet1xvet3 = {";
    for (j = 0; j < tamvet3; j++) {
      if (buscarElemento(tamvet3, vet2, vet3[j]) == 0 && vet3[j] != vet3[j - 1]) {
        cout << "(" << vet1[i] << "," << vet3[j] << ")";
      }
    }
  }
  cout << "}";
  cout << "\n";
}
void unirElementos(int vet1[], int tamvet1, int vet2[], int vet3[], int tamvet2, int tamvet3, int unirElementos[],
int totalVetorvet2vet3) {
  int k = 0, j = 0, i = 0, repetido = 0;
  for (j = 0; j < tamvet2; j++) {
    if (vet2[j] != vet2[j - 1]) {
      unirElementos[j] = vet2[j];
    } else {
      tamvet2--;
      totalVetorvet2vet3--;
    }
  }
  i = 0;
  for (j = 0; j < tamvet3; j++) {
    if (buscarElemento(tamvet2, vet2, vet3[j]) == 0 && vet3[j] != vet3[j - 1]) {
      unirElementos[i + tamvet2] = vet3[j];
      i++;
    } else {
      totalVetorvet2vet3--;
    }
  }
  cout << "BUC -> {";
  for (int j = 0; j < totalVetorvet2vet3; j++) {
    cout << unirElementos[j] << ",";
  }
  cout << "}";
  produto(vet1, tamvet1, vet2, tamvet2, vet3, tamvet3, unirElementos, totalVetorvet2vet3);
}

int main() {
  int tamvet1, tamvet2, tamvet3, totalVetorvet2vet3;
  cout << "Digite a quantidade de elementos do conjunto A -> ";
  cin >> tamvet1;
  int vet1[tamvet1];
  for (int j = 0; j < tamvet1; j++) {
    cout << "elemento " << j << " -> ";
    cin >> vet1[j];
  }
  cout << "\nDigite a quantidade de elementos do conjunto B -> ";
  cin >> tamvet2;
  int vet2[tamvet2];
  for (int i = 0; i < tamvet2; i++) {
    cout << "elemento " << i << " -> ";
    cin >> vet2[i];
  }
  cout << "\nDigite a quantidade de elementos do conjunto C -> ";
  cin >> tamvet3;
  int vet3[tamvet3];
  for (int k = 0; k < tamvet3; k++) {
    cout << "elemento " << k << " -> ";
    cin >> vet3[k];
  }
  cout << "\n";
  totalVetorvet2vet3 = tamvet2 + tamvet3;
  int unir[totalVetorvet2vet3];
  unirElementos(vet1, tamvet1, vet2, vet3, tamvet2, tamvet3, unir, totalVetorvet2vet3);

  cout << "\n";

  return 0;
}
