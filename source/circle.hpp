#ifndef CIRCLE_HPP
#define CIRCLE_HPP
class Circle
{
	public:
		Circle();
		Circle(float rad);

			void setradius(float r); //set Radius
			float getradius();       //get Radius

		bool operator< (Circle const& b);
		bool operator> (Circle const& b); //comparison		
		bool operator== (Circle const& b);

	private:
		float rad_;
};
#endif 
