IDIR =./include
INDIR =./lib
CC=g++
CFLAGS=-I$(IDIR) -I$(INDIR)
GTKFLAG = `pkg-config gtkmm-3.0 --cflags --libs`

ODIR =./bin
SDIR =./src
BDIR =./build

_DEPS = 2D.h 2Dto3D.h 3D.h 3Dto2D.h myarea.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = 2D.o 2Dto3D.o 3D.o 3Dto2D.o Main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_BUILDS = main
BUILDS = $(patsubst %,$(BDIR)/%,$(_BUILDS))

MKDIR = mkdir -p

OUT_DIR = bin build

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(GTKFLAG)

all: directories $(BUILDS)

directories: 
	$(MKDIR) $(OUT_DIR)

$(BDIR)/main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(GTKFLAG) 
