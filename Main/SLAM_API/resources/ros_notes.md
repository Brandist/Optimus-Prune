# ROS working steps:

ROS Noetic should already be installed

## Important

Make sure to run 

> roscore

in a different terminal, and keep it running

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

## ROS messages (.msg files)

ROS msg are files that essentially create a header of a custom datatype, like a struct or class. The .msg types are used to send a struct on the topic instead of a single data type such as a String or int.

.msg files are located in "packageName/msg/someMsg.msg" and the file itself can look like this:

```
Header header
float64[] x
float64[] y
float64[] z
```

The above file states a struct containing 3 float arrays for $x, y, z$ coordinates. float64 translates to a double in c++ code, in c++, float32 is an actual float. [Follow this link for all available datatypes](http://wiki.ros.org/msg).

In order to compile and use the message in code, we need to alter the CMakeLists.txt and package.xml first. So, after creating the .msg file in /src/cpp/packageName/msg/, add the following lines to the CMakeLists.txt

```
add_message_files(
  FILES
  someMsg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)
```

place the above code below find_package. Also in find_package add the message_generation dependency, like this:

```
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)
```

And in catkin_package add the message_runtime dependency, like this:

```
catkin_package(
 CATKIN_DEPENDS roscpp std_msgs message_runtime apilib
)
```

For the package.xml we need to add some dependencies. Add the following lines at the end of the existing dependencies.

```
<build_depend>message_generation</build_depend>
<exec_depend>message_runtime</exec_depend>
```

After editing these files, the someMsg.msg header file can be included in the main cpp file. No header has to be created by the user, ROS does this when compiling automatically. Include the header like this:

```
#include "packageName/someMsg.h"
```

After compiling the header is located in the ROS folder, which can be generated with this command:

> rosmsg list

This will show every msg generated from every package available to you. A lot of different messages are available, such as arrays, vectors, even pointclouds from the PCL lib, odometry, robot status etc. But in this case a custom message is added for scaleability. If the msg isnt in the list, make sure to compile it a couple of times. And make sure the include names correspond with the file names, the same goes for the CMakeLists.txt names. The include line might show an error as well, this shouldnt be a problem when compiling. 

To actually use the message and initialise the datatypes. We need to change the datatype from the ROS publisher object created from the tutorial. Like this:

**previously:**

```
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
```

**new:**

```
ros::Publisher some_var_name = n.advertise<packageName::someMsg>("topic_name", 1000);
```

Then we make an object of the message:

```
packageName::someMsg msg;
```

and, just like a struct, we can assign the msg variables, like this:

```
msg.some_variable = 10;
```

Make sure that the datatypes correspond with each other.