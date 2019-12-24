# SGP4 Python wrapper
Simple library for Python that wrapps C++ implementation of the SGP4 algorithm

SGP4 C++ implementation (SGP4/ folder) get from the [Celestrak](https://celestrak.com/software/vallado-sw.php) site. For the details of the algorithm please refer to the book "Fundamentals of Astrodynamics and Applications" Fourth Edition by David Vallado.

Simplified perturbations models (SGP) used to calculate orbital state vectors of satellites and space debris relative to the Earth-centered inertial coordinate system [[Wikipedia]](https://en.wikipedia.org/wiki/Simplified_perturbations_models).

### Dependencies

Python 3.8 and Boost.Python libraries are used. Installation process under Ubuntu (Debian):

```bash
sudo apt-get install libboost-python-dev 
sudo apt-get install python-dev
sudo apt-get install libpython3.8-dev
```

### Compilation
CMake is used to configure makefiles before build. Go to the directory and run
```bash
rm CMakeCache.txt && cmake .
```
and then
```bash
make
```
