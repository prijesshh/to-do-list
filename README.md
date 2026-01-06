# 📋 To-Do List Application

A simple command-line to-do list manager built with C++ for efficient task management.

## 📖 About

This is a console-based task management application that helps you organize your daily tasks. The application stores tasks persistently in a file, so your to-do list is saved between sessions.

## ✨ Features

- ✅ Add new tasks
- 📝 View all tasks
- ✔️ Mark tasks as complete
- 💾 Persistent storage (tasks saved to file)
- 🖥️ Simple command-line interface
- 🔐 Password protection (optional)

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:** File I/O, data structures, string manipulation
- **Storage:** Text file-based persistence

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Terminal/Command Prompt

### Compilation

```bash
# Using g++
g++ todo.cpp -o todo

# Or using clang++
clang++ todo.cpp -o todo
```

### Execution

```bash
# On Linux/Mac
./todo

# On Windows
todo.exe
```

## 💡 Usage

Once the program is running, follow the on-screen prompts to:

1. **Add a task** - Enter your task description
2. **View tasks** - See all your pending and completed tasks
3. **Complete a task** - Mark tasks as done
4. **Exit** - Close the application (tasks are automatically saved)

## 📁 File Structure

```
to-do-list/
├── todo.cpp              # Main application code
├── file.txt              # Task storage file
├── password.txt          # Password storage (if enabled)
├── build/                # Build directory
│   └── Debug/            # Debug build files
└── .vscode/              # VS Code configuration
```

## 🎯 Learning Outcomes

This project helped me practice:
- C++ file input/output operations
- Working with vectors and strings
- Managing program flow and user input
- Implementing data persistence
- Structuring a simple CLI application

## 🔮 Future Improvements

- [ ] Add task priorities (high, medium, low)
- [ ] Implement task categories/tags
- [ ] Add due dates and reminders
- [ ] Search and filter functionality
- [ ] Better error handling
- [ ] Color-coded terminal output
- [ ] Export tasks to different formats (JSON, CSV)

## 🐛 Known Issues

- No input validation for certain edge cases
- Limited error messages for file operations

## 🤝 Contributing

This is a learning project, but suggestions and improvements are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests

## 📧 Contact

**Prijesh Pradhan**
- GitHub: [@prijesshh](https://github.com/prijesshh)
- LinkedIn: [prijeshpradhan](https://www.linkedin.com/in/prijeshpradhan/)
- Email: prijeshpradhan@gmail.com

## 📝 License

This project is open source and available for educational purposes.

---

⭐ If you found this project helpful, consider giving it a star!
