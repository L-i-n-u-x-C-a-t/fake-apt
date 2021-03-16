CC = gcc
TARGET = fake-apt
TARGETPP = fake-apt++

linux:
	mkdir -p bin/
	$(CC) $(TARGET)/main.c -o bin/$(TARGET)

linuxpp:
	mkdir -p bin/
	g++ $(TARGETPP)/main.cpp -o bin/$(TARGETPP)

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	gcc -o bin/$(TARGET)X86 -target x86_64-apple-macos10.12 $(TARGET)/main.c

macARM:
	mkdir -p bin/
	gcc -o bin/$(TARGET)ARM -target arm64-apple-macos11 $(TARGET)/main.c
	
#please note that i never had a mac so i have no idea about building on it. if it doesnt work then idk

macX86pp:
	mkdir -p bin/
	g++ -o bin/$(TARGET)X86 -target x86_64-apple-macos10.12 $(TARGETPP)/main.cpp
	
macARMpp:
	mkdir -p bin/
	g++ -o bin/$(TARGET)ARM -target arm64-apple-macos11 $(TARGET)/main.cpp
	
clean:
	rm -f bin/* rm -d bin/
