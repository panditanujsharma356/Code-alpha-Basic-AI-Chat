#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Basic keywords for sentiment analysis
std::vector<std::string> positiveWords = {"good", "happy", "great", "awesome", "fantastic"};
std::vector<std::string> negativeWords = {"bad", "sad", "terrible", "awful", "horrible"};

// Function to detect sentiment based on keywords
std::string detectSentiment(const std::string& input) {
    int positiveCount = 0;
    int negativeCount = 0;

    // Check for positive words
    for (const auto& word : positiveWords) {
        if (input.find(word) != std::string::npos) {
            positiveCount++;
        }
    }

    // Check for negative words
    for (const auto& word : negativeWords) {
        if (input.find(word) != std::string::npos) {
            negativeCount++;
        }
    }

    if (positiveCount > negativeCount) {
        return "positive";
    } else if (negativeCount > positiveCount) {
        return "negative";
    } else {
        return "neutral";
    }
}

// Function to generate responses
std::string generateResponse(const std::string& input) {
    std::string sentiment = detectSentiment(input);
    std::string response;

    // Basic dialogue management based on detected sentiment
    if (sentiment == "positive") {
        response = "I'm glad to hear that!";
    } else if (sentiment == "negative") {
        response = "I'm sorry to hear that. Is there anything I can help with?";
    } else {
        if (input.find("hello") != std::string::npos || input.find("hi") != std::string::npos) {
            response = "Hello! How can I assist you today?";
        } else if (input.find("help") != std::string::npos) {
            response = "I'm here to help! You can ask me questions or tell me how you're feeling.";
        } else {
            response = "I'm here to chat! Feel free to tell me more.";
        }
    }

    return response;
}

int main() {
    std::string userInput;
    std::cout << "Welcome to the AI Chatbot! Type 'exit' to end the conversation.\n";

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        if (userInput == "exit") {
            std::cout << "Chatbot: Goodbye! Have a great day.\n";
            break;
        }

        std::string response = generateResponse(userInput);
        std::cout << "Chatbot: " << response << "\n";
    }

    return 0;
}

