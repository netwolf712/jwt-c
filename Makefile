CFLAGS = -I./include/
CXXFLAG=-O2 -g -Wall -fmessage-length=0 -fPIC
ifeq ($(shell uname),Darwin)
	LIB=-lc++
else	
	LIB=-lstdc++
endif
OUTPUT= ./output/
DLLNAME := libjwt.so
CC=gcc
CXX=g++
STRIP=strip
all : clean target slim


sha256.o:src/sha256.cpp
	$(CXX) $(CFLAGS) $(CXXFLAG) $(DOPTION) -c src/sha256.cpp

jwt.o:src/jwt.cpp
	$(CXX) $(CFLAGS) $(CXXFLAG) $(DOPTION) -c src/jwt.cpp

jwt_helper.o:src/jwt_helper.cpp
	$(CXX) $(CFLAGS) $(CXXFLAG) $(DOPTION) -c src/jwt_helper.cpp

OBJS=sha256.o jwt.o jwt_helper.o

target : $(OBJS)
	$(CC) $(ARCH) $(LFS_LDFLAGS) -D_REENTRANT -shared -o $(DLLNAME) $(OBJS) $(LIB)

slim:
ifeq ($(shell uname),Darwin)
else
	$(STRIP) -s -d $(DLLNAME)	
endif

install:
	$(shell mkdir -p $(OUTPUT))
	$(shell \cp -f $(DLLNAME) $(OUTPUT)/$(DLLNAME))

clean:
	rm -f *.o
	rm -rf $(DLLNAME)
