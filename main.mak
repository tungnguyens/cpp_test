####################################################################
# Custom: THL sensor makefile
####################################################################

# File *.cpp
SOURCE_FILES = \
	${SOURCE_PATTH}/main.cpp \

# File *.h
INCLUDES += \
	-I${SOURCE_PATTH} \


CXX_SOURCE_FILES += $(filter %.cpp, $(SOURCE_FILES))