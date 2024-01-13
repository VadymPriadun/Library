#pragma once
#ifndef LIBRARY_H    
#define LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

enum Status{
    OPENED, CLOSED, DELETED 
};

enum Genre {
    FICTION,
    NON_FICTION,
    MYSTERY,
    SCIENCE_FICTION,
    HORROR,
    ROMANCE,
    FANTASY,
    BIOGRAPHY,
    HISTORY,
    SELF_HELP,
    TECHNICAL,
    MAGIC_REALISM,
    MILITARY
};

class Book {
private:
    string name;
    double price;
    string author;
    string publication;
    int year;
    int count_of_pages;
    Genre genre;
    string link;
    vector<string> pages;
    int currentPage;
public:
    Book(const string& bookName, double bookPrice, const string& bookAuthor, const string& bookPublication,
         int bookYear, int bookPages, Genre bookGenre, const string& bookLink)
        : name(bookName), price(bookPrice), author(bookAuthor), publication(bookPublication),
          year(bookYear), count_of_pages(bookPages), genre(bookGenre), link(bookLink), currentPage(1) {
        readPagesFromLink();  
    }

    const string& getName() const { return name; }
    void setName(const string& newName) { name = newName; }

    double getPrice() const { return price; }
    void setPrice(double newPrice) { price = newPrice; }

    const string& getAuthor() const { return author; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }

    const string& getPublication() const { return publication; }
    void setPublication(const string& newPublication) { publication = newPublication; }

    int getYear() const { return year; }
    void setYear(int newYear) { year = newYear; }

    int getCountOfPages() const { return count_of_pages; }
    void setCountOfPages(int newPages) { count_of_pages = newPages; }

    Genre getGenre() const { return genre; }
    void setGenre(Genre newGenre) { genre = newGenre; }

    string getLink() const { return link; }
    void setLink(const string& newLink) { link = newLink; }

    void readPagesFromLink() {
        ifstream file(link);

        if (!file.is_open()) {
            cerr << "Unable to open file: " << link << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            pages.push_back(line);
        }

        currentPage = 1;
    }

    void readPage(int page) const {
        if (page >= 0 && page < pages.size()) {
            cout << "Page " << page + 1 << ":\n" << pages[page] << endl;
        } else {
            cerr << "Invalid page number." << endl;
        }
    }

    void flipPage() {
        if (currentPage + 1 < pages.size()) {
            ++currentPage;
            cout << "Flipped to page " << currentPage + 1 << endl;
        } else {
            cout << "You are already on the last page." << endl;
        }
    }

    vector<string> readPages(int startPage, int pagesToRead) const {
        vector<string> result;

        for (int i = startPage; i < startPage + pagesToRead && i < pages.size(); ++i) {
            result.push_back(pages[i]);
        }

        return result;
    }

    int getCurrentPage() const {
        return currentPage;
    }

    int getTotalPages() const {
        return pages.size();
    }

    void displayBookInfo() const {
        if (price > 0.0) {
            cout << "Book Information:" << endl;
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
            cout << "Author: " << author << endl;
            cout << "Publication: " << publication << endl;
            cout << "Year: " << year << endl;
            cout << "Pages: " << count_of_pages << endl;
            cout << "Page " << currentPage << " of " << (count_of_pages / 20) + 1 << ":\n";

            cout << "Genre: ";
            switch (genre) {
                case FICTION:
                    cout << "Fiction";
                    break;
                case NON_FICTION:
                    cout << "Non-Fiction";
                    break;
                case MYSTERY:
                    cout << "Mystery";
                    break;
                case SCIENCE_FICTION:
                    cout << "Science Fiction";
                    break;
                case HORROR:
                    cout << "Horror";
                    break;
                case ROMANCE:
                    cout << "Romance";
                    break;
                case FANTASY:
                    cout << "Fantasy";
                    break;
                case BIOGRAPHY:
                    cout << "Biography";
                    break;
                case HISTORY:
                    cout << "History";
                    break;
                case SELF_HELP:
                    cout << "Self-Help";
                    break;
                case TECHNICAL:
                    cout << "Technical";
                    break;
            }

            cout << endl;
        } else {
            cout << "Availability: Book is not available." << endl;
        }
    }

    void readAndDisplayBookContent(int pagesToRead) const {
    char c;
    do {
        vector<string> bookContent = readPages(currentPage, pagesToRead);

        if (!bookContent.empty()) {
            for (const string& page : bookContent) {
                cout << page << endl;
            }

            cout << "Press 'Y' or 'y' to move to the next page, 'N' or 'n' to exit: ";
            cin >> c;

            if (c == 'Y' || c == 'y') {
                flipPage();
            }
        } else {
            cout << "Failed to read the book. Book is empty :(" << endl;
            break;
        }
    } while ((c == 'Y' || c == 'y') && currentPage < getTotalPages());
}
};

class Bookmark {
private:
    const Book& linkedBook;
    int bookmarkID;
    int pageNumber;
    double timestamp;

public:
    Bookmark(const Book& book, int id, int page, double time)
        : linkedBook(book), bookmarkID(id), pageNumber(page), timestamp(time) {}

    const Book& getLinkedBook() const { return linkedBook; }

    int getBookmarkID() const { return bookmarkID; }
    void setBookmarkID(int id) { bookmarkID = id; }

    int getPageNumber() const { return pageNumber; }
    void setPageNumber(int page) { pageNumber = page; }

    double getTimestamp() const { return timestamp; }
    void setTimestamp(double time) { timestamp = time; }

    void displayBookmarkInfo() const {
        if (linkedBook.getPrice() > 0.0) {
            cout << "Bookmark Information:" << endl;
            cout << "Book Name: " << linkedBook.getName() << endl;
            cout << "Bookmark ID: " << bookmarkID << endl;
            cout << "Page Number: " << pageNumber << endl;
            cout << "Timestamp: " << timestamp << endl;
        } else {
            cout << "Availability: Book is not available." << endl;
        }
    }
};

class ReadingStats {
private:
    const Book& linkedBook;
    int statsID;
    double startTime;
    double endTime;
    int totalPagesRead;

public:
    ReadingStats(const Book& book, int id, double start, double end, int total)
        : linkedBook(book), statsID(id), startTime(start), endTime(end), totalPagesRead(total) {}

    const Book& getLinkedBook() const { return linkedBook; }

    int getStatsID() const { return statsID; }
    void setStatsID(int id) { statsID = id; }

    double getStartTime() const { return startTime; }
    void setStartTime(double start) { startTime = start; }

    double getEndTime() const { return endTime; }
    void setEndTime(double end) { endTime = end; }

    int getTotalPagesRead() const { return totalPagesRead; }
    void setTotalPagesRead(int total) { totalPagesRead = total; }

    void displayStatsInfo() const {
        if (linkedBook.getPrice() > 0.0) {
            cout << "Reading Stats Information:" << endl;
            cout << "Book Name: " << linkedBook.getName() << endl;
            cout << "Stats ID: " << statsID << endl;
            cout << "Start Time: " << startTime << endl;
            cout << "End Time: " << endTime << endl;
            cout << "Total Pages Read: " << totalPagesRead << endl;
        } else {
            cout << "Availability: Book is not available." << endl;
        }
    }
};
#endif