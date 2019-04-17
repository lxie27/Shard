#pragma once
#ifndef PY_SHAPE_H
#define PY_SHAPE_H

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif

#include "Vector2.h"
#include "Shape.h"
#include "Quad.h"
#include "Circle.h"
#include "Triangle.h"
#include "AABB.h"

#include <pybind11/pybind11.h>

namespace py = pybind11;

py::class<
//Trampoline for Shape's virtual calls

class PyShape : public Shape {
public:
	using Shape::Shape;

	void update() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Shape,
			update,
			);
	}

	Vector2 getForce() override {
		PYBIND11_OVERLOAD(
			Vector2,
			Shape,
			getForce,
			);
	}

	void setForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Shape,
			setForce,
			f
		);
	}

	void addForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Shape,
			addForce,
			f
		);
	}

	double getArea() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Shape,
			getArea,
			);
	}

	double getPerimeter() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Shape,
			getPerimeter,
			);
	}
	AABB getBB() override {
		PYBIND11_OVERLOAD_PURE(
			AABB,
			Shape,
			getBB,
			);
	}

	void setBB() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Shape,
			setBB,
			);
	}

	void render(SDL_Renderer* gRenderer) override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Shape,
			render,
			gRenderer
		);
	}
};

//Trampoline for Circle
class PyCircle : public Circle {
public:
	using Circle::Circle;

	void update() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Circle,
			update,
			);
	}

	Vector2 getForce() override {
		PYBIND11_OVERLOAD(
			Vector2,
			Circle,
			getForce,
			);
	}

	void setForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Circle,
			setForce,
			f
		);
	}

	void addForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Circle,
			addForce,
			f
		);
	}

	double getArea() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Circle,
			getArea,
			);
	}

	double getPerimeter() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Circle,
			getPerimeter,
			);
	}

	AABB getBB() override {
		PYBIND11_OVERLOAD_PURE(
			AABB,
			Circle,
			getBB,
			);
	}

	void setBB() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Circle,
			setBB,
			);
	}

	void render(SDL_Renderer* gRenderer) override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Circle,
			render,
			gRenderer
		);
	}

};

//Trampoline for Triangle
class PyTriangle : public Triangle {
public:
	using Triangle::Triangle;

	void update() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Triangle,
			update,
			);
	}

	Vector2 getForce() override {
		PYBIND11_OVERLOAD(
			Vector2,
			Triangle,
			getForce,
			);
	}

	void setForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Triangle,
			setForce,
			f
		);
	}

	void addForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Triangle,
			addForce,
			f
		);
	}

	double getArea() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Triangle,
			getArea,
			);
	}

	double getPerimeter() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Triangle,
			getPerimeter,
			);
	}

	AABB getBB() override {
		PYBIND11_OVERLOAD_PURE(
			AABB,
			Triangle,
			getBB,
			);
	}

	void setBB() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Triangle,
			setBB,
			);
	}

	void render(SDL_Renderer* gRenderer) override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Triangle,
			render,
			gRenderer
		);
	}

};

//Trampoline for Quad
class PyQuad : public Quad {
public:
	using Quad::Quad;

	void update() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Quad,
			update,
			);
	}

	Vector2 getForce() override {
		PYBIND11_OVERLOAD(
			Vector2,
			Quad,
			getForce,
			);
	}

	void setForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Quad,
			setForce,
			f
		);
	}

	void addForce(Vector2& f) override {
		PYBIND11_OVERLOAD(
			void,
			Quad,
			addForce,
			f
		);
	}

	double getArea() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Quad,
			getArea,
			);
	}

	double getPerimeter() override {
		PYBIND11_OVERLOAD_PURE(
			double,
			Quad,
			getPerimeter,
			);
	}

	AABB getBB() override {
		PYBIND11_OVERLOAD_PURE(
			AABB,
			Quad,
			getBB,
			);
	}

	void setBB() override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Quad,
			setBB,
			);
	}

	void render(SDL_Renderer* gRenderer) override {
		PYBIND11_OVERLOAD_PURE(
			void,
			Quad,
			render,
			gRenderer
		);
	}
};


#endif