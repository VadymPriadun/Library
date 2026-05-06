# 📚 E-Library

Console-based digital library app for reading and managing e-books.

This is my first C++ project 🎉

---

## ✨ Features

* 🔍 **Search System**
  Find books by **author** or **title**.

* 📖 **Book Information**
  View details like price, year, pages, and genre.

* 📄 **Built-in Reader**
  Read books directly in the terminal (20 lines per page).

* ⏱ **Reading Progress**
  Start from the beginning or continue from a specific page.

* 📊 **Reading Statistics**
  Track total pages read and time spent reading.

* 💻 **Cross-Platform**
  Works on macOS, Linux, and Windows.

---

## 🛠️ Technologies

* **Language:** C++ (C++17)
* **Libraries:**

  * `<iostream>`
  * `<fstream>`
  * `<vector>`
  * `<string>`
  * `<chrono>`

---

## 📋 Requirements

* C++ compiler with C++17 support (`g++`, `clang++`, or MSVC)

**macOS only:**

```bash
xcode-select --install
```

---

## 🚀 Run

```bash
git clone <your-github-repo-url>
cd Library
g++ -std=c++17 E-Library.cpp -o elibrary
./elibrary
```

**Windows:**

```bash
g++ -std=c++17 E-Library.cpp -o elibrary.exe
elibrary.exe
```

---

## 📖 Usage

1. Launch the app

2. Choose an option from the menu:

   * `1` — search by author
   * `2` — search by title
   * `3` — exit

3. Select a book from results

4. Press `Y` to start reading

### Navigation

* `B` — start from beginning
* `C` — continue from page
* `N` — next page
* `F` — finish reading

---

## 🧠 Notes

* Books are loaded from `.txt` files
* Simple console UI focused on functionality

---

## 👨‍💻 Author

First C++ project, built for learning and practice.
