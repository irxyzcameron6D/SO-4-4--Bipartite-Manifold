#include <iostream>
#include <iomanip>
#include <cmath>

// --- MICROSCOPIC CONSTANTS ---
const double K_E = 8.98755e9;          
const double M_ELECTRON = 9.109383e-31;
const double E_CHARGE = 1.602176e-19;  
const double R_BOHR = 5.29177e-11;     

class BipartiteMicroEngine {
private:
    double q_real;
    double m_imag;

public:
    BipartiteMicroEngine(double charge, double mass) {
        q_real = charge;
        m_imag = mass;
    }

    void simulateVelocitySweep(double beta) {
        // 1. Calculate Hyperbolic Rapidity (phi)
        // Capping beta slightly below 1 to simulate approaching the annihilation frame
        double safe_beta = (beta >= 1.0) ? 0.999999999 : beta; 
        double phi = std::atanh(safe_beta);

        // 2. The Trace Plane Restrictor Valve: sech^2(phi)
        double sech_phi = 1.0 / std::cosh(phi);
        double mass_coupling = sech_phi * sech_phi;

        // 3. Dynamic U(1) Phase Angle (Shear)
        double phase_angle = std::atan((m_imag * mass_coupling) / q_real);

        // Output the telemetry for this velocity frame
        std::cout << std::fixed << std::setprecision(6);
        std::cout << std::left << std::setw(12) << beta 
                  << std::setw(15) << phi 
                  << std::setw(20) << mass_coupling 
                  << std::scientific << phase_angle << "\n";
    }
};

int main() {
    std::cout << "=========================================================\n";
    std::cout << " SO(4,4) MICRO-ENGINE V2: RAPIDITY & PHASE SHEAR SWEEP   \n";
    std::cout << "=========================================================\n";
    std::cout << "Particle: Electron | Boundary: Coordinate Trace Plane\n\n";

    BipartiteMicroEngine engine(E_CHARGE, M_ELECTRON);

    std::cout << std::left << std::setw(12) << "Velocity(B)" 
              << std::setw(15) << "Rapidity(Phi)" 
              << std::setw(20) << "Mass Coupling" 
              << "Phase Angle (rad)\n";
    std::cout << "---------------------------------------------------------\n";

    // Sweep from Rest to the Annihilation Frame
    double test_velocities[] = {0.0, 0.5, 0.9, 0.99, 0.9999, 0.999999};
    
    for(double v : test_velocities) {
        engine.simulateVelocitySweep(v);
    }

    std::cout << "\n=========================================================\n";
    std::cout << "               EXECUTION COMPLETE                        \n";
    std::cout << "=========================================================\n";
    return 0;
}
