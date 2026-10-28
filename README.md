SO44-Bipartite-Manifold
A C++ macroscopic engine implementing the $SO(4,4)$ bipartite metric framework. This project replaces standard dark matter and dark energy paradigms entirely through pure metric geometry.
Overview
The SO44-Bipartite-Manifold repository provides a high-performance numerical engine designed to simulate and verify cosmological and galactic phenomena without invoking dark matter particles or dark energy field parameters. By modeling spacetime via an $SO(4,4)$ bipartite symmetry structure, gravitational and cosmological effects emerge naturally from macroscopic geometric dynamics.
Execution Pipeline
Compile the core C++ simulation engine with optimization flags, execute the numerical routine while logging performance metrics, and parse the resulting dataset using the Python analysis suite:h
Compile the C++ engine with C++11 standard and high-level optimizations
g++ -std=c++11 -O3 engine.cpp -o engine
Execute simulation and pipe stdout to log file
./engine > simulation_output.log
Process and visualize output via the Python parser
python3 parse_results.py --input simulation_output.log


## Macroscopic Proofs


### Proof 1: Galactic Rotation Curves


Standard Newtonian and Einsteinian gravity predict a Keplerian decline ($v \propto r^{-1/2}$) in orbital velocities beyond the visible stellar disk. The $SO(4,4)$ framework resolves this through a variable-shell Interstellar Medium (ISM) integration ($10^{-23}\text{ kg/m}^3$) coupled with $D^3$ effective mass scaling. 


* **Variable-Shell Integration:** Integrates low-density gas across extended radial scales, revealing hidden baryonic contributions.


* **Effective Mass Scaling:** At kiloparsec scales, $D^3$ metric scaling flattens rotation curves natively, matching observed flat galactic velocity profiles.


* **Calibration:** Calibrating the metric pressure coupling constant $\kappa$ yields Newton's gravitational constant $G = 6.674 \times 10^{-11}\text{ m}^3\text{kg}^{-1}\text{s}^{-2}$ directly from geometric principles.


### Proof 2: Hyperspherical Boundary Cosmology


Rather than introducing a Cosmological Constant ($\lambda$) or vacuum dark energy to account for the accelerating expansion of the universe, the $SO(4,4)$ manifold introduces geometric boundary repulsion ($\omega_{\text{Boundary}}$).


* **Geometric Repulsion:** Replaces ad-hoc dark energy densities with a natural boundary condition operating on the hyperspherical manifold edge.


* **Unidirectional Causality:** Applying strict unidirectional causal propagation across the bipartite metric structure accurately reproduces the Type 1A supernova distance modulus ($\mu \text{ vs. } z$) curve without requiring dark energy parameters.


### Proof 3: The Bullet Cluster Anomaly & Matrix Decoupling


The Bullet Cluster (1E 0657-558) presents a classic spatial separation between baryonic gas (observed in X-rays) and the total gravitational mass center (observed via weak lensing). The $SO(4,4)$ manifold accounts for this separation through velocity-dependent matrix decoupling:


| Component | Governed By | Velocity Scaling Factor | Dynamic Effect |


| --- | --- | --- | --- |


| **Intergalactic Gas** | Electromagnetic Coupling ($C_{EM}$) | $1 - \beta^2$ | Stalls rapidly during high-velocity collision due to non-linear drag coupling. |


| **Collisionless Stars** | $M_4$ Spatial Components | $1 + \beta^2$ | Maintains forward velocity unhindered through the interaction region. |


As high-velocity collisions ($\beta = v/c$) occur, the gas component is decelerated via the suppressed $C_{EM}$ term ($1-\beta^2$), while the collisionless stellar cores and their associated gravitational signatures persist via the enhanced $M_4$ spatial metric scaling ($1+\beta^2$). This mechanism creates a geometric spatial offset for gravitational lensing without requiring collisionless dark matter particles.