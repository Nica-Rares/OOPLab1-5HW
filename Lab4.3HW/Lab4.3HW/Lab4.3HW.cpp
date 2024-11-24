#include <iostream>
#include <vector>
#include <string>

class Review {
public:
    std::string reviewerName;
    std::string reviewContent;

    Review(std::string name, std::string content) : reviewerName(name), reviewContent(content) {}
};

class Book {
public:
    std::string title;
    std::vector<Review> reviews;

    Book(std::string bookTitle) : title(bookTitle) {}

    void addReview(std::string reviewerName, std::string reviewContent) {
        reviews.emplace_back(reviewerName, reviewContent);
    }

    void displayReviews() {
        std::cout << "Reviews for \"" << title << "\":" << std::endl;
        for (const auto& review : reviews) {
            std::cout << reviewerName << ": " << review.reviewContent << std::endl;
        }
    }

    void searchReview(std::string keyword) {
        std::cout << "Searching for \"" << keyword << "\" in reviews for \"" << title << "\":" << std::endl;
        for (const auto& review : reviews) {
            if (review.reviewerName.find(keyword) != std::string::npos ||
                review.reviewContent.find(keyword) != std::string::npos) {
                std::cout << review.reviewerName << ": " << review.reviewContent << std::endl;
            }
        }
    }
};

int main() {
    Book book("C++ Programming");
    book.addReview("Alice", "Great book for learning C++!");
    book.addReview("Bob", "Detailed explanations and examples.");

    book.displayReviews();

    std::string searchKeyword;
    std::cout << "Enter a keyword to search in reviews: ";
    std::getline(std::cin, searchKeyword);
    book.searchReview(searchKeyword);

    return 0;
}
