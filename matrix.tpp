// #include "matrix.hpp"
using namespace mbox;

template <typename T, int row, int column>
mat<T, row, column>::mat(const mat& other): m(other.m), n(other.n){
    createMatrix();
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

template <typename T, int row, int column>
mat<T, row, column>& mat<T, row, column>::operator=(const mat& other){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}


template <typename T, int row, int column>
void mat<T, row, column>::createMatrix(){
    matrix = new T*[m];
    for(int i = 0; i<m; i++){
        matrix[i] = new T[n];
        for(int j = 0; j<n; j++){
            matrix[i][j] = 0;
        }
    }
}

template <typename T, int row, int column>
void mat<T, row, column>::createIdentity(){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}

template <typename T, int row, int column>
void mat<T, row, column>::createIdentity(T val){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == j)
                matrix[i][j] = val;
            else
                matrix[i][j] = 0;
        }
    }
}

template <typename T, int row, int column>
void mat<T, row, column>::transpose(){
    T temp[row][column];
    cpyMatToArr(temp);

    if(row != column){
        m = column;
        n = row;
        createMatrix();
    }

    for(int i = 0; i<column; i++){
        for(int j = 0; j<row; j++){
            matrix[i][j] = temp[j][i];
        }
    }
}

template <typename T, int row, int column>
T mat<T, row, column>::minor(int a, int b){
    T res = createMinor(a, b).determinant();
    return res;
}

template <typename T, int row, int column>
T mat<T, row, column>::cofactor(int a, int b){
    T res = minor(a, b);
    return pow(-1, a+b)*res;
}

// template <typename T, int row, int column>
// T mat<T, row, column>::determinant() const {
//     if(row <= 0 || column <= 0){
//         std::cout << "operation failed" << std::endl;
//         return -1;
//     }
//     if(row == column){
//         T det = 0;

//         if (row == 1 && column == 1) {
//             // Base case: for a 1x1 matrix, determinant is the only element
//             det = matrix[0][0];
//         } else if (row == 2 && column == 2) {
//             // Base case: for a 2x2 matrix, use the formula ad - bc
//             det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
//         } else {
//             // Recursive case: use Laplace expansion along the first row
//             for (int j = 0; j < column; ++j) {
//                 // Calculate the cofactor for the current element
//                 T cofactor = createMinor(0, j).determinant();

//                 // Add or subtract based on the position
//                 det += (j % 2 == 0 ? 1 : -1) * matrix[0][j] * cofactor;
//             }
//         }

//         return det;
//     }
//     std::cout << "operation failed" << std::endl;
//     return -1;
// }

template <typename T, int row, int column>
T mat<T, row, column>::determinant() const {
    if(row == column){
        mat<T, row, column> temp(*this); 
        T det = 1;

        for (int i = 0; i < row; ++i) {
            int pivotRow = i;
            for (int j = i + 1; j < row; ++j) {
                if (std::abs(temp.matrix[j][i]) > std::abs(temp.matrix[pivotRow][i])) {
                    pivotRow = j;
                }
            }

            if (pivotRow != i) {
                for (int k = 0; k < column; ++k) {
                    std::swap(temp.matrix[i][k], temp.matrix[pivotRow][k]);
                }
                det *= -1; 
            }

            for (int j = i + 1; j < row; ++j) {
                T factor = temp.matrix[j][i] / temp.matrix[i][i];
                for (int k = i; k < column; ++k) {
                    temp.matrix[j][k] -= factor * temp.matrix[i][k];
                }
            }
            det *= temp.matrix[i][i];
        }

        return det;
    }
    std::cout << "operation failed" << std::endl;
    return -1;
}

template <typename T, int row, int column>
mat<T, row-1, column-1> mat<T, row, column>::createMinor(int a, int b)const{
    mat<T, row-1, column-1> temp;
    int row2 = row-1;
    int column2 = column -1;
    int tempi = 0;
    int tempj = 0;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(i == a || j == b){
                continue;
            }
            temp.updateElement(tempi, tempj, this->getElement(i, j));
            tempj++;
            if(tempj >= column2){
                tempj = 0;
                tempi++;
            }
        }
    }
    return temp;
}


template <typename T, int row, int column>
void mat<T, row, column>::cpyMatToArr(T cpy[row][column]){
    for(int i= 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cpy[i][j] = getElement(i, j);
        }
    }
}

template <typename T, int row, int column>
void mat<T, row, column>::updateFromArray(T* arr) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = arr[i * n + j];
        }
    }
}

template <typename T, int row, int column>
template <int size>
vec<T, size> mat<T, row, column>::tovec(){ 
    int count = 0;
    vec<T, size> result;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            result.updateElement(count, getElement(i, j));
            count++;
        }
    }
    return result;
}

template <typename T, int row, int column>
void mat<T, row, column>::printmat(){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

template <typename T, int row, int column>
mat<T, row, column> mat<T, row, column>::operator+(const mat& other) {
    mat<T, row, column> temp;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return temp;
}

template <typename T, int row, int column>
mat<T, row, column> mat<T, row, column>::operator-(const mat& other) {
    mat<T, row, column> temp;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return temp;
}

template <typename T, int row, int column>
template <typename U, int row2, int column2>
mat<T, row, column2> mat<T, row, column>::operator*(const mat<U, row2, column2>& other) {
    mat<T, row, column2> temp;
    if(column!=row2){
        return temp;
    }
    T tempElement;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column2; j++) { 
            tempElement = 0;
            for (int k = 0; k < row2; k++) {
                tempElement += matrix[i][k] * other.getElement(k, j);
            }
            temp.updateElement(i, j, tempElement);
        }
    }
    return temp;
}

template <typename T, int row, int column>
void mat<T, row, column>::mulnum(T val){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] *= val;
        }
    }
}

template <typename T, int row, int column>
void mat<T, row, column>::updateElement(int i, int j, T val){
    getElementMem(i, j) = val;
}

template <typename T, int row, int column>
mat<T, row, column>::~mat(){
    for(int i = 0; i<m; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}


