#include <iostream>
#include <string>

void print_matrix(double matrix[3][3]);
void mult_matrix(double matrixa[3][3], double matrixb[3][3], double matrixc[3][3]);

int main(){
    double matrix_a[3][3] = {{1,2,3},
                             {4,5,6},
                             {7,8,9}};
    double matrix_b[3][3] = {{}}
    double matrix_c[3][3];
    print_matrix(matrix_a);
    return 0;
}

void print_matrix(double matrix[3][3]){
    for (int idx_i=0; idx_i<3; idx_i++){
        for (int idx_j=0; idx_j<3; idx_j++){
            std::cout << std::to_string(matrix[idx_i][idx_j]) <<",";
        }
        std::cout<<"\n";
    }
}

void mult_matrix(double matrixa[3][3], double matrixb[3][3], double matrixc[3][3]){
    double accum;
    for (int idx_i=0; idx_i < 3; idx_i++) {
      for (int idx_j=0; idx_j < 3; idx_j++) {
         accum = 0;
         for (int idx_k=0; idx_k < 3; idx_k++) {
            accum +=  matrixa[idx_i][idx_k] * matrixb[idx_k][idx_j];
         }
         matrixc[idx_i][idx_j] = accum;
      }
   }
}