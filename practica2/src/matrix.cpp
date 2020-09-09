#include <iostream>
#include <string>

void print_matrix(double matrix[3][3]);
void mult_matrix(double matrixa[3][3], double matrixb[3][3], double matrixc[3][3]);
double determinante_matrix(double matrix[3][3]);

int main(){
    double det;
    double matrix_a[3][3];
    double matrix_b[3][3];
    double matrix_c[3][3];

    //Introduce matrix a
    std::cout <<"Introduce matrix A elements \n";
    for (int idx_i=0; idx_i<3; idx_i++){
        for (int idx_j=0; idx_j<3; idx_j++){
            std::cout << "Introduce element [" << std::to_string(idx_i)<<"][" <<std::to_string(idx_j)<<"]: ";
            std::cin >> matrix_a[idx_i][idx_j]; 
        }
    }
    //Introduce matrix b
    std::cout <<"Introduce matrix B elements \n";
    for (int idx_i=0; idx_i<3; idx_i++){
        for (int idx_j=0; idx_j<3; idx_j++){
            std::cout << "Introduce element [" << std::to_string(idx_i)<<"][" <<std::to_string(idx_j)<<"]: ";
            std::cin >> matrix_b[idx_i][idx_j]; 
        }
    }


    std::cout <<"Matrix A \n";
    print_matrix(matrix_a);
    std::cout <<"Matrix B \n";
    print_matrix(matrix_b);

    mult_matrix(matrix_a, matrix_b, matrix_c);
    std::cout <<"Result multiplication \n";
    print_matrix(matrix_c);

    det = determinante_matrix(matrix_c);
    std::cout << "Result determinant: " << std::to_string(det) <<"\n";

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

double determinante_matrix(double matrix[3][3]){
    double det=0;
    det = matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1]));
    det -= matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0]));
    det += matrix[0][2]*((matrix[1][0]*matrix[2][1])-(matrix[1][1]*matrix[2][0]));
    return det;
}