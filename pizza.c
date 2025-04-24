#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Размер массива ячеек
#define MEMORY_SIZE 30000
// Максимальная длина входного кода
#define MAX_CODE_SIZE 100000
// Максимальная вложенность циклов
#define MAX_LOOP_NESTING 1000

// Функция для чтения файла с кодом на "Пицце"
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "ERR: Could not open a file %s\n", filename);
        exit(1);
    }
    char* code = malloc(MAX_CODE_SIZE);
    size_t i = 0;
    int c;
    while ((c = fgetc(file)) != EOF && i < MAX_CODE_SIZE - 1) {
        code[i++] = c;
    }
    code[i] = '\0';
    fclose(file);
    return code;
}

// Функция для выполнения хаотичного действия 🍕
void pizza_chaos(unsigned char* cells, int memory_size) {
    int idx1 = rand() % memory_size;
    int idx2 = rand() % memory_size;
    switch (rand() % 5) {
        case 0: // Умножение двух случайных ячеек
            cells[idx1] *= cells[idx2];
            break;
        case 1: // Деление случайной ячейки на случайное число
            if (cells[idx1] != 0) {
                cells[idx1] /= (rand() % 255) + 1;
            }
            break;
        case 2: // Прибавление случайного числа
            cells[idx1] += rand() % 256;
            break;
        case 3: // Вычитание случайного числа
            cells[idx1] -= rand() % 256;
            break;
        case 4: // Вывод случайной ячейки
            putchar(cells[idx1]);
            break;
    }
}

// Функция для выполнения программы на "Пицце"
void interpret_pizza(const char* code) {
    unsigned char cells[MEMORY_SIZE] = {0}; // Массив ячеек
    int ptr = 0; // Указатель на текущую ячейку
    size_t code_len = strlen(code);
    size_t pc = 0; // Program counter (индекс текущей команды)

    // Стек для хранения позиций начала циклов
    size_t loop_stack[MAX_LOOP_NESTING];
    int loop_stack_top = -1;

    while (pc < code_len) {
        // Пропускаем пробелы и переносы строк
        if (code[pc] == ' ' || code[pc] == '\n' || code[pc] == '\t') {
            pc++;
            continue;
        }

        // Обработка команд
        if (code[pc] == '\xD0' && code[pc + 1] == '\xBF') { // п
            cells[ptr]++;
            pc += 2;
        } else if (code[pc] == '\xD0' && code[pc + 1] == '\xB8') { // и
            cells[ptr]--;
            pc += 2;
        } else if (code[pc] == '\xD1' && code[pc + 1] == '\x86') { // ц
            if (ptr + 1 < MEMORY_SIZE) {
                cells[ptr] *= cells[ptr + 1];
            }
            pc += 2;
        } else if (code[pc] == '\xD0' && code[pc + 1] == '\xB0') { // а
            putchar(cells[ptr]);
            pc += 2;
        } else if (code[pc] == '\xD1' && code[pc + 1] == '\x81') { // с
            if (cells[ptr] == 0) {
                // Пропускаем цикл
                int nesting = 1;
                pc += 2; // Перемещаемся после символа 'с'
                while (nesting > 0 && pc < code_len) {
                    if (code[pc] == '\xD1' && code[pc + 1] == '\x81') { // с
                        nesting++;
                        pc += 2;
                    } else if (code[pc] == '\xD1' && code[pc + 1] == '\x82') { // т
                        nesting--;
                        pc += 2;
                    } else if (code[pc] == '\xF0' && code[pc + 1] == '\x9F' && code[pc + 2] == '\x8D' && code[pc + 3] == '\x95') {
                        pc += 4; // Пропускаем 🍕
                    } else {
                        pc++;
                    }
                }
            } else {
                // Сохраняем позицию начала цикла
                if (loop_stack_top + 1 >= MAX_LOOP_NESTING) {
                    fprintf(stderr, "ERR: Too much nested cycles\n");
                    exit(1);
                }
                loop_stack[++loop_stack_top] = pc;
                pc += 2; // Перемещаемся после символа 'с'
            }
        } else if (code[pc] == '\xD1' && code[pc + 1] == '\x82') { // т
            if (loop_stack_top < 0) {
                fprintf(stderr, "ERR: Extra closing bracket 'т' in %zu\n", pc);
                exit(1);
            }
            if (cells[ptr] != 0) {
                // Возвращаемся к началу цикла
                pc = loop_stack[loop_stack_top];
                pc += 2; // я добавил вот это
            } else {
                // Выходим из цикла
                loop_stack_top--;
                pc += 2; // Перемещаемся после символа 'т'
            }
        } else if (code[pc] == '\xD0' && code[pc + 1] == '\xB7') { // з
            if (ptr + 1 < MEMORY_SIZE) {
                ptr++;
            }
            pc += 2;
        } else if (code[pc] == '\xD0' && code[pc + 1] == '\xBA') { // к
            if (ptr > 0) {
                ptr--;
            }
            pc += 2;
        } else if (code[pc] == '\xF0' && code[pc + 1] == '\x9F' && code[pc + 2] == '\x8D' && code[pc + 3] == '\x95') { // 🍕
            pizza_chaos(cells, MEMORY_SIZE);
            pc += 4;
        } else {
            fprintf(stderr, "WRN: Ignoring unknown symbol on %zu\n", pc);
            pc++;
        }
    }

    if (loop_stack_top >= 0) {
        fprintf(stderr, "ERR: unclosed cycle in %zu\n", loop_stack[loop_stack_top]);
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s pizza_code.pizza\n", argv[0]);
        return 1;
    }

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Чтение кода на "Пицце"
    char* pizza_code = read_file(argv[1]);

    // Выполнение программы
    interpret_pizza(pizza_code);

    // Освобождение памяти
    free(pizza_code);

    return 0;
}