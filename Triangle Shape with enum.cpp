#include <iostream>
#include <string>

using namespace std;

// definition of enumeration
enum triangleType
{
	scalene, isosceles, equilateral, noTriangle
};

// function prototypes
void get_values(double&, double&, double&);
triangleType triangleShape(double, double, double);
void printResult(triangleType);

int main()
{
	double a, b, c;

	triangleType triangle;

	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-="
		<< "-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

	cout << "\t\tTRIANGLE SHAPE DETECTOR\n";
	cout << "__________________________"
		<< "__________________________\n\n";

	get_values(a, b, c);

	triangle = triangleShape(a, b, c);

	printResult(triangle);

	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-="
		<< "-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	return 0;
}

// function declarations

// This function promts user to enter the sides
// of the triangle and sets them to a, b, c
// variables declared in the main function
void get_values(double& a, double& b, double& c)
{
	cout << "  Enter the sides of the triangle: ";
	cout << "\n  !Note: In a triangle, the sum of the\n"
		<< "  of the lengths of any two sides is greater\n"
		<< "  than the length of the third side.\n\n";
	cout << "  >>> a: ";
	cin >> a;
	cout << "  >>> b: ";
	cin >> b;
	cout << "  >>> c: ";
	cin >> c;
}

// This function has a return type of enumeration 
// triangleType. The function chekcs if the given
// numbers can form any shape. If yes,  it checks
// which  shape it is.  Then the function returns
// the result enumerator.
triangleType triangleShape(double x, double y, double z)
{
	if ((x + y) > z && (x + z) > y
		&& (y + z) > x)
	{
		if (x != y && y != z && x != z)
		{
			return scalene;
		}
		else if (x == y && y == z)
		{
			return equilateral;
		}
		else if ((x == y) || (x == z) || (y == z))
		{
			return isosceles;
		}
	}
	else
	{
		return noTriangle;
	}
}

// As we cannot read or output the
// enumerators, we must use indirect
// to do so. This function takes the
// enumeration type variable as a 
// value parameter and checks its 
// value. The function prints the
// name of the enumerator.
void printResult(triangleType shape)
{
	if (shape == scalene)
	{
		cout << "  The numbers you entered form a "
			<< "SCALENE TRIANGLE.\n\n";
	}
	else if (shape == equilateral)
	{
		cout << "  The numbers you entered form an "
			<< "EQUILATERAL TRIANGLE.\n\n";
	}
	else if (shape == isosceles)
	{
		cout << "  The numbers you entered form an "
			<< "ISOSCELES TRIANGLE.\n\n";
	}
	else if (shape == noTriangle)
	{
		cout << "  The numbers you entered cannot "
			"form any triangle. \n  TRY AGAIN!\n\n";
	}
}



/*
a. Define an enumeration type, triangleType, that has the values
scalene, isosceles, equilateral, and noTriangle.
b. Write a function, triangleShape, that takes as parameters three numbers,
each of which represents the length of a side of the triangle. The
function should return the shape of the triangle. (Note: In a triangle, the sum
of the lengths of any two sides is greater than the length of the third side.)
c. Write a program that prompts the user to input the length of the sides of
a triangle and outputs the shape of the triangle.
*/