#include <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E;

public:
    // Default constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }
    
    // Constructor with components
    Electric_Field(double Ex, double Ey, double Ez) {
        E = new double[3]{Ex, Ey, Ez};
    }
    
    // Destructor
    ~Electric_Field() {
        delete[] E;
    }
    
    // Magnitude calculation
    double calculateMagnitude() {
        return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }
    
    // Inner product calculation
    double calculateInnerProduct() {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
    
    // Setters
    void setField(double Ex, double Ey, double Ez) {
        E[0] = Ex;
        E[1] = Ey;
        E[2] = Ez;
    }
    
    // Getters
    double getX() { return E[0]; }
    double getY() { return E[1]; }
    double getZ() { return E[2]; }
};

class Magnetic_Field {
private:
    double *B;

public:
    // Default constructor
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};
    }
    
    // Constructor with components
    Magnetic_Field(double Bx, double By, double Bz) {
        B = new double[3]{Bx, By, Bz};
    }
    
    // Destructor
    ~Magnetic_Field() {
        delete[] B;
    }
    
    // Magnitude calculation
    double calculateMagnitude() {
        return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }
    
    // Unit vector calculation
    void calculateUnitVector(double &ux, double &uy, double &uz) {
        double magnitude = calculateMagnitude();
        if (magnitude == 0) {
            ux = uy = uz = 0.0;
        } else {
            ux = B[0] / magnitude;
            uy = B[1] / magnitude;
            uz = B[2] / magnitude;
        }
    }
    
    // Setters
    void setField(double Bx, double By, double Bz) {
        B[0] = Bx;
        B[1] = By;
        B[2] = Bz;
    }
    
    // Getters
    double getX() { return B[0]; }
    double getY() { return B[1]; }
    double getZ() { return B[2]; }
};

int main() {
    // Create electric field objects
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    
    // Set new values
    E_default.setField(3.0, 4.0, 12.0);
    
    // Output magnitudes and inner product
    std::cout << "Electric Field Magnitude (E_default): " << E_default.calculateMagnitude() << std::endl;
    std::cout << "Electric Field Magnitude (E_components): " << E_components.calculateMagnitude() << std::endl;
    std::cout << "Electric Field Inner Product: " << E_components.calculateInnerProduct() << std::endl;
    
    // Create magnetic field objects
    Magnetic_Field B_default;
    Magnetic_Field B_components(0.5, 1.5, 2.5);
    
    // Set new values
    B_default.setField(1.0, 1.0, 1.0);
    
    // Output magnitudes
    std::cout << "Magnetic Field Magnitude (B_default): " << B_default.calculateMagnitude() << std::endl;
    std::cout << "Magnetic Field Magnitude (B_components): " << B_components.calculateMagnitude() << std::endl;
    
    // Calculate and output unit vector of magnetic field
    double ux, uy, uz;
    B_components.calculateUnitVector(ux, uy, uz);
    std::cout << "Magnetic Field Unit Vector: (" << ux << ", " << uy << ", " << uz << ")" << std::endl;
    
    return 0;
}

