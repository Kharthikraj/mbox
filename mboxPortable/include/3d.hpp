#pragma once
#include "matrix.hpp"
#include "vec.hpp"
#include "cmath"

namespace mbox{
    namespace transform{
        template <typename T, int row, int column>
        static mat<T, row, column> translate(const mat<T, row, column>& mat, const vec<T, row-1>& vect, bool direction = false);

        template <typename T, int row, int column>
        static mat<T, row, column> scale(const mat<T, row, column>& mat, const vec<T, row-1>& vect, bool direction = false);

    }

    class Quat: private vec<float, 4>{      
        private:
            float x, y, z, w;

        protected:
            void updatetovec();
            void updatevals();     

        public:
            using vec<float, 4>::vec;

            void printQuat(){this->printVec();}

            Quat operator*(Quat& other);
            Quat& operator=(const Quat& other);

            Quat normalize();
            Quat conjugate();
            Quat inverse(){
                Quat temp = this->normalize();
                return temp.conjugate();
            }
            static Quat createQuatFromAxisAngle(vec3&, float);

            float scalar(){return this->getElement(3);};
            float magnitude()override{return vec<float, 4>::magnitude();};

            mat<float, 4, 4> createRotation();

            
    };
}

#include "3d.tpp"