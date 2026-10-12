# ASID C++ Coursework

A collection of independent C++ console assignments from the ASID course. Each assignment remains in its own directory, with its own Visual Studio solution and project files where available.

## Topics represented

The folder names and source files cover a range of algorithmic exercises, including sequence processing, binary search, tree operations, matrix operations, shortest-path search, and hashing. Exact task statements and naming are preserved from the coursework.

## Build and run

- Open an individual `.sln` file in Visual Studio.
- Build and run that assignment separately; there is no shared root application.
- Many exercises read from a nearby `input.txt` or similarly named input file and write results to `output.txt`.

Do not assume every folder is complete: the snapshot contains empty placeholder source files, including `Project1/Project1/FileName.cpp` and `Черный ящик/Черный ящик/FileName.cpp`, as well as some placeholder input/output files. Some legacy source comments also appear with broken text encoding. These have not been edited in the repository.

## Repository boundaries

Generated executables, debug outputs, and local IDE state are excluded from this snapshot. Input files are retained when they are part of an exercise. The `0.0/0.0` Visual Studio project built successfully with MSVC (v145 toolset override) in the Windows audit copy; it emitted a possible integer conversion warning. A full solution build was not run. Windows could not check out two very long tracked paths in the audit copy, so those assignments were not validated there.

This is a coursework archive rather than a single integrated C++ application. Check the exact assignment and course rules before making the repository public.
