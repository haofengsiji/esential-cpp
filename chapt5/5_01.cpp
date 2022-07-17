#include "LibMat.h"
#include "Book.h"
#include "AudioBook.h"


int main() {
    cout << "\n" << "Creating a LibMat object to print()\n";
    LibMat libmat;
    print(libmat);

    cout << "\n" << "Creating a Book object to print()\n";
    Book b("The Castle", "Franz Kafka");
    print(b);

    cout << "\n" << "Creating a AudioBook object to print()\n";
    AudioBook ab("Man without Qualities", "Robert Musil", "Kenneth Meyer");
    print(ab);
} 