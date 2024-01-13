#include <iostream>
#include <vector>
#include <string>
#include "library.h"
#include "book_data.h"

using namespace std;

void readAndDisplayBookContent(const Book& selectedBook, int pagesToRead) {
    char c;
    do {
        vector<string> bookContent = selectedBook.readPages(selectedBook.getCurrentPage(), pagesToRead);

        if (!bookContent.empty()) {
            for (const string& page : bookContent) {
                cout << page << endl;
            }

            cout << "Press 'Y' or 'y' to move to the next page, 'N' or 'n' to exit: ";
            cin >> c;

            if (c == 'Y' || c == 'y') {
                selectedBook.flipPage(); // Перегортання на наступну сторінку
            }
        } else {
            cout << "Failed to read the book. Book is empty :(" << endl;
            break;
        }
    } while ((c == 'Y' || c == 'y') && selectedBook.getCurrentPage() < selectedBook.getTotalPages());
}

void displayBooks(const vector<Book>& books) {
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". ";
        books[i].displayBookInfo();
    }
}

void searchByAuthor(const vector<Book>& books, const string& author) {
    vector<Book> foundBooks;

    for (const Book& book : books) {
        if (book.getAuthor() == author) {
            foundBooks.push_back(book);
        }
    }

    if (!foundBooks.empty()) {
        cout << "Books found by author " << author << ":" << endl;
        displayBooks(foundBooks);

        size_t choice;
        cout << "Enter the number of the book you want to read (0 to cancel): ";
        cin >> choice;

        if (choice > 0 && choice <= foundBooks.size()) {
            const Book& selectedBook = foundBooks[choice - 1];
            selectedBook.displayBookInfo();

            if (wantToRead()) {
                int pagesToRead = 40;
                selectedBook.readAndDisplayBookContent(pagesToRead);
            } else {
                cout << "Operation canceled or invalid choice." << endl;
            }
        } else {
            cout << "Invalid choice." << endl;
        }
    } else {
        cout << "Book haven't found by author: " << author << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    char choice;

    do {
        cout << R"(Main Menu:
1. Search by Author
2. Search by Title
3. Exit
Enter your choice: )";
        cin >> choice;

        switch (choice) {
            case '1': {
                string author;
                cout << "Enter author name: ";
                cin.ignore();
                getline(cin, author);
                searchByAuthor(books, author);
                break;
            }
            case '2': {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                //searchByTitle(books, title);
                break;
            }
            case '3': {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }

        cin.ignore();
    } while (choice != '3');

    return 0;
}
