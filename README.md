# Пицца 🍕  

🇷🇺 **Русская версия**  
**Пицца** — это эзотерический язык программирования, вдохновлённый Brainfuck, но с русскими командами и хаотичной «пицца-механикой».  

#### 🔹 **Особенности**  
- **Команды на кириллице** (`п`, `и`, `ц`, `а`, `с`, `т`, `з`, `к`).  
- **Случайные операции** через `🍕` (умножение, деление, вывод рандомных ячеек).  
- **Модель памяти**: 30 000 ячеек, как в Brainfuck.  

#### 🔹 **Установка**  
1. **Через Homebrew**:  
   ```bash
   brew tap ktilted/pizza && brew install pizza
   ```  
2. **Вручную**:  
   Скачайте [релиз](https://github.com/ktilted/pizza/releases) и добавьте `pizza` в `PATH`.  

#### 🔹 **Примеры**  
1. **Вывод «HELLO WORLD»**:  
   ```pizza
   пппппппппзппппппппкца # H
   иииа                  # E
   пппппппаа             # LL
   пппа                  # O
   ззппппппппзппппкца    # (space)
   ккппппппппа           # W
   ииииииииа             # O
   пппа                  # R
   ииииииа               # L
   ииииииииа             # D
   ```  
2. **Хаотичный цикл**:  
   ```pizza
   ппппппппзпппппппппппкцс🍕ит  # Уменьшаем число до 0, с хаосом от 🍕
   ```  

#### 🔹 **Документация**  
| Команда | Описание                  |  
|---------|---------------------------|  
| `п`     | +1 к текущей ячейке       |  
| `и`     | -1 к текущей ячейке       |  
| `з`     | Сдвиг вправо              |  
| `к`     | Сдвиг влево               |  
| `а`     | Вывод символа             |  
| `с`     | Начало цикла (`[`)        |  
| `т`     | Конец цикла (`]`)         |  
| `ц`     | Умножить текущую ячейку на следующую |  
| `🍕`    | Случайная операция        |  

---

### 🇺🇸 **English Version**  
**Pizza** is an esoteric programming language inspired by Brainfuck, but with Cyrillic commands and chaotic "pizza mechanics".  

#### 🔹 **Features**  
- **Cyrillic commands** (`п`, `и`, `ц`, `а`, `с`, `т`, `з`, `к`).  
- **Random operations** via `🍕` (multiplication, division, random cell output).  
- **Memory model**: 30,000 cells (like Brainfuck).  

#### 🔹 **Installation**  
1. **Via Homebrew**:  
   ```bash
   brew tap ktilted/pizza && brew install pizza
   ```  
2. **Manual**:  
   Download the [release](https://github.com/ktilted/pizza/releases) and add `pizza` to `PATH`.  

#### 🔹 **Examples**  
1. **Print "HELLO WORLD"**:  
   ```pizza
   пппппппппзппппппппкца # H
   иииа                  # E
   пппппппаа             # LL
   пппа                  # O
   ззппппппппзппппкца    # (space)
   ккппппппппа           # W
   ииииииииа             # O
   пппа                  # R
   ииииииа               # L
   ииииииииа             # D
   ```  
2. **Chaotic loop**:  
   ```pizza
   ппппппппзпппппппппппкцс🍕ит  # Decrement cell until 0, with 🍕 chaos
   ```  

#### 🔹 **Command Reference**  
| Command | Description               |  
|---------|---------------------------|  
| `п`     | Increment current cell    |  
| `и`     | Decrement current cell    |  
| `з`     | Move pointer right        |  
| `к`     | Move pointer left         |  
| `а`     | Output ASCII char         |  
| `с`     | Start loop (`[`)          |  
| `т`     | End loop (`]`)            |  
| `ц`     | Multiply current cell by next |  
| `🍕`    | Random operation          |  

---

### **🎯 Why Пицца?**  
- Для любителей эзотерики и абсурда. / For esolang lovers and chaos enthusiasts.  
- Можно написать «Hello World», но с 🍕 он может сломаться.  

---

**License**: MIT  
**Author**: KTILTED
**🍕 Pull Requests Welcome!**  
