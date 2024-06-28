/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

class Message {
private:
    string text;
    int order; // Sequence number or timestamp

public:
    // Empty constructor
    Message() {}

    // Constructor with text and order parameter
    Message(const string& txt, int ord) : text(txt), order(ord) {}

    // Getter for text
    const string& get_text() const {
        return text;
    }

    // Getter for order
    int get_order() const {
        return order;
    }

    // Less than operator for sorting
    bool operator<(const Message& other) const {
        return order < other.order;
    }
};

class MessageFactory {
private:
    int order_counter; // Keeps track of message order

public:
    // Empty constructor
    MessageFactory() : order_counter(0) {}

    // Method to create message
    Message create_message(const string& text) {
        return Message(text, order_counter++);
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message>& messages, Recipient& recipient) {
        // Simulates the unpredictable network, where sent messages might arrive in unspecified order
        // Use a random seed based on a random_device
        random_device rd;
        default_random_engine rng(rd());
        
        shuffle(messages.begin(), messages.end(), rng); // Shuffle messages
        
        for (auto& msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
