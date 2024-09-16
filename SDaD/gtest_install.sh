sudo apt-get install libgtest-dev libgmock-dev
sudo apt-get install libtbb-dev
sudo apt-get install cmake
cd /usr/src/googletest/
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp lib/* /usr/lib

g++ main.cpp -o test -lgtest -lgmock -pthread
./test
