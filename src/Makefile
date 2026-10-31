CC = gcc

CFLAGS = -Wall -Wextra

TARGET = university_lab

SOURCES = main.c \
          student.c \
          faculty.c \
          laboratory.c \
          equipment.c \
          booking.c \
          os_features.c

OBJECTS = $(SOURCES:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(TARGET)


run: $(TARGET)
	./$(TARGET)