#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Adheres to the Single Responsibility Principle (it would not if we would done saving book in the same class)

// Class responsible for Book data
class Book {
public:
    void setTitle(const std::string& title) {
        this->title = title;
    }

    void setAuthor(const std::string& author) {
        this->author = author;
    }

    void addPage(const std::string& page) {
        pages.push_back(page);
    }

    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    const std::vector<std::string>& getPages() const {
        return pages;
    }

private:
    std::string title;
    std::string author;
    std::vector<std::string> pages;
};

// Class responsible for persisting Book data
class BookPersistence {
public:
    void saveToFile(const Book& book, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Title: " << book.getTitle() << std::endl;
            file << "Author: " << book.getAuthor() << std::endl;
            for (const auto& page : book.getPages()) {
                file << page << std::endl;
            }
            file.close();
        }
    }
};

int main() {
    Book myBook;
    myBook.setTitle("The Hitchhiker's Guide to the Galaxy");
    myBook.setAuthor("Douglas Adams");
    myBook.addPage("Chapter 1: The End of the World");
    myBook.addPage("Chapter 2: The Restaurant at the End of the Universe");

    BookPersistence persistence;
    persistence.saveToFile(myBook, "another_book.txt");

    return 0;
}