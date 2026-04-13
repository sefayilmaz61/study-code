#include <string>
#include <iostream>

class Note
{
private:
    std::string *text;

public:
    Note(std::string* text_input)
    {
        text = new std::string;
        *text = text_input;
    }

    Note(const Note &otherNote)
    {
        text = new std::string;
        *text = *otherNote.text;
    }
    
    ~Note()
    {
        delete text;
        text = nullptr;
        std::cout << "Memory released" << std::endl;
    }

    void display();

};

void Note::display()
{
    std::cout << *text << std::endl;
}