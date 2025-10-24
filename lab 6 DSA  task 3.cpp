#include <iostream>
#include <string>
using namespace std;

class Book {
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;
public:
    Book() {}
    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
    string getId() { return bookId; }
    void setBook(string id, string name, double price, string author, string isbn) {
        bookId = id; bookName = name; bookPrice = price; bookAuthor = author; bookISBN = isbn;
    }
    void print() {
        cout << "ID: " << bookId << ", Name: " << bookName << ", Price: " << bookPrice
             << ", Author: " << bookAuthor << ", ISBN: " << bookISBN << endl;
    }
};

class Node {
    Book book;
public:
    Node* next;
    Node* prev;
    Node() { next = prev = nullptr; }
    Node(Book b) { book = b; next = prev = nullptr; }
    Book getBook() { return book; }
    void setBook(Book b) { book = b; }
};

class BookList {
    Node* tail;
public:
    BookList() { tail = nullptr; }
    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);
        if (!tail) {
            tail = newNode;
            tail->next = tail->prev = tail;
        } else {
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Book " << id << " added successfully ";
    }
    void removeBook(string id) {
        if (!tail) { cout << "List empty "; return; }
        Node* temp = tail->next;
        do {
            if (temp->getBook().getId() == id) {
                if (temp == tail && temp->next == tail) { delete temp; tail = nullptr; }
                else { temp->prev->next = temp->next; temp->next->prev = temp->prev; if (temp==tail) tail=temp->prev; delete temp; }
                cout << "Book " << id << " removed successfully."; return;
            }
            temp = temp->next;
        } while (temp != tail->next);
        cout << "Book " << id << " not found ";
    }
    void updateBook(string id, string name, double price, string author, string isbn) {
        if (!tail) { cout << "List empty "; return; }
        Node* temp = tail->next;
        do {
            if (temp->getBook().getId() == id) { temp->setBook(Book(id,name,price,author,isbn)); cout<<"Book "<<id<<" updated successfully"; return;}
            temp = temp->next;
        } while(temp!=tail->next);
        cout<<"Book "<<id<<" not found ";
    }
    void printBooks() {
        if(!tail) { cout<<"No books"; return;}
        Node* temp = tail->next;
        do { temp->getBook().print(); temp=temp->next;} while(temp!=tail->next);
    }
    void printBook(string id) {
        if(!tail) { cout<<"No books"; return;}
        Node* temp = tail->next;
        do { if(temp->getBook().getId()==id){temp->getBook().print(); return;} temp=temp->next;} while(temp!=tail->next);
        cout<<"Book "<<id<<" not found";
    }
};

int main() {
    BookList list;
    for(int i=1;i<=10;i++) list.addBook("B"+to_string(i),"Book"+to_string(i),100+i,"Author"+to_string(i),"ISBN"+to_string(i));
    cout<<"All Books="; list.printBooks();
    cout<<"Removing Book B5 and B15="; list.removeBook("B5"); list.removeBook("B15");
    cout<<"All Books after removal="; list.printBooks();
    cout<<"Updating Book B3="; list.updateBook("B3","UpdatedBook3",999,"UpdatedAuthor3","UpdatedISBN3"); list.printBook("B3");
    return 0;
}
