#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
using namespace std;

class reportObj
{
public:
    int current_bid;
    int total_bid;
    int successful_bid;
    int rejected_bid;

    reportObj(int cb)
    {
        current_bid = cb;
        total_bid = 0;
        successful_bid = 0;
        rejected_bid = 0;
    }
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each item
    // You need to track: total bids, successful bids, rejected bids for each item
    // Hint: You may use additional BSTs or other data structures
    // Start your code here
    string item_id;
    int bid_amount;
    BST<string, int> *auction_bst = new ListBST<string, int>();
    BST<string, int> *totalBid_bst = new ListBST<string, int>();
    BST<string, int> *successfulBid_bst = new ListBST<string, int>();
    BST<string, int> *rejectedBid_bst = new ListBST<string, int>();
    BST<string, reportObj *> *report = new ListBST<string, reportObj *>();

    int totalSuccessfulBids = 0, totalRejectedBids = 0;
    // End your code here

    int n;
    in_file >> n;
    for (int i = 0; i < n; ++i)
    {
        // TODO: Implement the logic to read initial items and their starting bids
        // Initialize statistics tracking for each item
        // Start your code here
        in_file >> item_id >> bid_amount;
        auction_bst->insert(item_id, bid_amount);
        totalBid_bst->insert(item_id, 0);
        successfulBid_bst->insert(item_id, 0);
        rejectedBid_bst->insert(item_id, 0);
        report->insert(item_id, new reportObj(bid_amount));
        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    cout << "Initial auction items:" << endl;
    auction_bst->print('I');
   
    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation)
    {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified item
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here
        if (operation == "BID")
        {
            in_file >> item_id >> bid_amount;
            reportObj *r_obj = report->get(item_id);
            r_obj->total_bid++;
            totalBid_bst->update(item_id, totalBid_bst->get(item_id) + 1);
            if (auction_bst->get(item_id) < bid_amount)
            {
                auction_bst->update(item_id, bid_amount);
                r_obj->current_bid = bid_amount;
                successfulBid_bst->update(item_id, successfulBid_bst->get(item_id) + 1);
                r_obj->successful_bid++;
                totalSuccessfulBids++;
                cout << "Bid of " << bid_amount << " on " << item_id << " accepted. Current bid: " << bid_amount << endl;
            }
            else
            {
                rejectedBid_bst->update(item_id, rejectedBid_bst->get(item_id) + 1);
                r_obj->rejected_bid++;
                totalRejectedBids++;
                cout << "Bid of " << bid_amount << " on " << item_id << " rejected. Current bid: " << auction_bst->get(item_id) << endl;
            }
            auction_bst->print('I');
          
        }
        else if (operation == "CHECK")
        {
            in_file >> item_id;
            if (auction_bst->find(item_id))
                cout << "Current bid for " << item_id << ": " << auction_bst->get(item_id) << endl;
            auction_bst->print('I');
           
        }
        else if (operation == "STATS")
        {
            in_file >> item_id;

            cout << " Statistics for " << item_id << ":" << endl;
            cout << " Current highest bid: " << auction_bst->get(item_id) << endl;
            cout << " Total bids placed: " << totalBid_bst->get(item_id) << endl;
            cout << " Successful bids: " << successfulBid_bst->get(item_id) << endl;
            cout << " Rejected bids: " << rejectedBid_bst->get(item_id) << endl;
        }
        else if (operation == "ADD")
        {
            in_file >> item_id >> bid_amount;
            if (!auction_bst->find(item_id))
            {
                auction_bst->insert(item_id, bid_amount);
                totalBid_bst->insert(item_id, 0);
                successfulBid_bst->insert(item_id, 0);
                rejectedBid_bst->insert(item_id, 0);
                report->insert(item_id, new reportObj(bid_amount));
                cout << "Item " << item_id << " added with starting bid " << bid_amount << endl;
            }
            else
            {
                reportObj *r_obj = report->get(item_id);
                r_obj->total_bid++;
                totalBid_bst->update(item_id, totalBid_bst->get(item_id) + 1);
                if (auction_bst->get(item_id) < bid_amount)
                {
                    auction_bst->update(item_id, bid_amount);
                    r_obj->current_bid = bid_amount;
                    successfulBid_bst->update(item_id, successfulBid_bst->get(item_id) + 1);
                    r_obj->successful_bid++;
                    totalSuccessfulBids++;
                    cout << "Item " << item_id << " added with bid " << bid_amount << endl;
                }
                else
                {
                    cout << "Item " << item_id << " already exists " << endl;
                    rejectedBid_bst->update(item_id, rejectedBid_bst->get(item_id) + 1);
                    r_obj->rejected_bid++;
                    totalRejectedBids++;
                }
            }
            auction_bst->print('I');
        }
        else if (operation == "REPORT")
        {
            cout << "Auction Report: " << endl;
            int length = auction_bst->size();
            cout << "Total items: " << length << endl;
            cout << "Total bids placed: " << totalSuccessfulBids + totalRejectedBids << endl;
            cout << "Total successful bids: " << totalSuccessfulBids << endl;
            cout << "Total rejected bids: " << totalRejectedBids << endl;
            cout << endl;
            cout << "Item Statistics:" << endl;

            BST<string, reportObj *> *temp = new ListBST<string, reportObj *>();
            while (!report->empty())
            {
                string min_item = report->find_min();
                reportObj *r_obj = report->get(min_item);

                cout << "  " << min_item
                     << ": Current bid: " << r_obj->current_bid
                     << ", Total bids: " << r_obj->total_bid
                     << ", Successful: " << r_obj->successful_bid
                     << ", Rejected: " << r_obj->rejected_bid << endl;

                temp->insert(min_item, r_obj);
                report->remove(min_item);
            }
            while (!temp->empty())
            {
                string min_item = temp->find_min();
                report->insert(min_item, temp->get(min_item));
                temp->remove(min_item);
            }

            delete temp;
            cout << endl;
        }
        else
            cout << "Invalid Command!" << endl;

        // End your code here
        cout << "==============================\n";
    }

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    delete auction_bst;
    delete totalBid_bst;
    delete successfulBid_bst;
    delete rejectedBid_bst;
    delete report;
    // End your code here
    return 0;
}

// Compile: g++ -std=c++11 task2.cpp -o task2.exe
// Run: .\task2.exe in_task2.txt > myout_task2.txt

