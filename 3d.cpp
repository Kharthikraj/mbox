#include "3d.hpp"
using namespace mbox;
using namespace transform;

void mbox::Quat::updatevals(){
    x = getElement(0);
    y = getElement(1);
    z = getElement(2);
    w = getElement(3);
}

void mbox::Quat::updatetovec(){
    this->updateElement(0, x);
    this->updateElement(1, y);
    this->updateElement(2, z);
    this->updateElement(3, w);
}

mbox::Quat mbox::Quat::normalize(){
    Quat temp;
    vec4 tempvec = vec<float, 4>::unit();
    temp.x = tempvec.getElement(0);
    temp.y = tempvec.getElement(1);
    temp.z = tempvec.getElement(2);
    temp.w = tempvec.getElement(3);
    temp.updatetovec();
    return temp;
}

mbox::Quat mbox::Quat::conjugate(){
    updatevals();
    Quat temp;
    temp.x = -x;
    temp.y = -y;
    temp.z = -z;
    temp.w = w;
    temp.updatetovec();
    return temp;
}

mbox::Quat mbox::Quat::createQuatFromAxisAngle(vec3& vector, float angle){
    vec3 tempvec;
    tempvec = vector.unit();
    float sina = sin(angle/2);
    float cosa = cos(angle/2);

    Quat temp;
    temp.x = tempvec.getElement(0)*sina;
    temp.y = tempvec.getElement(1)*sina;
    temp.z = tempvec.getElement(2)*sina;
    temp.w = cosa;

    temp.updatetovec();

    return temp;
}

mbox::Quat mbox::Quat::createQuatFromEuler(float ax, float ay, float az, bool isDeg){
    vec3 vx(1, 0, 0);
    vec3 vy(0, 1, 0);
    vec3 vz(0, 0, 1);

    if(isDeg){
        ax = (M_PI/180)*(ax);
        ay = (M_PI/180)*(ay);
        az = (M_PI/180)*(az);
    }

    Quat qx = createQuatFromAxisAngle(vx, ax);
    Quat qy = createQuatFromAxisAngle(vy, ay);
    Quat qz = createQuatFromAxisAngle(vz, az);

    qx.printQuat();
    qy.printQuat();
    qz.printQuat();

    Quat temp = qx*qy*qz;

    temp.printQuat();

    if(temp.x < 0.03 || temp.y < 0.03 || temp.z < 0.03 || temp.w < 0.03)
        return temp.normalize();
    return temp;
}

mbox::Quat mbox::Quat::operator*(Quat& other){
    this->updatevals();
    other.updatevals();
    Quat temp;  
    temp.x = this->w*other.x + this->x*other.w + this->y*other.z - this->z*other.y;
    temp.y = this->w*other.y + this->y*other.w + this->z*other.x - this->x*other.z;
    temp.z = this->w*other.z + this->z*other.w + this->x*other.y - this->y*other.x;
    temp.w = this->w*other.w - this->x*other.x - this->y*other.y - this->z*other.z;

    temp.updatetovec();
    return temp;
}

mbox::Quat& mbox::Quat::operator=(const Quat& other){
    for(int i = 0; i<4; i++){
        this->updateElement(i, other.getElement(i));
    }
    return *this;
}

mbox::mat<float, 4, 4> mbox::transform::createRotation(Quat& obj){
    mbox::mat<float, 4, 4> temp;

    float x = obj.X();
    float y = obj.Y();
    float z= obj.Z();
    float w = obj.W();
    
    float xx = x*x;
    float xy = x*y;
    float xz = x*z;
    float xw = x*w;
    
    float yy = y*y;
    float yz = y*z;
    float yw = y*w;

    float zz = z*z;
    float zw = z*w;
    
    float m0 = 1-2*(yy + zz);
    float m1 = 2*(xy-zw);
    float m2 = 2*(xz+yw);
    
    float m4 = 2*(xy+zw);
    float m5 = 1-2*(xx + zz);
    float m6 = 2*(yz - xw);

    float m8 = 2*(xz - yw);
    float m9 = 2*(yz + xw);
    float m10 = 1-2*(xx + yy);

    float m15 = 1;

    float m3 = 0;
    float m7 = 0;
    float m11 = 0;
    float m12 = 0;
    float m13 = 0;
    float m14 = 0;

    temp.updateElement(0, 0, m0<0.01?0:m0);
    temp.updateElement(0, 1, m1);
    temp.updateElement(0, 2, m2);
    temp.updateElement(0, 3, m3);
    temp.updateElement(1, 0, m4);
    temp.updateElement(1, 1, m5<0.01?0:m5);
    temp.updateElement(1, 2, m6);
    temp.updateElement(1, 3, m7);
    temp.updateElement(2, 0, m8);
    temp.updateElement(2, 1, m9);
    temp.updateElement(2, 2, m10<0.01?0:m10);
    temp.updateElement(2, 3, m11);
    temp.updateElement(3, 0, m12);
    temp.updateElement(3, 1, m13);
    temp.updateElement(3, 2, m14);
    temp.updateElement(3, 3, m15);

    return temp;
}