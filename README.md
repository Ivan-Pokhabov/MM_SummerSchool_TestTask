# MM_SummerSchool_TestTask
# BMP headers reader
Application that prints the header of a bmp file in human readable format. Application only supports BMP versions 3, 4, 5.

### Requirements
- Make
- GCC
  
For ARM cross-compilation:
- gcc-arm-linux-gnueabi

### Start
From the root directory of the repository:
```
make
```
Then you can pass a bmp image to app:
```
./bmp path/to/your_file
```
Cross compilation:
```
make build
./bmp path/to/your_file
```
Clean the repository
```
make clean
```