#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

/// <summary>
/// Virtual Shape Class
/// </summary>
class Shape {
public:
	// virtual destructor
	virtual ~Shape() {}
	// virtual method to calculate area of shape
	virtual float area() = 0;
};

/// <summary>
/// Circle Class  
/// </summary>

/// <summary>
/// A class inheriting from Shape and representing the Circle
/// </summary>
class Circle : public Shape {
private:
	// private field needed to represent a specific shape 
	float radius;
public:

	/// <summary>
	/// public constructor without parameters, each field should default to zero
	/// </summary>
	/// <returns></returns>
	Circle() : radius(0){}

	/// <summary>
	/// public constructor that initializes class fields
	/// </summary>
	/// <returns></returns>
	Circle(float radius) { this->radius = radius; }

	/// <summary>
	/// public method of setting fields of the class
	/// </summary>
	/// <param name="r"> radius </param>
	void setRadius(double r) { radius = r; }

	/// <summary>
	/// public method of returning fields of the class
	/// </summary>
	/// <returns> radius </returns>
	float getRadius() { return radius; }

	/// <summary>
	/// the overloaded area method
	/// </summary>
	/// <returns> area of circle </returns>
	virtual float area(){ return M_PI * (radius * radius); }

	/// <summary>
	/// public operator that compares the field of the object
	/// </summary>
	/// <param name="other"> the other object of Circle type to compare with this object of Circle </param>
	/// <returns></returns>
	bool operator>= (Circle& other){ return this->area() >= other.area(); }

};

/// <summary>
/// A ShapeList class representing an array of objects
/// </summary>
class ShapeList : public Circle {
private:
	// private field of type pointer to the type of programmed class
	Circle* circleArray;

	// a private size field of type size_t representing the size of the array
	size_t tableSize;
public:

	/// <summary>
	/// public one-parameter constructor allocating dynamic memory (array) for a class pointer of the size given in the parameter
	/// </summary>
	/// <param name="s"> table size </param>
	/// <returns> table size </returns>
	ShapeList(size_t s)
	{
		// assign the tableSize with s
		tableSize = s;
		// allocating dynamic memory
		circleArray = new Circle[tableSize];
		// print in console the size of created array
		cout << "Size of the array is " << getTableSize() << endl;
	}

	/// <summary>
	/// a public method returning the size of the array 
	/// </summary>
	/// <returns> table size </returns>
	size_t getTableSize() { return tableSize; }

	/// <summary>
	/// public copy constructor 
	/// </summary>
	/// <param name="copy">object to copy</param>
	ShapeList(const ShapeList& copy) {
		std::cout << "Copy constructor" << std::endl;
		tableSize = copy.tableSize;
		circleArray = new Circle[tableSize];
		for (int i = 0; i < tableSize; i++) {
			circleArray[i] = copy.circleArray[i];
		}
	}

	/// <summary>
	/// public assignment operator (=)
	/// </summary>
	/// <param name="copy">object to assign with </param>
	/// <returns></returns>
	ShapeList& operator=(const ShapeList& copy) {
		if (this != &copy) {
			std::cout << "Overloaded assignment operator" << std::endl;
			delete[] circleArray;
			tableSize = copy.tableSize;
			circleArray = new Circle[tableSize];
			for (int i = 0; i < tableSize; i++) {
				circleArray[i] = copy.circleArray[i];
			}
		}
		else {
			std::cout << "Self-assignment error" << std::endl;
		}
		return *this;
	}

	// public destructor
	~ShapeList()
	{
		// delete the created array
		delete[] circleArray;
		cout << "Circle array deleted " << this << endl;
	}

	/// <summary>
	/// public operator [] returning a reference to an array element (an object of the type of the programmed class),
	/// if the index exceeds the range of the array, behavior should be undefined - don't handle this situation
	/// </summary>
	/// <param name="index"> index of object in array </param>
	/// <returns> object[i] that we need </returns>
	Circle& operator[](int index)
	{
		if (index >= tableSize) {
			cout << "Array index out of bound, exiting" << endl;
			exit(0);
		}
		else return circleArray[index];
	}

};

/// <summary>
/// Main function
/// </summary>
/// <returns></returns>
int main()
{
	// student card number
	int x = 18507;
	int option = x % 4;
	cout << "Student name - Kyrylo Pylinskyi" << endl << "Number of student card - " << x << endl << "Option = " << option << endl;

	cout << "--------------------------------------------------------" << endl;

	// main function where we will create an objects of the ShapeList type and
	// assign objects (more than 2) to an array stored by the object (using the [] operator)
	ShapeList l1(3);

	cout << "Setting values for Shape List 1" << endl;
	// loop will sets radius for every objects in array
	for (int i = 0; i < l1.getTableSize(); i++)
	{
		int value;
		cout << "Set radius for circle with index [" << i << "] -> ";
		cin >> value;
		l1[i].setRadius(value);
	}

	cout << "--------------------------------------------------------" << endl;

	cout << "Shape List 1 areas" << endl;
	// loop will show what we created
	for (int i = 0; i < l1.getTableSize(); i++)
	{
		cout << "Area of circle with index [" << i << "] is: " << l1[i].area() << endl;
	}

	cout << "--------------------------------------------------------" << endl;

	cout << "Setting values for Shape List 2" << endl;
	// creating second array list by copeing first array
	ShapeList l2 = l1;
	cout << "Shape List 2 copy values from Shape List 1" << endl;
	cout << "Shape List 2 areas" << endl;
	for (int i = 0; i < l2.getTableSize(); i++)
	{
		cout << "Area of circle with index [" << i << "] is: " << l2[i].area() << endl;
	}

	cout << "--------------------------------------------------------" << endl;

	size_t size;
	cout << "Set the size of new ShapeList array of Circles -> ";
	cin >> size;
	ShapeList l3(size);

	cout << "Setting values for Shape List 3" << endl;
	// Setting values for Shape List 3
	for (int i = 0; i < l3.getTableSize(); i++)
	{
		int value;
		cout << "Set radius for circle with index [" << i << "] -> ";
		cin >> value;
		l3[i].setRadius(value);
	}

	cout << "--------------------------------------------------------" << endl;

	cout << "Finding the maximum radius and area" << endl;
	
	// Creating the maximum elemnt of array
	Circle max = 0;
	
	// Check every object in array for maximum object
	for (int i = 1; i < l3.getTableSize(); i++)
	{
		// inverting the (>=) operator to get (<=) operator
		if (!(max >= l3[i]))
			max = l3[i];
	}

	cout << "Largest radius is: " << max.getRadius() << endl;
	cout << "Largest area is: " << max.area() << endl;

	return 0;
}

