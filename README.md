#Sign In/Out/Up System for Team Management  
This is a simple and easy to use team management tool that is desgined to run an a small linux computer such as a raspberry pi and log times of users  
Initial design is to be used for the Marine Robotics Club at Flordia Atlantic University  
  
## Setup:  
### Installing Depenencies:  
>sudo apt install cmake build-essential libgl1-mesa-dev qtbase5-dev
  
>cd /usr/src/gtest  
>sudo cmake CMakeLists.txt  
>sudo make

>sudo cp *.a /usr/lib  

## How to Build:  
>mkdir build  
>cd build  
>cmake ..  
>make  
  
Executable file should be in the **build/src** folder  
