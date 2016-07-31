# Contains header files
INCLUDE = include/
# Names of all the header files
INCLUDES := $(wildcard $(INCLUDE)*.h)

# Compile with all the warnings on
CXXFLAGS = -Wall -I$(INCLUDE)
# Link the math library
LDFLAGS = -lm

# Contains source files
SRC = src/
# Names of all the source files
SOURCES := $(wildcard $(SRC)*.cpp)

# Contains object files
OBJ = obj/
# Names of all the object files
OBJECTS := $(patsubst %.cpp,$(OBJ)%.o,$(notdir $(SOURCES)))

# Contains executables
BIN = bin/
# Names of all the target executables
BINS := $(patsubst %.cpp,$(BIN)%,$(notdir $(SOURCES)))

all : $(BINS)

.SECONDEXPANSION:
SRCFILE = $(patsubst $(OBJ)%.o,$(SRC)%.cpp,$@)
OBJFILE = $(patsubst $(BIN)%,$(OBJ)%.o,$@)
BINFILE = $@

# Rule to make executables
$(BIN)% : $(OBJECTS)
	$(CXX) $(OBJFILE) $(LDFLAGS) -o $(BINFILE)

# Rule to make object files
$(OBJ)%.o : $(SOURCES) $(INCLUDES)
	$(CXX) $(SRCFILE) $(CXXFLAGS) -c -o $(OBJFILE)

# Don't remove intermediate object files
.PRECIOUS : $(OBJECTS)

make_dirs:
	mkdir -p $(OBJ) $(BIN)

clean_obj:
	-rm $(OBJECTS)

clean :
	-rm $(OBJECTS)
	-rm $(BINS)
