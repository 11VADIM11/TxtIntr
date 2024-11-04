# Компилятор
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# Имя выходного файла
TARGET = calculator

# Исходные файлы
SRC = calculator.cpp

# Объектные файлы
OBJ = $(SRC:.cpp=.o)

# Правило для сборки программы
all: $(TARGET)

# Линковка объектных файлов для создания исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Правило компиляции исходных файлов в объектные файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f $(TARGET) $(OBJ)

# Специальные правила
.PHONY: all clean
