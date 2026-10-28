#include <iostream>
#include <iomanip>
#include <cmath>

// --- MACROSCOPIC CONSTANTS ---
const double C = 299792458.0;                 // Speed of light (m/s)
const double G = 6.67430e-11;                 // Gravitational constant (N m^2/kg^2)
const double KPC_TO_M = 3.086e19;             // Kiloparsec to meters
const double CORE_ISM_DENSITY = 1.0e-21;      // kg/m^3 (Dynamic core density)

class BipartiteMacroEngine {
public:
    // Calculates mass of the spherical shell based on 1/r^2 density decay
    double computeShellMass(double radius_kpc) {
        double r_meters = radius_kpc * KPC_TO_M;
        // Density decays as 1/r^2 from the core
        double density = CORE_ISM_DENSITY / std::pow(radius_kpc, 2); 
        // V \[Proportional] D^3 (Spherical volume)
        double volume = (4.0 / 3.0) * M_PI * std::pow(r_meters, 3);
        return density * volume;
    }

    // Applies the SO(4,4) rapidity restrictor valve to the gravitational mass
    double computeEffectiveMass(double base_mass, double velocity_m_s) {
        double beta = velocity_m_s / C;
        double safe_beta = (beta >= 1.0) ? 0.999999999 : beta; 
        double phi = std::atanh(safe_beta);
        
        // sech^2(phi) choke point
        double mass_coupling = 1.0 / std::pow(std::cosh(phi), 2);
        
        return base_mass * mass_coupling;
    }
};

int main() {
    std::cout << "=========================================================\n";
    std::cout << " SO(4,4) MACRO-ENGINE V2: MASS-SHELLS & RAPIDITY VALVE   \n";
    std::cout << "=========================================================\n";
    
    BipartiteMacroEngine galaxy;

    std::cout << std::left << std::setw(10) << "R(kpc)" 
              << std::setw(12) << "Vel(km/s)" 
              << std::setw(20) << "Base Mass(kg)" 
              << std::setw(15) << "Coupling" 
              << "Effective Mass\n";
    std::cout << "----------------------------------------------------------------------\n";

    // Test Cases: 
    // 1-3: Standard Galactic Radii (Flat rotation curves ~220 km/s)
    // 4-5: Relativistic Core / Jet environments (v -> c)
    double test_radii[] = {5.0, 10.0, 20.0, 0.1, 0.01};
    double test_vels[]  = {220000, 220000, 220000, 1.5e8, 2.99e8}; 

    for (int i = 0; i < 5; ++i) {
        double r = test_radii[i];
        double v = test_vels[i];
        
        double base_mass = galaxy.computeShellMass(r);
        double eff_mass = galaxy.computeEffectiveMass(base_mass, v);
        
        // Reverse engineer the coupling percentage for display
        double coupling = eff_mass / base_mass;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left << std::setw(10) << r 
                  << std::setw(12) << v / 1000.0 
                  << std::scientific << std::setprecision(4)
                  << std::setw(20) << base_mass 
                  << std::fixed << std::setprecision(6)
                  << std::setw(15) << coupling 
                  << std::scientific << std::setprecision(4)
                  << eff_mass << "\n";
    }

    std::cout << "\n=========================================================\n";
    std::cout << "               EXECUTION COMPLETE                        \n";
    std::cout << "=========================================================\n";
    return 0;
}
