#include <iostream>
#include<vector>




using namespace std;

class Point {
private:
	int x;
	int y;
	int z;

public:
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}

	int getZ() {
		return this->z;
	}

	int setX(int x) {
		this->x = x;
		return this->x;
	}

	int setY(int y) {
		this->y = y;
		return this->y;
	}

	int setZ(int z) {
		this->z = z;
		return this->z;
	}

	void setXYZ(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};


class Cone {
private:
	Point centerPoint;
	Point vortexPoint;
	int radius;
	double generatrix;

public:
	Cone(int botX, int botY, int botZ, int topX, int topY, int topZ, int radius) {
		this->centerPoint.setXYZ(botX, botY, botZ);
		this->vortexPoint.setXYZ(topX, topY, topZ);
		this->radius = radius;
		int squareH = ((topY - botY) * (topY - botY));
		int squareR = (radius * radius);
		this->generatrix = sqrt(squareH + squareR);
	}

	Cone(){
	}

	Point getCenter() {
		return this->centerPoint;
	}

	Point getVortexPoint() {
		return this->vortexPoint;
	}

	int getRadius() {
		return this->radius;
	}

	double getGeneratrix() {
		return this->generatrix;
	}

	void printCone() {
		cout << "Center point (" << this->centerPoint.getX() << "," << this->centerPoint.getY() << "," << this->centerPoint.getZ() << ")\n";
		cout << "Vortex point (" << this->vortexPoint.getX() << "," << this->vortexPoint.getY() << "," << this->vortexPoint.getZ() << ")\n";
		cout << "Radius " << this->getRadius() << "\n";
		cout << "Generatrix " << this->getGeneratrix() << "\n";
	}
};

vector<Cone> getConesListFromConcole();
void printListOfCones(vector<Cone> list);
void printSpecificCone(vector<Cone> list);