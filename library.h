#pragma once
#ifndef LIBRARY_H    
#define LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

enum Genre{
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

class Book{
private:
    string name;
    double price;
    string author;
    string publication;
    int year;
    int count_of_pages;
    Genre genre;
    string link;
    int currentPage;
public:
    Book(const string& bookName, double bookPrice, const string& bookAuthor, const string& bookPublication, int bookYear, int bookPages, Genre bookGenre, const string& bookLink)
        : name(bookName), price(bookPrice), author(bookAuthor), publication(bookPublication), year(bookYear), count_of_pages(bookPages), genre(bookGenre), link(bookLink), currentPage(1) {}

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

    void displayBookInfo() const {
        if (price > 0.0)
        {
            cout << "Book Information:" << endl;
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
            cout << "Author: " << author << endl;
            cout << "Publication: " << publication << endl;
            cout << "Year: " << year << endl;
            cout << "Pages: " << count_of_pages << endl;
            cout << "Page " << currentPage << " of " << (count_of_pages / 20) + 1 << ":\n";

            cout << "Genre: ";
            switch (genre){
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
            cout << "*--------------------*" << endl;
        }
        else
        {
            cout << "Availability: Book is not available." << endl;
        }
    }
};


class ReadingStats{
private:
    const Book& linkedBook;
    int statsID;
    clock_t startTime;
    clock_t endTime;
    int totalPagesRead;

public:
    ReadingStats(const Book& book, int id, double start, double end, int total)
        : linkedBook(book), statsID(id), startTime(start), endTime(end), totalPagesRead(total) {startTime = clock();}

    const Book& getLinkedBook() const { return linkedBook; }

    int getStatsID() const { return statsID; }
    void setStatsID(int id) { statsID = id; }

    double getStartTime() const { return startTime; }
    void setStartTime(double start) { startTime = start; }

    double getEndTime() const { return endTime; }
    void setEndTime(double end) { endTime = end; }

    int getTotalPagesRead() const { return totalPagesRead; }
    void setTotalPagesRead(int total) { totalPagesRead = total; }

    void displayStatsInfo() const{
        if (linkedBook.getPrice() > 0.0)
        {
            cout << "Reading Stats Information:" << endl;
            cout << "Book Name: " << linkedBook.getName() << endl;
            cout << "Stats ID: " << statsID << endl;
            cout << "Total Pages Read: " << totalPagesRead << endl;
            cout << "Total reading duration: " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
        }
        else
        {
            cout << "Availability: Book is not available." << endl;
        }
    }
    void finishReading(){
        endTime = clock();
        displayStatsInfo();
    }
};
#endif