# SO(4,4) Bipartite Manifold: Dual-Suite Computational Model

This repository hosts a computational physics toy model testing the **SO(4,4) Bipartite Manifold** framework. This model replaces traditional de Broglie matter waves with complex energy waves, mapping electromagnetism (charge) to the real coordinate space (x_r) and gravity (mass) to the imaginary coordinate space (x_i). 

By replacing mathematical complex conjugates with a physical **coordinate trace plane**, this framework derives special relativity, Maxwell's equations, and galactic rotation curves purely from geometric boundary conditions and phase kinetics.

## 1. The Theoretical Framework

* **The Coordinate Trace Plane:** Rather than forcing imaginary components to cancel via standard complex conjugates, this model maps an active boundary plane separating the electromagnetic and gravitational manifolds.
* **Hyperbolic Rapidity (phi) & The Choke Point:** Relativistic limits are handled using rapidity. The mass-manifold coupling is governed by a velocity-dependent restrictor valve: sech^2(phi). 
* **Annihilation Frames (ds^2 = 0):** As v approaches c, the trace plane absolutely chokes off the mass manifold, physically forcing the spacetime interval to 0 and transitioning the entity fully into a self-sustaining electromagnetic wave (photon).

## 2. The Computational Engines

### Microscopic Engine (micro_engine.cpp)
Models the quantum baseline and electrodynamic phase shear.
* **Electrostatic Residual Bias:** Calculates the 10^-68 N base asymmetry at the Bohr radius.
* **U(1) Phase-Shear:** Proves that classical magnetic fields are not a separate force, but the geometric curl generated as the mass/charge manifolds shear apart during acceleration.

### Macroscopic Engine (engine.cpp)
Models galactic rotation curves and relativistic environments without Dark Matter.
* **Variable ISM Mass-Shells:** Calculates active gravitational mass based on V scales with D^3 expanding spheres of influence and 1/r^2 density decay from the galactic core.
* **Relativistic Decoupling:** Applies the sech^2(phi) restrictor valve to galactic scaling, demonstrating how active gravitational mass decouples in extreme velocity environments.

## 3. Compiling and Running Locally

To test the engines on your local machine, clone the repository and compile using standard C++11 (or higher).

**Run the Micro-Engine:**
g++ -std=c++11 micro_engine.cpp -o micro_engine
./micro_engine

**Run the Macro-Engine:**
g++ -std=c++11 engine.cpp -o engine
./engine
