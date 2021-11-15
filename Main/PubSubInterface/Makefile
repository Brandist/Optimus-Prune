PACKAGEPUB := publisher
TARGETPUB := talker
PACKAGESUB := subscriber
TARGETSUB := listener

all: compile

pub: 
	rosrun $(PACKAGEPUB) $(TARGETPUB) 

sub:
	rosrun $(PACKAGESUB) $(TARGETSUB)
	
compile: 
	catkin_make

clean:
	find . -type f -name '*.o' -delete
	rm -rf build devel
