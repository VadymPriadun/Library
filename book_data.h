#pragma once
#ifndef BOOK_DATA
#define BOOK_DATA
#include "library.h"

vector<Book> books = {
    Book("The C++ Programming Language", 49.99, "Bjarne Stroustrup", "Addison-Wesley", 1985, 1348, TECHNICAL, "books/txt/The_C++_Programming_Language.txt"),
    Book("To Kill a Mockingbird", 14.99, "Harper Lee", "J.B. Lippincott & Co.", 1960, 281, FICTION, "books/txt/mockingbird.txt"),
    Book("1984", 19.99, "George Orwell", "Secker & Warburg", 1949, 328, SCIENCE_FICTION, "books/txt/1984.txt"),
    Book("The Great Gatsby", 9.99, "F. Scott Fitzgerald", "Charles Scribner's Sons", 1925, 180, FICTION, "books/txt/the-great-gatsby.txt"),
    Book("The Hobbit", 12.99, "J.R.R. Tolkien", "Allen & Unwin", 1937, 310, FANTASY, "books/txt/TheHobbit-J.R.R.Tolkien.txt"),
    Book("Pride and Prejudice", 8.99, "Jane Austen", "T. Egerton", 1813, 279, ROMANCE, "books/txt/pride-and-prejudice.txt"),
    Book("The Catcher in the Rye", 11.99, "J.D. Salinger", "Little, Brown and Company", 1951, 214, FICTION, "books/txt/Catcher in the Rye.txt"),
    Book("The Lord of the Rings", 29.99, "J.R.R. Tolkien", "George Allen & Unwin", 1954, 1037, FANTASY, "books/txt/Tolkien-J.-The-lord-of-the-rings-HarperCollins-ebooks-2010.txt"),
    Book("Moby-Dick", 16.99, "Herman Melville", "Richard Bentley", 1851, 635, FICTION, "books/txt/moby-dick.txt"),
    Book("The Da Vinci Code", 18.99, "Dan Brown", "Doubleday", 2003, 454, MYSTERY, "books/txt/The_Da_Vinci_Code.txt"),
    Book("Brave New World", 15.99, "Aldous Huxley", "Chatto & Windus", 1932, 311, SCIENCE_FICTION, "books/txt/Brave-New-World_-_Aldous-Huxley.txt"),
    Book("The Odyssey", 13.99, "Homer", "Unknown", -800, 384, FANTASY, "books/txt/the-odyssey.txt"),
    Book("The Shining", 17.99, "Stephen King", "Doubleday", 1977, 447, HORROR, "books/txt/The-Shining.txt"),
    Book("The Alchemist", 10.99, "Paulo Coelho", "Rocco", 1988, 163, FICTION, "books/txt/_OceanofPDF.com_The_Alchemist.txt"),
    Book("Frankenstein", 14.99, "Mary Shelley", "Lackington, Hughes, Harding, Mavor & Jones", 1818, 280, HORROR, "books/txt/frankenstein.txt"),
    Book("One Hundred Years of Solitude", 22.99, "Gabriel Garcia Marquez", "Editorial Sudamericana", 1967, 417, MAGIC_REALISM, "books/txt/One_Hundred_Years_of_Solitude.txt"),
    Book("The Art of War", 7.99, "Sun Tzu", "Unknown", -500, 60, MILITARY, "books/txt/ArtOfWar.txt"),
    Book("The Road", 16.99, "Cormac McCarthy", "Alfred A. Knopf", 2006, 287, FICTION, "books/txt/the_road_-_text.txt")
};

#endif