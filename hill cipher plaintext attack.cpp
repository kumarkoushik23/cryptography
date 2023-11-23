#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3 

int modInv(int a, int m) {

}

void matMul(int A[N][N], int B[N][N], int C[N][N]) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = 0;
      for (int k = 0; k < N; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void encrypt(int* msg, int key[N][N]) {

  int cipher[N];
  
  for (int i = 0; i < N; i++) {
    cipher[i] = 0;
    for (int j = 0; j < N; j++) {
      cipher[i] += key[i][j] * msg[j];
    }
  }

  for (int i = 0; i < N; i++)
    cipher[i] %= 26;

  for (int i = 0; i < N; i++)  
    msg[i] = cipher[i];
}

void decrypt(int* cipher, int keyInv[N][N]) {

  int msg[N];

  for (int i = 0; i < N; i++) {
    msg[i] = 0;
    for (int j = 0; j < N; j++) {
      msg[i] += keyInv[i][j] * cipher[j];
    }
  }

  for (int i = 0; i < N; i++)
    msg[i] %= 26;

  for (int i = 0; i < N; i++)
    cipher[i] = msg[i];  
}

int main() {
	 int key[N][N] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};

  int det = key[0][0] * (key[1][1] * key[2][2] - key[2][1] * key[1][2]) - 
           key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
           key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

  int keyInv[N][N];
  int invDet = modInv(det, 26);
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      keyInv[i][j] = ((key[(j + 1) % N][(i + 1) % N] * invDet) % 26);
    }
  }
     
  return 0;
}
