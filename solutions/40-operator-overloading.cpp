/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    vector<vector<int>> data; // 'a' renamed to 'data'
    int rows;
    int cols;

public:
    // Default constructor
    Matrix() : rows(0), cols(0) {}

    // Constructor with size
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0));
    }

    // Getter for rows
    int get_rows() const {
        return rows;
    }

    // Getter for columns
    int get_cols() const {
        return cols;
    }

    // Method to add a new row to the matrix
    void add_row(const vector<int>& row) {
        if (row.size() != static_cast<size_t>(cols)) {
            cerr << "Row size (" << row.size() << ") does not match matrix columns (" << cols << ")." << endl;
            throw invalid_argument("Row size does not match matrix columns.");
        }
        data.push_back(row);
        ++rows;
    }


    // Overloading addition operator (+)
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions do not match.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Overloading output operator (<<)
    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            bool hasValue = false; // Flag to check if there's any value in the row
            for (int j = 0; j < matrix.cols; ++j) {
                if (matrix.data[i][j] != 0) {
                    hasValue = true;
                    break;
                }
            }
            // Print the row only if it has at least one value
            if (hasValue) {
                for (int j = 0; j < matrix.cols; ++j) {
                    if (matrix.data[i][j] != 0) {
                        os << matrix.data[i][j] << " ";
                    }
                }
                os << endl;
            }
        }
        return os;
    }
};

int main () {
   int cases, k;
   cin >> cases;
   for(k = 0; k < cases; k++) {
      int n, m, i, j;
      cin >> n >> m;

      // Initialize matrices with specified number of rows and columns
      Matrix x(n, m);
      Matrix y(n, m);
      Matrix result(n, m); // Initialize result matrix with the same dimensions as input matrices

      try {
         // Read input data for matrix x
         for(i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for(j = 0; j < m; j++) {
               cin >> num;
               b.push_back(num);
            }
            x.add_row(b);
         }

         // Read input data for matrix y
         for(i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for(j = 0; j < m; j++) {
               cin >> num;
               b.push_back(num);
            }
            y.add_row(b);
         }

         // Perform matrix addition
         result = x + y;
         cout << result;
      } catch(const std::invalid_argument& e) {
         cerr << "Error: " << e.what() << endl;
      }
   }  
   return 0;
}
