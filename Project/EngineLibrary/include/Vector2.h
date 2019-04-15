#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

// Vector2 performs vector operations with 2-dimensions
// The purpose of this class is primarily for 2D graphics
// applications.
struct Vector2{
    // Note: x,y,are a convention
    // x,y could be position, but also any 2-component value.
    double x,y;

    Vector2() = default;

    Vector2(double a, double b){
		this->x = a;
		this->y = b;
    }

    // Index operator, allowing us to access the individual
    // x,y,z components of our vector.
    double& operator[](int i){
      return ((&x)[i]);
    }

    // Index operator, allowing us to access the individual
    // x,y,z components of our vector.
    const double& operator[](int i) const{
        return ((&x)[i]);
    }

    // Multiplication Operator
    // Multiply vector by a uniform-scalar.
    Vector2& operator *=(double s){

		this->x = this->x * s;
		this->y = this->y * s;

        return (*this);
    }

    // Division Operator
    Vector2& operator /=(double s){

		this->x = this->x / s;
		this->y = this->y / s;

        return (*this);
    }

    // Addition operator
    Vector2& operator +=(const Vector2& v){

		this->x = this->x + v.x;
		this->y = this->y + v.y;

      return (*this);
    }

    // Subtraction operator
    Vector2& operator -=(const Vector2& v){

		this->x = this->x - v.x;
		this->y = this->y - v.y;

      return (*this);
    }

};

// Compute the dot product of a Vector2
inline double Dot(const Vector2& a, const Vector2& b){

	return (a.x * b.x + a.y * b.y);
}

// Multiplication of a vector by a scalar values
inline Vector2 operator *(const Vector2& v, double s){
  Vector2 vec;

  vec.x = v.x * s;
  vec.y = v.y * s;

  return vec;
}

// Division of a vector by a scalar value.
inline Vector2 operator /(const Vector2& v, double s){
  Vector2 vec;

  vec.x = v.x / s;
  vec.y = v.y / s;

  return vec;
}

// Negation of a vector
inline Vector2 operator -(const Vector2& v){
  Vector2 vec;

  vec.x = 0 - v.x;
  vec.y = 0 - v.y;

  return vec;
}

// Return the magnitude of a vector
inline double Magnitude(const Vector2& v){

	double mag = sqrt(pow(v.x, 2.0) + pow(v.y, 2.0));

  return mag;
}

// Add two vectors together
inline Vector2 operator +(const Vector2& a, const Vector2& b){
	Vector2 vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;

  return vec;
}

// Subtract two vectors
inline Vector2 operator -(const Vector2& a, const Vector2& b){
  Vector2 vec;

  vec.x = a.x - b.x;
  vec.y = a.y - b.y;

  return vec;
}

// Vector Projection
inline Vector2 Project(const Vector2& a, const Vector2& b){
  Vector2 vec;

  double dot = Dot(a, b);
  double sProject = dot / Magnitude(b);

  sProject = sProject / Magnitude(b);

  vec = b * sProject;

  return vec;
}

// Set a vectors magnitude to 1
// Note: This is NOT generating a normal vector
inline Vector2 Normalize(const Vector2& v){
  Vector2 vec;

  double mag = Magnitude(v);

  vec.x = v.x / mag;
  vec.y = v.y / mag;

  return vec;
}

#endif
