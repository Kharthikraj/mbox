#pragma once
#include <iostream>
#include <cmath>
#include "matrix.hpp"

namespace mbox{
    template <typename T, int size>
    class vec{
        private:
            T *vector;
            int m;
            int count = 0;

            void pushVec(T arg){
                vector[size-1] = arg;
            }

            template <typename... Args>
            void pushVec(T arg, Args... args);

        public:
            vec():m(size){createVector();}
            vec(T val): m(size){createVector(val);}
            vec(const vec& other);

            template <typename... Args>
            vec(T arg, Args... args): m(size){
                createVector();
                pushVec(arg, args...);
            }

            void createVector();
            void createVector(T val);

            void updateFromArray(T* arr);
            void updateElement(int index, T val);
            T getElement(int n)const{return vector[n];};

            void printVec();
            void type();
            int getSize(){return m;}

            static vec addVec(const vec& vec1, const vec& vec2);
            static vec subVec(const vec& vec1, const vec& vec2);
            static float dot(const vec& vec1, const vec& vec2);
            static vec cross(const vec& vec1, const vec& vec2);

            vec unit();

            vec& operator=(const vec& other);

            virtual float magnitude();

            template <int row, int column>
            mat<T, row, column> tomat();

            const T* val_ptr(){
                return vector;
            }

            ~vec();
    };
    typedef vec<float, 1> vec1;
    typedef vec<float, 2> vec2;
    typedef vec<float, 3> vec3;
    typedef vec<float, 4> vec4;

}

#include "vec.tpp"
