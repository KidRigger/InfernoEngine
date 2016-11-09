
#ifndef _OBJECT_HPP
#define _OBJECT_HPP

class Object {

public:
	Object(float x, float y, float w, float h) {

		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;

	}
	virtual ~Object(void) { ; }
	virtual void Update(float delta_time) { ; }
	virtual void Draw(void) { ; }
	float GetX(void) { return this->x; }
	float GetY(void) { return this->y; }
	float GetW(void) { return this->w; }
	float GetH(void) { return this->h; }

protected:
	float x, y, w, h;
	
};

#endif 

