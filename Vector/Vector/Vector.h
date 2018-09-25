#ifndef VECTOR_H
#define VECTOR_H

template <class VARIABLE>
class vec3
{
private:
	VARIABLE x, y, z;
public:
	vec3() {};
	vec3(const VARIABLE& x, const VARIABLE& y, const VARIABLE& z):x(x),y(y),z(z){};
	vec3(const vec3&  vec) :x(vec.x), y(vec.y), z(vec.z){};
	vec3 operator+(const vec3& vec) const
	{
		return vec3(x + vec.x, y + vec.y, z + vec.z);
	}
	vec3 operator-(const vec3& vec) const
	{
		return vec3(x - vec.x, y - vec.y, z - vec.z);
	}
	vec3 operator+=(const vec3& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
		return *this;
	}
	vec3 operator-=(const vec3& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
		return *this;
	}
	bool operator==(const vec3& v) const
	{
		return (this->x == v.x &&this->y == v.y &&this->z == v.z);
	}
	void zero()
	{
		this->x = this->y = this->z = 0.00f;
		
	}
	bool is_zero() const
	{
		return (this->x == 0 && this->y == 0 && this->z == 0);
	}
	void normalize()
	{
		VARIABLE aux = sqrt(this->x*this->x +this->y * this->y + this->y * this->y);
		if (aux != 0) {
			this->x /= aux;
			this->y /= aux;
			this->z /= aux;
		}
	}
	VARIABLE DistanceTo(const vec3& vec)const {
		return sqrt((x - vec.x) * (x - vec.x) + ((y - vec.y) * (y - vec.y)) + ((z - vec.z) * (z - vec.z)));
	}
	VARIABLE distance_squared_to(const vec3 &vector)const {
		return ((x - vector.x) * (x - vector.x) + ((y - vector.y) * (y - vector.y)) + ((z - vector.z) * (z - vector.z)));
	}
};


#endif
