
---

# 🕹️ Tic Tac Toe (C Implementation)

This is a **console-based Tic Tac Toe game** in C where a human player competes against a computer. The computer picks random available moves, and the game continues until a win or draw is detected.

---

## 🧱 Project Structure

```
project/
├── main.c               # Entry point of the game
├── lib/
│   └── tictactoe.h      # Header for all game logic
└── tictactoe.c          # All core logic (display, input, turns, winner check)
```

---

## ✅ Features

- Choose your symbol (`X` or `O`)
- Play on a 3x3 grid using standard positions (A1, B2, etc.)
- Computer plays random available moves
- Detects winner (rows, columns, diagonals)
- Detects draw after 5 moves without a winner

---

## 🕹️ How to Play

1. **Start the game**
   ```
   make run   # or compile manually: gcc main.c tictactoe.c -o ttt && ./ttt
   ```

2. **Choose your symbol**
   ```
   Select symbol (O or X) : X
   ```

3. **Pick a position**
   ```
   Select position (e.g A1) : B2
   ```

4. **Watch the board update after each turn**
   ```
   #########
   # O   X #
   #   X   #
   #       #
   #########
   ```

---

## 📦 Example Game Flow

```
Select symbol (O or X) : O
Player symbol   : 'O'
Computer symbol : 'X'
______________________

Select position (e.g A1) : A1
#########
# O     #
#       #
#       #
#########

Computer's move...
#########
# O X   #
#       #
#       #
#########
```

---

## 🧠 Logic Highlights

- `displayGrid()` shows the current board.
- `selectPlayerPosition()` validates user input (like "B2").
- `computerTurn()` picks a random unoccupied square.
- `checkWinner()` checks rows, columns, and diagonals for a win or draw.
- The game ends when a player wins or the grid is full.

---

## 🔧 Requirements

- C compiler (e.g., `gcc`)
- `make` (optional, for build automation)

---

## 📜 License

Free to use and modify for learning or projects. No warranties.

---
