CFLAGS = -I../include/
ifeq ($(shell uname),Darwin)
	LIBS = -L../output/ -ljwt
else	
	LIBS = -L../output/ -ljwt  -Wl,--rpath=./
endif
OUTPUT= ../output/
all: jwt-test
CXXFLAG = -fPIC
CC=gcc

jwt-test.o:jwt-test.c
	$(CC) $(CFLAGS) $(CXXFLAG) -c jwt-test.c

jwt-test:  jwt-test.o
	$(CC) $(CXXFLAG) $(LIBS) -o jwt-test jwt-test.o  

install:
	$(shell mkdir -p $(OUTPUT)/)
	$(shell \cp -f jwt-test $(OUTPUT)/jwt-test)

clean:
	rm -f *.o jwt-test
