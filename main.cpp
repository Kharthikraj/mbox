#include "mbox.hpp"
using namespace mbox;
using namespace transform;
using namespace std;

int main() {
    // mat3x1 test;
    // float arr[3] = {1, 2, 3};
    // test.updateFromArray(arr);
    // test.printmat();
    // vec3 t1, t2, t3;
    // float ele[3] = {1, 1, 1};
    // float ele1[3] = {1, 1, 1};

    // t1.updateFromArray(ele);
    // t2.updateFromArray(ele1);

    // t3 = vec3::cross(t1, t2);
    // t3.printVec();

    // vec3 test(1.0f, 2.0f, 3.0f);
    // test.printVec();

    // vec2 test2(3, 7);
    // test2.printVec();

    // gpt generated

    // Test default constructor
    // mbox::vec<float, 3> v1;
    // v1.printVec();  // Output should be: 0 0 0

    // // Test constructor with a single value
    // mbox::vec<float, 3> v2(5.0);
    // v2.printVec();  // Output should be: 5 5 5

    // // Test constructor with multiple values
    // mbox::vec<float, 3> v3(1.0, 2.0, 3.0);
    // v3.printVec();  // Output should be: 1 2 3

    // // Test copy constructor
    // mbox::vec<float, 3> v4(v3);
    // v4.printVec();  // Output should be: 1 2 3

    // // Test updateFromArray
    // float arr[3] = {4.0, 5.0, 6.0};
    // v3.updateFromArray(arr);
    // v3.printVec();  // Output should be: 4 5 6

    // // Test updateElement
    // v3.updateElement(1, 10.0);
    // v3.printVec();  // Output should be: 4 10 6

    // // Test getElement
    // float element = v3.getElement(2);
    // std::cout << "Element at index 2: " << element << std::endl;  // Output should be: 6

    // // Test addVec
    // mbox::vec<float, 3> v5 = mbox::vec<float, 3>::addVec(v3, v2);
    // v5.printVec();  // Output should be: 9 20 12

    // // Test subVec
    // mbox::vec<float, 3> v6 = mbox::vec<float, 3>::subVec(v3, v2);
    // v6.printVec();  // Output should be: -1 5 -4

    // // Test dot product
    // float dotProduct = mbox::vec<float, 3>::dot(v3, v2);
    // std::cout << "Dot product: " << dotProduct << std::endl;  // Output should be: 124

    // // Test cross product (for vec3)
    // mbox::vec<float, 3> v7 = mbox::vec<float, 3>::cross(v3, v2);
    // v7.printVec();  // Output should be: -30 18 -5

    // // Test magnitude
    // float mag = v3.magnitude();
    // std::cout << "Magnitude: " << mag << std::endl;  // Output should be: 8.06226

    // // Test default constructor
    // mbox::mat<float, 3, 3> m1;
    // m1.printmat();  // Output should be a 3x3 matrix with all zeros

    // // Test constructor with a single value
    // mbox::mat<float, 3, 3> m2(2.0);
    // m2.printmat();  // Output should be a 3x3 matrix with all 2.0

    // // Test copy constructor
    // mbox::mat<float, 3, 3> m3(m2);
    // m3.printmat();  // Output should be a 3x3 matrix with all 2.0

    // // Test operator+
    // mbox::mat<float, 3, 3> m4 = m2 + m3;
    // m4.printmat();  // Output should be a 3x3 matrix with all 4.0

    // // Test operator-
    // mbox::mat<float, 3, 3> m5 = m2 - m3;
    // m5.printmat();  // Output should be a 3x3 matrix with all 0.0

    // // Test operator*
    // mbox::mat<float, 3, 3> m6 = m2 * 3.0;
    // m6.printmat();  // Output should be a 3x3 matrix with all 6.0

    // // Test operator* (matrix multiplication)
    // mbox::mat<float, 3, 2> m7(1.0);
    // mbox::mat<float, 2, 4> m8(2.0);
    // mbox::mat<float, 3, 4> m9 = m7 * m8;
    // m9.printmat();  // Output should be a 3x4 matrix with all 8.0

    // // Test transpose
    // m9.transpose();
    // m9.printmat();  // Output should be a transposed 4x3 matrix with all 8.0

    // // Test determinant
    // float det = m9.determinant();
    // std::cout << "Determinant: " << det << std::endl;  // Output should be 4096.0

    // // Test tovec
    // mbox::vec<float, 12> v10 = m9.tovec();
    // v10.printVec();  // Output should be a vector with elements from the transposed matrix

    // mbox::mat<float, 4, 4> mat1(1.0);
    // mbox::vec<float, 3> vec1(2.0, 3.0, 4.0);
    // mbox::mat<float, 4, 4> result1 = mbox::transform::translate(mat1, vec1);
    // result1.printmat();  // Output should be a translated matrix

    // // Test scale
    // mbox::mat<float, 4, 4> mat2(2.0);
    // mbox::vec<float, 3> vec2(0.5, 2.0, 1.5);
    // mbox::mat<float, 4, 4> result2 = mbox::transform::scale(mat2, vec2);
    // result2.printmat();  // Output should be a scaled matrix


    // // quat test
    // Quat test(1, 1,1,2);
    // test.printQuat();
    // Quat test1(test);
    // test.printQuat();
    // test1.printQuat();
    // Quat test2(5);
    // test2.printQuat();
    // test2 = test.conjugate();
    // test2.printQuat();

    // vec3 un(5, 3, 1);
    // vec3 un1;
    // un1 = un.unit();
    // un1.printVec();

    Quat test1(2, 3, 4, 1);
    Quat test2(2, 3, 4, 1);
    Quat test3(2, 3, 4, 1);
    Quat test = test1*test2*test3;

    Quat rot = Quat::createQuatFromEuler(90, 0, 0);

    test.printQuat();

    rot.printQuat();

    mat4 rotmat = mbox::transform::createRotation(rot);
    rotmat.printmat();

    return 0;
}

// template <typename T, int row, int column>
// T mat<T, row, column>::minor(int a, int b){

// }
// template <typename T, int row, int column>
// T mat<T, row, column>::cofactor(int a, int b){
    
// }

// template <typename T, int row, int column>
// T mat<T, row, column>::determinant() {
//     if (row == column) {
//         T tempResult = 0;
//         int i = 0;
//         mat<T, row-1, column-1> temp;
//         if (row == 2) {
//             T a = this->getElement(0, 0);
//             T c = this->getElement(1, 0);
//             T b = this->getElement(0, 1);
//             T d = this->getElement(1, 1);
//             tempResult = a * d - b * c;
//             return tempResult;
//         }
//         for (int j = 0; j < column; j++) {
//             temp = this->createMinor(i, j);
//             tempResult += pow(-1, i+j) * this->getElement(i, j) * temp.determinant<T, row-1, column-1>();
//         }
//         return tempResult;
//     }
//     std::cout << "operation cancelled\n";
//     return -1;
// }

