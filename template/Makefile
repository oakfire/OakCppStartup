CC = clang++ 
INCLUDE += -I src/ -I src/common/ 
GTKFLAG = `pkg-config --cflags gtk+-2.0`
LDFLAGS +=  -L deps/libname/lib 
LDLIBS  += -lpthread -lm -lrt  

SOURCES := $(wildcard src/*.cpp) $(wildcard src/common/*.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
DOBJECTS := $(SOURCES:.cpp=.do)

ProjectName := hello_world

OUTDIR = build
OUTFILE = $(OUTDIR)/$(ProjectName)
DOUTDIR = debug
DOUTFILE = $(DOUTDIR/$(ProjectName)

CFLAGS  += -Wall -O0

DEB_DEST_DIR = pkg/usr/local/bin
DEB_DEST = $(DEB_DEST_DIR)/$(ProjectName)

all: $(OUTFILE)

debug: $(DOUTFILE)

$(OUTFILE) : $(OBJECTS)
	@mkdir -p $(OUTDIR)
	$(CC) -o $(OUTFILE) $(OBJECTS)  $(LDFLAGS)  $(LDLIBS) 
	@echo "Build Finished"

$(DOUTFILE) : $(DOBJECTS)
	@mkdir -p $(DOUTDIR)
	$(CC) -o $(DOUTFILE) $(DOBJECTS) $(LDFLAGS) $(LDLIBS)
	@echo "Build debug Finished"

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.do: %.cpp
	$(CC) -g $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OUTDIR) $(DOUTDIR) $(OBJECTS) $(DEB_DEST) $(DOBJECTS) 
deb:
	test -f $(OUTFILE) || exit 1
	mkdir -p $(DEB_DEST_DIR)
	cp -f $(OUTFILE) $(DEB_DEST)
	dpkg -b pkg $(ProjectName).deb


