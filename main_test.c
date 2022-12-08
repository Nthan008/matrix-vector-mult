#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define LOWER 1
#define UPPER 5

#include "mylib/mylib.h"

void test_multiply_vector_matrix(int *Matrix, int *Vector, int N, int *vector_expected)
{
  int *vector_result = (int*)malloc(N * sizeof(int));

  if (vector_result == NULL)
  {
    printf("Malloc is failed!\n");
    return;
  }
  
  matVecMult(Matrix, Vector, vector_result, N);

  // Compare the result of the multiplication and the expected result

  int i;
  for (i = 0; i < N; i++)
  {
    printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, vector_result[i], i, vector_expected[i]);
    assert(vector_result[i] == vector_expected[i]);
  }
}

int main()
{
  int Total_test_cases = 3;
  int N = 2;

  int matrix_input_test_case[3][3] = {
    {4, 1, 2},
    {2, 4, 5},
    {1, 1, 3},
  };

  int vector_input_test_case[3][2] = {
    {0, 0},
    {1, 2},
    {4, 1},
  };

  int vector_expected_test_case[3][2] = {
    {0, 0},
    {10, 7},
    {5, 12},
  };


  int i;
  for (i = 0; i < Total_test_cases; i++)
  {
    printf("Test %d:\n", i + 1);
    test_multiply_vector_matrix(
      matrix_input_test_case[i],
      vector_input_test_case[i],
      N,
      vector_expected_test_case[i]
    );
    printf("\n");
  }

  return 0;
}
