#include <bits/stdc++.h>

using namespace std;

struct Matrix
{
  vector<vector<int>> base;

  int row() // number of rows in matrix
  {
    return base.size();
  }

  int col() // number of columns in matrix
  {
    return base[0].size();
  }

  // read Matrix from input
  Matrix() {}
  Matrix(int r, int c)
  {
    vector<vector<int>> cur(r, vector<int> (c));
    base = cur;
  }
  Matrix(vector<vector<int>> v)
  {
    base = v;
  }


  // define some operation
  auto & operator [] (int i)
  {
    return base[i];
  }
  const auto & operator [] (int i) const
  {
    return base[i];
  }

  Matrix identity(int n)  // build the identity matrix
  {
    Matrix res = Matrix(n, n);
    while(n--)
    {
      res[n][n] = 1;
    }
    return res;
  }

  Matrix operator * (Matrix &b) // A[n, m] * B[m, p] = C[n, p]
  {
    Matrix a = *this;
    Matrix c = Matrix(a.row(), b.col());
    for(int i = 0; i < a.row(); ++i)
      for(int j = 0; j < b.col(); ++j)
        for(int k = 0; k < a.col(); ++k)
          c[i][j] += a[i][k] * b[k][j];
    return c;
  }

  Matrix Pow(long long x) // Matrix Exponentiation
  {
    Matrix a = *this;
    Matrix res = identity(a.row());
    while(x > 0)
    {
      if(x & 1) res = res * a;
      a = a * a;
      x >>= 1;
    }
    return res;
  }
};

int main()
{
  cout << "\\\\\\\\\\\\\\\\\\\\" << '\n';
  Matrix a({
      {1, 2},
      {3, 4}
  });

  Matrix b(
  {
      {0, 10, 100},
      {1, 1, 10}
  });

  // Matrix multiplication
  Matrix c1 = a * b;
  for(vector<int> x : c1.base)
  {
    for(int y : x)
      cout << y << ' ';
    cout << '\n';
  }
  cout << "\\\\\\\\\\\\\\\\\\\\" << '\n';

  // Matrix exponentiation
  Matrix c2 = a.Pow(3);
  for(vector<int> x : c2.base)
  {
    for(int y : x)
      cout << y << ' ';
    cout << '\n';
  }
  cout << "\\\\\\\\\\\\\\\\\\\\" << '\n';

  // Identity Matrix
  Matrix c3 = a.identity(3);
  for(vector<int> x : c3.base)
  {
    for(int y : x)
      cout << y << ' ';
    cout << '\n';
  }
  cout << "\\\\\\\\\\\\\\\\\\\\" << '\n';

  return 0;
}
