// #include "vec.hpp"

using namespace mbox;

template <typename T, int size>
template <typename... Args>
void vec<T, size>::pushVec(T arg, Args... args){
    vector[count] = arg;
    count++;
    pushVec(args...);
}

template <typename T, int size>
vec<T, size>::vec(const vec& other) : m(size) {
    createVector();
    for (int i = 0; i < m; i++) {
        vector[i] = other.vector[i];
    }
}

template <typename T, int size>
void vec<T, size>::createVector(){
    vector = new T[m];
    for(int i = 0; i<m; i++){
        vector[i] = 0;
    }
}

template <typename T, int size>
void vec<T, size>::createVector(T val){
    vector = new T[m];
    for(int i = 0; i<m; i++){
        vector[i] = val;
    }
}

template <typename T, int size>
void vec<T, size>::printVec(){
    for(int i = 0; i<m; i++){
        std::cout << vector[i] << "  ";
    }
    std::cout << std::endl;
}

template <typename T, int size>
void vec<T, size>::type(){
    std::cout << "vec" << size << std::endl;
}

template <typename T, int size>
void vec<T, size>::updateFromArray(T* arr){
    for(int i = 0; i<m; i++){
        vector[i] = arr[i];
    }
}

template <typename T, int size>
void vec<T, size>::updateElement(int index, T val){
    vector[index] = val;
}

template <typename T, int size>
vec<T, size> vec<T, size>::addVec(const vec& vec1, const vec& vec2){
    vec<T, size> temp;
    for(int i = 0; i<size; i++){
        temp.vector[i] = vec1.vector[i] + vec2.vector[i];
    }
    return temp;
}

template <typename T, int size>
vec<T, size> vec<T, size>::subVec(const vec& vec1, const vec& vec2){
    vec<T, size> temp;
    for(int i = 0; i<size; i++){
        temp.vector[i] = vec1.vector[i] - vec2.vector[i];
    }
    return temp;
}

template <typename T, int size>
vec<T, size> vec<T, size>::unit(){
    vec<T, size> temp;
    float mag = this->magnitude();
    for(int i = 0; i<size; i++){
        temp.vector[i] = this->vector[i] / mag;
    }
    return temp;
}

template <typename T, int size>
vec<T, size>& vec<T, size>::operator=(const vec& other){
    for(int i = 0; i<m; i++){
        this->vector[i] = other.vector[i];
    }
    return *this;
}

template <typename T, int size>
float vec<T, size>::dot(const vec& vec1, const vec& vec2){
    float temp = 0;
    for(int i = 0; i<size; i++){
        temp += vec1.vector[i] * vec2.vector[i];
    }
    return temp;
}

template <typename T, int size>
vec<T, size> vec<T, size>::cross(const vec& vec1, const vec& vec2){
    mat<T, 3, size> temp;
    vec<T, size> tempVec;
    for(int j = 0; j<size; j++){
        temp.updateElement(1, j, vec1.getElement(j));
        temp.updateElement(2, j, vec2.getElement(j));
    }
    for(int j = 0; j<size; j++){
        tempVec.updateElement(j, temp.cofactor(0, j));
    }
    return tempVec;
}

template <typename T, int size>
float vec<T, size>::magnitude(){
    float temp = 0;
    for(int i =0; i<m; i++){
        temp += pow(vector[i], 2);
    }
    return sqrt(temp);
}

template <typename T, int size>
template <int row, int column>
mat<T, row, column> vec<T, size>::tomat(){
    mat<T, row, column> temp;
    for(int i =0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(this->getSize() > (i+j)){
                temp.updateElement(i, j, this->get(i+j));
            }else{
                temp.updateElement(i, j, 0);
            }
        }
    }
    return temp;
}

template <typename T, int size>
vec<T, size>::~vec(){
    delete[] vector;
}

