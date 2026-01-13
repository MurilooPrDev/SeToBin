CXX = g++
CXXFLAGS = -std=c++17 -I./include
SRC = src/main.cpp src/loader.cpp src/packager.cpp src/EXEzecutor.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = bin/STE

ifeq ($(shell uname -o), Android)
	INSTALL_PATH = $(PREFIX)/bin
else
	INSTALL_PATH = /usr/local/bin
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

install: all
	@echo "Installing STE to $(INSTALL_PATH)..."
	cp $(TARGET) $(INSTALL_PATH)/STE
	chmod +x $(INSTALL_PATH)/STE
	@echo "Installation complete!"

clean:
	rm -f src/*.o bin/STE
