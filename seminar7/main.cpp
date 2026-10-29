int main(){
    std::cout << "static values: " << std::endl;
    Book::print_count(); 
    std::cout << Book::class_name << std::endl;     std::cout << std::endl;


    std::cout << "Book creation: " << std::endl;
    Book my_first_book ("Volkov Alexander", "The Wizard of Oz", 500, 1939);
    my_first_book.printBook();
    my_first_book.print_count();
    std::cout << my_first_book << std::endl;
   
    std::cout << "Second book: " << std::endl;
    Book my_second_book {my_first_book};
    std::cout << my_second_book << std::endl;
    my_second_book.add_bookmark(222);
    my_first_book.add_bookmark(111);
    my_second_book.printBook();


    {
        std::cout << " inside {} " << std::endl;
        Book my_second_book {my_first_book};
        std::cout << my_second_book << std::endl;
        my_second_book.add_bookmark(30);
        my_first_book.add_bookmark(40);
        my_second_book.printBook();
    }


    std::cout << " outside {} " << std::endl;
    my_second_book.printBook();


    return 0;
}
