/*string readBookContent(const string& link) {
    ifstream file(link);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << link << endl;
        return "";
    }

    string bookContent;
    string line;

    while (getline(file, line)) {
        bookContent += line + "\n";
    }

    file.close();

    return bookContent;
}*/