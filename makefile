#Defining compiler 
CC = g++
#Defining flags
CFLAGS = -g -Wall
#Defining FILES
TARGET = yaga
#Defining that all
all = $(TARGET)
	
$(TARGET): $(TARGET).cpp	
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp 2>$(TARGET)_logs
	
clean:
	$(RM) $(TARGET)