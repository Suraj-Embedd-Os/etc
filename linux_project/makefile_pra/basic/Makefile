#all: ;

#override PATH=bar
#$(info $(FOO))

#$(info $(PATH) $(origin PATH))
#ifndef BUILD_DEBUG 
#BUILD_DEBUG := yes 
#endif

#BUILD_DEBUG :=yes

#.PHONY:	all

#all:
#	@echo BUILD_DEBUG is $(BUILD_DEBUG)
	
#the $(shell) environment  test start

export FOO=bar
$(info $(shell printenv |grep FOO))

all: ;
	@printenv | grep FOO

#the $(shell) environment  test end