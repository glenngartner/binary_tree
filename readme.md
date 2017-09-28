## Custom Binary Tree Application 
An interactive app implementing a custom binary tree algorithm.

### Dependencies
Have cmake installed, and accessible in your path (ie: you should be able to launch cmake from your terminal).

This repo uses Cinder to render graphics and other cool effects, so clone this repository recursively: 

```bash
git clone --recursive https://github.com/glenngartner/binary_tree.git
```

This will clone the Cinder repo into your local repos' lib/ folder. CMAKE is expecting this repo, so make sure it's included. Once there, CMAKE will handle the building and linking of Cinder auto-magically.

### Run / Debug
If your IDE supports CMake configurations directly (using the CMakeLists.txt file), like Visual Studio 2017 or CLion, just open the project root folder in your IDE. You can then run or debug the app without running CMake. If you want to use XCode, Visual Studio with a .sln file, or another IDE, then generate your project files with cmake (next section).

### Generate Project Files
If you want to generate project files for your IDE of choice (Visual Studio solution, XCode, etc), and build from source, cd to the project root directory in your terminal. Then, change to the build directory, launch cmake, and direct cmake at the project root, like so:

```bash
{project_root}> cd build/
{project_root}/build> cmake .. # direct cmake up one directory, to the project root, where the CMakeLists.txt file resides
```

Cmake will generate project files, and deposit them in the build folder (or the folder you launched CMake from). Now you can open and compile the project in your IDE.

### Compile
Compile the project in your IDE. If you chose UNIX Makefiles during cmake configuration, then run make from the build directory: 
```bash
{project_root}/build> make .
``` 

### Binaries
If you don't want to build yourself, I'll add windows (.exe) and OSX (unix executable) binaries in the bin/ folder soon. You can download, and launch them directly.