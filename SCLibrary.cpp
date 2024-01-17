#include <fstream>
#include "library.h"
#include "book_data.h"
#include "displayPages.h"
using namespace std;

extern vector<Book> books;
vector<string> readBookContent(const string& link);
void searchByAuthor(const vector<Book>& books, const string& author);
void searchByTitle(const vector<Book>& books, const string& title);

int main(){
    setlocale(LC_ALL, "ukr");

    cout << R"(/---------E-Library---------\)" << endl;
    cout << "I made some examples of books in txt format. Authors and their books: \n";
    for (const auto& book : books) {
        cout << "Author: " << book.getAuthor() << " - Book: " << book.getName() << " " << book.getYear() << " year. "<< endl;
    }

    char choice;

    do{
        cout << R"(Main Menu:
1. Search by Author
2. Search by Title
3. Exit
Enter your choice: )";
        cin >> choice;

        switch (choice){
            case '1':
            {
                string author;
                cout << "Enter author name: ";
                cin.ignore();
                getline(cin, author);
                searchByAuthor(books, author);
                break;
            }
            case '2':
            {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                searchByTitle(books, title);
                break;
            }
            case '3':
            {
                cout << "Exiting program." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }
        cin.ignore();
        cout << "*--------------------*" << endl;
    }while (choice != '3');
    
    return 0;
}

vector<string> readBookContent(const string& link){
    ifstream file(link);
    vector<string> bookContent;
    string line;

    if (!file.is_open())
    {
        cerr << "Unable to open file: " << link << endl;
        return bookContent;
    }

    while (getline(file, line))
    {
        bookContent.push_back(line);
    }

    file.close();

    return bookContent;
}

void searchByAuthor(const vector<Book>& books, const string& author){
    vector<Book> foundBooks;

    for (const Book& book : books)
    {
        if (book.getAuthor() == author)
        {
            foundBooks.push_back(book);
        }
    }

    if (!foundBooks.empty())
    {
        cout << "Books found by author " << author << ":" << endl;

        for (size_t i = 0; i < foundBooks.size(); ++i)
        {
            cout << i + 1 << ". " << foundBooks[i].getName() << endl;
        }

        cout << "Enter the number of the book you want to read (0 to cancel): " << endl;
        size_t choice;
        cin >> choice;
        cout << "*--------------------*" << endl;
        if (choice > 0 && choice <= foundBooks.size())
        {
            const Book& selectedBook = foundBooks[choice - 1];

            cout << "Book selected: " << selectedBook.getName() << endl;
            selectedBook.displayBookInfo();

            cout << "Do you want to read the book? (Y/N)\n";
            char c;
            cin >> c;
            if (c == 'Y')
            {
                ReadingStats readingStats(selectedBook, 1, 0.0, 0.0, 0);
                vector<string> bookContent = readBookContent(selectedBook.getLink());

                if (!bookContent.empty()){
                    int startingPage = readingStats.getTotalPagesRead() + 1;

                    cout << "Do you want to start reading from the beginning or continue from a specific page? (B/C)\n";
                    cin >> c;

                    switch (c){
                        case 'B':
                        case 'b':

                            readingStats.setStartTime(clock());
                            displayPages(readingStats, bookContent, startingPage);
                            readingStats.setEndTime(clock());
                            break;
                        case 'C':
                        case 'c':
                            cout << "Enter the page number to continue reading: ";
                            int pageNum;
                            cin >> pageNum;
                            readingStats.setStartTime(clock());
                            displayPages(readingStats, bookContent, pageNum);
                            readingStats.setEndTime(clock());
                            break;
                        default:
                            cout << "Invalid choice. Starting from the beginning by default.\n";
                            readingStats.setStartTime(clock());
                            readingStats.setEndTime(clock());
                            break;
                    }
                    cout << "*--------------------*" << endl;
                    readingStats.displayStatsInfo();
                    
                }
                else
                {
                    cout << "Failed to read the book." << endl;
                }
            }
            else
            {
                cout << "Operation canceled." << endl;
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    else
    {
        cout << "Book haven't found by author: " << author << endl;
    }
}


void searchByTitle(const vector<Book>& books, const string& title){
    vector<Book> foundBooks;

    for (const Book& book : books)
    {
        if (book.getName() == title)
        {
            foundBooks.push_back(book);
        }
    }

    if (!foundBooks.empty())
    {
        cout << "Books found by title " << title << ":" << endl;

        for (size_t i = 0; i < foundBooks.size(); ++i)
        {
            cout << i + 1 << ". " << foundBooks[i].getName() << endl;
        }

        cout << "Enter the number of the book you want to read (0 to cancel): " << endl;
        size_t choice;
        cin >> choice;
        cout << "*--------------------*" << endl;

        if (choice > 0 && choice <= foundBooks.size())
        {
            const Book& selectedBook = foundBooks[choice - 1];

            cout << "Book selected: " << selectedBook.getName() << endl;
            selectedBook.displayBookInfo();
            cout << "Do you want to read the book? (Y/N)\n";
            char c;
            cin >> c;
            if (c == 'Y')
            {
                ReadingStats readingStats(selectedBook, 1, 0.0, 0.0, 0);
                vector<string> bookContent = readBookContent(selectedBook.getLink());

                if (!bookContent.empty())
                {
                    int startingPage = readingStats.getTotalPagesRead() + 1;

                    cout << "Do you want to start reading from the BEGINNING or CONTINUE from a specific page? (B/C)\n";
                    cin >> c;

                    switch (c){
                        case 'B':
                        case 'b':
                            readingStats.setStartTime(clock());
                            displayPages(readingStats, bookContent, startingPage);
                            readingStats.setEndTime(clock());
                            break;
                        case 'C':
                        case 'c':
                            cout << "Enter the page number to continue reading: ";
                            int pageNum;
                            cin >> pageNum;
                            readingStats.setStartTime(clock());
                            displayPages(readingStats, bookContent, pageNum);
                            readingStats.setEndTime(clock());
                            break;
                        default:
                            cout << "Invalid choice. Starting from the beginning by default.\n";
                            readingStats.setStartTime(clock());
                            readingStats.setEndTime(clock());
                            break;
                    }
                    cout << "*--------------------*" << endl;
                    readingStats.displayStatsInfo();
                }
                else
                {
                    cout << "Failed to read the book." << endl;
                }
            }
            else
            {
                cout << "Operation canceled." << endl;
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    else
    {
        cout << "Book haven't found by title: " << title << endl;
    }
}
