#pragma once
#ifndef DISPLAY_PAGES_H
#define DISPLAY_PAGES_H
#include "library.h"

bool displayPages(ReadingStats& readingStats, const vector<string>& bookContent, int startingPage = 1){
    const int linesPerPage = 20;
    int currentPage = startingPage;

    for (size_t i = (startingPage - 1) * linesPerPage; i < bookContent.size(); i += linesPerPage)
    {
        cout << "*--------------------*" << endl;
        cout << R"(        Page)" << currentPage << ":\n";
        cout << "*--------------------*" << endl;
        for (size_t j = i; j < i + linesPerPage && j < bookContent.size(); ++j)
        {
            cout << bookContent[j] << endl;
        }

        cout << "Press 'N/n' to move to the next page, or 'F/f' to finish reading the book.";
        char userInput;
        cin >> userInput;

        if (userInput == 'F' || userInput == 'f')
        {
            readingStats.setTotalPagesRead(readingStats.getTotalPagesRead() + currentPage - startingPage);
            return true;
        }
        cin.ignore();
        currentPage++;
    }

    readingStats.setTotalPagesRead(readingStats.getTotalPagesRead() + currentPage - startingPage);
    return false;
}
#endif 