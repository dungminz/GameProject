CXX = g++
CXXFLAGS = -I/opt/homebrew/Cellar/sdl2_mixer/2.8.0/include/SDL2 \
		   -I/opt/homebrew/Cellar/sdl2_ttf/2.22.0/include/SDL2 \
		   -I/opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2 \
		   -I/opt/homebrew/Cellar/sdl2/2.30.0/include/SDL2
LDFLAGS = -L/opt/homebrew/Cellar/sdl2_mixer/2.8.0/lib \
		  -L/opt/homebrew/Cellar/sdl2_ttf/2.22.0/lib \
		  -L/opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib \
		  -L/opt/homebrew/Cellar/sdl2/2.30.0/lib
LIBS = -lSDL2_mixer -lSDL2_ttf -lSDL2_image -lSDL2
TARGET = main
SRCS = Main.cpp Game.cpp TextureManager.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LIBS) -o $@ $^ &&./main
