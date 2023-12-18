#Defining compiler 
CC = g++
#Defining flags
CFLAGS = -g -Wall
#Defining FILES
TARGET = yaga
#Defining that all
all = $(TARGET)
	
$(TARGET): $(TARGET).cpp	
	$(CC) -o $(TARGET) $(TARGET).cpp 2>$(TARGET)_logs
	$(CC) $(TARGET).cpp -o /data/data/com.termux/files/usr/bin/yaga
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET)_debug
	
clean:
	$(RM) $(TARGET)