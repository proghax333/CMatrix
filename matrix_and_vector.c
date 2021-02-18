
/**
  * A simple linear algebra library.
  * The library contains basic functions and  
  *   operations which can be performed on vectors
  *   and matrices.
  * It includes operations like addition and
  *   multiplication of vectors and matrices.
  * It also provides functions for transposing the matrix
  *   , identity matrix of nxn dimension and for checking
  *   orthonormality of a matrix.
  */

#include <math.h>
#include "matrix_and_vector.h"

/****** VECTOR FUNCTIONS ******/
void set_vector(int vector_size, double V[vector_size], double s) {
  
  for(int i = 0; i < vector_size; ++i) {
    V[i] = s;
  }

}

void add_scalar_to_vector(int vector_size, double Vin[vector_size]
  , double Vout[vector_size], double s) {
  
  for(int i = 0; i < vector_size; ++i) {
    Vout[i] = Vin[i] + s;
  }
  
}

void mul_vector_by_scalar(int vector_size, double Vin[vector_size],
  double Vout[vector_size], double s) {
  
  for(int i = 0; i < vector_size; ++i) {
    Vout[i] = Vin[i] * s;
  }
  
}

double dot_product(int vector_size, double V1[vector_size],
  double V2[vector_size]) {
  
  double result = 0.0;
  for(int i = 0; i < vector_size; ++i) {
    result += V1[i] * V2[i];
  }
  
  return result;
}

double norm(int vector_size, double V[vector_size]) {
  return sqrt(dot_product(vector_size, V, V));
}

void add_vectors(int vector_size, double V1[vector_size],
  double V2[vector_size], double Vout[vector_size]) {
  
  for(int i = 0; i < vector_size; ++i) {
    Vout[i] = V1[i] + V2[i];
  }
  
}

/****** MATRIX FUNCTIONS ******/

void identity(int size, double M[size][size]) {
  
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      M[i][j] = 0;
    }
    M[i][i] = 1;
  }
  
}

void circulant(int n, double A[n][n], double V[n]) {
  
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      A[i][j] = V[(i + j) % n];
    }
  }
  
}

int matrices_equal(int rows, int cols, double A[rows][cols],
  double B[rows][cols]) {
  
  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if(A[i][j] != B[i][j]) {
        return 0;
      }
    }
  }
  
  return 1;
}

void add_matrices(int rows, int cols, double A[rows][cols],
  double B[rows][cols], double C[rows][cols]) {
  
  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  
}

double trace(int n, double A[n][n]) {
  double result = 0.0;
  
  for(int i = 0; i < n; ++i) {
    result += A[i][i];
  }
  
  return result;
}

void transpose(int n, int k, double A[n][k], double T[k][n]) {
  
  for(int i = 0; i < k; ++i) {
    for(int j = 0; j < n; ++j) {
      T[i][j] = A[j][i];
    }
  }
  
}

void matrix_multiply(int m, int n, int k, double A[m][n],
  double B[n][k], double C[m][k])
{
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < k; ++j) {
      C[i][j] = 0.0;
      
      for(int p = 0; p < n; ++p) {
        C[i][j] += A[i][p] * B[p][j];
      }
    }
  }
}

void matrix_vector_multiply(int n, int k, double A[n][k],
  double V[k], double Vout[k])
{
  for(int i = 0; i < n; ++i) {
    Vout[i] = 0.0;
    for(int j = 0; j < k; ++j) {
      Vout[i] += A[i][j] * V[j];
    }
  }
  
}

int test_orthonormal(int n, double A[n][n]) {
  double identity_matrix[n][n];
  identity(n, identity_matrix);
  
  double transpose_matrix[n][n];
  transpose(n, n, A, transpose_matrix);
  
  double product_matrix[n][n];
  matrix_multiply(n, n, n, A, transpose_matrix, product_matrix);
  
  return matrices_equal(n, n, product_matrix, identity_matrix);
}

