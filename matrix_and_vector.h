#include <math.h> //For the sqrt() function


/****************************** VECTOR FUNCTIONS ******************************/

/* set_vector(vector_size, vector, s)
   Given a scalar value s, a vector to store the result and its size,
   set the elements of V at indices 0, 1, 2, ..., vector_size - 1
   to the provided value s. Do not set any other indices of the vector.

   Parameters: vector_size (integer), V (array of double), s (double)
   Return value: None
*/
void set_vector(int vector_size, double V[vector_size], double s);

/* add_scalar_to_vector(vector_size, Vin, Vout, s)
   Given an input vector Vin, an output vector Vout, a size and a scalar value s,
   set every element of Vout to be the corresponding element
   of Vin plus the value of s.
   Do not modify any elements of the input vector Vin.

   Parameters: vector_size (integer), Vin (array of double), Vout (array of double), s (double)
   Return value: None
*/
void add_scalar_to_vector(int vector_size, double Vin[vector_size], double Vout[vector_size], double s);

/* mul_vector_by_scalar(vector_size, Vin, Vout, s)
   Given an input vector Vin, an output vector Vout, a size and a scalar value s,
   set every element of Vout to be the corresponding element
   of Vin multiplied by the value of s.
   Do not modify any elements of the input vector V.

   Parameters: vector_size (integer), Vin (array of double), Vout (array of double), s (double)
   Return value: None
*/
void mul_vector_by_scalar(int vector_size, double Vin[vector_size], double Vout[vector_size], double s);

/* dot_product(vector_size, V1, V2)
   Given two vectors V1 and V2, along with their size (which is assumed
   to be the same for both input vectors), return the dot product of
   V1 and V2.
   Do not modify any elements of the input vectors V1 and V2.

   Parameters: vector_size (integer), V1 (array of double), V2 (array of double)
   Return value (double): Dot product of V1 and V2
*/
double dot_product(int vector_size, double V1[vector_size], double V2[vector_size]);

/* norm(vector_size, V)
   Given a vector V and its size, return the norm (length) of V.
   Recall that the length of a vector V is the square root
   of the dot product of V with itself.
   Do not modify any elements of the input vector V.

   Parameters: vector_size (integer), V (array of double)
   Return value (double): Norm (length) of the vector V
*/
double norm(int vector_size, double V[vector_size]);

/* add_vectors(vector_size, V1, V2, Vout)
   Given two input vectors V1 and V2, an output vector Vout, and a size,
   store the (elementwise) vector sum V1 + V2 into Vout. Do not set
   any indices beyond vector_size-1.
   Do not modify any elements of the input vectors V1 and V2.

   Parameters: vector_size (integer), V1 (array of double), V2 (array of double), Vout (array of double)
   Return value: None
*/
void add_vectors(int vector_size, double V1[vector_size], double V2[vector_size], double Vout[vector_size]);




/****************************** MATRIX FUNCTIONS ******************************/


/* identity(size, M)
   Given a square matrix M to store the result, set M to contain 
   the identity matrix of the specified size.
   By definition, the identity matrix is square (so the number of rows and
   the number of columns are equal).

   Parameters: size (integer), M (2d array of double)
   Return value: None
*/
void identity(int size, double M[size][size]);

/* circulant(n, A, V)
   Given an integer n, a n x n matrix A and an n-element vector V, 
   set A to contain the circulant matrix specified by V.

   The first row of the circulant matrix is a copy of V. Each subsequent 
   row is a copy of the previous row, shifted by one position to the left.

   For example, if V contains (1,2,3,4), the circulant matrix is 
     1 2 3 4
     2 3 4 1
     3 4 1 2
     4 1 2 3

   Parameters: n (integer), A (2d array of double), V (array of double)
   Return value: None
*/
void circulant(int n, double A[n][n], double V[n]);

/* matrices_equal(rows, cols, A, B)
   Given two input matrices A and B (both with the number of rows/columns provided),
   return 1 if they are equal and 0 otherwise.

   (As a simplification, you may assume that two matrices are equal if their elements are
    exactly the same. In practice, matrices would normally be considered equal if elements
    were within some small tolerance value to account for things like rounding errors).

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double)
   Return value (integer):
     - Return 1 if the two matrices are equal (that is, if each element of A is equal to the corresponding element of B)
     - Return 0 otherwise 
*/
int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]);


/* add_matrices(rows, cols, A, B, C)
   Given two input matrices A and B (both with the number of rows/columns provided),
   set C to be the elementwise sum of A and B.
   Do not modify any elements of the input matrices A and B.

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double), C (2d array of double)
   Return value: None
*/
void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]);

/* trace(n, A)
   Given an integer n and a matrix A with n rows and n columns, compute the 
   trace of A.

   The trace of a matrix is the sum of the entries along the forward diagonal.
   For example, consider the matrix
          7 -1 -2 
     A =  6 10 17
          9 20 111
   the trace of A is 7 + 10 + 111 = 128

   Parameters: n (integer), A (2d array of double)
   Return value (double): The trace of A
*/
double trace(int n, double A[n][n]);

/* transpose(n, k, A, T)
   Given integers n and k, along with an n x k input matrix A
   and a k x n output matrix T, set T to be the transpose of A. 

   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double), T (2d array of double)
   Return value: None
*/
void transpose(int n, int k, double A[n][k], double T[k][n]);

/* matrix_vector_multiply(n, k, A, V, Vout)
   Given integers n and k, multiply the n x k matrix A by the k-element vector V, 
   producting an n-element vector Vout.

   Note that the product AV where A is an n x k matrix and V is a k-element vector 
   can be computed with the usual matrix multiplication algorithm by treating V 
   as a k x 1 matrix.

   Do not modify any elements of the input matrix A and B or the input vector V.

   Parameters: n (integer), k (integer), A (2d array of double), V (array of double), Vout (array of double)
   Return value: None
*/
void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]);

/* matrix_multiply(m, n, k, A, B, C)
   Given integers m, n and k, compute the matrix product C = A*B.
   The input matrix A will be m x n and the input matrix B will be n x k.
   The output matrix C will be m x k.
   
   Do not modify any elements of the input matrices A and B.
   
   For details on matrix multiplication, take a look at the video posted in the 
   Week 7 Part 2 lecture material, or take a look at 
   https://en.wikipedia.org/wiki/Matrix_multiplication

   Parameters: 
      m, n, k (all integers)
      A, B, C (all 2d arrays of double, note the different dimensions in the signature)
   Return value: None
*/
void matrix_multiply(int m, int n, int k, double A[m][n], double B[n][k], double C[m][k]);


/* test_orthonormal(n, A)
   Given an integer n and a matrix A with n rows and n columns, test whether A
   is an orthonormal matrix.

   The matrix A is orthonormal if the product of A and its transpose is 
   equal to the n x n identity matrix.

   Parameters: n (integer), A (2d array of double)
   Return value (integer):
    - Return 1 if A is orthonormal
    - Return 0 otherwise
*/
int test_orthonormal(int n, double A[n][n]);
