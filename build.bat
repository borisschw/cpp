@echo off

set build_folder=D:\my_projects\cpp\build
set source_folder=D:\my_projects\cpp\

@REM echo Make clean
@REM cd %build_folder%
@REM make clean

echo Generate
cmake -DCMAKE_BUILD_TYPE=Debug -S %source_folder% -B %build_folder% -G "MinGW Makefiles"

echo Make
cd %build_folder%
make

echo ------------------------
echo --Exectute the program--
echo ------------------------


app.exe
cd ..