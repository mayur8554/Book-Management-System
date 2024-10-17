#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#define size 200
using namespace std;

//int MAX_BOOKS = 100;

class Book {
public:
    int ISBN;
    string Title;
    string Author;
    string Genre;
    int Pages;

    Book() = default;

   Book(int isbn, string title, string author, string genre, int pages) 
  : ISBN(isbn), Title(title), Author(author), Genre(genre), Pages(pages){}
  
  


};

void AddBook(Book books[], int &bookCount);
void RemoveBook(Book books[], int &bookCount);
void SearchBook(const Book books[], int bookCount);
void UpdateBookData(Book books[], int bookCount);
void DisplayAllBooks(const Book books[], int bookCount);
void AlreadyStore(Book books[], int &bookCount);
void Messenger(const Book books[], int bookCount);

int main() {
    system("color 9F");
    Book books[size];
    int bookCount = 0;
    int choice;

    AlreadyStore(books, bookCount);

    do {
        cout << "\n\t\t\t**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        cout << "\t\t\t* Book Management System Menu *\n";
        cout << "\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>**\n\n";
        cout << "\t\t\t1. Add Book\n";
        cout << "\t\t\t2. Display All Books\n";
        cout << "\t\t\t3. Remove Book\n";
        cout << "\t\t\t4. Search Book\n";
        cout << "\t\t\t5. Update Book Data\n";
        cout << "\t\t\t6. Exit\n\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddBook(books, bookCount);
                break;
            case 2:
                DisplayAllBooks(books, bookCount);
                break;
            case 3:
                RemoveBook(books, bookCount);
                break;
            case 4:
                SearchBook(books, bookCount);
                break;
            case 5:
                UpdateBookData(books, bookCount);
                break;
            case 6:
                cout << "\t\t\tTHANKS FOR VISITING.\n";
                break;
            default:
                cout << "\t\t\tInvalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

void AlreadyStore(Book books[], int &bookCount)
 {
    if (bookCount + 5 <=size) {
        books[bookCount++] = Book(4563, "The Guide", "R.K. NARAYAN ", " Sort Story ", 328);
        books[bookCount++] = Book(758, "Broken Republic ", "ARUNDHATI ROY", "  Criminal  ", 332);
        books[bookCount++] = Book(75896, "The Swap", "Shuma Raha   ", "Girls thises", 281);
        books[bookCount++] = Book(9781, "Bhagwat Gita", " acharay     ", "  Historic  ", 700);
        books[bookCount++] = Book(97800, "mind crack", "diljith sonii", "   magic    ", 277);
        //books[bookCount++] = Book(9780, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 1178);
    }
}

void DisplayAllBooks(const Book books[], int bookCount)
 {
    if (bookCount == 0) {
        cout << "\t\t\tBook database is empty. No books to display.\n";
        return;
    }

    printf("\n");
    printf("\t\t\t+---------------+---------------------+---------------+--------------+-----------------+\n");
    printf("\t\t\t|     ISBN      |       Title         |   Author      |  Types       |    Pages        |\n");
    printf("\t\t\t+---------------+---------------------+---------------+--------------+-----------------+\n");

    for (int i = 0; i < bookCount; i++) 
	{
        printf("\t\t\t| %-13d | %-19s | %-10s | %-7s | %-15d |\n",
               books[i].ISBN, books[i].Title.c_str(), books[i].Author.c_str(), books[i].Genre.c_str(), books[i].Pages);
    }

     printf("\t\t\t+---------------+---------------------+---------------+--------------+-----------------+\n");

}

void AddBook(Book books[], int &bookCount) 
{
    if (bookCount >= size) {
        cout << "\t\t\tBook database is full. Cannot add more books.\n";
        return;
    }

    Book newBook;
    cout << "\t\t\tEnter ISBN: ";
    cin >> newBook.ISBN;
    cout << "\t\t\tEnter Title: ";
    cin.ignore();
    getline(cin, newBook.Title);
    cout << "\t\t\tEnter Author: ";
    getline(cin, newBook.Author);
    cout << "\t\t\tEnter types: ";
    getline(cin, newBook.Genre);
    cout << "\t\t\tEnter Pages: ";
    cin >> newBook.Pages;

    books[bookCount++] = newBook;
    cout << "\t\t\tBook added successfully.\n";
}

void RemoveBook(Book books[], int &bookCount) {
    if (bookCount == 0) {
        cout << "\t\t\tBook database is empty. Cannot remove a book.\n";
        return;
    }

    int choice;
    cout << "\t\t\tHow would you like to remove the book?\n";
    cout << "\t\t\t1. Remove by ISBN\n";
    cout << "\t\t\t2. Remove by Title\n";
    cout << "\t\t\tEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int ISBNToRemove;
        cout << "\t\t\tEnter the ISBN of the book you want to remove: ";
        cin >> ISBNToRemove;

        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].ISBN == ISBNToRemove) {
                found = true;
                for (int j = i; j < bookCount - 1; ++j) {
                    books[j] = books[j + 1];
                }
                --bookCount;
                cout << "\t\t\tBook with ISBN " << ISBNToRemove << " is removed.\n";
                break;
            }
        }
        if (!found) {
            cout << "\t\t\tBook with ISBN " << ISBNToRemove << " not found.\n";
        }
    } else if (choice == 2) {
        string TitleToRemove;
        cout << "\t\t\tEnter the title of the book you want to remove: ";
        cin >> TitleToRemove;

        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].Title == TitleToRemove) {
                found = true;
                for (int j = i; j < bookCount - 1; ++j) {
                    books[j] = books[j + 1];
                }
                --bookCount;
                cout << "\t\t\tBook with Title '" << TitleToRemove << "' is removed.\n";
                break;
            }
        }
        if (!found) {
            cout << "\t\t\tBook with Title '" << TitleToRemove << "' not found.\n";
        }
    } else {
        cout << "\t\t\tInvalid choice.\n";
    }
}

void SearchBook(const Book books[], int bookCount) {
    if (bookCount == 0) {
        cout << "\t\t\tBook database is empty. Cannot search for a book.\n";
        return;
    }

    int choice;
    cout << "\t\t\tHow would you like to search the book?\n";
    cout << "\t\t\t1. Search by ISBN\n";
    cout << "\t\t\t2. Search by Title\n";
    cout << "\t\t\tEnteryour choice: ";
    cin >> choice;

    if (choice == 1) {
        int SearchISBN;
        cout << "\t\t\tEnter the ISBN of the book you want to search: ";
        cin >> SearchISBN;

        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].ISBN == SearchISBN) {
                found = true;
                cout << "\t\t\tBook found:\n";
                cout << "\t\t\tISBN: " << books[i].ISBN << " Title: " << books[i].Title
                          << " Author: " << books[i].Author << " Genre: " << books[i].Genre
                          << " Pages: " << books[i].Pages << "\n";
                break;
            }
        }
        if (!found) {
            cout << "\t\t\tBook with ISBN " << SearchISBN << " not found.\n";
        }
    } else if (choice == 2) {
        string SearchTitle;
        cout << "\t\t\tEnter the title of the book you want to search: ";
        cin >> SearchTitle;

        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].Title == SearchTitle) {
                found = true;
                cout << "\t\t\tBook found:\n";
                cout << "\t\t\tISBN: " << books[i].ISBN << " Title: " << books[i].Title
                          << " Author: " << books[i].Author << " Genre: " << books[i].Genre
                          << " Pages: " << books[i].Pages << "\n";
                break;
            }
        }
        if (!found) {
            cout << "\t\t\tBook with Title '" << SearchTitle << "' not found.\n";
        }
    } else {
        cout << "\t\t\tInvalid choice.\n";
    }
}

void UpdateBookData(Book books[], int bookCount) {
    if (bookCount == 0) {
        cout << "\t\t\tBook database is empty. Cannot update book data.\n";
        return;
    }

    int ISBNToUpdate;
    cout << "\t\t\tEnter the ISBN of the book you want to update: ";
    cin >> ISBNToUpdate;

    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].ISBN == ISBNToUpdate) {
            found = true;
            cout << "\t\t\tUpdating data for book with ISBN " << ISBNToUpdate << ":\n";
            cout << "\t\t\tEnter new Title: ";
            cin.ignore();
            getline(cin, books[i].Title);
            cout << "\t\t\tEnter new Author: ";
            getline(cin, books[i].Author);
            cout << "\t\t\tEnter new Genre: ";
            getline(cin, books[i].Genre);
            cout << "\t\t\tEnter new Pages: ";
            cin >> books[i].Pages;
            cout << "\t\t\tBook data updated successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "\t\t\tBook with ISBN " << ISBNToUpdate << " not found.\n";
    }
}
