# Basic pub sub with libraries

This ROS-pub-sub model consists of 4 ROS packages, the publisher, subscriber and 2 libraries. The publisher consists of just 1 file which is the main, the main includes headers which are located in an external package. In this package the publisher application logic in located. See it as calling a class or function in another file, but for ROS its another package. Then the entire package is include in the CMakeList as a library. The same goes for the subscriber. So 4 packakges, like this:

- publisher
- app_logic_pub
- subscriber
- app_logic_sub

In a nutshell: the main from pub and sub controlls the communication (send receive through the topics). The application logic packages contain files where the actual logic, functions, calculations, etc are

## Additional information per package

### Publisher:

The publisher includes the ROS headers and also the headers from the corresponding application package, like this:

```
#include "ros/ros.h"
#include "app_logic_sub/SomeMap/Someheader.h"
```

Then the header classes and variables can be called normally in the main. Including these headers can be done by manipulating the CMakeLists.txt and package.xml. This is already done. But the external library is added in the find_package and catkin_package in the CMakeLists.txt as well with the essential ROS packages. Like this:

```
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  app_logic_sub               
)

catkin_package(
 CATKIN_DEPENDS roscpp std_msgs app_logic_sub
)
```

The package.xml is mostly complete, but the package must included here as well, like this:

```
<depend>app_logic_sub</depend>
```

The include folder in this package should be empty since every include from external files are in the external package.

### application_logic_pub

This packages acts as a container of all the external cpp and header files for the publisher. The structure might look something like this:

> src/SomeFolder/SomeFile.cpp

> src/SomeOtherFolder/SomeOtherFile.cpp

> include/app_logic_sub/ISomeFolder/ISomeFile.h

> include/app_logic_sub/SomeOtherFolder/ISomeOtherFile.h

Where the cpp files include their corresponding headers just like a normal cpp application. 

The CMakeLists.txt will look different as well. A skeleton is already been made, but some additional information: 

```
add_library(${PROJECT_NAME}
  src/SomeFolder/SomeFile.cpp
  src/SomeOtherFolder/SomeOtherFile.cpp
)
```

Here all the cpp files are located in the src directory, make sure to change the names to the names according to your projects

Linking the is done with this:

```
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
```

The package.xml is not altered in any way shape or form.

### Subscriber and application logic

The structure and coding of the CMakeLists.txt is exactly the same as the publisher, just the names are different.

## Making

In the root directory, where the Makefile is located, thats where we should make the build with catkin_make. This is written in the Makefile, so just use 

> make

## Running

**MAKE SURE TO RUN ROS IN ANOTHER TERMINAL, with:**

> roscore

in order to build the packages and the libraries and run the publisher. Use

> make pub

in another terminal to run the subscriber

> make sub

The ros includes may give an error in code, but try running the package anyway. I can work without any warnings or errors.

If any other errors occur, like not finding the package called talker or listener. Run

> source /opt/ros/noetic/setup.bash

after running make

# For own use

Copy paste or git clone this pub sub code and try to make it run with the commands stated here. If everything works, alter the code to what is needed for your application. Make sure to alter the names in CMakeLists.txt and includes if you do rename or add files. There might be some problems with the includes and path, honestly I'm not sure how to fix this. 

As far as I know, the publisher and subscriber code shouldnt be altered that much since it controlls the communication and topics. Make sure to change the datatype send to the topic and maybe add more topics if multiple sets of data are sent to other subscribers. Look at the source stated above the talker/listener.cpp for comments and more information.

The CMakeLists.txt in the src folder shouldnt be altered in any way shape or form as far as I know.

In the gitignore, Ive put the build and devel directories, so make sure the make first to generate these.

More information in the ROS commands can be found on github in the resources folder or at the end of this file

# Additional information:

ROS Noetic should already be installed thanks to Ijdo

## ROS installation and sourcing: 

ROS is installed under:
> /opt/ros/noetic/

The include files are located here as well

Source:
> source /opt/ros/noetic/setup.bash

OR for zsh
> source /opt/ros/noetic/setup.zsh

You can add this to your /.bashrc or /zshrc to avoid sourcing everytime a new terminal is opened

## Create a package: http://wiki.ros.org/ROS/Tutorials/CreatingPackage

Root of your project make a package

> catkin_create_pkg somePackageName std_msgs roscpp

Where std_msgs and roscpp are the dependencies needed. These packages can be includes in the packages.xml etc .. This will create a directory and CMakeLists, package.xml etc containing everything that is needed for catkin

In the root of your project, compike with:
> catkin_make 

This will generate the build and devel directories

To generate the package files
> source ./devel/setup.zsh

This will add your ROS package to the ROS package list, which can be seen in:
> rosrun ? 

## Running a ros package

In the root of the directory. Where the build and devel directories are present.

> catkin_make

Dont forget to source the setup.zsh or setup.bash

## Tip:

Make a Makefile containing the catkin_make and clean etc