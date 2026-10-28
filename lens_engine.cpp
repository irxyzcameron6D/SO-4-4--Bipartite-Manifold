#include <iostream>
#include <iomanip>
#include <cmath>

// --- ASTRONOMICAL CONSTANTS ---
const double G = 6.67430e-11;               // Gravitational constant
const double C = 299792458.0;               // Speed of light (m/s)
const double M_SUN = 1.989e30;              // Solar mass (kg)
const double R_SUN = 6.957e8;               // Solar radius (m)
const double RAD_TO_ARCSEC = 206264.806;    // Conversion factor

class RefractiveGravityEngine {
private:
    double x_i_pressure_magnitude;

public:
    RefractiveGravityEngine(double mass) {
        x_i_pressure_magnitude = (2.0 * G * mass) / (C * C);
    }

    double computeRefractiveIndex(double r) {
        return 1.0 + (2.0 * x_i_pressure_magnitude) / r;
    }

    double computeDeflectionAngle(double impact_parameter) {
        double deflection_radians = (2.0 * x_i_pressure_magnitude) / impact_parameter;
        return deflection_radians * RAD_TO_ARCSEC;
    }
};

int main() {
    std::cout << "=========================================================\n";
    std::cout << " SO(4,4) LENS-ENGINE V1: REFRACTIVE TRACE PLANE GRAVITY  \n";
    std::cout << "=========================================================\n";
    std::cout << "Central Body: The Sun (1 Solar Mass)\n\n";
    
    RefractiveGravityEngine sun(M_SUN);

    std::cout << std::left << std::setw(20) << "Impact Distance" 
              << std::setw(20) << "Trace Plane n(r)" 
              << "Deflection (arcsec)\n";
    std::cout << "---------------------------------------------------------\n";

    double test_radii[] = {1.0 * R_SUN, 2.0 * R_SUN, 10.0 * R_SUN, 100.0 * R_SUN};
    std::string labels[] = {"1 Rsun (Grazing)", "2 Rsun", "10 Rsun", "100 Rsun"};

    for (int i = 0; i < 4; ++i) {
        double b = test_radii[i];
        double n = sun.computeRefractiveIndex(b);
        double angle = sun.computeDeflectionAngle(b);

        std::cout << std::fixed << std::setprecision(7);
        std::cout << std::left << std::setw(20) << labels[i] 
                  << std::setw(20) << n 
                  << angle << "\n";
    }

    std::cout << "\n=========================================================\n";
    std::cout << " * 1.75 arcsec matches the 1919 Eddington observation. \n";
    std::cout << "=========================================================\n";
    return 0;
}
